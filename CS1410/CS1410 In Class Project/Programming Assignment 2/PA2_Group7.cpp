//Group 7
//Seth Tourish, Diego Moya, Jonathan Lopez
//February 21st, 2023
//This is a menu based program which calculates a customer's total bill after taking inputs of which plan they use and how many minutes they have used in their plan.

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	//Variable Declaration
	char menuInput;
	double totalBill, minutesUsed;

	//Start of menu, Menu formatting
	cout << "Welcome to Cell Incorporated's Bill Calculator. Here are a list of the different packages: " << endl
		 << "----------------------------------------------------------------------------------------------------";
	cout << "Package A: For $29.99 per month 250 minutes are provided. Additional minutes are $0.27 per minute." << endl
		<< "Package B: For $39.99 per month 500 minutes are provided. Additional minutes are $0.23 per minute." << endl
		<< "Package C: For $49.99 per month 750 minutes are provided. Additional minutes are $0.21 per minute." << endl
		<< "Package D: For $59.99 per month 1000 minutes are provided. Additional minutes are $0.19 per minute." << endl
		<< "Package E: For $69.99 per month unlimited minutes provided." << endl;
	cout << "----------------------------------------------------------------------------------------------------";

	//Menu User option input
	cout << "Please enter the letter of the package you have as a capital letter: ";
	cin >> menuInput;
	cout << endl << "Please enter the amount of minutes used: ";
	cin >> minutesUsed;
	cout << endl;
	//Input Validation
	if (menuInput == 'A' || menuInput == 'B' || menuInput == 'C' || menuInput == 'D' || menuInput == 'E') {

		if (minutesUsed >= 0) {
			//If both input validations are passed, begin switch statement
			switch (menuInput) {
				
				case 'A' : {
					//check for minutes over package limit and if greater
					if (minutesUsed > 250) {
						totalBill = 29.99 + (minutesUsed - 250) * 0.27;
						cout << fixed << showpoint << setprecision(2);
						cout << "Your Total Bill is $" << totalBill << endl;
					}
					//otherwise, print the static price
					else {
						cout << fixed << showpoint << setprecision(2);
						cout << "Your Total Bill is $29.99" << endl;
					}
					break;
				}

				case 'B': {
					//check for minutes over package limit and if greater
					if (minutesUsed > 500) {
						totalBill = 39.99 + (minutesUsed - 500) * 0.23;
						cout << fixed << showpoint << setprecision(2);
						cout << "Your Total Bill is $" << totalBill << endl;
					}
					//otherwise, print the static price
					else {
						cout << fixed << showpoint << setprecision(2);
						cout << "Your Total Bill is $39.99" << endl;
					}
					break;
				}

				case 'C': {
					//check for minutes over package limit and if greater
					if (minutesUsed > 750) {
						totalBill = 49.99 + (minutesUsed - 750) * 0.21;
						cout << fixed << showpoint << setprecision(2);
						cout << "Your Total Bill is $" << totalBill << endl;
					}
					//otherwise, print the static price
					else {
						cout << fixed << showpoint << setprecision(2);
						cout << "Your Total Bill is $49.99" << endl;
					}
					break;
				}

				case 'D': {
					//check for minutes over package limit and if greater
					if (minutesUsed > 1000) {
						totalBill = 59.99 + (minutesUsed - 1000) * 0.19;
						cout << fixed << showpoint << setprecision(2);
						cout << "Your Total Bill is $" << totalBill << endl;
					}
					//otherwise, print the static price
					else {
						cout << fixed << showpoint << setprecision(2);
						cout << "Your Total Bill is $59.99" << endl;
					}
					break;
				}

				case 'E': {
					//Package E has a static price with no limit of minutes, so print the price to the console
					cout << "Your Total Bill is $69.99";
					break;
				}

			}

		}
		//Minutes Input Validation failure statement
		else {
			cout << "You have entered an invalid number of minutes. Please enter a valid number of minutes." << endl;
		}

	}
	//Package Input Validation failure statement
	else {
		cout << "You have made an incorrect package selection. Please select a package from the list." << endl;
	}


	//End of program
	return 0;
}