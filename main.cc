#include <cstdio>
#include <cstdlib>
#include <string>
#include <list>

#include "log.hpp"
#include "config.hpp"
#include "getopt.h"

static void show_version();
static void show_help();

int main(int argc, char **argv)
{
	// parse argument flags
	int opt;
	constexpr const char* option_string = "vVh";
	while((opt = getopt(argc, argv, option_string)) != -1)
	{
		switch(opt)
		{
			case 'v':
				config::flags::verbose = true;
				break;
			case 'V':
				show_version();
				break;
			case 'h':
				show_help();
				break;
			default:
				return 1;
		}
	}

	// gather inputs
	std::list<std::string> files;
	for(int file = optind; file != argc; ++file)
	{
		files.push_back(argv[file]);
		verbose("Adding file '%s' for processing.", argv[file]);
	}

	return 0;
}

static void show_version()
{
	printf("%s version %d.%d\n", config::program_name, config::version_major, config::version_minor);
	exit(0);
}

static void show_help()
{
	printf("Usage: %s [options] file...\n", config::program_name);
	printf("Options:\n");
	printf("  -h\tDisplay this information.\n");
	printf("  -V\tDisplay version information.\n");
	printf("  -v\tDisplay verbose logging information.\n");
	exit(0);
}