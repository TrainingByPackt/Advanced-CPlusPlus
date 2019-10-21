//============================================================================
// Name        : Exercise1.cpp
// Author      : Olena Lizina
// Description : Exercise 1
//============================================================================

#include <iostream>
#include <string>

class Track
{
public:
	Track(const std::string& name,
		  const std::string& singer,
	      const std::string& date,
	      const unsigned int& lengthInSeconds)
		: m_Name(name)
		, m_Singer(singer)
		, m_Date(date)
		, m_LengthInSeconds(lengthInSeconds)
{
}

	std::string getName() const { return m_Name; }
	std::string getSinger() const { return m_Singer; }
	std::string getDate() const { return m_Date; }
	unsigned int getLength() const { return m_LengthInSeconds; }

private:
	std::string m_Name;
	std::string m_Singer;
	std::string m_Date;
	unsigned int m_LengthInSeconds;
};

template <typename charT, typename Traits>
inline std::basic_ostream<charT, Traits>&
operator<<(std::basic_ostream<charT, Traits>& os, Track trackItem)
{
	os << "Track information: ["
	   << "Name: " << trackItem.getName()
	   << ", Singer: " << trackItem.getSinger()
	   << ", Date of creation: " << trackItem.getDate()
	   << ", Length in seconds: " << trackItem.getLength()
	   << "]";
	return os;
}

int main(int argc, char **argv)
{
	Track track_001("Summer night city",
			        "ABBA",
					"1979",
					213);

	std::cout << track_001 << std::endl;

	return 0;
}
