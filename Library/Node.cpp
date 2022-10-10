#include "Node.h"
#include <string>
#include <sstream>

Node::Node() 
	: data(0), left(nullptr), right(nullptr), parent(nullptr)
{
}

Node::Node(const int data)
	: data(data), left(nullptr), right(nullptr), parent(nullptr)
{
}


std::wstring ToString(const Node& node)
{
	std::wstringstream out;
	out << node;
	return out.str();
}

std::ostream& operator<<(std::ostream& out, const Node& node)
{
	return out << node.data;
}

std::wostream& operator<<(std::wostream& out, const Node& node)
{
	return out << node.data;
}

std::istream& operator>>(std::istream& in, Node& node)
{
	if (in.peek() == '\n' || in.eof())
	{
		return in;
	}

	in >> node.data;
	return in;
}

bool operator==(const Node& lha, const Node& rha)
{
	return lha.data == rha.data;
}

bool operator!=(const Node& lha, const Node& rha)
{
	return !(lha == rha);
}

bool operator>(const Node& lha, const Node& rha)
{
	return lha.data > rha.data;
}

bool operator>=(const Node& lha, const Node& rha)
{
	return lha.data >= rha.data;
}

bool operator<(const Node& lha, const Node& rha)
{
	return lha.data > rha.data;
}

bool operator<=(const Node& lha, const Node& rha)
{
	return lha.data <= rha.data;
}
