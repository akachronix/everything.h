#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

namespace brisk
{
	enum class loglevel
	{
		nothing = -1,
		print = 0,
		errors = 1,
		warnings = 2,
		everything = 3
	};

	class logger
	{
	public:
		logger(logger&) = delete;
		logger(logger&&) = delete;

		logger(loglevel _loglevel, std::string _logfile);
		~logger();

		std::string filename() const;

		bool logError(std::string error_str);
		bool logWarning(std::string warning_str);

		template<typename T> bool print(T value);
		bool print(logger&(*func)(logger&));

		template<typename T> void input(T& var);

		bool dumpLog(std::string file);
		bool dumpLog();

	private:
		std::vector<std::string> logHistory;
		loglevel m_logLevel;
		std::string m_logFile;
	};

	logger::logger(loglevel _loglevel, std::string _logfile)
		: m_logLevel(_loglevel), m_logFile(_logfile)
	{

	}

	logger::~logger()
	{
		dumpLog(m_logFile);
	}

	std::string logger::filename() const
	{
		return m_logFile;
	}

	bool logger::logError(std::string error_str)
	{
		if (m_logLevel >= loglevel::errors)
		{
			std::string message = "[ERROR] " + error_str + "\n";

			std::cout << message;
			logHistory.push_back(message);

			return true;
		}

		return false;
	}

	bool logger::logWarning(std::string warning_str)
	{
		if (m_logLevel >= loglevel::warnings)
		{
			std::string message = "[WARNING] " + warning_str + "\n";

			std::cout << message;
			logHistory.push_back(message);

			return true;
		}

		return false;
	}

	template<typename T>
	bool logger::print(T value)
	{
		if (m_logLevel >= loglevel::print)
		{
			std::stringstream casted_value;
			casted_value << value;
			std::cout << value;

			logHistory.push_back(casted_value.str());

			return true;
		}

		return false;
	}

	bool logger::print(logger& (*func) (logger&))
	{
		if (m_logLevel >= loglevel::print)
		{
			func(*this);
			return true;
		}

		return false;
	}

	template<typename T>
	void logger::input(T& var)
	{
		std::cin >> var;

		std::stringstream varToString;
		varToString << var << "\n";
		logHistory.push_back(varToString.str());
	}

	template<typename T>
	logger& operator<<(logger& log, T value)
	{
		log.print(value);
		return log;
	}

	logger& operator<<(logger& log, logger&(*func)(logger&))
	{
		return (*func)(log);
	}

	template<typename T>
	logger& operator>>(logger& log, T& value)
	{
		log.input(value);
		return log;
	}

	logger& newl(logger& log)
	{
		log.print("\n");
		return log;
	}

	logger& stab(logger& log)
	{
		log.print("  ");
		return log;
	}

	logger& tab(logger& log)
	{
		log.print("    ");
		return log;
	}

	logger& space(logger& log)
	{
		log.print(" ");
		return log;
	}

	bool logger::dumpLog(std::string file)
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

	bool logger::dumpLog()
	{
		return dumpLog(m_logFile);
	}
}