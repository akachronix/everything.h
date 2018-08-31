#pragma once

#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>

enum loglevel_t
{
    print = 0,
    errors = 1,
    warnings = 2,
    everything = 3
};

class Logger
{
public:
    Logger(loglevel_t _loglevel, std::string _logfile);
	
    Logger();
    ~Logger();

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
	
	friend void operator<<(Logger& log, short value);
	friend void operator<<(Logger& log, unsigned short value);
	friend void operator<<(Logger& log, int value);
	friend void operator<<(Logger& log, unsigned int value);
	friend void operator<<(Logger& log, float value);
	friend void operator<<(Logger& log, double value);
	friend void operator<<(Logger& log, long double value);
	friend void operator<<(Logger& log, const char* str);
	friend void operator<<(Logger& log, std::string str);
	friend void operator<<(Logger& log, void(*func)(Logger&));

    bool dumpLog(std::string file);
	bool dumpLog();

private:
    std::vector<std::string> logHistory;
	loglevel_t m_logLevel;
    std::string m_logFile;
};

void newl(Logger& log);
void tab(Logger& log);

using logger_t = Logger;