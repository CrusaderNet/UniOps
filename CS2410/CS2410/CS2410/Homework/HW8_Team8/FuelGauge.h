//Team 8 - (Seth Tourish 50%, Milly Flores 50%)
//Preprocessor directives
#ifndef _FUELGAUGE_
#define _FUELGAUGE_
#include <iostream>

//Namespace declaration
using namespace std;

//FuelGauge class
class FuelGauge
{
private:
	double currentFuel;
	static const int maxFuel = 15;
public:
	//Constructor
	FuelGauge();
	//Mutators and accessors
	void setCurFuel(double c);
	double getCurFuel() const;
	void increaseFuel();
	void decreaseFuel ();
};
#endif
