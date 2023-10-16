//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

//Preprocessor Directives
#include <iostream>
#include "NumberArray.h"

//Namespace Declaration
using namespace std;

//Function Prototypes
void printNumberArray(const NumberArray &numbers, int size);

//Driver Function
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
    NumberArray numbers2 = numbers;
    
    cout << "--------------------------------------------------------" << endl;

    //Retrieve a number from any element of the array
    cout << "The numbers you entered for the original Number Array are:" << endl;
    printNumberArray(numbers, size);

    cout << "--------------------------------------------------------" << endl;

    //Print Copied Array
    cout << "The numbers for the copied Number Array are:" << endl;
    printNumberArray(numbers2, size);

    cout << "--------------------------------------------------------" << endl;
    
    //Return the average of all the numbers in the array
    cout << "The average of those numbers is:  " << numbers.getAverage() << endl;


    return 0;
}

//Function that Prints the values of the NumberArray
void printNumberArray(const NumberArray &numbers, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << "\tNumber " << i + 1 << ":  " << numbers.getElementValue(i) << endl;
    }
}