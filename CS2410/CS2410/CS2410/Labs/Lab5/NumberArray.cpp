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