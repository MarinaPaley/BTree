#pragma once
#include <iostream>
#include "Node.h"

class Tree;

/**
* \*brief ����� ������ �� "������" ������.
* \*param tree ������.
*/
std::wstring ToString(const Tree& tree);

/**
* \brief ����� ������.
*/
class Tree
{
private:
    /**
    * \*brief ������.
    */
    Node* root;

    /**
    * \brief ���������� ���������.
    */
    int count;

    /**
    * \brief ����������� �����������. ������.
    */
    Tree(const Tree& other) = delete;

    /**
    * \brief ����������� �����������. ������.
    */
    Tree(Tree&& other) = delete;

    /**
    * \brief �������� �����������. ������.
    */
    Tree& operator=(const Tree& other) = delete;

    /**
    * \brief �������� ������������� �����������. ������.
    */
    Tree& operator=(Tree&& other) = delete;

    /**
    * \brief ����������� ����� ������� ����.
    * \param current ������� ����.
    * \param node ����������� ����.
    * \param parent. ������������ ����.
    */
    Node* Insert(Node* current, Node* node, Node* parent);

    void Delete(Node* deleted);

    void Transplant(Node* parent, Node* son);

    /**
    * \brief ������� ������� � ������.
    * \param current ������� ����.
    * \param target ������� �������.
    * \return ��������� ����.
    */
    Node* Find(Node* current, int target) const noexcept;

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
    /**
    * \brief ����� ������������ ����.
    * \param node ��������� ����.
    * \return  ����������� ����.
    */
    Node* TreeMinimum(Node* node);

    /**
    * \brief ����� �������������  ����.
    * \param node ��������� ����.
    * \return  ����������� ����.
    */
    Node* TreeMaximum(Node* node);
    friend std::ostream& operator<<(std::ostream& out, const Tree& tree);
    friend std::wostream& operator<<(std::wostream& out, const Tree& tree);
};