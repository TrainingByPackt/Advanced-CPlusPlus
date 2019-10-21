//============================================================================
// Name        : chapter5.cpp
// Author      : Olena Lizina
// Description : Exercise 4 Chapter 5
//============================================================================

#include <iostream>
#include <thread>
#include <vector>
#include <string>

class Converter
{
	public:
	Converter(std::vector<std::string>& bufferIn)
		: m_bufferIn(bufferIn)
	{
	}

	Converter(Converter&& rhs)
		: m_bufferIn(std::move(rhs.m_bufferIn))
	{
	}

	Converter(const Converter&) = delete;
	Converter& operator=(const Converter&) = delete;
	Converter& operator=(Converter&&) = delete;

	void operator()(const int idx, std::vector<std::string>& result)
	{
		try
		{
			std::string::const_iterator end = m_bufferIn.at(idx).end();
			std::string bufferOut;

			for (std::string::const_iterator iter = m_bufferIn.at(idx).begin(); iter != end; iter++)
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
			result[idx] = bufferOut;
		}
		catch(...)
		{
			std::cout << "Invalid index" << std::endl;
		}
	}

	private:
	const std::vector<std::string>& m_bufferIn;
};

int main()
{
	const int numberOfTasks = 5;
	std::vector<Converter> functions;
	functions.reserve(numberOfTasks);
	std::vector<std::thread> threads;
	threads.reserve(numberOfTasks);

	std::vector<std::string> textArr;
	textArr.emplace_back("In the previous topics, we learned almost all that we need to work with threads. But we still have something interesting to consider – how to synchronize threads using future results. When we considered condition variables we didn’t cover the second type of synchronization with future results. Now it’s time to learn that.");
	textArr.emplace_back("First of all, let’s consider a real-life example. Imagine, you just passed the exam at the university. You were asked to wait for results some time. So, you have time to coffee with your mates, and every 10-15 mins you check are results available. Then, when you finished all your other activities, you just come to the door of the lecture room and wait for results.");
	textArr.emplace_back("In this exercise, we will write a simple application where we will use std::move() with threads. First of all, we will implement a class that is move constructible. This class will convert lowercase text into uppercase text. Then we will create a vector of instances of this class. Next, we will create a vector of std::thread object. Finally, we will initialize threads with an object from the first vector");
	textArr.emplace_back("Let’s consider one interesting issue. As you remember when we initialize std::thread all constructor arguments are copied into thread memory, including a callable object – lambda, function, std::function. But what if our callable object doesn’t support copy semantic? For example, we created a class that has only move constructor and move assignment operator:");
	textArr.emplace_back("Run this code in your editor. You will see in the console log from the default constructor, two logs from the move operator, then one log from a destructor, then message from the doSomeJob() function and, finally two other log messages from the destructor. We see that the move constructor is called twice.You will get the output like the following:");

	for (int i = 0; i < numberOfTasks; ++i)
	{
	    functions.push_back(Converter(textArr));
	}

	std::vector<std::string> result;
	for (int i = 0; i < numberOfTasks; ++i)
	{
		result.push_back("");
	}
	int idx = 0;

	for (auto iter = functions.begin(); iter != functions.end(); ++iter)
	{
	    std::thread tmp(std::move(*iter), idx, std::ref(result));
	    threads.push_back(std::move(tmp));
	    idx++;
	}

	for (auto iter = threads.begin(); iter != threads.end(); ++iter)
	{
	    (*iter).detach();
	}

	using namespace std::chrono_literals;
	std::this_thread::sleep_for(5s);

	for (const auto& str : result)
	{
		std::cout << str;
	}

	return 0;
}
