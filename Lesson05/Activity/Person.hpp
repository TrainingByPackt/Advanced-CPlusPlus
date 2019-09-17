#ifndef PERSON_HPP
#define PERSON_HPP

class Person
{
public:
	Person();
	Person& operator=(Person&&);
	Person(Person&&);
	~Person() = default;

	Person(const Person&) = delete;
	Person& operator=(const Person&) = delete;

private:
	int m_Id;
	static int m_NextId;
};

#endif // PERSON_HPP
