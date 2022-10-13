#pragma once
#include <iostream>

class Node;
/**
* \brief Статический метод преобразования в строку.
* \param node Узел дерева.
* \return Данные в виде строки.
*/
std::wstring ToString(const Node& node);

/**
* \brief Узел дерева.
*/
class Node
{
private:
	/**
	* \brief Данные.
	*/
	int data;
	/**
	* \brief Указатель на левый узел.
	*/
	Node* left;
	/**
	* \brief Указатель на правый узел.
	*/
	Node* right;
	/**
	* \brief Указатель на родительский узел.
	*/
	Node* parent;

public:
	/**
	* \brief Инициализация нового экземпляра класса Узел дерева.
	* \brif Необходим для тестов.
	*/
	Node();

	/**
	* \brief Инициализация нового экземпляра класса Узел дерева.
	* \param data Данные.
	*/
	Node(const int data);

	/**
	* \brief Оператор вывода в стандартный поток данных.
	* \param out Стандартный поток данных.
	* \param node Узел дерева.
	*/
	friend std::ostream& operator<<(std::ostream& out, const Node& node);

	friend std::wostream& operator<<(std::wostream& out, const Node& node);
	/**
	* \brief Оператор ввода из стандартного потока данных.
	* \param out Стандартный поток данных.
	* \param node Узел дерева.
	*/
	friend std::istream& operator>>(std::istream& in, Node& node);

	/**
	* \brief Оператор равенства двух узлов.
	* \param lha Левый узел.
	* \parm rha Правый узел.
	* \return true, если равны.
	*/
	friend bool operator==(const Node& lha, const Node& rha);

	/**
	* \brief Оператор неравенства двух узлов.
	* \param lha Левый узел.
	* \param rha Правый узел.
	* \return true, если не равны.
	*/
	friend bool operator!=(const Node& lha, const Node& rha);

	/**
	* \brief Оператор больше.
	* \param lha Левый узел.
	* \param rha Правый узел.
	* \return true, если левый узел больше.
	*/
	friend bool operator>(const Node& lha, const Node& rha);

	/**
	* \brief Оператор больше или равно.
	* \param lha Левый узел.
	* \param rha Правый узел.
	* \return true, если левый узел больше.
	*/
	friend bool operator>=(const Node& lha, const Node& rha);

	/**
	* \brief Оператор меньше.
	* \param lha Левый узел.
	* \param rha Правый узел.
	* \return true, если левый узел меньше.
	*/
	friend bool operator<(const Node& lha, const Node& rha);

	/**
	* \brief Оператор меньше.
	* \param lha Левый узел.
	* \parm rha Правый узел.
	* \return true, если левый узел меньше.
	*/
	friend bool operator<=(const Node& lha, const Node& rha);
};
