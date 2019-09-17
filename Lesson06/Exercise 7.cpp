//============================================================================
// Name        : Exercise7.cpp
// Author      : Olena Lizina
// Description : Exercise 7
//============================================================================

#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>

template< class CharT, class Traits = std::char_traits<CharT> >
class extended_streambuf : public std::basic_streambuf< CharT, Traits >
{
public:
    int overflow( int c = EOF ) override
    {
    	if (!Traits::eq_int_type(c, EOF))
    	{
    		return fputc( c, stdout );
    	}
    	return Traits::not_eof(c);
    }
};

template< class CharT, class Traits = std::char_traits<CharT> >
class extended_ostream : public std::basic_ostream< CharT, Traits >
{
public:
	extended_ostream()
		: std::basic_ostream< CharT, Traits >::basic_ostream(&buffer)
		, buffer()
    {
        this->init(&buffer);
    }

	extended_streambuf< CharT, Traits >* rdbuf () const
	{
		return (extended_streambuf< CharT, Traits >*)&buffer;
	}

private:
    extended_streambuf< CharT, Traits > buffer;
};

class logger
{
public:
	logger()
		: m_log()
		, writeAdditionalInfo(true)
	{
	}

	template<typename T>
	logger& operator<<(const T& value)
	{
		if (writeAdditionalInfo)
		{
			std::string time = fTime();
			auto id = threadId();
			m_log << time << id << value;
			writeAdditionalInfo = false;
		}
		else
		{
			m_log << value;
		}
		return *this;
	}

	logger&
	operator<<(std::ostream& (*pfn)(std::ostream&))
	{
		writeAdditionalInfo = true;
		pfn(m_log);
		return *this;
	}

private:
	std::string fTime()
	{
		auto now = std::chrono::system_clock::now();
		std::time_t time = std::chrono::system_clock::to_time_t(now);
		std::ostringstream log;
		std::string strTime(std::ctime(&time));
		strTime.pop_back();
		log << "[" << strTime << "]";
		return log.str();
	}

	std::string threadId()
	{
		auto id = std::this_thread::get_id();
		std::ostringstream log;
		log << "[" << std::dec << id << "]";
		return log.str();
	}

private:
	extended_ostream<char> m_log;
	bool writeAdditionalInfo;
};

int main()
{
	logger log;
	log << "Integer: " << 156 << std::endl;
	log << "Float: " << 156.12 << std::endl;
	log << "Hexadecimal: " << std::hex << std::showbase
			<< std::uppercase << 0x2a << std::dec << std::endl;
	log << "Bool: " << std::boolalpha << false << std::endl;

	std::thread thr1([]()
			{
				logger log;
				log << "Integer: " << 156 << std::endl;
				log << "Float: " << 156.12 << std::endl;
				log << "Hexadecimal: " << std::hex << std::showbase
						<< std::uppercase << 0x2a << std::dec << std::endl;
				log << "Bool: " << std::boolalpha << false << std::endl;
			});
	thr1.join();
	return 0;
}
