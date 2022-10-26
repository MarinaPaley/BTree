#pragma once
#include <iostream>
#include "Node.h"

class Tree;

/**
* \*brief Метод вывода на "печать" дерева.
* \*param tree Дерево.
*/
std::wstring ToString(const Tree& tree);

/**
* \brief Класс дерево.
*/
class Tree
{
private:
    /**
    * \*brief Корень.
    */
    Node* root;

    /**
    * \brief Количество элементов.
    */
    int count;

    /**
    * \brief Конструктор копирования. Удален.
    */
    Tree(const Tree& other) = delete;

    /**
    * \brief Конструктор перемещения. Удален.
    */
    Tree(Tree&& other) = delete;

    /**
    * \brief Оператор копирования. Удален.
    */
    Tree& operator=(const Tree& other) = delete;

    /**
    * \brief Оператор перемещающего копирования. Удален.
    */
    Tree& operator=(Tree&& other) = delete;

    /**
    * \brief Рекурсивный метод вставки узла.
    * \param current Текущий узел.
    * \param node Вставляемый узел.
    * \param parent. Родительский узел.
    */
    Node* Insert(Node* current, Node* node, Node* parent);

    void Delete(Node* deleted);

    void Transplant(Node* parent, Node* son);

    /**
    * \brief Находит элемент в дереве.
    * \param current Текущий узел.
    * \param target Искомый элемент.
    * \return Найденный узел.
    */
    Node* Find(Node* current, int target) const noexcept;

    void DestroyRecursive(Node* deleted);

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
    * \brief Поиск минимального узла.
    * \param node Начальный узел.
    * \return  Минимальный узел.
    */
    Node* TreeMinimum(Node* node);

    /**
    * \brief Поиск максимального  узла.
    * \param node Начальный узел.
    * \return  Максимльный узел.
    */
    Node* TreeMaximum(Node* node);
    friend std::ostream& operator<<(std::ostream& out, const Tree& tree);
    friend std::wostream& operator<<(std::wostream& out, const Tree& tree);
};
