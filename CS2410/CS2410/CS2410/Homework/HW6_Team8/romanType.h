//Team 8 - (Milly Flores 50%, Seth Tourish 50%)

//Header File
#ifndef _ROMANTYPE_H
#define _ROMANTYPE_H
#include <iostream>
#include <string>

//Namespace Declaration
using namespace std;

//romanType Class Declaration
class romanType
{
	//Private Variables
private:
	 string RomNum;
	int RomToNum = 0;
	//Public Variables
public:
	//Default Constructor
	romanType();
	//Parameterized Constructor
	romanType(string r);
	//Destructor
	~romanType();

	//Function that sets the input value to variable
	void setRomNum(string r);
	//Function that get the input
	string getRomanNum () const ;

	int getRomToNum(char ch);
	//Function that calculates the Roman Numerals to Integers
	void ToNum();
	//Function that prints out the input and the calculation of the input
	void print() const;

};
#endif