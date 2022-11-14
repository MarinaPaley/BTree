#include "Iterator.h"

Iterator::Iterator(Node* value): current(value)
{
}

Iterator::Iterator(const Iterator& other)
{
	this->current = other.current;
}

bool Iterator::operator==(Iterator const& other) const
{
	return (this->current == other.current);
}

bool Iterator::operator!=(Iterator const& other) const
{
	return (this->current != other.current);
}

Iterator Iterator::operator++()
{
	return Iterator();
}
