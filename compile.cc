#include <cassert>
#include "config.hpp"
#include <list>
#include "log.hpp"
#include <string>
#include <cstring>

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>

#include <boost/algorithm/string.hpp>

#include "node.hpp"
#include "comment.hpp"
#include "class.hpp"

static void compile_type_file(const std::string& file);
static void process_xml(rapidxml::xml_document<>& document);
static void process_node(Node* parent, rapidxml::xml_node<>* node);
static Node* process_comment(rapidxml::xml_node<>* node);
static Node* process_class(rapidxml::xml_node<>* node);
static Node* process_struct(rapidxml::xml_node<>* node);

void compile_types(std::list<std::string> files)
{
	for(auto itr : files)
	{
		log("Compiling '%s'\n", itr.c_str());
		compile_type_file(itr);
	}
}

static void compile_type_file(const std::string& file)
{
	try {
		// load the victim file
		rapidxml::file<> xml_file(file.c_str());
		
		// build an xml_document
		rapidxml::xml_document<> doc;
		doc.parse<0>(xml_file.data());

		// process the xml
		process_xml(doc);
	}
	catch(std::runtime_error e)
	{
		log("[Exception] Failed to open file '%s'.\n", e.what(), file.c_str());
		exit(error::file_open_error);
	}
	catch(rapidxml::parse_error e)
	{
		log("[Exception] Failed to parse file '%s'. Error was '%s'\n", file.c_str(), e.what());
		exit(error::xml_parse_error);
	}
	catch(...)
	{
		log("[Exception] Unknown unhandled exception while parsing file '%s'.\n", file.c_str());
		exit(error::unknown_error);
	}
}

static void process_xml(rapidxml::xml_document<>& document)
{
	Node code_document;
	code_document.set_type(Node::type_document);

	// process the parent level nods in the document and recurse down
	for(auto node = document.first_node()->first_node(); node; node = node->next_sibling())
	{
		process_node(&code_document, node);
	}
}

static void process_node(Node* parent, rapidxml::xml_node<>* node)
{
	if(node)
	{
		developer("<%s>%s</%s>\n", node->name(), node->value(), node->name());

		Node *code_node = nullptr;

		// get the type of the node
		if(boost::iequals(node->name(), "comment"))
		{
			code_node = process_comment(node);
		}
		else if(boost::iequals(node->name(), "class"))
		{
			code_node = process_class(node);
		}
		else if(boost::iequals(node->name(), "struct"))
		{
			code_node = process_struct(node);
		}
		else if(boost::iequals(node->name(), "function"))
		{
			//code_node = process_struct(node);
			code_node = new Node();
		}
		else if(boost::iequals(node->name(), "member"))
		{
			//code_node = process_struct(node);
			code_node = new Node();
		}

		parent->add_child(code_node);
	}
}

static Node* process_comment(rapidxml::xml_node<>* node)
{
	developer("Processing a comment.\n");
	Comment *comment = new Comment();
	comment->set_text(node->value());
	return comment;
}

static Node* process_class(rapidxml::xml_node<>* node)
{
	developer("Processing a class.\n");
	//process class bases etc here

	Class *theclass = new Class();
	theclass->set_name("TBD: some classname");

	for(auto child = node->first_node(); !!child; child = child->next_sibling())
	{
		process_node(theclass, child);
	}

	return theclass;
}

static Node* process_struct(rapidxml::xml_node<>* node)
{
	developer("Processing a struct.\n");
	//process class bases etc here

	Class *theclass = new Class();
	theclass->set_name("TBD: some classname");

	for(auto child = node->first_node(); !!child; child = child->next_sibling())
	{
		process_node(theclass, child);
	}

	return theclass;
}