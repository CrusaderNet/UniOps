#include <iostream>

using namespace std;

int recursiveSum(int num[], int size){
    if(size == 0){
        return 0;
    }
    return num[size - 1] + recursiveSum(num, size - 1);
}

int main(){
    int size = 4;
    int num[] = {2, 4, 6, 8};
    cout << "Sum: " << recursiveSum(num, size) << endl;
}