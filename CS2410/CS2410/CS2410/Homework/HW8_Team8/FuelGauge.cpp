//Team 8 - (Seth Tourish 50%, Milly Flores 50%)
//Preprocessor directives
#include "FuelGauge.h"
#include <iostream>

//Namespace declaration
using namespace std;

//Constructor
FuelGauge::FuelGauge()
{
	currentFuel = 0;
}

//Mutators and accessors
void FuelGauge::setCurFuel(double c)
{
	currentFuel = c;
}
double FuelGauge::getCurFuel() const
{
	return currentFuel;
}
void FuelGauge::increaseFuel()
{
	if (currentFuel < maxFuel)
	{
		currentFuel++;
	}
}
void FuelGauge::decreaseFuel()
{
	if (currentFuel > 0)
	{
		currentFuel--;
	}
}