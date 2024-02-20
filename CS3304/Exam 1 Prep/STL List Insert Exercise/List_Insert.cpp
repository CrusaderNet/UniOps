//Exam 1 prep
//Write a function template called List_Insert. This function will take as input, 3 parameters:
//1. An STL list
//2. The position of the insertion
//3. The value to be inserted
//List_Insert will insert a value into a list of any data type. Be sure that this function can insert any valid value into any
//valid position correctly. This would include the beginning and the end of the list. This would also include lists that have
//a size of 0. If the position is invalid, the function will output an error message to the console screen.
//Demonstrate this function working with 2 different types of STL lists – a list of integers and a list of characters.

#include <iostream>
#include <list>

using namespace std;

template <class anyType>
void displayList(list<anyType> &lst)
{
    typename list<anyType>::iterator i1;
    for(i1 = lst.begin(); i1 != lst.end(); i1++)
    {
        cout << " " << *i1;
    }

    cout << endl;
}

template <class anyType>
void List_Insert(list<anyType> &lst, int position, anyType value)
{
    typename list<anyType>:: iterator i1;

    i1 = lst.begin();

    if(position > lst.size())
    {
        cout << "ERROR: " << position << " is an invalid position. Maximum position is: " << lst.size() << endl;
    }
    else
    {
        int i = 0;
        while(i < position)
        {
            i++;
            i1++;
        }

       lst.insert(i1, value);

    }

    cout << "List: ";
    displayList(lst);
    cout << endl;

}

int main()
{
    list<int> int_list;
    cout << "Enter elements into the list: " << endl;

    List_Insert(int_list, 0, 4);
    List_Insert(int_list, 0, 5);
    List_Insert(int_list, 1, 6);
    List_Insert(int_list, 6, 6);
    List_Insert(int_list, 3, 7);

    list<char> char_list;
    List_Insert(char_list, 1, 'a');
    List_Insert(char_list, 0, 'b');


}