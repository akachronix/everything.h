#include <iostream>

#include "everything.h"

int main(int argc, const char* argv[])
{
	{
		SmartPtr<logger_t> test(new logger_t(loglevel_t::everything, "logger.log"));
		auto logger = test.get();

		(*logger) << "hello, world!" << newl;
	}

	std::cin.get();
	return 0;
}