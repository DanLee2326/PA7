#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Stack.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ostream;
using std::istream;

class Data
{
public:
	Data(int newRecNum = 0, int newIDNum = 0, string newName = "", string newEmail = "",
		string newUnits = "", string newProgram = "", string newLevel = "", int newAbsNum = 0);
	Data(const Data& copyData);
	~Data();

	void setRecNum(int newRecNum);
	void setIDNum(int newIDNum);
	void setName(string newName);
	void setEmail(string newEmail);
	void setUnits(string newUnits);
	void setProgram(string newProgram);
	void setLevel(string newLevel);

	int getRecNum() const;
	int getIDNum() const;
	string getName() const;
	string getEmail() const;
	string getUnits() const;
	string getProgram() const;
	string getLevel() const;
	int getAbsNum() const;
	Stack* getPAbsStore();

	void incrementAbsNum();

private:
	int recNum;
	int idNum;
	string name;
	string email;
	string units;
	string program;
	string level;
	int absNum;
	Stack absStore;
};

ostream& operator<< (ostream& lhs, const Data& rhs);