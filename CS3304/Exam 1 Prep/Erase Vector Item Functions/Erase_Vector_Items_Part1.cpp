//Exam 1 prep program to erase vector items
//Instructions:
//Write a function called Erase_Vector_Items. This function will take as input, 2 parameters:
//1. A vector of integers
//2. The integer to erase from the vector (if it exists)
//The post-condition after this function is called is that no element within the vector will contain this item.
//Write a separate function that will output the contents of the vector.
//Demonstrate both functions working.

#include <iostream>
#include <vector>

using namespace std;

void Erase_Vector_Items(vector<int> &, int);

void Print_Vector_Items(vector<int> &);

int main()
{
    vector<int> vec = {1, 3, 5, 9, 10, 3, 11};
    int removeValue;

    cout << "Please enter the value you wish to remove: ";
    cin >> removeValue;

    cout << endl;

    Erase_Vector_Items(vec, removeValue);

    Print_Vector_Items(vec);

}

void Erase_Vector_Items(vector<int> &vec, int remove)
{
    int valuePresent = 1;
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] == remove)
        {
            vec.erase(vec.begin()+i);
            valuePresent = 0;
            --i;
        }
    }

    if(valuePresent == 1)
        cout << ("Value does not exist in vector.\n");

}

void Print_Vector_Items(vector<int> &vec)
{
    cout << "Current Vector: <";

    for(int i = 0; i < vec.size(); i++)
    {
        cout << " " << vec[i];
    }

    cout << " >";
}