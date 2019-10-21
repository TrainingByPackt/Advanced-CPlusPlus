#ifndef WATCHMAN_HPP
#define WATCHMAN_HPP

#include <mutex>
#include <thread>
#include <condition_variable>
#include "Persons.hpp"

class Watchman
{
public:
	Watchman(std::condition_variable&,
			std::condition_variable&,
			std::mutex&,
			std::mutex&,
			bool&,
			bool&,
			Persons&,
			Persons&,
			Persons&);

	~Watchman();

	Watchman(const Watchman&) = delete;
	Watchman(Watchman&&) = delete;
	Watchman& operator=(const Watchman&) = delete;
	Watchman& operator=(Watchman&&) = delete;

private:
	void runAdd();
	void runRemove();

private:
	std::thread m_ThreadAdd;
	std::thread m_ThreadRemove;

	std::condition_variable& m_CondVarRemovePerson;
	std::condition_variable& m_CondVarAddPerson;

	std::mutex& m_AddMux;
	std::mutex& m_RemoveMux;

	bool& m_AddNotified;
	bool& m_RemoveNotified;

	Persons& m_PeopleInside;
	Persons& m_PeopleInQueue;
	Persons& m_CreatedPeople;
};

#endif // WATCHMAN_HPP
