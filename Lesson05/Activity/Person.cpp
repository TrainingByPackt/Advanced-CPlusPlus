#include "Person.hpp"
#include <iostream>

int Person::m_NextId;

Person::Person()
	: m_Id(m_NextId++)
{
	std::cout << "Person | Person | Hello! I'm " << m_Id << std::endl;
}

Person& Person::operator=(Person&& other)
{
	m_Id = other.m_Id;
	return *this;
}

Person::Person(Person&& other)
	: m_Id(other.m_Id)
{
}
