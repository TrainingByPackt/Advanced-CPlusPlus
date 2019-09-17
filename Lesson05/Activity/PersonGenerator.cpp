#include "PersonGenerator.hpp"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time, chrono */
#include <ratio>        /* std::milli */

PersonGenerator::PersonGenerator(Persons& persons,
					std::condition_variable& add_person,
					std::condition_variable& remove_person,
					std::mutex& add_lock,
					std::mutex& remove_lock,
					bool& addNotified,
					bool& removeNotified)
	: m_CreatedPersons(persons)
	, m_CondVarAddPerson(add_person)
	, m_AddLock(add_lock)
	, m_AddNotified(addNotified)
	, m_CondVarRemovePerson(remove_person)
	, m_RemoveLock(remove_lock)
	, m_RemoveNotified(removeNotified)
{
	m_CreateThread = std::thread(&PersonGenerator::runCreating, this);
	m_RemoveThread = std::thread(&PersonGenerator::runRemoving, this);
}

PersonGenerator::~PersonGenerator()
{
	if (m_CreateThread.joinable())
	{
		m_CreateThread.join();
	}
	if (m_RemoveThread.joinable())
	{
		m_RemoveThread.join();
	}
}

void PersonGenerator::runCreating()
{
	using namespace std::chrono_literals;
	srand (time(NULL));
	while(true)
	{
		std::chrono::duration<int, std::milli> duration((rand() % 10 + 1)*1000);
		std::this_thread::sleep_for(duration);
		std::cout << "PersonGenerator | runCreating | new person:" << std::endl;
		m_CreatedPersons.add(std::move(Person()));
		notifyCreated();
	}
}

void PersonGenerator::runRemoving()
{
	using namespace std::chrono_literals;
	srand (time(NULL));
	while(true)
	{
		std::chrono::duration<int, std::milli> duration((rand() % 10 + 20)*1000);
		std::this_thread::sleep_for(duration);
		std::cout << "PersonGenerator | runRemoving | somebody has left the gallery:" << std::endl;
		notifyRemoved();
	}
}

void PersonGenerator::notifyCreated()
{
	std::unique_lock<std::mutex> lock(m_AddLock);
	m_AddNotified = true;
	m_CondVarAddPerson.notify_all();
}

void PersonGenerator::notifyRemoved()
{
	std::unique_lock<std::mutex> lock(m_RemoveLock);
	m_RemoveNotified = true;
	m_CondVarRemovePerson.notify_all();
}
