//Calculator to take input of cost and profit percentage and return total price

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double cost, profit, selling_price;

	cout << "Please enter cost of the Circuit Board: ";
	cin >> cost;

	cout << "\nPlease enter the profit percentage: ";
	cin >> profit;

	selling_price = cost + cost * (profit / 100);

	cout << fixed << showpoint << setprecision(2);
	cout << "\nSelling Price of the Circuit Board is: " << selling_price << "." << endl;

	return 0;

}