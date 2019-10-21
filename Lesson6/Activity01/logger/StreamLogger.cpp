/*
 * StreamLogger.cpp
 *
 *  Created on: 15 вер. 2019 р.
 *      Author: Olena Lizina
 */

#include "StreamLogger.hpp"
#include <iostream>

std::mutex logger::StreamLogger::m_mux;

namespace logger
{
StreamLogger::StreamLogger(const std::string logLevel,
			   const std::string fileLine,
			   const std::string funcName)
		: m_logLevel(logLevel)
		, m_fileLine(fileLine)
		, m_funcName(funcName)
{}

StreamLogger::~StreamLogger()
{
	std::lock_guard<std::mutex> lock(m_mux);
	if (this->str().empty())
	{
		std::cout << DATETIME << THREAD_ID << m_logLevel << m_fileLine << m_funcName << std::endl;
	}
	else
	{
		std::cout << DATETIME << THREAD_ID << m_logLevel << m_fileLine << m_funcName << " | " << this->str() << std::endl;
	}
}
}

