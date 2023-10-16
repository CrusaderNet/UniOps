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
    //Copy Constructor
    NumberArray(const NumberArray &obj);
    //Getters
    float getAverage();
    float getElementValue(int index) const;
    //Setter
    void setElementValue(float value, int index);
};

#endif