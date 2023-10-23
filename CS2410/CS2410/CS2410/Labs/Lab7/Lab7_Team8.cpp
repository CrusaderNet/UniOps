//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

#include <iostream>
#include <iomanip>
#include "NumDays.h"

using namespace std;

int main()
{
    //Variables
    float hours_1 = 0;
    float hours_2 = 0;

    //Take inputs for hours
    cout << "Value1 (in hours): ";
    cin >> hours_1;

    cout << "Value2 (in hours): ";
    cin >> hours_2;

    cout << endl;
    
    //Create objects
    NumDays value1(hours_1);
    NumDays value2(hours_2);

    //Display values in days
    cout << "Value1 (in days): " << value1.getDays() << endl;
    cout << "Value2 (in days): " << value2.getDays() << endl;
    cout << endl;

    //Create object to hold sum of values 1 and 2
    NumDays value3 = value1 + value2;
    cout << "Value3 (in days): " << value3.getDays() << endl;
    cout << endl;

    //Compare values 1 and 2
    if(value1 > value2)
    {
        cout << "Value1 is greater than Value2" << endl;
    }
    else if(value1 < value2)
    {
        cout << "Value1 is less than Value2" << endl;
    }
    else if(value1 == value2)
    {
        cout << "Value1 is equal to Value2" << endl;
    }

    //End program
    return 0;
}