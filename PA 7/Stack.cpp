#include "Stack.hpp"

Stack::Stack()
{
	this->top = -1;
}
Stack::Stack(const Stack& copyStack)
{

}
Stack::~Stack()
{
	vec.clear();
}

void Stack::push(string n)
{
	this->vec.push_back(n);
	top++;
}
void Stack::pop()
{
	if (!isEmpty())
	{
		this->vec.pop_back();
		top--;
	}
	else
	{
		cout << "There is nothing to remove!" << endl;
	}
}
string Stack::peek()
{
	if (!isEmpty())
	{
		return vec[top];
	}
	else
	{
		return "";
	}
}
bool Stack::isEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}