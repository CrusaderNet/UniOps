#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(){

int test[37] = {156, 150, 189, 175, 147, 195, 148, 96, 162, 209, 194, 207, 156, 163, 166, 104, 148, 193, 215, 172, 150, 147, 147, 214, 168, 159, 210, 148, 167, 214, 143, 160, 163, 161, 163, 86, 158};

vector <int> output = {72, 84, 66, 123};

for (int i = 3; i < 37; i++){
    output.push_back(test[i] - output[i]);

}

for(int i = 0; i < output.size(); i++){
    cout << (char)output[i];
}

}