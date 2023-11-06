//Team 8 - (Seth Tourish 50%, Milly Flores 50%)
#include <iostream>
#include <iomanip>
#include "ProductionWorker.h"
using namespace std;

// Function prototype
void displayInfo(ProductionWorker);

int main()
{
	ProductionWorker pw_1("ABC XYZ", "123", "10/12/2010", 2, 18.00);
	ProductionWorker pw_2("DEF PQR", "124", "10/12/2011", 1, 15.00);
	displayInfo(pw_1);
	displayInfo(pw_2);
	return 0;
}

//******************************************************
// The displayInfo function displays a production      *
// worker's employment information.                    *
//******************************************************
void displayInfo(ProductionWorker e)
{
	cout << setprecision(2) << fixed << showpoint;
	cout << "Name: " 
		 << e.getName() << endl;
	cout << "Employee number: " 
		 << e.getNumber() << endl;
	cout << "Hire date: " 
		 << e.getHireDate() << endl;
	cout << "Shift: " 
		 << e.getShiftName() << endl;
	cout << "Shift number: " 
		 << e.getShiftNumber() << endl;
	cout << "Pay rate: " 
		 << e.getPayRate() << endl;
	cout << "----------------------" << endl;
}