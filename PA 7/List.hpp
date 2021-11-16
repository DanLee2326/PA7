#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Node.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ostream;
using std::istream;

template <class T>
class List // master list
{
public:
	List();
	List(const List<T>& copyList);
	~List();

	void setPHead(Node<T>* newPHead);
	Node<T>* getPHead() const;

	bool isEmpty();
	void insertAtFront(T newData);
	void deleteAtFront();
	void printList();
	void destroyList();

private:
	Node<T>* pHead;
};

template <class T>
List<T>::List()
{
	pHead = nullptr;
}
template <class T>
List<T>::List(const List<T>& copyList)
{

}
template <class T>
List<T>::~List()
{
	destroyList();
}

template <class T>
void List<T>::setPHead(Node<T>* newPHead)
{
	this->pHead = newPHead;
}
template <class T>
Node<T>* List<T>::getPHead() const
{
	return this->pHead;
}
template <class T>
bool List<T>::isEmpty()
{
	if (pHead == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <class T>
void List<T>::insertAtFront(T newData)
{
	Node<T>* temp = new Node<T>(newData);

	if (temp != nullptr)
	{
		temp->setPNext(pHead);
		pHead = temp;
	}
}
template <class T>
void List<T>::deleteAtFront()
{
	Node<T>* front = pHead;
	if (!isEmpty())
	{
		pHead = front->getPNext();
		delete front;
	}
}
template <class T>
void List<T>::printList()
{
	if (!pHead)
	{
		cout << "The list is empty!" << endl;
	}
	else
	{
		Node<T>* print = pHead;
		while (print != nullptr)
		{
			cout << *(print->getPData());
			print = print->getPNext();
		}
	}
}
template <class T>
void List<T>::destroyList()
{
	while (!isEmpty())
	{
		deleteAtFront();
	}
}

template <class T>
fstream& operator<< (fstream& store, const List<T>& node)
{
	Node<T>* printToFile = node.getPHead();

	while (printToFile != nullptr)
	{
		Data d = *(printToFile->getPData());
		store << d.getRecNum() << "," << d.getIDNum() << ",\"" << d.getName() << "\"," << d.getEmail() 
			<< "," << d.getUnits() << "," << d.getProgram() << "," << d.getLevel() << endl;
		printToFile = printToFile->getPNext();
	}

	return store;
}