//Exam 1 Prep code

//Write a C++ program that uses a function to search a 2D vector of floats.
//The function will have 2 parameters:
//1. A 2 dimensional vector of floats, v
//2. The floating point number that you are searching for, item
//The function will return a vector of objects. Each object will contain the row and column of
//each instance where the item is found in the 2D vector.
//If the vector does not contain the item that it is searched for, the vector returned will only
//have 1 object. Within this object, the value -1 will be stored in the row member. Output to
//the console screen a message indicating that the vector did not contain this item if this is the
//case.
//The main function will:
//1) Output the contents of the 2D vector
//2) Output the item number that you are searching for
//3) Call the function that will search the 2D vector
//4) Output the locations of where the item can be found within the 2D vector or output a
//message indicating that the item is not located within the 2D vector

#include <iostream>
#include <vector>

using namespace std;

struct location
{
    int row, col;
};

vector<location> search(vector<vector<float>> &vec, float item)
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
    vector<vector<float>> vec = {{7,7,7},{4,4,4,4,4,4}};
    float item;

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