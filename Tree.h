#pragma once
#include <iostream>
#include "Node.h"

class Tree;
std::wstring ToString(const Tree& tree);

class Tree
{
private:
    Node* root;
    int count;
    Tree(const Tree& other) = delete;
    Tree(Tree&& other) = delete;
    Tree& operator=(const Tree& other) = delete;
    Tree& operator=(Tree&& other) = delete;
    Node* Insert(Node* current, Node* node, Node* parent);
    
public:
    Tree();
    ~Tree();
    Tree(std::initializer_list<int> elements);
    int GetCount() const noexcept;
    bool Add(const int element) noexcept;
    bool Delete(const int element) noexcept; 
    bool Contains(const int element) const noexcept;
    bool IsEmpty() const noexcept;
    void Clear() noexcept;

    friend std::ostream& operator<<(std::ostream& out,const Tree& tree);
    friend std::wostream& operator<<(std::wostream& out,const Tree& tree);
}