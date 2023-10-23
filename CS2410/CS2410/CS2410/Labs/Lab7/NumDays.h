//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays
{
    private:
        //variables
        float hours;
        float days;

    public:
        //Constructor and destructor
        NumDays(float);
        ~NumDays();

        //setters
        void setHours(float);
        
        //getters
        float getHours() const;
        float getDays() const;

        //maniupulators
        float convertToDays(float);

        //operator overloads
        NumDays operator+(const NumDays&);
        bool operator>(const NumDays&);
        bool operator<(const NumDays&);
        bool operator==(const NumDays&);
};

#endif