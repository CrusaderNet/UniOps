//Group 7
//Seth Tourish, Diego Moya, Jonathan Lopez
//April 13, 2023
//Uses modular programming to take inputs and calculate the total paint costs, total labor charges, total labor hours, gallons of paint required, and total cost of a paint job.

//Preprocessor Directives
#include <iostream>
#include <iomanip>

using namespace std;

//Function Prototypes
int getNumberOfRooms();

double getPaintPrice(int);

int getWallSquareFootage(int);

int numberofGallonsOfPaint(int);

double laborHours(int);

void displayTotalCost(double, double);

//Main Function
int main() {

	//Call all functions for inputs and calculations except for final cost function
	int numOfRooms = getNumberOfRooms();
	int sqFootTotal = getWallSquareFootage(numOfRooms);
	int numberOfGallons = numberofGallonsOfPaint(sqFootTotal);
	double paintPrice = getPaintPrice(numberOfGallons);
	double laborTotal = laborHours(sqFootTotal);

	//Output Formatting
	cout << fixed << showpoint << setprecision(2);
	
	//Display the results of the calculations
	cout << "-------------------------------------" << endl;
	cout << "Gallons of Paint Required: " << numberOfGallons << " gallons" << endl;
	cout << "Labor Hours Required: " << laborTotal << " hours" << endl;
	cout << "Total Paint Cost: $" << paintPrice << endl;
	cout << "Total Labor Charge: $" << laborTotal * 25.00 << endl;

	//Calculate and display the total cost of the paint job
	displayTotalCost(laborTotal, paintPrice);
	cout << "-------------------------------------" << endl;

	return 0;

}

//Function that gets the number of rooms to be painted wit input validation of greater than 0
int getNumberOfRooms() {
	int numOfRooms;

	cout << "Please enter the number of rooms: ";
	cin >> numOfRooms;
	cout << endl;

	//input validation and on fail, reinput value and validate
	if (numOfRooms < 1) {
		while(numOfRooms < 1) {
			cout << "Invalid Number of Rooms entered. Please Enter a value of 1 or greater." << endl;
			cout << "Enter number of rooms: ";
			cin >> numOfRooms;
			cout << endl;
		}
	}

	return numOfRooms;
}

//Function that gets the price of the paint and calculates the total price of paint for the job, with input validation of greater than 10.00
double getPaintPrice(int gallons) {
	double price;
	double totalPrice;

	cout << "Please enter the price of the paint: ";
	cin >> price;
	cout << endl;

	//input validation and on fail, reinput value and validate
	if (price < 10.00) {
		while (price < 10.00) {
			cout << "Invalid price of paint entered. Please enter a value of 10.00 or greater." << endl;
			cout << "Enter number of rooms: ";
			cin >> price;
			cout << endl;
		}
	}

	totalPrice = price * gallons;

	return totalPrice;
}

//Function that gets the total square footage of the job, taking input of square footage of each room and calculates total sq feet. Input validation of above 0.
int getWallSquareFootage(int numOfRooms) {
	int sqFootRoom;
	int total = 0;

	//Loop for inputs of each room's square footage
	for (int i = 0; i < numOfRooms; i++) {
		cout << "Please enter square feet of wall space in room " << i + 1 << ": ";
		cin >> sqFootRoom;

		//Input validation, and on fail, retake inputs and validate
		while (sqFootRoom <= 0) {
			cout << endl;
			cout << "Invalid square footage entered. Please enter a value greater that 0." << endl;
			cout << "Enter the square feet of wall space in room " << i + 1 << ": ";
			cin >> sqFootRoom;
		}
		cout << endl;
		total += sqFootRoom;
	}

	return total;
}

//Function that calculates the total number of gallons of paint needed to complete the paint job
int numberofGallonsOfPaint(int sqFootTotal) {
	int gallons = 0;
	if (sqFootTotal % 110 == 0)
		gallons = sqFootTotal / 110;
	else
		gallons = (sqFootTotal / 110) + 1;

	return gallons;
}

//Function that takes the total square footage of the job and calculates the labor hours needed.
double laborHours(int sqFootTotal) {
	double hours = 0;

	hours = (sqFootTotal / 110.00) * 8.00;

	return hours;
}

//Function that calculates and displays the total cost of the paint job.
void displayTotalCost(double labor, double paintPrice) {
	
	double totalCost = (labor * 25.00) + (paintPrice);

	cout << fixed << showpoint << setprecision(2);
	cout << "Total Cost: $" << totalCost << endl;

}