//Exam 1 Prep code

//Rewrite the Search_2D_Vector function so that it can work with any data type.
//Show that this function can work with a 2D vector of type float and a 2D vector of type char.

#include <iostream>
#include <vector>

using namespace std;

struct location
{
    int row, col;
};

template <class anyType>
vector<location> search(vector<vector<anyType>> &vec, anyType item)
{
    location L;
    vector<location> locations;
    unsigned int col_size;
    unsigned int num_rows = vec.size();

    for(int i = 0; i < num_rows; i++)
    {
        col_size = vec[i].size();
        
        for(int j = 0; j < col_size; j++)
        {
            if(vec[i][j] == item)
            {
                L.row = i;
                L.col = j;

                locations.push_back(L);
            }
        }
    }
    if(locations.size() == 0)
    {
        L.row == -1;
        locations.push_back(L);
    }

    return locations;
}

int main()
{
    //vector<vector<float>> vec = {{0,1,2},{-2,0,2}};
    vector<vector<double>> vec = {{7.1,7.1,7.1},{4.3,4.3,4.3,4.3,4.3,4.3}};
    double item;

    unsigned int col_size;
    unsigned int num_rows = vec.size();

    cout << "2D Vector Contents ->" << endl;

    for(int i = 0; i < num_rows; i++)
    {
        col_size = vec[i].size();
        
        for(int j = 0; j < col_size; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    cout << "************" << endl;

    cout << "Enter an item to search for: ";
    cin >> item;

    cout << endl;

    vector<location> locations = search(vec, item);

    cout << "The item that you searched for is: " << item << endl;
    if(locations[0].row == -1)
    {
        cout << "This vector did not contain the item that you searched for.";
        return 0;
    }
    else
    {
        cout << "The item that you searched for can be found at the following Location(s) ->" <<  endl;
        for(int i = 0; i < locations.size(); i++)
        {
            cout << locations[i].row << " " << locations[i].col << endl;
        }
    }

    return 0;

}