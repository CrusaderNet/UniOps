#include <iostream>
#include <math.h>
#include <vector>
#include <cmath>

using namespace std;

vector<char> Float_To_Hex(float);

void Display_1D_Vector(vector<char>);

int main()
{

	float inputFloat;
	char contFlag = 'Y';
	vector<char> hexValue;

	do 
	{
		cout << "***********************************" << endl << "Input a floating point number: ";
		cin >> inputFloat;
		cout << endl;

		hexValue = Float_To_Hex(inputFloat);

		cout << "Hexadecimal Equivalent: ";
		Display_1D_Vector(hexValue);

		cout << endl << "Do you want to continue (Y/y)? ";
		cin >> contFlag;
		cout << endl << "***********************************" << endl << endl;
	} while (contFlag == 'Y' || contFlag ==  'y');

	return 0;
}

vector<char> Float_To_Hex(float num)
{
	vector<char> hexVal;

	float fracPart, tempIntPart;
	float tempCalc;
	float newVal;

	fracPart = modf(num, &tempIntPart);
	int intPart = (int)tempIntPart;

	while (intPart != 0)
	{
		tempCalc = intPart % 16;

		if (tempCalc == 0)
			hexVal.insert(hexVal.begin(), '0');
		else if (tempCalc == 1)
			hexVal.insert(hexVal.begin(), '1');
		else if (tempCalc == 2)
			hexVal.insert(hexVal.begin(), '2');
		else if (tempCalc == 3)
			hexVal.insert(hexVal.begin(), '3');
		else if (tempCalc == 4)
			hexVal.insert(hexVal.begin(), '4');
		else if (tempCalc == 5)
			hexVal.insert(hexVal.begin(), '5');
		else if (tempCalc == 6)
			hexVal.insert(hexVal.begin(), '6');
		else if (tempCalc == 7)
			hexVal.insert(hexVal.begin(), '7');
		else if (tempCalc == 8)
			hexVal.insert(hexVal.begin(), '8');
		else if (tempCalc == 9)
			hexVal.insert(hexVal.begin(), '9');
		else if(tempCalc == 10)
			hexVal.insert(hexVal.begin(), 'A');
		else if (tempCalc == 11)
			hexVal.insert(hexVal.begin(), 'B');
		else if (tempCalc == 12)
			hexVal.insert(hexVal.begin(), 'C');
		else if (tempCalc == 13)
			hexVal.insert(hexVal.begin(), 'D');
		else if (tempCalc == 14)
			hexVal.insert(hexVal.begin(), 'E');
		else if (tempCalc == 15)
			hexVal.insert(hexVal.begin(), 'F');

		intPart /= 16;
	}

	hexVal.push_back('.');

	if (fracPart == 0.0)
	{
		hexVal.push_back('0');
	}
	else
	{
		while (fracPart != 0.0)
		{
			newVal = fracPart * 16;
			fracPart = modf(newVal, &tempIntPart);

			int twoIntPart = (int)tempIntPart;

			if (twoIntPart == 0)
				hexVal.push_back('0');
			else if (twoIntPart == 1)
				hexVal.push_back('1');
			else if (twoIntPart == 2)
				hexVal.push_back('2');
			else if (twoIntPart == 3)
				hexVal.push_back('3');
			else if (twoIntPart == 4)
				hexVal.push_back('4');
			else if (twoIntPart == 5)
				hexVal.push_back('5');
			else if (twoIntPart == 6)
				hexVal.push_back('6');
			else if (twoIntPart == 7)
				hexVal.push_back('7');
			else if (twoIntPart == 8)
				hexVal.push_back('8');
			else if (twoIntPart == 9)
				hexVal.push_back('9');
			else if (twoIntPart == 10)
				hexVal.push_back('A');
			else if (twoIntPart == 11)
				hexVal.push_back('B');
			else if (twoIntPart == 12)
				hexVal.push_back('C');
			else if (twoIntPart == 13)
				hexVal.push_back('D');
			else if (twoIntPart == 14)
				hexVal.push_back('E');
			else if (twoIntPart == 15)
				hexVal.push_back('F');

		}
	}

	return(hexVal);

}

void Display_1D_Vector(vector<char> hexVals)
{

	for (int i = 0; i < hexVals.size(); i++)
	{
		cout << hexVals[i];
	}

}