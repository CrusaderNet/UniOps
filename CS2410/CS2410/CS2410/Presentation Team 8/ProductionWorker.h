// Specification file for the ProductionWorker Class
#ifndef PRODUCTION_WORKER_H
#define PRODUCTION_WORKER_H
#include "Employee.h"
#include <string>
using namespace std;

// Exception classes
class InvalidShift {};
class InvalidPayRate { };

class ProductionWorker : public Employee
{
private:
	int shift;		// The worker's shift
	double payRate;	// The worker's hourly pay rate

public:
	// Default constructor
	ProductionWorker() : Employee()
		{ shift = 0; payRate = 0.0; }

	// Constructor
	ProductionWorker(string aName, string aNumber, string aDate,
		int aShift, double aPayRate) : Employee(aName, aNumber, aDate)
		{ if (testShift(aShift) && testPayRate(aPayRate))
		  {
			shift = aShift; payRate = aPayRate;
		  }
		}

	// Mutators
	void setShift(int s)
		{ if (testShift(s))
		     shift = s;
		}

	void setPayRate(double r)
		{ if (testPayRate(r))
			payRate = r;
		}

	// Accessors
	int getShiftNumber() const
		{ return shift; }

	string getShiftName() const
		{ if (shift == 1)
			 return "Day";
		  else
			 return "Night";
		}

	double getPayRate() const
		{ return payRate; }

	// testShift function
	bool testShift(int shift)
		{ if (shift < 1 || shift > 2)
			 throw InvalidShift();
		  return true;
		}

	bool testPayRate(double rate)
		{ if (rate < 0)
			 throw InvalidPayRate();
		  return true;
		}
};

#endif