#include "Tree.h"

std::wstring ToString(const Tree& tree)
{
    return std::wstring();
}

std::ostream& operator<<(std::ostream& out, const Tree& tree)
{
    // TODO: вставьте здесь оператор return
    return out;
}

std::wostream& operator<<(std::wostream& out, const Tree& tree)
{
    // TODO: вставьте здесь оператор return
    return out;
}

Node* Tree::Insert(Node* current, Node* node, Node* parent)
{
    if (current == nullptr)
    {
        current = node;
        current->parent = parent;
        return current;
    }

    if (*node < *current)
    {
        current->left = this->Insert(current->left, node, current);
    }
    else if (*node > *current)
    {
        current->right = this->Insert(current->right, node, current);
    }

    return current;
}

void Tree::Delete(Node* deleted)
{
    if (deleted->left != nullptr && deleted->right != nullptr)
    {
        auto successor = this->TreeMinimum(deleted->right);
        if (successor->parent != deleted)
        {
            this->Transplant(successor, successor->right);
            successor->right = deleted->right;
            successor->right->parent = successor;
        }

        this->Transplant(deleted, successor);
        successor->left = deleted->left;
        successor->left->parent = successor;
    }
    else if (deleted->left == nullptr)
    {
        this->Transplant(deleted, deleted->right);
    }
    else if (deleted->right == nullptr)
    {
        this->Transplant(deleted, deleted->left);
    }

    deleted->Invalidate();
    delete deleted;
}

void Tree::Transplant(Node* parent, Node* son)
{
    if (parent->parent == nullptr)
    {
        this->root = son;
    }
    else if (parent == parent->parent->left)
    {
        parent->parent->left = son;
    }
    else
    {
        parent->parent->right = son;
    }

    if (son != nullptr)
    {
        son->parent = parent->parent;
    }
}

Node* Tree::Find(Node* current, int target) const noexcept
{
    if (current == nullptr)
    {
        return nullptr;
    }

    if (target < current->data)
    {
        return this->Find(current->left, target);
    }

    if (target > current->data)
    {
        return this->Find(current->right, target);
    }

    if (target == current->data)
    {
        return current;
    }
    else
    {
        return nullptr;
    }

}

Tree::Tree() : root(nullptr), count(0)
{
}

Tree::~Tree()
{
}

Tree::Tree(std::initializer_list<int> elements): Tree()
{
    for (auto it = elements.begin(); it != elements.end(); it++)
    {
        this->Add(*it);
    }
}

int Tree::GetCount() const noexcept
{
    return this->count;
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

    this->count++;
    return true;
}

bool Tree::Delete(const int element) noexcept
{
    if (this->IsEmpty())
    {
        return false;
    }

    auto deleted = this->Find(this->root, element);
    if (deleted == nullptr)
    {
        return false;
    }

    this->Delete(deleted);

    this->count--;
    return true;
}

bool Tree::Contains(const int element) const noexcept
{
    if (this->IsEmpty())
    {
        return false;
    }

    return (this->Find(this->root, element) != nullptr);
}

bool Tree::IsEmpty() const noexcept
{
    return this->root == nullptr;
}

void Tree::Clear() noexcept
{
}

Node* Tree::TreeMinimum(Node* node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}

Node* Tree::TreeMaximum(Node* node)
{
    while (node->right != nullptr)
    {
        node = node->right;
    }

    return node;
}
