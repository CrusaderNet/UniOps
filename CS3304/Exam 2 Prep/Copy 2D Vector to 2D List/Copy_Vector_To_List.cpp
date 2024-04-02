#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <class anyType>
void Copy_Vector_To_List_2d(vector<vector<anyType>> &vec, list<list<anyType>> &lst)
{
    typename vector<vector<anyType>>::iterator i1;
    typename vector<anyType>::iterator i2;

    for(i1 = vec.begin(); i1 != vec.end(); i1++)
    {
        list<anyType> temp_list;
        for(i2 = i1->begin(); i2 != i1->end(); i2++)
        {
            temp_list.push_back(*i2);
        }
        lst.push_back(temp_list);
    }
}

int main()
{
    vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    list<list<int>> lst;

    Copy_Vector_To_List_2d(vec, lst);

    cout << "Vector: " << endl;
    for(auto i1 = vec.begin(); i1 != vec.end(); i1++)
    {
        for(auto i2 = i1->begin(); i2 != i1->end(); i2++)
        {
            cout << " " << *i2;
        }
        cout << endl;
    }

    cout << "List: " << endl;
    for(auto i1 = lst.begin(); i1 != lst.end(); i1++)
    {
        for(auto i2 = i1->begin(); i2 != i1->end(); i2++)
        {
            cout << " " << *i2;
        }
        cout << endl;
    }

    return 0;
}