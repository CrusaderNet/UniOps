//Team 8 - (Seth Tourish 50%, Milly Flores 50%)
//Preprocessor directives
#include "Odometer.h"
#include "FuelGauge.h"
#include <iostream>

//Namespace declaration
using namespace std;

//Constructor
Odometer::Odometer(FuelGauge *f)
{
	fuel = f;
	currentMil = 0;
}
//Mutators and accessors
void Odometer::setCurrentMil(int c)
{
	c = currentMil;
}
int Odometer::getCurrentMil() const
{
	return currentMil;
}
void Odometer::increaseMil()
{
	if (currentMil < maxMil)
	{
		currentMil++;
	}
	else
		currentMil= 0;
}
//Drive function that increases the mileage and decreases the fuel
void Odometer::Drive()
{
	increaseMil();
	if (currentMil % 24 == 0)
	{
		fuel->decreaseFuel();
	}
}
