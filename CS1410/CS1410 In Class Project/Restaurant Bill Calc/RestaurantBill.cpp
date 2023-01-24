//Seth T.
// January 24, 2023
//In Class Activity, Restaurant Bill Calculator

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	
	const double TAX_RATE = 0.0675;
	const double TIP_RATE = 0.020;

	double subtotal, tax, tip, total;

	cout << "Enter the Meal Cost: ";
	cin >> subtotal;

	tax = subtotal * TAX_RATE;
	tip = (subtotal + tax) * TIP_RATE;

	total = subtotal + tax + tip;

	cout << fixed << showpoint << setprecision(2);
	cout << "\n-------- BILL --------\n" << "    Meal Cost: $" << subtotal << endl << "    Tax Amount: $" << tax << endl << "    Tip Amount: $" << tip << endl << "    Total Bill: $" << total << endl;

	return 0;

}