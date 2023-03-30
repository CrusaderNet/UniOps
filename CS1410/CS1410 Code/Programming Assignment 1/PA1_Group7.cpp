//Group 7
//Seth Tourish, Diego Moya, Jonathan Lopez
//February 21st, 2023
//To create a compounding interest calculator for Annual payments followed by monthly interest gained.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	
	//Declaring Variables
	int startAge, midAge, endAge, yearsElapsed, paymentYears;
	double annualInterest, monthlyInterest, paymentAnnual, paymentInterestTotal, monthInterestTotal, futureValue, totalInterestEarned;

	//Take Age inputs
	cout << "Please enter the age payments started: ";
	cin >> startAge; cout << endl;

	cout << "Please enter the age payments ended: ";
	cin >> midAge; cout << endl;

	cout << "Please enter the final age to calculate interest: ";
	cin >> endAge; cout << endl;

	//calculate how many years monthly interest is being earned
	yearsElapsed = endAge - midAge;

	//Take Interest inputs
	cout << "Please enter the annual interest rate as a perentage: ";
	cin >> annualInterest; cout << endl;

	//convert percentages to decimals
	annualInterest = annualInterest * 0.01;

	cout << "Please enter the monthly interest rate as a perentage: ";
	cin >> monthlyInterest; cout << endl;

	//convert percentages to decimals
	monthlyInterest = monthlyInterest * 0.01;

	//Take yearly payment amount input
	cout << "Please enter annual deposit amount: ";
	cin >> paymentAnnual; cout << endl;

	//calculate how many years payments are made, including first year
	paymentYears = 1 * (midAge - startAge + 1);

	//calculate how much the IRA is worth after all the payments have been made
	futureValue = paymentAnnual * ((pow(1 + annualInterest, paymentYears) - 1) / annualInterest);

	//calculate how much interest has been made from start of payments to end of payments
	paymentInterestTotal = futureValue - paymentAnnual * paymentYears;

	//calculate how much interest is earned from monthly compounding interest after payments ended
	monthInterestTotal = futureValue * pow(1 + (monthlyInterest / 12), (yearsElapsed * 12));

	//calculate total overall interest earned
	totalInterestEarned = paymentInterestTotal + monthInterestTotal;

	//formatting output to 2 decimal places
	cout << fixed << showpoint << setprecision(2);

	//output interest totals
	cout << "Total Interest Earned from age " << startAge << " to " << midAge << " is $" << paymentInterestTotal << endl;
	cout << "Total Value at age " << midAge << " is $" << futureValue << endl;
	cout << "Total Interest Earned from age " << midAge << " to " << endAge << " is $" << monthInterestTotal << endl;
	cout << "Total Value at age " << endAge << " is $" << (futureValue + monthInterestTotal) << endl;
	cout << "Total Interest Earned is $" << totalInterestEarned << endl << endl;

	//end of program
	return 0;

}