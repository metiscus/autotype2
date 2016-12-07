#include "log.hpp"
#include "config.hpp"
#include <cstdio>
#include <cstdarg>

int log(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	int ret = vprintf(format, args);

	va_end(args);
	return ret;
}

int verbose(const char* format, ...)
{
	int ret = 0;
	if(config::flags::verbose)
	{
		va_list args;
		va_start(args, format);

		ret = vprintf(format, args);

		va_end(args);
	}
	return ret;
}

int developer(const char* format, ...)
{
	int ret = 0;
	if(config::flags::developer_mode)
	{
		va_list args;
		va_start(args, format);

		ret = vprintf(format, args);

		va_end(args);
	}
	return ret;
}