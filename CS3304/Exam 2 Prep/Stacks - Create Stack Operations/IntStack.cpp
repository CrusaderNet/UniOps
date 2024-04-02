#include "IntStack.h"
#include <iostream>

using namespace std;

IntStack::IntStack(int size)
{
    stackArray = new int[size];
    stackSize = size;
    top = -1;
}

IntStack::IntStack(const IntStack &obj)
{
    if(obj.stackSize > 0)
        stackArray = new int[obj.stackSize];
    else
        stackArray = nullptr;

    stackSize = obj.stackSize;

    for(int count = 0; count < obj.stackSize; count++)
        stackArray[count] = obj.stackArray[count];

    top = obj.top;
}

IntStack::~IntStack()
{
    delete [] stackArray;
}

void IntStack::push(int num)
{
    if(isFull())
    {
        cout << "The Stack is Full" << endl;
    }else{
        cout << "Pushing " << num << endl;
        top++;
        stackArray[top] = num;
    }
}

void IntStack::pop(int &num)
{
    if(isEmpty())
    {
        cout << "The Stack is Empty" << endl;
    }else{
        num = stackArray[top];
        top--;
    }
}

void IntStack::add()
{
    int sum, num;
    if(isEmpty())
    {
        cout << "The Stack is Empty" << endl;
    }else{
        pop(sum);
        pop(num);
        sum += num;
        cout << "The Sum is " << sum << endl << endl;
    }
}

void IntStack::sub()
{
    int diff, sub;
    if(isEmpty())
    {
        cout << "The Stack is Empty" << endl;
    }else{
        pop(diff);
        pop(sub);
        diff -= sub;
        cout << "The Difference is " << diff << endl << endl;
    }
}

void IntStack::mult()
{
    int result, num;
    if(isEmpty())
    {
        cout << "The Stack is Empty" << endl;
    }else{
        pop(result);
        pop(num);
        result *= num;
        cout << "The Product is " << result << endl << endl;
    }
}

void IntStack::div()
{
    int num1, num2;
    if(isEmpty())
    {
        cout << "The Stack is Empty" << endl;
    }else{
        pop(num1);
        pop(num2);
        cout << "The Quotient is " << num1 / num2 << endl << endl;
    }
}

void IntStack::addAll()
{
    int sum;
    int num;

    if(isEmpty())
    {
        cout << "The Stack is Empty" << endl;
    }else{
        pop(sum);
        while(!isEmpty())
        {
            pop(num);
            sum += num;
        }
        cout << "The Sum of all values in the stack is " << sum << endl << endl;
    }
}

void IntStack::multAll()
{
    int product;
    int num;
    if(isEmpty())
    {
        cout << "The Stack is Empty" << endl;
    }else{
        pop(product);
        while(!isEmpty())
        {
            pop(num);
            product *= num;
        }
        cout << "The Product of all values in the stack is " << product << endl << endl;
    }
}

bool IntStack::isFull() const
{
    bool status;

    if(top == stackSize - 1)
        status = true;
    else
        status = false;

    return status;
}

bool IntStack::isEmpty() const
{
    bool status;
    if(top == -1)
        status = true;
    else
        status = false;

    return status;
}