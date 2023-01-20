#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

bool is_integer(const string& s) {

    return regex_match(s, regex("^[-+]?\[0-9]+$"));

}

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

    while (true) {

        string result = valid_input(nmbr);

        if(result == "Q") break;

        vec.push_back(stoi(result));

        nmbr++;
    }



    /*for (int x = 0; x < 6; x++) {
        int nmbr = x + 1;
        int in;
        cout << "Please enter value " << nmbr << ": ";
        cin >> in;
        cout << "\n";
        vec.push_back(in);
    }*/

    int option = 0;
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