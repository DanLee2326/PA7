#include "Data.hpp"

Data::Data(int newRecNum, int newIDNum, string newName, string newEmail, 
	string newUnits, string newProgram, string newLevel, int newAbsNum)
{
	this->recNum = newRecNum;
	this->idNum = newIDNum;
	this->name = newName;
	this->email = newEmail;
	this->units = newUnits;
	this->program = newProgram;
	this->level = newLevel;
	this->absNum = newAbsNum;
}
Data::Data(const Data& copyData)
{
	this->absStore = copyData.absStore;
	this->recNum = copyData.recNum;
	this->idNum = copyData.idNum;
	this->name = copyData.name;
	this->email = copyData.email;
	this->units = copyData.units;
	this->program = copyData.program;
	this->level = copyData.level;
	this->absNum = copyData.absNum;
}
Data::~Data()
{

}

void Data::setRecNum(int newRecNum)
{
	this->recNum = newRecNum;
}
void Data::setIDNum(int newIDNum)
{
	this->idNum = newIDNum;
}
void Data::setName(string newName)
{
	this->name = newName;
}
void Data::setEmail(string newEmail)
{
	this->email = newEmail;
}
void Data::setUnits(string newUnits)
{
	this->units = newUnits;
}
void Data::setProgram(string newProgram)
{
	this->program = newProgram;
}
void Data::setLevel(string newLevel)
{
	this->level = newLevel;
}

int Data::getRecNum() const
{
	return this->recNum;
}
int Data::getIDNum() const
{
	return this->idNum;
}
string Data::getName() const
{
	return this->name;
}
string Data::getEmail() const
{
	return this->email;
}
string Data::getUnits() const
{
	return this->units;
}
string Data::getProgram() const
{
	return this->program;
}
string Data::getLevel() const
{
	return this->level;
}
int Data::getAbsNum() const
{
	return this->absNum;
}
Stack* Data::getPAbsStore()
{
	return &this->absStore;
}

void Data::incrementAbsNum()
{
	this->absNum++;
}

ostream& operator<< (ostream& lhs, const Data& rhs)
{
	lhs << rhs.getRecNum() << "," << rhs.getIDNum() << ",\"" << rhs.getName() << "\"," << rhs.getEmail()
		<< "," << rhs.getUnits() << "," << rhs.getProgram() << "," << rhs.getLevel() << endl;
	return lhs;
}