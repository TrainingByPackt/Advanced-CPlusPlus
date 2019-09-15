/*
 * LoggerUtils.hpp
 *
 *  Created on: 14 вер. 2019 р.
 *      Author: Olena Lizina
 */

#ifndef LOGGERUTILS_HPP_
#define LOGGERUTILS_HPP_

#include <string>

namespace logger
{
namespace utils
{
class LoggerUtils
{
public:
	static std::string getDateTime();
	static std::string getThreadId();
	static std::string getLoggingLevel(const std::string& level);
	static std::string getFileAndLine(const std::string& file, const int& line);
	static std::string getFuncName(const std::string& func);
	static std::string getInFuncName(const std::string& func);
	static std::string getOutFuncName(const std::string& func);
};
} // namespace utils
} // namespace logger

#endif /* LOGGERUTILS_HPP_ */
