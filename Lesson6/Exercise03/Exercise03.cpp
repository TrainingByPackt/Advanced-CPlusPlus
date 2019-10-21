//============================================================================
// Name        : Exercise3.cpp
// Author      : Olena Lizina
// Description : Exercise 3
//============================================================================

#include <sstream>
#include <iostream>

class Replacer
{
public:
	std::string operator()(const std::string& originalString,
						   const std::string& wordToBeReplaced,
						   const std::string& wordReplaceBy)
	{
		std::istringstream iss(originalString);
		std::ostringstream oss;

		std::string word;
		while (iss >> word)
		{
			if (0 == word.compare(wordToBeReplaced))
			{
				oss << wordReplaceBy << " ";
			}
			else
			{
				oss << word << " ";
			}
		}

		return oss.str();
	}
};

int main(int argc, char **argv)
{
	Replacer worker;

	std::string foodList("coffee tomatoes coffee cucumbers sugar");
	std::string changedList(worker(foodList, "coffee", "chocolate"));

	std::cout << changedList;
	return 0;
}
