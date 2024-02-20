//Exam 1 prep program to erase vector items of any type
//Instructions:
//Write a function called Erase_Vector_Items. This function will take as input, 2 parameters:
//1. A vector
//2. The item to erase from the vector (if it exists)
//The post-condition after this function is called is that no element within the vector will contain this item.
//Erase_Vector_Items needs to work with vectors of any data-type.
//Write a separate function that will output the contents of the vector (of any data-type).
//Demonstrate both functions working with 2 different data-types.

#include <iostream>
#include <vector>

using namespace std;

template <class anyType>
void Erase_Vector_Items(vector<anyType> &vec, anyType remove)
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
        cout << "ERROR: Entered value does not exist in vector.\n";

    else
        cout << "Value deleted from Vector.\n";

}

template <class anyType>
void Print_Vector_Items(vector<anyType> &vec)
{
    cout << "Current Vector: <";

    for(int i = 0; i < vec.size() - 1; i++)
    {
        cout << " " << vec[i] << ",";
    }

    cout << " " << vec[vec.size() - 1] << " >";
}

int main()
{
    vector<double> vec = {1.2, 3.5, 5.2, 9.3, 10.2, 3.5, 11.9};
    double removeValue;

    cout << "Please enter the value you wish to remove: ";
    cin >> removeValue;

    cout << endl;

    Erase_Vector_Items(vec, removeValue);

    Print_Vector_Items(vec);

}