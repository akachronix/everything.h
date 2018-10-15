#pragma once

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

	void disableLogging();
	void enableLogging(loglevel_t _loglevel);

    bool logError(std::string error_str);
    bool logWarning(std::string warning_str);

	bool print(short value);
	bool print(unsigned short value);
	bool print(int value);
	bool print(unsigned int value);
	bool print(float value);
	bool print(double value);
	bool print(long double value);
	bool print(const char* print_str);
	bool print(std::string print_str);

    bool dumpLog(std::string file);
	bool dumpLog();

private:
    std::vector<std::string> logHistory;
	loglevel_t m_logLevel;
    std::string m_logFile;
};

Logger& operator<< (Logger& log, short value);
Logger& operator<< (Logger& log, unsigned short value);
Logger& operator<< (Logger& log, int value);
Logger& operator<< (Logger& log, unsigned int value);
Logger& operator<< (Logger& log, float value);
Logger& operator<< (Logger& log, double value);
Logger& operator<< (Logger& log, long double value);
Logger& operator<< (Logger& log, const char* str);
Logger& operator<< (Logger& log, std::string str);
Logger& operator<< (Logger& log, Logger&(*func)(Logger&));

Logger& newl(Logger& log);
Logger& tab(Logger& log);
Logger& space(Logger& log);

using logger_t = Logger;