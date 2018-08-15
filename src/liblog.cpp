#include "liblog.hpp"

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

logger::logger(loglevel_t loglevel, std::string logfile)
{
    m_loglevel = loglevel;
    m_logfile = logfile;
}

logger::logger(loglevel_t loglevel)
{
    m_loglevel = loglevel;
}

logger::logger()
{
    // use defaults (which are to log everything and set filename to logger.log)
    m_loglevel = everything;
    m_logfile = "logger.log";
}

logger::~logger()
{
    dump_log(m_logfile);
}

bool logger::log_error(std::string error_str)
{
    if (m_loglevel >= errors)
    {
        std::string message = "[ERROR] " + error_str + "\n";

        std::cout << message;
        log_history.push_back(message);

        return true;
    }

    return false;
}

bool logger::log_warning(std::string warning_str)
{
    if (m_loglevel >= warnings)
    {
        std::string message = "[WARNING] " + warning_str + "\n";

        std::cout << message;
        log_history.push_back(message);

        return true;
    }

    return false;
}

bool logger::log(std::string log_str)
{
    if (m_loglevel >= everything)
    {
        std::string message = "[LOG] " + log_str + "\n";

        std::cout << message;
        log_history.push_back(message);

        return true;
    }

    return false;
}

bool logger::log_value(std::string log_str, int value)
{
    if (m_loglevel >= everything)
    {
        /* Credit: https://stackoverflow.com/questions/332111/how-do-i-convert-a-double-into-a-string-in-c
         *
         * std::ostringstream strs;
         * strs << dbl;
         * std::string str = strs.str(); */

        std::ostringstream casted_value;
        casted_value << value;

        std::string message = BLANK_STR;

        if(log_str != "")
        {
            message = log_str + casted_value.str() + "\n";
        }

        else
        {
            message = casted_value.str() + "\n";
        }

        log_history.push_back(message);

        return true;
    }

    return false;
}

bool logger::log_value(std::string log_str, float value)
{
	if (m_loglevel >= everything)
	{
		/* Credit: https://stackoverflow.com/questions/332111/how-do-i-convert-a-double-into-a-string-in-c
		*
		* std::ostringstream strs;
		* strs << dbl;
		* std::string str = strs.str(); */

		std::ostringstream casted_value;
		casted_value << value;

		std::string message = BLANK_STR;

		if (log_str != "")
		{
			message = log_str + casted_value.str() + "\n";
		}

		else
		{
			message = casted_value.str() + "\n";
		}

		log_history.push_back(message);

		return true;
	}

	return false;
}

bool logger::log_value(std::string log_str, double value)
{
    if (m_loglevel >= everything)
    {
        /* Credit: https://stackoverflow.com/questions/332111/how-do-i-convert-a-double-into-a-string-in-c
         *
         * std::ostringstream strs;
         * strs << dbl;
         * std::string str = strs.str(); */

        std::ostringstream casted_value;
        casted_value << value;

        std::string message = BLANK_STR;

        if(log_str != "")
        {
            message = log_str + casted_value.str() + "\n";
        }

        else
        {
            message = casted_value.str() + "\n";
        }

        log_history.push_back(message);

        return true;
    }

    return false;
}

bool logger::log_value(int value)
{
	if (m_loglevel >= everything)
	{
		/* Credit: https://stackoverflow.com/questions/332111/how-do-i-convert-a-double-into-a-string-in-c
		*
		* std::ostringstream strs;
		* strs << dbl;
		* std::string str = strs.str(); */

		std::ostringstream casted_value;
		casted_value << value;

		std::string message = casted_value.str() + "\n";

		log_history.push_back(message);

		return true;
	}

	return false;
}

bool logger::log_value(float value)
{
	if (m_loglevel >= everything)
	{
		/* Credit: https://stackoverflow.com/questions/332111/how-do-i-convert-a-double-into-a-string-in-c
		*
		* std::ostringstream strs;
		* strs << dbl;
		* std::string str = strs.str(); */

		std::ostringstream casted_value;
		casted_value << value;

		std::string message = casted_value.str() + "\n";

		log_history.push_back(message);

		return true;
	}

	return false;
}

bool logger::log_value(double value)
{
	if (m_loglevel >= everything)
	{
		/* Credit: https://stackoverflow.com/questions/332111/how-do-i-convert-a-double-into-a-string-in-c
		*
		* std::ostringstream strs;
		* strs << dbl;
		* std::string str = strs.str(); */

		std::ostringstream casted_value;
		casted_value << value;

		std::string message = casted_value.str() + "\n";

		log_history.push_back(message);

		return true;
	}

	return false;
}

bool logger::print(std::string print_str)
{
    if (m_loglevel >= loglevel_t::print)
    {
        std::cout << print_str;
        log_history.push_back(print_str);

        return true;
    }

    return false;
}

bool logger::dump_log(std::string file)
{
    if(log_history.size() != 0)
    {
        std::ofstream log_file;
        log_file.open(file);

        if(log_file.is_open())
        {
            for(auto x : log_history)
            {
                log_file << x;
            }

            log_file.close();

            return true;
        }
    }
    return false;
}

bool logger::dump_log()
{
	return dump_log(m_logfile);
}
