#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

enum class loglevel_t
{
	nothing = -1,
	print = 0,
	errors = 1,
	warnings = 2,
	everything = 3
};

class Logger
{
public:
	Logger();
	Logger(loglevel_t _loglevel, std::string _logfile);
	Logger(Logger&) = delete;
	Logger(Logger&&) = delete;

	~Logger();

	bool logError(std::string error_str);
	bool logWarning(std::string warning_str);

	template<typename T> bool print(T value);
	bool print(Logger&(*func)(Logger&));

	template<typename T> void input(T& var);

	bool dumpLog(std::string file);
	bool dumpLog();

private:
	std::vector<std::string> logHistory;
	loglevel_t m_logLevel;
	std::string m_logFile;
};

Logger::Logger()
	: m_logLevel(loglevel_t::everything), m_logFile("Logger.log")
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "Logger()\n";
#endif
}

Logger::Logger(loglevel_t _loglevel, std::string _logfile)
	: m_logLevel(_loglevel), m_logFile(_logfile)
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "Logger(loglevel_t _loglevel, std::string _logfile)\n";
#endif
}

Logger::~Logger()
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "~Logger()\n";
#endif

	dumpLog(m_logFile);
}

bool Logger::logError(std::string error_str)
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "bool Logger::logError(std::string error_str)\n";
#endif

	if (m_logLevel >= loglevel_t::errors)
	{
		std::string message = "[ERROR] " + error_str + "\n";

		std::cout << message;
		logHistory.push_back(message);

		return true;
	}

	return false;
}

bool Logger::logWarning(std::string warning_str)
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "bool Logger::logWarning(std::string warning_str)\n";
#endif

	if (m_logLevel >= loglevel_t::warnings)
	{
		std::string message = "[WARNING] " + warning_str + "\n";

		std::cout << message;
		logHistory.push_back(message);

		return true;
	}

	return false;
}

template<typename T>
bool Logger::print(T value)
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "bool Logger::print(T value)\n";
#endif

	if (m_logLevel >= loglevel_t::print)
	{
		std::stringstream casted_value;
		casted_value << value;
		std::cout << value;

		logHistory.push_back(casted_value.str());

		return true;
	}

	return false;
}

bool Logger::print(Logger& (*func) (Logger&))
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "bool Logger::print(Logger& (*func) (Logger&))\n";
#endif

	if (m_logLevel >= loglevel_t::print)
	{
		func(*this);
		return true;
	}

	return false;
}

template<typename T>
void Logger::input(T& var)
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "void Logger::input(T& var)\n";
#endif

	std::cin >> var;

	std::stringstream varToString;
	varToString << var << "\n";
	logHistory.push_back(varToString.str());
}

template<typename T>
Logger& operator<<(Logger& log, T value)
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "Logger& operator<<(Logger& log, T value)\n";
#endif

	log.print(value);
	return log;
}

Logger& operator<<(Logger& log, Logger&(*func)(Logger&))
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "Logger& operator<<(Logger&, Logger&(*func)(Logger&)\n";
#endif

	return (*func)(log);
}

template<typename T>
Logger& operator>>(Logger& log, T& value)
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "Logger& operator>>(Logger& log, T& value)\n";
#endif

	log.input(value);
	return log;
}

Logger& newl(Logger& log)
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "Logger& newl(Logger& log)\n";
#endif

	log.print("\n");
	return log;
}

Logger& stab(Logger& log)
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "Logger& stab(Logger& log)\n";
#endif

	log.print("  ");
	return log;
}

Logger& tab(Logger& log)
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "Logger& tab(Logger& log)\n";
#endif

	log.print("    ");
	return log;
}

Logger& space(Logger& log)
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "Logger& space(Logger& log)\n";
#endif

	log.print(" ");
	return log;
}

bool Logger::dumpLog(std::string file)
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "bool Logger::dumpLog(std::string file)\n";
#endif

	if (logHistory.size() != 0)
	{
		std::ofstream log_file(file);
		if (log_file.is_open())
		{
			for (auto x : logHistory)
				log_file << x;

			log_file.close();
			return true;
		}
	}
	
	return false;
}

bool Logger::dumpLog()
{
#if defined(EVERYTHING_DEBUG) || defined(LOGGER_DEBUG)
	std::cout << "bool Logger::dumpLog()\n";
#endif

	return dumpLog(m_logFile);
}

using logger_t = Logger;
