//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

#ifndef _NUMBERARRAY_H
#define _NUMBERARRAY_H

class NumberArray
{
private:
    float *aPtr;
    int arraySize;
public:
    //Constructor
    NumberArray(int size);
    //Destructor
    ~NumberArray();
    //Getters
    float getAverage();
    float getElementValue(int index);
    //Setter
    void setElementValue(float value, int index);
    //Print Function
    void print();
};

#endif