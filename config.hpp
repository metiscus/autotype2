#pragma once

namespace config
{
	constexpr const char* program_name = "tcc";
	constexpr const int version_major = 1;
	constexpr const int version_minor = 0;

	constexpr const char* copyright_string = 
	"(c) 2016 Michael A Bosse' <metiscus@gmail.com>\n"
    "This program is free software: you can redistribute it and/or modify\n"
    "it under the terms of the GNU General Public License as published by\n"
    "the Free Software Foundation, either version 3 of the License, or\n"
    "(at your option) any later version.\n"
    "\n"
    "This program is distributed in the hope that it will be useful,\n"
    "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
    "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
    "GNU General Public License for more details.\n\n"
	"Built using software created by others:\n"
	"\n"
	"=== RapidXML - 1.13 ===\n"
	"Copyright (c) 2006, 2007 Marcin Kalicinski\n"
	"\n"
	"=== Free Getopt - 0.11 ===\n"
	"Copyright (c) 2002, 2003 Mark K. Kim\n"
	"\n";

	namespace flags
	{
		extern bool verbose;
		extern bool developer_mode;
		extern bool generate_xml_serialization;
		extern bool generate_script_bindings;
		extern bool generate_sql_bindings;
	}
}

namespace error
{
	constexpr const int bad_arguments   = 1;
	constexpr const int file_open_error = 2;
	constexpr const int xml_parse_error = 3;
	constexpr const int unknown_error   = 100;
}
