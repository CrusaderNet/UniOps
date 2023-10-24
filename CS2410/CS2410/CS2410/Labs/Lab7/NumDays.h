//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <iostream>

using namespace std;

class NumDays;

ostream& operator<<(ostream& os, const NumDays& obj);

class NumDays
{
    private:
        //variables
        float hours;
        float days;

    public:
        //Constructor and destructor
        NumDays(float h);
        ~NumDays();

        //setters
        void setHours(float h);
        
        //getters
        float getHours() const;
        float getDays() const;

        //maniupulators
        float convertToDays(float h);

        //friend
        friend ostream& operator<<(ostream& os, const NumDays& obj);

        //operator overloads
        NumDays operator+(const NumDays &right);
        bool operator>(const NumDays &right);
        bool operator<(const NumDays &right);
        bool operator==(const NumDays &right);
};

#endif