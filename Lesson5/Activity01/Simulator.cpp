//============================================================================
// Name        : Simulator.cpp
// Author      : Olena Lizina
// Description : The Art Gallery work simulator
//============================================================================

#include <iostream>
#include <condition_variable>

#include "Persons.hpp"
#include "Watchman.hpp"
#include "PersonGenerator.hpp"

int main()
{
	{
		std::condition_variable g_CondVarRemovePerson;
		std::condition_variable g_CondVarAddPerson;

		std::mutex g_AddMux;
		std::mutex g_RemoveMux;

		bool g_AddNotified = false;;
		bool g_RemoveNotified = false;

		Persons g_PeopleInside;
		Persons g_PeopleInQueue;
		Persons g_CreatedPersons;

		PersonGenerator generator(g_CreatedPersons, g_CondVarAddPerson, g_CondVarRemovePerson,
						g_AddMux, g_RemoveMux, g_AddNotified, g_RemoveNotified);

		Watchman watchman(g_CondVarAddPerson,
				g_CondVarRemovePerson,
				g_AddMux,
				g_RemoveMux,
				g_AddNotified,
				g_RemoveNotified,
				g_PeopleInside,
				g_PeopleInQueue,
				g_CreatedPersons);
	}

	char a;
	std::cin >> a;
	return 0;
}
