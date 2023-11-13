//Team 8 - (Seth Tourish 50%, Milly Flores 50%)
//Preprocessor directives
#include "Odometer.h"
#include "FuelGauge.h"
#include <iostream>

//Namespace declaration
using namespace std;

//Main function
int main()
{
	//Create objects
	FuelGauge fuelgauge;
	Odometer odometer(&fuelgauge);

	//Display Starting values
	cout << "Mileage: " << odometer.getCurrentMil() << endl;
	cout << "Fuel level: " << fuelgauge.getCurFuel() << " gallons" << endl;
	cout << "--------------------------" << endl;

	//Loop to fuel the car
	while(fuelgauge.getCurFuel() < 15)
	{
		//Increase fuel
		fuelgauge.increaseFuel();
		//Display values
		cout << "Mileage: " << odometer.getCurrentMil() << endl;
		cout << "Fuel level: " << fuelgauge.getCurFuel() << " gallons" << endl;
		cout << "--------------------------" << endl;
	}

	//Loop to drive the car
	while(fuelgauge.getCurFuel() > 0)
	{
		//Drive the car
		odometer.Drive();
		//Display values
		cout << "Mileage: " << odometer.getCurrentMil() << endl;
		cout << "Fuel level: " << fuelgauge.getCurFuel() << " gallons" << endl;
		cout << "--------------------------" << endl;
	}

	//End program
	return 0;
}