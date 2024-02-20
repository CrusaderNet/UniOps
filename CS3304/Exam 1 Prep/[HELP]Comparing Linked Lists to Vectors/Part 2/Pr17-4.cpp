// This program demonstrates the deleteNode member function.
#include <iostream>
#include "LinkedList.h"
#include <time.h>
#include <vector>
#include <list>
#include <iomanip>
using namespace std;

int main()
{
   // Define a NumberList object.
   LinkedList<int> lst;

   list<int> lst2;

   const int SIZE = 100000;

   vector<int> vec;

   // Build the vector and list with some values.
   for(int i = 0; i < SIZE; i++)
   {
      vec.push_back(i);
   }
   cout << vec[0];

   for(int i = 0; i < SIZE; i++)
   {
      lst.appendNode(i);
   }

   for(int i = 0; i < SIZE; i++)
   {
      lst2.push_back(i);
   }


   clock_t begin, end, b2, e2, b3, e3;
	double elapsed_seconds;

	b2 = clock();
	//CODE TO TIME ->
   for(int i = 0; i < SIZE; i++)
   {
      vec.erase(vec.begin());
   }

	e2 = clock();

   cout << "Vector Deletion Time: ";
   cout << setprecision(15);
	elapsed_seconds = double(e2 - b2) / CLOCKS_PER_SEC;
	cout << elapsed_seconds << endl;
   
   begin = clock();
	//CODE TO TIME ->
   for(int i = 0; i < SIZE; i++)
   {
      lst.deleteNode(i);
   }


	end = clock();

   cout << "Linked List Deletion Time: ";
	elapsed_seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << elapsed_seconds << endl;


   b3 = clock();
	//CODE TO TIME ->
   for(int i = 0; i < SIZE; i++)
   {
      lst2.erase(lst2.begin());
   }   

	e3 = clock();

   cout << "STL List Deletion Time: ";
   cout << setprecision(15);
	elapsed_seconds = double(e3 - b3) / CLOCKS_PER_SEC;
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