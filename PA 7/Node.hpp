#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Data.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ostream;
using std::istream;

template <class T>
class Node
{
public:
	Node(T& newData);
	Node(const Node<T>& copyNode);
	~Node();

	void setData(T newData);
	void setPNext(Node<T>* newPNext);

	T* getPData();
	Node<T>* getPNext() const;


private:
	T data;
	Node<T>* pNext;
};

template <class T>
Node<T>::Node(T& newData)
{
	this->data = newData;
	this->pNext = nullptr;
}
template <class T>
Node<T>::Node(const Node<T>& copyNode)
{
	this->data = copyNode.data;
	this->pNext = copyNode.pNext;
}
template <class T>
Node<T>::~Node()
{

}

template <class T>
void Node<T>::setData(T newData)
{
	this->data = newData;
}
template <class T>
void Node<T>::setPNext(Node<T>* newPNext)
{
	this->pNext = newPNext;
}

template <class T>
T* Node<T>::getPData()
{
	return &this->data;
}
template <class T>
Node<T>* Node<T>::getPNext() const
{
	return this->pNext;
}