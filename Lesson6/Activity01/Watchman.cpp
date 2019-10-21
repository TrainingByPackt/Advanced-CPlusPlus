#include "Watchman.hpp"
#include "logger/Logger.hpp"
#include "Common.hpp"
#include <iostream>

Watchman::Watchman(std::condition_variable& addPerson,
			std::condition_variable& removePerson,
			std::mutex& addMux,
			std::mutex& removeMux,
			bool& addNotified,
			bool& removeNotified,
			Persons& peopleInside,
			Persons& peopleInQueue,
			Persons& createdPeople)
	: m_CondVarRemovePerson(removePerson)
	, m_CondVarAddPerson(addPerson)
	, m_AddMux(addMux)
	, m_RemoveMux(removeMux)
	, m_AddNotified(addNotified)
	, m_RemoveNotified(removeNotified)
	, m_PeopleInside(peopleInside)
	, m_PeopleInQueue(peopleInQueue)
	, m_CreatedPeople(createdPeople)
{
	m_ThreadAdd = std::thread(&Watchman::runAdd, this);
	m_ThreadRemove = std::thread(&Watchman::runRemove, this);
}

Watchman::~Watchman()
{
	if (m_ThreadAdd.joinable())
	{
		m_ThreadAdd.join();
	}
	if (m_ThreadRemove.joinable())
	{
		m_ThreadRemove.join();
	}
}

void Watchman::runAdd()
{
	while (true)
	{
		std::unique_lock<std::mutex> locker(m_AddMux);
		while(!m_AddNotified)
		{
			LOG_DEBUG() << "Spurious awakening";
			m_CondVarAddPerson.wait(locker);
		}

		LOG_INFO() << "New person came";
		m_AddNotified = false;
		while (m_CreatedPeople.size() > 0)
		{
			try
			{
				auto person = m_CreatedPeople.get();
				if (m_PeopleInside.size() < CountPeopleInside)
				{
					LOG_INFO() << "Welcome in the our Art Gallery";
					m_PeopleInside.add(std::move(person));
				}
				else
				{
					LOG_INFO() << "Sorry, we are full. Please wait";
					m_PeopleInQueue.add(std::move(person));
				}
			}
			catch(const std::string& e)
			{
				LOG_ERROR() << e;
			}
		}

		LOG_TRACE() << "Check people in queue";
		if (m_PeopleInQueue.size() > 0)
		{
			while (m_PeopleInside.size() < CountPeopleInside)
			{
				try
				{
					auto person = m_PeopleInQueue.get();
					LOG_INFO() << "Welcome in the our Art Gallery";
					m_PeopleInside.add(std::move(person));
				}
				catch(const std::string& e)
				{
					LOG_ERROR() << e;
				}
			}
		}
	}
}

void Watchman::runRemove()
{
	while (true)
	{
		std::unique_lock<std::mutex> locker(m_RemoveMux);
		while(!m_RemoveNotified)
		{
			LOG_WARN() << "Spurious awakening";
			m_CondVarRemovePerson.wait(locker);
		}

		m_RemoveNotified = false;

		if (m_PeopleInside.size() > 0)
		{
			m_PeopleInside.removePerson();
			LOG_INFO() << "Good buy";
		}
		else
		{
			LOG_INFO() << "There is nobody in The Art Gallery";
		}

		LOG_TRACE() << "Check people in queue";

		if (m_PeopleInQueue.size() > 0)
		{
			while (m_PeopleInside.size() < CountPeopleInside)
			{
				try
				{
					auto person = m_PeopleInQueue.get();
					LOG_INFO() << "Welcome in our The Art Gallery";
					m_PeopleInside.add(std::move(person));
				}
				catch(const std::string& e)
				{
					LOG_ERROR() << e;
				}
			}
		}
	}
}
