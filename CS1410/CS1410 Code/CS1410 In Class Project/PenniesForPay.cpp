//Write a program that calculates how much a person would earn over a period of time if his or her salary is one penny the first day and two pennies the second day, and continues to double each day. The program should ask for a number of days. Display a table showing how much the salary was for each day, and then show the total pay at the end of the period. The output should be displayed in a dollar amount, not the number of pennies.
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int number_of_days;
	double pay, total_pay;

	pay = 0.01;
	total_pay = 0;

	cout << "Enter the number of days: ";
	cin >> number_of_days;

	while (number_of_days < 1) {
		cout << "Number of days worked must be at least one. Check and reenter";
		cin >> number_of_days;
	}

	cout << "Day\t\tTotal Pay\n";
	cout << "_______________________________\n";

	cout << fixed << showpoint << setprecision(2);

	for(int day = 1; day <= number_of_days; day++){
		cout << day << "\t\t$" << setw(8) << pay << endl;
		total_pay += pay;
		pay *= 2;
	}

	cout << "_______________________________\n";
	cout << "Total" << "\t\t$" << setw(8) << total_pay << endl;

	return 0;
}