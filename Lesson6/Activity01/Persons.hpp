#ifndef PERSONS_HPP
#define PERSONS_HPP

#include "Person.hpp"
#include <mutex>
#include <vector>

class Persons
{
public:
	Persons();
	~Persons() = default;

	void add(Person&& person);
	Person get();

	size_t size() const;
	void removePerson();

private:
	std::mutex m_Mutex;
	std::vector<Person> m_Persons;
};

#endif // PERSONS_HPP
