#pragma once

#include <string>

#include "node.hpp"

class Comment : public Node
{
	std::string text_;
public:
	Comment()
		: Node()
	{
		set_type(Node::type_comment);
	}

	virtual ~Comment() = default;

	inline void set_text(const std::string& text)
	{
		text_ = text;
	}

	const std::string& get_text() const
	{
		return text_;
	}
};