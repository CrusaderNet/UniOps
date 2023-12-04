//Team 8 - (Milly Flores 50%,Seth Tourish 50%)
// This program demonstrates a simple append
// operation on a linked list.
#include <iostream>
#include "NumberList.h"
using namespace std;
int main()
{
	// Define a NumberList object.
	NumberList list;
	double val;
	// Append some values to the list.
	list.appendNode(2.5);
	list.appendNode(7.9);
	list.appendNode(12.6);
	list.displayList();
	cout << "The total of the values in the list is " << list.total() << endl << endl;

	cout << "Enter a value to search for: ";
	cin >> val;
	cout << endl;

	 val = list.search(val);
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