#include <iostream>
#include <vector>

using namespace std;

vector<int> sort(vector<int> v){

    int i = v.size();
    for(int j = 0; j < i; j++){
           for(int k = 0; k < i; k++){
            if(v[k] > v[j]){
                int temp = v[j];
                v[j] = v[k];
                v[k] = temp;
            }
           }
    }
    return v;

}

int search(vector<int> v, int i){

    int index = -1;

    for(int j = 0; j < v.size(); j++){
        if(v[j] == i){
            index = j;
        } 
    }

    if(index == -1){
        cout << "The element " << i << " has not been found in the given vector.\n";
    } else{
        cout << "The element " << i << " is at index " << index << "\n";
    }

    return index;
}


int main(){

    vector<int> vec;

    for(int x = 0; x < 6; x++){
        int nmbr = x + 1;
        int in;
        cout << "Please enter value " << nmbr << ": ";
        cin >>in;
        cout << "\n";
        vec.push_back(in);
    }

     int option = 0;
     while(option != 3){
        cout << "Please enter an option for what you want to do with your vector: \n" << "1): Sort\n" << "2): Search\n" << "3). Exit\n" << "\n";
        cout << "Option: "; cin >> option; cout << "\n";
    switch(option){
        case 1: 
        {
            vector<int> vec1 = sort(vec);
            cout << "----------------------------------------------\n";
            cout << "Your sorted vector is: ";
            for(int i = 0; i < vec1.size() - 1; i++){
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
}