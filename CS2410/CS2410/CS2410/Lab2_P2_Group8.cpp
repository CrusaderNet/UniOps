// Team-8 (Milly Flores 50%, Seth Tourish 50%)
#include <iostream>

using namespace std;

//Function prototype
void swap(float *, float *);

//Main function
int main()
{
   float first, second; //Declare two float variables

    cout << "Enter first number: ";
    cin >> first; //Take first number from user
    cout << "Enter second number: ";
    cin >> second; //Take second number from user

    //Call function to swap the numbers
    swap(&first, &second);

    //Output after swapping
    cout << "\nAfter swapping, The First Number is: " << first << endl;
    cout << "After swapping, The Second Number is: " << second << endl;

    return 0;
}

// function to swap the numbers
void swap(float *number1, float *number2)
{
    float temp; //Declare a temporary variable
    temp = *number1; //Put the value of number1 in temp
    *number1 = *number2; //Put the value of number2 in number1
    *number2 = temp; //Put the value of temp in number2
}