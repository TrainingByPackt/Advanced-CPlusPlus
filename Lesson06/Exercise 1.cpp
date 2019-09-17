//============================================================================
// Name        : Exercise1.cpp
// Author      : Olena Lizina
// Description : Exercise 1
//============================================================================

#include <fstream>
#include <iostream>
#include <string>

class Book
{
public:
	Book(const std::string& name,
		 const std::string& author,
		 const int year,
		 const float price)
	: m_Name(name)
	, m_Author(author)
	, m_Year(year)
	, m_Price(price) {}

	std::string getName() const { return m_Name; }
	std::string getAuthor() const { return m_Author; }
	int getYear() const { return m_Year; }
	float getPrice() const { return m_Price; }

private:
	std::string m_Name;
	std::string m_Author;
	int m_Year;
	float m_Price;
};

int main(int argc, char **argv)
{
	std::string pricesFile("prices.txt");

	Book book_001("Brave", "Olena Lizina", 2017, 33.57);

	{
		std::ofstream outFile(pricesFile);
		if (outFile.fail())
		{
			std::cerr << "Failed to open file " << pricesFile << std::endl;
			return 1;
		}

		outFile << book_001.getName() << " "
				<< book_001.getAuthor() << " "
				<< book_001.getYear() << " "
				<< book_001.getPrice() << std::endl;
	}

	{
		std::string name;
		std::string authorName;
		std::string authorSurname;
		int year;
		float price;

		std::ifstream inFile(pricesFile);
		if (inFile.fail())
		{
			std::cerr << "Failed to open file " << pricesFile << std::endl;
			return 1;
		}

		inFile >> name >> authorName >> authorSurname >> year >> price;
		Book book_002(name, std::string(authorName + " " + authorSurname), year, price);

		std::cout << "Book name: " << book_002.getName() << std::endl
				  << "Author name: " << book_002.getAuthor() << std::endl
				  << "Year: " << book_002.getYear() << std::endl
				  << "Price: " << book_002.getPrice() << std::endl;
	}
	return 0;
}
