// This program demonstrates the deleteNode member function.
#include <iostream>
#include "NumberList.h"
#include <time.h>
#include <vector>
using namespace std;

int main()
{
   // Define a NumberList object.
   NumberList list;

   const int SIZE = 10000;

   vector<int> vec;

   // Build the vector and list with some values.
   for(int i = 0; i < SIZE; i++)
   {
      vec.push_back(i);
   }
   cout << vec[0];

   for(int i = 0; i < SIZE; i++)
   {
      list.appendNode(i);
   }

   // Delete the middle node.
   cout << "Now deleting the node in the middle.\n";

   clock_t begin, end;
	double elapsed_seconds;

	begin = clock();
	//CODE TO TIME ->
	for (unsigned int i = 0; i < SIZE; i++)
	{
      list.deleteNode(i);
	}


	end = clock();

   cout << "Linked List Deletion Time: ";
	elapsed_seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << elapsed_seconds << endl;

   // Delete the middle node.
   cout << "Now deleting the Vector value in the middle.\n";

	begin = clock();
	//CODE TO TIME ->
   for(int i = 0; i < SIZE; i++)
   {
      vec.erase(vec.begin());
   }

	end = clock();

   cout << "Vector Deletion Time: ";
	elapsed_seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << elapsed_seconds << endl;

   //// Delete the last node.
   //cout << "Now deleting the last node.\n";
   //list.deleteNode(12.6);
//
   //// Display the list.
   //cout << "Here are the nodes left.\n";
   //list.displayList();
   //cout << endl;
//
   //// Delete the only node left in the list.
   //cout << "Now deleting the only remaining node.\n";
   //list.deleteNode(2.5);
//
   //// Display the list.
   //cout << "Here are the nodes left.\n";
   //list.displayList();
   return 0;
}