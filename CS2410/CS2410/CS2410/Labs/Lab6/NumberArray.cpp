//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

#include <iostream>
#include "NumberArray.h"

using namespace std;

//Constructor
NumberArray::NumberArray(int size)
{
    arraySize = size;
    aPtr = new float[arraySize];
}

//Destructor
NumberArray::~NumberArray()
{
    if(aPtr != nullptr)
        delete [] aPtr;
}

//copy constructor
NumberArray::NumberArray(const NumberArray &obj)
{
    //copy array size
    arraySize = obj.arraySize;
    //declare new dynamic array
    aPtr = new float[arraySize];
    //Copy array to new array
    for(int i = 0; i < arraySize; i++)
    {
        aPtr[i] = obj.aPtr[i];
    }
}

//Mutator
void NumberArray::setElementValue(float value, int index)
{
    if(value >= 0 && index < arraySize)
    aPtr[index] = value;
}

//Accessors
float NumberArray::getElementValue(int index)
{
    if(index < 0 || index >= arraySize)
        exit(1);
    else
        return aPtr[index];
}

float NumberArray::getAverage()
{
    float sum = 0;
    for(int i = 0; i < arraySize; i++)
    {
        sum += aPtr[i];
    }
    return sum / arraySize;
}

//Print Function
void NumberArray::printNumberArray(NumberArray numbers, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << "\tNumber " << i + 1 << ":  " << numbers.getElementValue(i) << endl;
    }

}