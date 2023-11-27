//Team 8 - (Seth Tourish 100%)
// This program demonstrates a simple append
// operation on a linked list.
#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
   // Define a NumberList object.
   NumberList list;

   // Append some values to the list.
   list.appendNode(2.5);
   list.appendNode(7.9);
   list.appendNode(12.6);
   list.displayList();
   cout << "The total of the values in the list is " << list.total() << endl;
 
   return 0;
}