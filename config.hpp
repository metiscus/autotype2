#pragma once

namespace config
{
	constexpr const char* program_name = "tcc";
	constexpr const int version_major = 1;
	constexpr const int version_minor = 0;

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
