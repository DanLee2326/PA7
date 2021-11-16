#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Data.hpp"
#include "List.hpp"


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ostream;
using std::istream;

class ATApp
{
public:
	void runApp(void);
	void displayMenu();
	void fileToMaster(fstream& file);
	void markAbsences();

private:
	List<Data> master;
	int selectMenuOption() const;
};