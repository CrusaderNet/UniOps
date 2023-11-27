//Team 8 - (Seth Tourish 50%, Milly Flores 50%)
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class NegativeException {};

template <class T>
T minimum(T a, T b)
{
    return (a < b) ? a : b;
}

int main()
{
    string a, b;
    try
    {
        cout << "Enter the first number: ";
        cin >> a;

        if(stoi(a.data()) < 0 || stof(a.data()) < 0)
            throw NegativeException();
    }
    catch(NegativeException)
    {
        while (stoi(a.data()) < 0 || stof(a.data()) < 0)
        {
            cout << "ERROR: Please enter a positive number for the first number: ";
            cin >> a;
        }
    }

    cout << "Enter the second number: ";

    try
    {
        cout << "Enter the second number: ";
        cin >> b;
        if(stoi(b.data()) < 0 || stof(b.data()) < 0)
            throw NegativeException();
    }
    catch(NegativeException)
    {
        while (stoi(b.data()) < 0 || stof(b.data()) < 0)
        {
            cout << "ERROR: Please enter a positive number for the second number: ";
            cin >> b;
        }
    }

    cout << "The minimum of " << a << " and " << b << " is " << minimum(a, b) << endl;

    return 0;
}