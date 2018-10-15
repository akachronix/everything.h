#include "liblog.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

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

void Logger::disableLogging()
{
    m_logLevel = loglevel_t::nothing;
}

void Logger::enableLogging(loglevel_t _loglevel)
{
    m_logLevel = _loglevel;
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

bool Logger::print(short value)
{
    if (m_logLevel >= loglevel_t::print)
    {
		std::ostringstream casted_value;
		casted_value << value;
		
        std::cout << casted_value.str();
        logHistory.push_back(casted_value.str());

        return true;
    }

    return false;
}

bool Logger::print(unsigned short value)
{
    if (m_logLevel >= loglevel_t::print)
    {
		std::ostringstream casted_value;
		casted_value << value;
		
        std::cout << casted_value.str();
        logHistory.push_back(casted_value.str());

        return true;
    }

    return false;
}

bool Logger::print(int value)
{
    if (m_logLevel >= loglevel_t::print)
    {
		std::ostringstream casted_value;
		casted_value << value;
		
        std::cout << casted_value.str();
        logHistory.push_back(casted_value.str());

        return true;
    }

    return false;
}

bool Logger::print(unsigned int value)
{
    if (m_logLevel >= loglevel_t::print)
    {
		std::ostringstream casted_value;
		casted_value << value;
		
        std::cout << casted_value.str();
        logHistory.push_back(casted_value.str());

        return true;
    }

    return false;
}

bool Logger::print(float value)
{
    if (m_logLevel >= loglevel_t::print)
    {
		std::ostringstream casted_value;
		casted_value << value;
		
        std::cout << casted_value.str();
        logHistory.push_back(casted_value.str());

        return true;
    }

    return false;
}

bool Logger::print(double value)
{
    if (m_logLevel >= loglevel_t::print)
    {
		std::ostringstream casted_value;
		casted_value << value;
		
        std::cout << casted_value.str();
        logHistory.push_back(casted_value.str());

        return true;
    }

    return false;
}

bool Logger::print(long double value)
{
    if (m_logLevel >= loglevel_t::print)
    {
		std::ostringstream casted_value;
		casted_value << value;
		
        std::cout << casted_value.str();
        logHistory.push_back(casted_value.str());

        return true;
    }

    return false;
}

bool Logger::print(const char* print_str)
{
	if (m_logLevel >= loglevel_t::print)
	{
		std::cout << print_str;
		logHistory.push_back(print_str);
		
		return true;
	}
	
	return false;
}

bool Logger::print(std::string print_str)
{
    if (m_logLevel >= loglevel_t::print)
    {
        std::cout << print_str;
        logHistory.push_back(print_str);

        return true;
    }

    return false;
}

Logger& operator<<(Logger& log, short value)
{
	log.print(value);
    return log;
}

Logger& operator<<(Logger& log, unsigned short value)
{
	log.print(value);
    return log;
}

Logger& operator<<(Logger& log, int value)
{
	log.print(value);
    return log;
}

Logger& operator<<(Logger& log, unsigned int value)
{
	log.print(value);
    return log;
}

Logger& operator<<(Logger& log, float value)
{
	log.print(value);
    return log;
}

Logger& operator<<(Logger& log, double value)
{
	log.print(value);
    return log;
}

Logger& operator<<(Logger& log, long double value)
{
	log.print(value);
    return log;
}

Logger& operator<<(Logger& log, const char* str)
{
	log.print(str);
    return log;
}

Logger& operator<<(Logger& log, std::string str)
{
	log.print(str);
    return log;
}

Logger& operator<<(Logger& log, Logger&(*func)(Logger&))
{
	return (*func)(log);
}

Logger& newl(Logger& log)
{
	log.print("\n");
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
    if(logHistory.size() != 0)
    {
        std::ofstream log_file;
        log_file.open(file);

        if(log_file.is_open())
        {
            for(auto x : logHistory)
            {
                log_file << x;
            }

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