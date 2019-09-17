//============================================================================
// Name        : Exercise6.cpp
// Author      : Olena Lizina
// Description : Exercise 6
//============================================================================

#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>

class extendedOstream
{
public:
	extendedOstream()
		: m_oss(std::cout)
		, writeAdditionalInfo(true)
	{
	}

	template<typename T>
	extendedOstream& operator<<(const T& value)
	{
		if (writeAdditionalInfo)
		{
			std::string time = fTime();
			auto id = threadId();
			m_oss << time << id << value;
			writeAdditionalInfo = false;
		}
		else
		{
			m_oss << value;
		}
		return *this;
	}

	extendedOstream&
	operator<<(std::ostream& (*pfn)(std::ostream&))
	{
		writeAdditionalInfo = true;
		pfn(m_oss);
		return *this;
	}

private:
	std::string fTime()
	{
		auto now = std::chrono::system_clock::now();
		std::time_t time = std::chrono::system_clock::to_time_t(now);
		std::ostringstream oss;
		std::string strTime(std::ctime(&time));
		strTime.pop_back();
		oss << "[" << strTime << "]";
		return oss.str();
	}

	std::string threadId()
	{
		auto id = std::this_thread::get_id();
		std::ostringstream oss;
		oss << "[" << std::dec << id << "]";
		return oss.str();
	}

private:
	std::ostream& m_oss;
	bool writeAdditionalInfo;
};

int main()
{
	extendedOstream oss;
	oss << "Integer: " << 156 << std::endl;
	oss << "Float: " << 156.12 << std::endl;
	oss << "Hexadecimal: " << std::hex << std::showbase
		<< std::uppercase << 0x2a << std::dec << std::endl;
	oss << "Bool: " << std::boolalpha << false << std::endl;

	std::thread thr1([]()
			{
				extendedOstream oss;
				oss << "Integer: " << 156 << std::endl;
				oss << "Float: " << 156.12 << std::endl;
				oss << "Hexadecimal: " << std::hex << std::showbase
					<< std::uppercase << 0x2a << std::dec << std::endl;
				oss << "Bool: " << std::boolalpha << false << std::endl;
			});
	thr1.join();
	return 0;
}
