#include <iostream>
#include <array>

using namespace std;

int main()
{
    const int SIZE = 7;
    long int empId[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    int hours[SIZE];
    double payRate[SIZE];
    double wages[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter the hours worked by employee " << empId[i] << ": ";
        cin >> hours[i];
        cout << "Enter the hourly pay rate for employee " << empId[i] << ": ";
        cin >> payRate[i];
        wages[i] = hours[i] * payRate[i];
    }

    cout << "Employee ID\t\tWages" << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << empId[i] << "\t\t\t" << wages[i] << endl;
    }

    return 0;

}