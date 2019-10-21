#include "Watchman.hpp"
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
			std::cerr << "Watchman | runAdd | false awakening" << std::endl;
			m_CondVarAddPerson.wait(locker);
		}

		std::cout << "Watchman | runAdd | new person came" << std::endl;
		m_AddNotified = false;
		while (m_CreatedPeople.size() > 0)
		{
			try
			{
				auto person = m_CreatedPeople.get();
				if (m_PeopleInside.size() < CountPeopleInside)
				{
					std::cout << "Watchman | runAdd | welcome in our The Art Gallery" << std::endl;
					m_PeopleInside.add(std::move(person));
				}
				else
				{
					std::cout << "Watchman | runAdd | Sorry, we are full. Please wait" << std::endl;
					m_PeopleInQueue.add(std::move(person));
				}
			}
			catch(const std::string& e)
			{
				std::cout << e << std::endl;
			}
		}

		std::cout << "Watchman | runAdd | check people in queue" << std::endl;
		if (m_PeopleInQueue.size() > 0)
		{
			while (m_PeopleInside.size() < CountPeopleInside)
			{
				try
				{
					auto person = m_PeopleInQueue.get();
					std::cout << "Watchman | runAdd | welcome in our The Art Gallery" << std::endl;
					m_PeopleInside.add(std::move(person));
				}
				catch(const std::string& e)
				{
					std::cout << e << std::endl;
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
			std::cerr << "Watchman | runRemove | false awakening" << std::endl;
			m_CondVarRemovePerson.wait(locker);
		}

		m_RemoveNotified = false;

		if (m_PeopleInside.size() > 0)
		{
			m_PeopleInside.removePerson();
			std::cout << "Watchman | runRemove | good buy" << std::endl;
		}
		else
		{
			std::cout << "Watchman | runRemove | there is nobody in The Art Gallery" << std::endl;
		}

		std::cout << "Watchman | runRemove | check people in queue" << std::endl;

		if (m_PeopleInQueue.size() > 0)
		{
			while (m_PeopleInside.size() < CountPeopleInside)
			{
				try
				{
					auto person = m_PeopleInQueue.get();
					std::cout << "Watchman | runRemove | welcome in our The Art Gallery" << std::endl;
					m_PeopleInside.add(std::move(person));
				}
				catch(const std::string& e)
				{
					std::cout << e << std::endl;
				}
			}
		}
	}
}
