#pragma once
#include "Node.h"

class Iterator 
{
private:
	Node* current;

public:
	explicit Iterator(Node* value);
    Iterator(const Iterator& other);

    bool operator == (Iterator const& other) const;
    bool operator != (Iterator const& other) const;
    Iterator operator++();
    int& operator *();
    int& operator *() const;
};
