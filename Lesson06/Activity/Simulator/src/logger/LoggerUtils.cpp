/*
 * LoggerUtils.cpp
 *
 *  Created on: 14 вер. 2019 р.
 *      Author: Olena Lizina
 */
#include "LoggerUtils.hpp"

#include <sstream>
#include <ctime>
#include <thread>

namespace logger
{
namespace utils
{
std::string LoggerUtils::getDateTime()
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,sizeof(buffer),"%d-%m-%YT%H:%M:%S",timeinfo);
	std::stringstream ss;
	ss << "[";
	ss << buffer;
	ss << "]";
	return ss.str();
}

std::string LoggerUtils::getThreadId()
{
	std::stringstream ss;
	ss << "[";
	ss << std::this_thread::get_id();
	ss << "]";
	return ss.str();
}

std::string LoggerUtils::getLoggingLevel(const std::string& level)
{
	std::stringstream ss;
	ss << "[";
	ss << level;
	ss << "]";
	return ss.str();
}

std::string LoggerUtils::getFileAndLine(const std::string& file, const int& line)
{
	std::stringstream ss;
	ss << " ";
	ss << file;
	ss << ":";
	ss << line;
	ss << ":";
	return ss.str();
}

std::string LoggerUtils::getFuncName(const std::string& func)
{
	std::stringstream ss;
	ss << " --- ";
	ss << func;
	ss << "()";
	return ss.str();
}

std::string LoggerUtils::getInFuncName(const std::string& func)
{
	std::stringstream ss;
	ss << " --> ";
	ss << func;
	ss << "()";
	return ss.str();
}

std::string LoggerUtils::getOutFuncName(const std::string& func)
{
	std::stringstream ss;
	ss << " <-- ";
	ss << func;
	ss << "()";
	return ss.str();
}
}
}



