#ifndef PERSON_GENERATOR_HPP
#define PERSON_GENERATOR_HPP

#include "Persons.hpp"
#include <condition_variable>
#include <thread>

class PersonGenerator
{
public:
	PersonGenerator(Persons& persons,
			std::condition_variable& add_person,
			std::condition_variable& remove_person,
			std::mutex& add_lock,
			std::mutex& remove_lock,
			bool& addNotified,
			bool& removeNotified);

	~PersonGenerator();

	PersonGenerator(const PersonGenerator&) = delete;
	PersonGenerator(PersonGenerator&&) = delete;
	PersonGenerator& operator=(const PersonGenerator&) = delete;
	PersonGenerator& operator=(PersonGenerator&&) = delete;

private:
	void runCreating();
	void runRemoving();

	void notifyCreated();
	void notifyRemoved();

private:
	std::thread m_CreateThread;
	std::thread m_RemoveThread;

	Persons& m_CreatedPersons;

	// to notify about creating new person
	std::condition_variable& m_CondVarAddPerson;
	std::mutex& m_AddLock;
	bool& m_AddNotified;

	// to notify that person needs to be removed
	std::condition_variable& m_CondVarRemovePerson;
	std::mutex& m_RemoveLock;
	bool& m_RemoveNotified;
};

#endif // PERSON_GENERATOR_HPP
