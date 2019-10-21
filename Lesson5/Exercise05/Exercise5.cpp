//============================================================================
// Name        : chapter5.cpp
// Author      : Olena Lizina
// Description : Exercise 5 Chapter 5
//============================================================================

#include <iostream>
#include <future>

class ToUppercase
{
	public:
	std::string operator()(const std::string& bufIn)
	{
		std::string bufferOut;
		for (std::string::const_iterator iter = bufIn.begin(); iter != bufIn.end(); iter++)
		{
			if (*iter >= 97 && *iter <= 122)
			{
				bufferOut += static_cast<char>(static_cast<int>(*iter) - 32);
			}
			else
			{
				bufferOut += *iter;
			}
		}
		return bufferOut;
	}

	void operator()(const std::string& bufIn, std::promise<std::string> result)
	{
		std::string bufferOut;
		for (std::string::const_iterator iter = bufIn.begin(); iter != bufIn.end(); iter++)
		{
			if (*iter >= 97 && *iter <= 122)
			{
				bufferOut += static_cast<char>(static_cast<int>(*iter) - 32);
			}
			else
			{
				bufferOut += *iter;
			}
		}
		result.set_value(bufferOut);
	}
};

int main()
{
	ToUppercase ptConverter;
	std::packaged_task<std::string(const std::string&)> upperCaseResult1(ptConverter);
	std::future<std::string> futureUpperResult1= upperCaseResult1.get_future();
	std::thread thr1(std::move(upperCaseResult1), "This is a string for the packaged task task");
	thr1.detach();

	ToUppercase fConverter;
	std::future<std::string> futureUpperResult2 = std::async(fConverter, "This is a string for the asynchronous task");

	ToUppercase pConverter;
	std::promise<std::string> promiseResult;
	std::future<std::string> futureUpperResult3 = promiseResult.get_future();
	std::thread thr2(pConverter, "This is a string for the task that returns a promise", std::move(promiseResult));
	thr2.detach();

	futureUpperResult3.wait();
	std::cout << "Converted strings: "
			<< futureUpperResult1.get() << std::endl
			<< futureUpperResult2.get() << std::endl
			<< futureUpperResult3.get() << std::endl;
    return 0;
}
