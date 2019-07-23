//============================================================================
// Name        : chapter5.cpp
// Author      : Olena Lizina
// Description : Exercise 3 Chapter 5
//============================================================================

#include <iostream>
#include <thread>

class Handler
{
public:

	Handler()
	{
	    std::cout << "Handler()" << std::endl;
	}
	Handler(const Handler&)
	{
	    std::cout << "Handler(const Handler&)" << std::endl;
	}
	Handler& operator=(const Handler&)
	{
	    std::cout << "Handler& operator=(const Handler&)" << std::endl;
	    return *this;
	}
 	Handler(Handler && obj)
 	{
	    std::cout << "Handler(Handler && obj)" << std::endl;
	}
	Handler & operator=(Handler && obj)
	{
	    std::cout << "Handler & operator=(Handler && obj)" << std::endl;
	    return *this;
	}
	~Handler()
	{
	    std::cout << "~Handler()" << std::endl;
	}
};

void doSomeJob(Handler&& h)
{
    std::cout << "I'm here" << std::endl;
}

int main()
{
	Handler handler;
	std::thread thr1(doSomeJob, std::move(handler));

	thr1.detach();
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(5s);

	return 0;
}
