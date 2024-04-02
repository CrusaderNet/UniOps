#include "IntStack.h"
#include <iostream>

using namespace std;

int main()
{
    IntStack stack(5);

    stack.push(3);
    stack.push(6);
    stack.add();

    stack.push(3);
    stack.push(6);
    stack.mult();

    stack.push(3);
    stack.push(6);
    stack.div();

    stack.push(7);
    stack.push(10);
    stack.sub();

    stack.push(2);
    stack.addAll();

    stack.push(3);
    stack.push(5);
    stack.push(10);
    stack.addAll();

    stack.push(1);
    stack.multAll();

    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.multAll();
}