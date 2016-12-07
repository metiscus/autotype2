#pragma once

#include <string>
#include <list>

#include "node.hpp"

class Class : public Node
{
	std::list<std::string> bases_;

public:
	Class()
		: Node()
	{
		set_type(Node::type_class);
	}

	virtual ~Class() = default;

	void add_base(const std::string& base)
	{
		bases_.push_back(base);
	}

	std::list<std::string> get_base_list() const
	{
		return bases_;
	}
};