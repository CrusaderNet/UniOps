#ifndef INTSTACK_H
#define INTSTACK_H

class IntStack
{
private:
   int *stackArray;  // Pointer to the stack array
   int stackSize;    // The stack size
   int top;          // Indicates the top of the stack

public:
IntStack(int);
IntStack(const IntStack &);
~IntStack();

void push(int);
void pop(int &);

void add();
void sub();
void mult();
void div();
void addAll();
void multAll();

bool isFull() const;
bool isEmpty() const;
};

#endif