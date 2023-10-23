//Team 8 - (Milly Flores 50%, Seth Tourish 50%)

//Preprocessor Directives
#include <iostream>
#include <cstdlib>
#include <string>
#include "romanType.h"

//Namespace Declaration
using namespace std;

//Default Constructor
romanType::romanType()
{
	RomNum = "";
	RomToNum = 0;
}

//Parameterized Constructor
 romanType::romanType(string r)
{
	 RomNum = r;
	 ToNum();
}

//Destructor
romanType::~romanType()
{
	
}
 
 //Function that sets the input value to variable
void romanType :: setRomNum(string r)
{
	RomNum = r;
	ToNum();
}

//Function that get the input
 string romanType::getRomanNum()const
{
	 return RomNum;
}

//Function that gets a Roman Numeral and converts it to Integer
int romanType::getRomToNum(char ch)
{
	if(ch == 'I')
		return 1;
	else if(ch == 'V')
		return 5;
	else if(ch == 'X')
		return 10;
	else if(ch == 'L')
		return 50;
	else if(ch == 'C')
		return 100;
	else if(ch == 'D')
		return 500;
	else if(ch == 'M')
		return 1000;
	else
		return -1;
}

 //Function that calculates the Roman Numerals to Integers
 void romanType::ToNum()
 {
	 //Loop to check the inputs length
	 for ( int i = 0; i < RomNum.length(); i++)
	 {
		 //If statement to check the inputs length
		 if (i < RomNum.length() - 1)
		 {
			 //If statement to check if the input is less than the next input
			 if (getRomToNum(RomNum[i]) >= getRomToNum(RomNum[i + 1]))
			 {
				 //Calculation of the Roman Numerals to Integers
				 RomToNum += getRomToNum(RomNum[i]);
			 }
			 //Else statement to add the following input to the current input
			 else
			 {
				 //Calculation of the Roman Numerals to Integers
				 RomToNum += (getRomToNum(RomNum[i + 1]) - getRomToNum(RomNum[i]));
				 i++;
			 }
		 }
		 else
		 {
			 //Calculation of the Roman Numerals to Integers
			 RomToNum = RomToNum + getRomToNum(RomNum[i]);
		 }
	 }
 }

 //Function that prints out the input and the calculation of the input
void romanType::print()const
{
	cout << "The Roman Number you inputed was: " << RomNum << endl;
	cout << "The Number Version of the Roman Number is: " << RomToNum << endl;
	
}