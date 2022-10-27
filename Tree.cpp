#include "Tree.h"
#include <queue>
#include <sstream>

std::wstring ToString(const Tree& tree)
{
   return tree.ToString();
}

std::ostream& operator<<(std::ostream& out, const Tree& tree)
{
    if (tree.IsEmpty())
    {
        return out;
    }

    std::queue<Node*> queue;
    tree.InOrder(queue, tree.root);

    while (!queue.empty())
    {
        Node* node = queue.front();
        out << *node << " ";
        queue.pop();
    }

    return out;
}

std::wostream& operator<<(std::wostream& out, const Tree& tree)
{
    return out << tree.ToString();
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

std::wstring Tree::ToString() const noexcept
{
    std::wstringstream buffer;
    if (this->IsEmpty())
    {
        return buffer.str();
    }

    std::queue<Node*> queue;
    this->InOrder(queue, this->root);

    while (!queue.empty())
    {
        Node* node = queue.front();
        buffer << node->data << L" ";
        queue.pop();
    }
    return buffer.str();
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

void Tree::DestroyRecursive(Node* deleted)
{
    if (deleted == nullptr)
    {
        return;
    }

    this->DestroyRecursive(deleted->left);
    this->DestroyRecursive(deleted->right);
    delete deleted;
}

void Tree::InOrder(std::queue<Node*>& queue, Node* node) const
{
    if (node == nullptr)
    {
        return;
    }

    this->InOrder(queue, node->left);
    queue.push(node);
    this->InOrder(queue, node->right);
}

Tree::Tree()
    : root(nullptr), count(0)
{
}

Tree::~Tree()
{
    this->DestroyRecursive(this->root);
}

Tree::Tree(std::initializer_list<int> elements)
    : Tree()
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
