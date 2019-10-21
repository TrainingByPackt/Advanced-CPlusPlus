/*
 * LoggerMacroses.hpp
 *
 *  Created on: 14 вер. 2019 р.
 *      Author: Olena Lizina
 */

#ifndef LOGGERMACROSES_HPP_
#define LOGGERMACROSES_HPP_

#define DATETIME \
	logger::utils::LoggerUtils::getDateTime()

#define THREAD_ID \
	logger::utils::LoggerUtils::getThreadId()

#define LOG_LEVEL( level ) \
	logger::utils::LoggerUtils::getLoggingLevel(level)

#define FILE_LINE \
	logger::utils::LoggerUtils::getFileAndLine(__FILE__, __LINE__)

#define FUNC_NAME \
	logger::utils::LoggerUtils::getFuncName(__FUNCTION__)

#define FUNC_ENTRY_NAME \
	logger::utils::LoggerUtils::getInFuncName(__FUNCTION__)

#define FUNC_EXIT_NAME \
	logger::utils::LoggerUtils::getOutFuncName(__FUNCTION__)

#endif /* LOGGERMACROSES_HPP_ */
