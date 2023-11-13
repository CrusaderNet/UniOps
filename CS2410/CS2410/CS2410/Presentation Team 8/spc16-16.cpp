#include <iostream>
#include <iomanip>
#include "ProductionWorker.h"
using namespace std;

// Function prototypes
ProductionWorker *createProductionWorker(string, string, string, int, double);
void displayInfo(ProductionWorker);

int main()
{
	ProductionWorker *pwPtr = nullptr;

	// Test a valid ProductionWorker
	pwPtr = createProductionWorker("John Jones", "123", "1/1/2006", 2, 18.00);
	if (pwPtr != nullptr)
		displayInfo(*pwPtr);

	// Test a ProductionWorker with an invalid
	// employee number.
	pwPtr = createProductionWorker("John Jones", "99999", "1/1/2006", 2, 18.00);
	if (pwPtr != nullptr)
		displayInfo(*pwPtr);

	// Test a ProductionWorker with an invalid
	// shift number.
	pwPtr = createProductionWorker("John Jones", "AAA", "1/1/2006", 1, 18.00);
	if (pwPtr != nullptr)
		displayInfo(*pwPtr);

	// Test a ProductionWorker with an invalid
	// hourly pay rate.
	pwPtr = createProductionWorker("John Jones", "123", "1/1/2006", 2, -99);
	if (pwPtr != nullptr)
		displayInfo(*pwPtr);

	return 0;
}

//****************************************************
// The createProductionWorker function creates       *
// a ProductionWorker object and returns a pointer   *
// to it. If any of the values passed as arguments   *
// are invalid, a null pointer is returned.          *
//****************************************************

ProductionWorker *createProductionWorker(string name, string number, 
                                         string hireDate, int shift, 
                                         double payRate)
{
	ProductionWorker *pwPtr = nullptr;

	try
	{
		// Create a ProductionWorker object.
		pwPtr = new ProductionWorker(name, number, hireDate,shift, payRate);
	}
	catch (InvalidEmployeeNumber)
	{
		cout << "Error: Invalid employee number.\n";
	}
	catch (InvalidShift)
	{
		cout << "Error: Invalid shift number.\n";
	}
	catch (InvalidPayRate)
	{
		cout << "Error: Invalid pay rate.\n";
	}

	return pwPtr;
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
}