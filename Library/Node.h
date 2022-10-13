#pragma once
#include <iostream>

class Node;
/**
* \brief ����������� ����� �������������� � ������.
* \param node ���� ������.
* \return ������ � ���� ������.
*/
std::wstring ToString(const Node& node);

/**
* \brief ���� ������.
*/
class Node
{
private:
	/**
	* \brief ������.
	*/
	int data;
	/**
	* \brief ��������� �� ����� ����.
	*/
	Node* left;
	/**
	* \brief ��������� �� ������ ����.
	*/
	Node* right;
	/**
	* \brief ��������� �� ������������ ����.
	*/
	Node* parent;

public:
	/**
	* \brief ������������� ������ ���������� ������ ���� ������.
	* \brif ��������� ��� ������.
	*/
	Node();

	/**
	* \brief ������������� ������ ���������� ������ ���� ������.
	* \param data ������.
	*/
	Node(const int data);

	/**
	* \brief �������� ������ � ����������� ����� ������.
	* \param out ����������� ����� ������.
	* \param node ���� ������.
	*/
	friend std::ostream& operator<<(std::ostream& out, const Node& node);

	friend std::wostream& operator<<(std::wostream& out, const Node& node);
	/**
	* \brief �������� ����� �� ������������ ������ ������.
	* \param out ����������� ����� ������.
	* \param node ���� ������.
	*/
	friend std::istream& operator>>(std::istream& in, Node& node);

	/**
	* \brief �������� ��������� ���� �����.
	* \param lha ����� ����.
	* \parm rha ������ ����.
	* \return true, ���� �����.
	*/
	friend bool operator==(const Node& lha, const Node& rha);

	/**
	* \brief �������� ����������� ���� �����.
	* \param lha ����� ����.
	* \param rha ������ ����.
	* \return true, ���� �� �����.
	*/
	friend bool operator!=(const Node& lha, const Node& rha);

	/**
	* \brief �������� ������.
	* \param lha ����� ����.
	* \param rha ������ ����.
	* \return true, ���� ����� ���� ������.
	*/
	friend bool operator>(const Node& lha, const Node& rha);

	/**
	* \brief �������� ������ ��� �����.
	* \param lha ����� ����.
	* \param rha ������ ����.
	* \return true, ���� ����� ���� ������.
	*/
	friend bool operator>=(const Node& lha, const Node& rha);

	/**
	* \brief �������� ������.
	* \param lha ����� ����.
	* \param rha ������ ����.
	* \return true, ���� ����� ���� ������.
	*/
	friend bool operator<(const Node& lha, const Node& rha);

	/**
	* \brief �������� ������.
	* \param lha ����� ����.
	* \parm rha ������ ����.
	* \return true, ���� ����� ���� ������.
	*/
	friend bool operator<=(const Node& lha, const Node& rha);
};
