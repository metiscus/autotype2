#include "log.hpp"
#include "config.hpp"
#include <cstdio>
#include <cstdarg>

int log(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	vprintf(format, args);

	va_end(args);
}

int verbose(const char* format, ...)
{
	if(config::flags::verbose)
	{
		va_list args;
		va_start(args, format);

		vprintf(format, args);

		va_end(args);
	}
}