//Team 8 - (Seth Tourish 50%, Milly Flores 50%)
//Preprocessor directives
#ifndef _ODOMETER_
#define _ODOMETER_
#include "FuelGauge.h"

//Namespace declaration
using namespace std;

//Odometer class
class Odometer
{
private:
	int currentMil;
	static const int maxMil = 999999;

	//FuelGauge pointer to relate it to created FuelGauge object
	FuelGauge *fuel;
public: 
	//Constructor
	Odometer(FuelGauge *f);
	//Mutators and accessors
	void setCurrentMil(int c);
	int getCurrentMil()const;
	void  increaseMil();
	void Drive();
};

#endif
