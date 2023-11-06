#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee
{
protected:
    string name;		// Employee name
    string number;		// Employee number
    string hireDate;	// Employee hire date

public:
    // Default constructor
    Employee()
    {
        name = "";
        number = "";
        hireDate = "";
    }

    // Constructor
    Employee(string n, string num, string date)
    {
        name = n;
        number = num;
        hireDate = date;
    }

    // Destructor
    ~Employee()
    {}

    // Mutators
    void setName(string n)
    {
        name = n;
    }
    void setNumber(string num)
    {
        number = num;
    }
    void setHireDate(string date)
    {
        hireDate = date;
    }

    // Accessors
    string getName() const
    {
        return name;
    }
    string getNumber() const
    {
        return number;
    }
    string getHireDate() const
    {
        return hireDate;
    }
};

#endif