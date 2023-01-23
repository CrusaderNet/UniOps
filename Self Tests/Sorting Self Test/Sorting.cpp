#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

//This program takes user inputs into a vector, and then provides options to Sort or Search the user defined vector.



//Uses Regular Expression search to check the user input string for anything other than integers. If the user input has only integers, returns true.
bool is_integer(const string& s) {

    return regex_match(s, regex("^[-+]?\[0-9]+$"));

}

//Input Validity checking function that calls the is_integer function. If the input is a integer, returns that input as a string.
string valid_input(int nmbr) {

    while (true) {

        string input;

        cout << "[" << nmbr << "] " << "Please enter value: ";
        cin >> input;

        if (is_integer(input)) {

            return (input);

        }
        else if (input == "Q") {

            return "Q";

        }
        else {

            cout << "Invalid input\n";

        }
        input = "";
    }

}

//Sort function that iterates through each index of the vector multiple times, sorting the vector from smallest to largest value. Does not modify the original vector.
vector<int> sort(vector<int> v) {

    int i = v.size();
    for (int j = 0; j < i; j++) {
        for (int k = 0; k < i; k++) {
            if (v[k] > v[j]) {
                int temp = v[j];
                v[j] = v[k];
                v[k] = temp;
            }
        }
    }
    return v;

}

//Search function that iterates through the user vector and returns if the integer is found in the vector, and the index it is found in.
int search(const vector<int>& v, const int i) {

    int index = -1;

    for (int j = 0; j < v.size(); j++) {
        if (v[j] == i) {
            index = j;
        }
    }

    if (index == -1) {
        cout << "The element " << i << " has not been found in the given vector.\n";
    }
    else {
        cout << "The element " << i << " is at index " << index << "\n";
    }

    return index;
}


int main() {

    vector<int> vec;
    int nmbr = 1;

    cout << "Enter in the numbers for your vector, and input Q to exit\n";
    cout << "---------------------------------------------------------\n";

    //Accepting inputs for user defined vector, with calling input failure checking function. 
    while (true) {

        string result = valid_input(nmbr);

        if(result == "Q") break;

        vec.push_back(stoi(result));

        nmbr++;
    }

    int option = 0;

    //Option Menu loop, taking option number inputs from user and calling functions based on user input.
    while (option != 3) {
        cout << "\nPlease enter an option for what you want to do with your vector: \n" << "1): Sort\n" << "2): Search\n" << "3). Exit\n" << "\n";
        cout << "Option: "; cin >> option; cout << "\n";
        switch (option) {
        case 1:
        {
            vector<int> vec1 = sort(vec);
            cout << "----------------------------------------------\n";
            cout << "Your sorted vector is: ";
            for (int i = 0; i < vec1.size() - 1; i++) {
                cout << vec1[i] << ", ";
            }
            cout << vec1[vec1.size() - 1];
            cout << "\n----------------------------------------------\n\n";
            break;
        }
        case 2:
        {
            int z;
            cout << "----------------------------------------------\n";
            cout << "Enter a number you want to search for: ";
            cin >> z;
            search(vec, z);
            cout << "----------------------------------------------\n\n";
            break;
        }
        case 3:
        {
            break;
        }

        }
    }

    return 0;

}