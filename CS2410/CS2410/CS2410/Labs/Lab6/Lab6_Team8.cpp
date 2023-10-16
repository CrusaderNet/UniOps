//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

#include <iostream>
#include "NumberArray.h"

using namespace std;

int main()
{
    int size;

    cout << "How many numbers would you like to store:  ";
    cin >> size;
    cout << endl;

    //Create an array of size "size", Dynamically allocate float array
    NumberArray numbers(size);

    //Store a number for any element of the array
    cout << "Enter the " << size << " numbers:" << endl;
    for(int i = 0; i < size; i++)
    {
        float value;
        cout << "\tNumber " << i + 1 << ":  ";
        cin >> value;
        numbers.setElementValue(value, i);
    }

    //Copy first object to new second object
    NumberArray numbers2(numbers);

    cout << "--------------------------------------------------------" << endl;

    //Retrieve a number from any element of the array
    cout << "The numbers you entered are:" << endl;
    numbers.printNumberArray(numbers, size);

    cout << "--------------------------------------------------------" << endl;
    
    //Return the average of all the numbers in the array
    cout << "The average of those numbers is:  " << numbers.getAverage() << endl;


    return 0;
}