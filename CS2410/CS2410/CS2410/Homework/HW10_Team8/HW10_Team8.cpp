//Team 8 - (Milly Flores 50%, Seth Tourish 50%)

//Preprocessor directives
#include <iostream>
#include "NumberList.h"

//Namespace declaration
using namespace std;

//Main function
int main()
{
	// Define a NumberList object
	NumberList list;
	double val;
	// Append some values to the list
	list.appendNode(2.5);
	list.appendNode(7.9);
	list.appendNode(12.6);
	// Display the list
	list.displayList();
	// Display the total of the values in the list
	cout << "The total of the values in the list is " << list.total() << endl << endl;

	//Search for a value, take in user input
	cout << "Enter a value to search for: ";
	cin >> val;
	cout << endl;

	//Call search function
	val = list.search(val);
	//Display results
	if (val != -1)
	{
		cout << "The value you are searching for is in position " << val << endl;
	}
	else
	{
		cout << "The value you are searching for is not in the list" << endl;
	}

	return 0;
}