#pragma once
#include <iostream>
#include <queue>
#include "Node.h"
#include "Iterator.h"

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

    /**
    * \brief Рекурсивный метод удаления узла.
    * \param deleted Удаляемый узел.
    */
    void Delete(Node* deleted);

    /**
    * \brief Метод "пересадки" узлов.
    * \param parent Родительский узел.
    * \param son Дочерний узел.
    */
    void Transplant(Node* parent, Node* son);

    /**
    * \brief Находит элемент в дереве.
    * \param current Текущий узел.
    * \param target Искомый элемент.
    * \return Найденный узел.
    */
    Node* Find(Node* current, int target) const noexcept;

    /**
    * \brief Рекурсивное удаление всех узлов из дерева.
    * \param deleted Текуший удаляемый узел.
    */
    void DestroyRecursive(Node* deleted);


    /**
    * \brief Рекурсивный обход дерева по порядку.
    * \param queue Очередь, в которую вставлям последовательно элементы обхода.
    * \param node Текущий узел.
    */
    void InOrder(std::queue<Node*>& q, Node* node);

    std::queue<Node*> queue;

    void InOrder();

    void QueueClear();

public:
    /**
    * \brief Конструктор по умолчанию.
    */
    Tree();

    /**
    * \brief Конструктор с параметром коллекции целых чисел.
    * \param elements Коллекция целых чисел.
    */
    Tree(std::initializer_list<int> elements);
    /**
    * \brief Деструктор.
    */
    ~Tree();

    /**
    * \brief Количество элементов в дереве.
    */
    int GetCount() const noexcept;

    /**
    * \brief Метод добавления в дерево.
    * \param element Добавляемый элемент.
    * \return true, если элемент был добавлен
    */
    bool Add(const int element) noexcept;

    /**
    * \brief Метод удаления из дерева.
    * \param element Удаляемый элемент.
    * \return true, если элемент был удален.
    */
    bool Delete(const int element) noexcept;

    /**
    * \brief Содержится элемент в дереве.
    * \param Искомый элемент.
    * \return true, если элемент найден.
    */
    bool Contains(const int element) const noexcept;

    /**
    * \brief Пустая ли коллекция (дерево)?
    * \return true, если пустая коллекция (дерево).
    */
    bool IsEmpty() const noexcept;

    /**
    * \brief Метод удаления элементов из дерева.
    */
    void Clear() noexcept;

    /**
    * \brief Метод перевода элементов дерева в строку.
    * \return Строковое представление дерева.
    */
    std::wstring ToString() const noexcept;

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

    /**
    * \brief Оператор сдвига дерева в стандартный поток ввода-вывода.
    * \param out Cтандартный поток ввода-вывода.
    * \param tree Дерево.
    */
    friend std::ostream& operator<<(std::ostream& out, const Tree& tree);

    /**
    * \brief Оператор сдвига дерева в стандартный поток ввода-вывода.
    * \param out Cтандартный поток ввода-вывода.
    * \param tree Дерево.
    */
    friend std::wostream& operator<<(std::wostream& out, const Tree& tree);

    friend class Iterator;
    Iterator begin();
    Iterator end();
    const Iterator cbegin();
    const Iterator cend();
    Iterator operator++();
};