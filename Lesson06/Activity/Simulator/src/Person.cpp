#include "Person.hpp"
#include "logger/Logger.hpp"
#include <iostream>

int Person::m_NextId;

Person::Person()
	: m_Id(m_NextId++)
{
	LOG_TRACE() << "Hello! I'm " << m_Id;
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
