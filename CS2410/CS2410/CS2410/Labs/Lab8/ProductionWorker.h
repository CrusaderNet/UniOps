//Team 8 - (Seth Tourish 50%, Milly Flores 50%)
#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H
#include "Employee.h"
#include <string>

using namespace std;

class ProductionWorker : public Employee
{
private:
    int shiftNum;       //1 for day shift, 2 for night shift
    double payRate;     //Hourly pay rate
    string shiftName;   //Day or Night shift
public:

    //Default constructor
    ProductionWorker() : Employee()
    {
        shiftNum = 0;
        payRate = 0.0;
        shiftName = "";
    }

    //Constructor
    ProductionWorker(string n, string num, string date, int shift, double rate) : Employee(n, num, date)
    {
        shiftNum = shift;
        payRate = rate;
        if (shiftNum == 1)
            shiftName = "Day";
        else if (shiftNum == 2)
            shiftName = "Night";
        else
            shiftName = "Invalid Shift Assigned!";
    }

    //Destructor
    ~ProductionWorker()
    {}

    //Mutators
    void setshiftNum(int shift)
    {
        shiftNum = shift;
    }
    void setPayRate(double rate)
    {
        payRate = rate;
    }
    void setShiftName(string name)
    {
        shiftName = name;
    }

    //Accessors
    int getShiftNumber() const
    {
        return shiftNum;
    }
    double getPayRate() const
    {
        return payRate;
    }
    string getShiftName() const
    {
        return shiftName;
    }
};

#endif