//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

#include <iostream>
#include "NumDays.h"

using namespace std;

const float HOURS_PER_DAY = 8.0;

//Constructor
NumDays::NumDays(float h)
{
    hours = h;
    days = convertToDays(h);
}

//Destructor
NumDays::~NumDays()
{
}

//Manipulator to convert hours to days
float NumDays::convertToDays(float h)
{
    return h / HOURS_PER_DAY;
}

//Setters
void NumDays::setHours(float h)
{
    hours = h;
}

//Getters
float NumDays::getHours() const
{
    return hours;
}

float NumDays::getDays() const
{
    return days;
}

//Operator overloads
NumDays NumDays::operator+(const NumDays& right)
{
    NumDays temp(0);
    temp.hours = hours + right.hours;
    temp.days = days + right.days;
    return temp;
}

bool NumDays::operator>(const NumDays& right)
{
    NumDays temp(0);
    if (hours > right.hours)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool NumDays::operator<(const NumDays& right)
{
    NumDays temp(0);
    if (hours < right.hours)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool NumDays::operator==(const NumDays& right)
{
    NumDays temp(0);
    if (hours == right.hours)
    {
        return true;
    }
    else
    {
        return false;
    }
}