#include <iostream>

using namespace std;

int recursiveMult(int x, int y){
    if(y == 1){
        return x;
    }
    return x + recursiveMult(x, y - 1);
}

int main(){
    int x = 5;
    int y = 3;
    cout << "Product: " << recursiveMult(x, y) << endl;
}