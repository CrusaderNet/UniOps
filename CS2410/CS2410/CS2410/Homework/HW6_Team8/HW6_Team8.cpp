// Team 8 - (MIlly Flores 50% , Seth Tourish 50%)

//Driver Program

//Preprocessor Directives
#include <iostream>
#include <string>
#include "romanType.h"

//NameSpace Declarectives
using namespace std;

//Main Function
int main()
{
	//To hold string input
	  string Input;

	//Get the Roman Numbers from user
	cout << "Enter a Roman Numeral: ";
		cin >> Input;

		//Define a romanType object
		romanType RoNum(Input);

		//Print statement from romanType class
		RoNum.print();

		//Exit Program
		return 0;
}