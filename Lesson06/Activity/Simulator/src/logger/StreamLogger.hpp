/*
 * StreamLogger.hpp
 *
 *  Created on: 15 вер. 2019 р.
 *      Author: Olena Lizina
 */

#ifndef STREAMLOGGER_HPP_
#define STREAMLOGGER_HPP_

#include "LoggerMacroses.hpp"
#include "LoggerUtils.hpp"
#include <sstream>
#include <thread>
#include <mutex>

namespace logger
{
class StreamLogger : public std::ostringstream
{
public:
	StreamLogger(const std::string logLevel,
		   const std::string fileLine,
		   const std::string funcName);

	~StreamLogger();

private:
	static std::mutex m_mux;
	const std::string m_logLevel;
	const std::string m_fileLine;
	const std::string m_funcName;
};
} // namespace logger

#endif /* STREAMLOGGER_HPP_ */
