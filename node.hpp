#pragma once

#include <algorithm>
#include <list>
#include <string>

class Node
{
public:
	enum Type
	{
		type_document,
		type_enum,
		type_comment,
		type_namespace,
		type_class,
		type_struct,
		type_concrete
	};

private:
	std::string name_;
	Type type_;
	std::list<Node*> children_;

public:
	Node() = default;
	virtual ~Node()
	{
		for(auto itr: children_)
		{
			delete itr;
		}
	}

	inline void set_type(Type type)
	{
		type_ = type;
	}

	inline void set_name(const std::string& name)
	{
		name_ = name;
	}

	inline void set_name(const char* name)
	{
		if(name) name_ = name;
	}

	inline void add_child(Node* child)
	{
		children_.push_back(child);
	}

	inline void remove_child(Node* child)
	{
		auto it = std::find(children_.begin(), children_.end(), child);
		if(it != children_.end())
		{
			children_.erase(it);
		}
	}

	typedef std::list<Node*>::iterator iterator;
	inline iterator begin() 
	{
		return children_.begin();
	}

	inline iterator end()
	{
		return children_.end();
	}

	typedef std::list<Node*>::const_iterator const_iterator;
	inline const_iterator begin() const
	{
		return children_.begin();
	}

	inline const_iterator end() const
	{
		return children_.end();
	}

	inline size_t size() const
	{
		return children_.size();
	}

	inline bool empty() const
	{
		return children_.empty();
	}
};