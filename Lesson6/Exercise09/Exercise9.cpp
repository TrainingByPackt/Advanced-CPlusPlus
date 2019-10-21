//============================================================================
// Name        : Exercise9.cpp
// Author      : Olena Lizina
// Description : Exercise 9
//============================================================================
#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>

class mtcout : public std::ostringstream
{
public:
	mtcout() = default;
	~mtcout()
	{
		std::lock_guard<std::mutex> lock(m_mux);
		std::cout << std::this_thread::get_id() << " " << this->str();
	}
private:
	static std::mutex m_mux;
};

std::mutex mtcout::m_mux;

int main(int argc, char* argv[])
{
	auto func = [](const std::string msg)
	{
		using namespace std::chrono_literals;
		for (int i = 0; i < 1000; ++i)
		{
//			mtcout{} << msg << std::endl;
			std::cout << std::this_thread::get_id() << " " << msg << std::endl;
		}
	};

	std::thread thr1(func, "111111111");
	std::thread thr2(func, "222222222");
	std::thread thr3(func, "333333333");
	std::thread thr4(func, "444444444");

	thr1.join();
	thr2.join();
	thr3.join();
	thr4.join();
	return 0;
}
