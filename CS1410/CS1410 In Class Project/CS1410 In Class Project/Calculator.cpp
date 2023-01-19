//T. Seth
//January 19, 2023
//To compute the gross pay of employee based upon the number of hours worked and an hourly pay rate

#include <iostream>
using namespace std;

int main() {

	//Declare variables
	double hoursWorked, hourlyPayRate, grossPay;

	//Get the number of hours worked
	cout << "Enter the number of hours worked: ";
	cin >> hoursWorked;

	//Get the hourly pay rate
	cout << "Enter the hourly pay rate: ";
	cin >> hourlyPayRate;

	//Calculate the gross pay
	grossPay = hoursWorked * hourlyPayRate;

	//Display the gross pay
	cout << "The gross pay is $" << grossPay << endl;

	return 0;
	
}