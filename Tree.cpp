#include "Tree.h"
#include "Node.h"

Tree::Tree() : root(nullptr), count(0)
{}

bool Tree::IsEmpty() const noexcept
{
    return this->root == nullptr;
}

Node* Tree::Insert(Node* current, Node* node, Node* parent)
{
    if (current == nullptr)
    {
        current = node;
        current->parent = parent;
        return current;
    }

    if (node < current)
            {
                current->left = this->Insert(current->left, node, current);
            }
            else if (node > current)
            {
                current->right = this->Insert(current->right, node, current);
            }

            return current;
}

bool Tree::Add(const int element) noexcept
{
    auto node = new Node(element);

    if (this->IsEmpty())
    {
        this->root = node;
    }
    else
    {
        this->root = this->Insert(this->root, node, this->root->parent);
    }
        this->count += 1; 
        return true;
}