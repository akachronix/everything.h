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
	~Logger();

	Logger(loglevel_t _loglevel, std::string _logfile);

	bool logError(std::string error_str);
	bool logWarning(std::string warning_str);

	template<typename T> bool print(T value);
	bool print(Logger& (*func) (Logger&));

	template<typename T> void input(T& var);

	bool dumpLog(std::string file);
	bool dumpLog();

private:
	std::vector<std::string> logHistory;
	loglevel_t m_logLevel;
	std::string m_logFile;
};

Logger::Logger(loglevel_t _loglevel, std::string _logfile)
	: m_logLevel(_loglevel), m_logFile(_logfile)
{

}

Logger::Logger()
	: m_logLevel(loglevel_t::everything), m_logFile("Logger.log")
{

}

Logger::~Logger()
{
	dumpLog(m_logFile);
}

bool Logger::logError(std::string error_str)
{
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
	std::cin >> var;

	std::stringstream varToString;
	varToString << var << "\n";
	logHistory.push_back(varToString.str());
}

template<typename T>
Logger& operator<< (Logger& log, T value)
{
	log.print(value);
	return log;
}

Logger& operator<< (Logger& log, Logger&(*func)(Logger&))
{
	return (*func)(log);
}

template<typename T>
Logger& operator>> (Logger& log, T& value)
{
	log.input(value);
	return log;
}

Logger& newl(Logger& log)
{
	log.print("\n");
	return log;
}

Logger& stab(Logger& log)
{
	log.print("  ");
	return log;
}

Logger& tab(Logger& log)
{
	log.print("    ");
	return log;
}

Logger& space(Logger& log)
{
	log.print(" ");
	return log;
}

bool Logger::dumpLog(std::string file)
{
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
	return dumpLog(m_logFile);
}

using logger_t = Logger;
