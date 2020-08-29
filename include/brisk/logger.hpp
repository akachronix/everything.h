#pragma once

#include <iostream>
#include <sstream>
#include <fstream>

#include "vector.hpp"
#include "string.hpp"
#include "utility.hpp"

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
		logger(loglevel loglevel, brisk::string logfile)
		{
			m_logLevel = loglevel;
			m_logFile = logfile;
			m_amILogging = true;
			m_amIPrinting = true;
		}

		logger(const logger& other)
		{
			logHistory = other.logHistory;
			m_logLevel = other.m_logLevel;
			m_logFile = other.m_logFile;
			m_amILogging = other.m_amILogging;
			m_amIPrinting = other.m_amIPrinting;
		}

		logger(logger&& other) noexcept
		{
			logHistory = brisk::move(other.logHistory);
			m_logLevel = brisk::move(other.m_logLevel);
			m_logFile = brisk::move(other.m_logFile);
			m_amILogging = brisk::move(other.m_amILogging);
			m_amIPrinting = brisk::move(other.m_amIPrinting);

			other.m_logLevel = brisk::loglevel::everything;
			other.m_amILogging = true;
			other.m_amIPrinting = true;
		}

		~logger()
		{
			dumpLog(m_logFile);
		}

		logger& operator=(const logger& other)
		{
			logHistory = other.logHistory;
			m_logLevel = other.m_logLevel;
			m_logFile = other.m_logFile;
			m_amILogging = other.m_amILogging;
			m_amIPrinting = other.m_amIPrinting;

			return *this;
		}
		
		logger& operator=(logger&& other) noexcept
		{
			if (this != &other)
			{
				logHistory = brisk::move(other.logHistory);
				m_logLevel = brisk::move(other.m_logLevel);
				m_logFile = brisk::move(other.m_logFile);
				m_amILogging = brisk::move(other.m_amILogging);
				m_amIPrinting = brisk::move(other.m_amIPrinting);

				other.m_logLevel = brisk::loglevel::everything;
				other.m_amILogging = true;
				other.m_amIPrinting = true;
			}

			return *this;
		}

		brisk::string filename() const noexcept
		{
			return m_logFile;
		}

		void filename(const brisk::string filename) noexcept
		{
			m_logFile = filename;
		}

		bool logError(const brisk::string error_str)
		{
			if (m_logLevel >= loglevel::errors)
			{
				brisk::string message = "[ERROR] " + error_str + "\n";
				
				if (m_amIPrinting)
					std::cout << message;

				logHistory.push_back(message);
				return true;
			}

			return false;
		}

		bool logWarning(const brisk::string warning_str)
		{
			if (m_logLevel >= loglevel::warnings)
			{
				brisk::string message = "[WARNING] " + warning_str + "\n";

				if (m_amIPrinting)
					std::cout << message;

				logHistory.push_back(message);
				return true;
			}

			return false;
		}

		template <class T>
		bool print(T value)
		{
			if (m_logLevel >= loglevel::print)
			{
				std::stringstream casted_value;
				casted_value << value;

				if (m_amIPrinting)
					std::cout << value;

				logHistory.push_back(casted_value.str().c_str());
				return true;
			}

			return false;
		}

		bool print(logger&(*func)(logger&))
		{
			if (m_logLevel >= loglevel::print)
			{
				func(*this);
				return true;
			}

			return false;
		}

		template<class T>
		void input(T& var)
		{
			std::cin >> var;

			std::stringstream varToString;
			varToString << var << "\n";
			logHistory.push_back(varToString.str().c_str());
		}

		brisk::vector<brisk::string>& buffer() noexcept
		{
			return logHistory;
		}

		size_t size() noexcept
		{
			size_t sz = 0;
			for (auto& it : logHistory)
				sz += it.size() + sizeof(brisk::string);
			
			return sz;
		}

		void shrink_to_fit()
		{
			brisk::string s = "";
			for (auto& it : logHistory)
				s.append(it); 
			
			logHistory.erase(logHistory.begin(), logHistory.end());
			logHistory.emplace_back(s);
			logHistory.shrink_to_fit();
		}

		long ram_usage()
		{
			long size = sizeof(brisk::string) * logHistory.size();
			for (int i = 0; i < logHistory.size(); ++i)
				size += logHistory[i].size();
			
			return size;
		}

		bool dumpLog(const brisk::string file)
		{
			if (logHistory.size() != 0 && m_amILogging == true)
			{
				std::ofstream log_file(file.c_str());
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

		bool dumpLog()
		{
			return dumpLog(m_logFile);
		}

		void disableLogging() noexcept
		{
			m_amILogging = false;
		}

		void enableLogging() noexcept
		{
			m_amILogging = true;
		}

		void disablePrinting() noexcept
		{
			m_amIPrinting = false;
		}

		void enablePrinting() noexcept
		{
			m_amIPrinting = true;
		}

	private:
		brisk::vector<brisk::string> logHistory;
		loglevel m_logLevel;
		brisk::string m_logFile;
		bool m_amILogging;
		bool m_amIPrinting;
	};

	template <class T>
	logger& operator<<(logger& log, T value)
	{
		log.print(value);
		return log;
	}

	logger& operator<<(logger& log, logger&(*func)(logger&))
	{
		return (*func)(log);
	}

	template <class T>
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
}
