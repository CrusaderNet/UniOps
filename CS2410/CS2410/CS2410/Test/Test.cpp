#include <iostream>

using namespace std;

class NumberArray
{
private:
    int arraySize;
public:
    //Constructor
    NumberArray() {arraySize = 0;}
    //Destructor
    ~NumberArray() {}
    //Getters
    float getAverage() {return 15;}
    //Print Function
    virtual void print() {cout << arraySize;}
};

class Test : public NumberArray
{
    private:
    int x;
    public:
    Test() {x = 0;}
    void print() {cout << this->getAverage() << endl;}
};

int main()
{
    Test test;
    test.print();

    return 0;
}

