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


int main(){

    vector<int> vec = {2, 1, 7, 6, 20, 3};
    vector<int> vec1 = sort(vec);
    for(int i = 0; i < vec1.size(); i++){
        cout << vec1[i] << ", ";
    }


}