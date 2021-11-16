#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ostream;
using std::istream;

class Stack
{
public:
	Stack();
	Stack(const Stack& copyStack);
	~Stack();

	void push(string n);
	void pop();
	string peek();
	bool isEmpty();

private:
	vector<string> vec;
	int top;
};