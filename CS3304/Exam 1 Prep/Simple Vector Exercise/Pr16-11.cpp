// This program demonstrates the SimpleVector template.
#include <iostream>
#include "SimpleVector.h"
#include <vector>
#include <time.h>
using namespace std;

int main()
{
   const int SIZE = 100000001;    // Number of elements
   int count;              // Loop counter
   
   // Create a SimpleVector of ints.
   SimpleVector<int> intTable(SIZE);

   vector<double> doubleTable(SIZE);

   // Store values in the two SimpleVectors.
   for (count = 0; count < SIZE; count++)
   {
      doubleTable[count] = (count + 1);
   }

   SimpleVector<double> doubleTable2(doubleTable);
   double test;
   clock_t begin, end;
	double elapsed_seconds;

   //TIMING STL VECTORS
   cout << "These values are in the STL Vector:\n";
   begin = clock();
	//CODE TO TIME ->
	for (unsigned int i = 0; i < 100000001; i++)
	{// Display the values in the SimpleVectors.
         doubleTable[i] = 1;
	}
	end = clock();
   cout << endl;
   elapsed_seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << "STL VECTOR ACCESS TIME: " << elapsed_seconds << endl;

   cout << "These values are in SimpleVector:\n";
   begin = clock();
	//CODE TO TIME ->
	for (unsigned int i = 0; i < 100000001; i++)
	{
         doubleTable2[i] = 1;
	}
	end = clock();
   cout << endl;
	elapsed_seconds = double(end - begin) / CLOCKS_PER_SEC;
	cout << "SIMPLEVECTOR ACCESS TIME:" << elapsed_seconds << endl;

   //// Display the values in the SimpleVectors.
   //cout << "These values are in the STL Vector:\n";
   //for (count = 0; count < SIZE; count++)
   //   cout << doubleTable[count] << " ";
   //cout << endl;
   //cout << "These values are in SimpleVector:\n";
   //for (count = 0; count < SIZE; count++)
   //   cout << doubleTable2[count] << " ";
   //cout << endl;
   
   //// Use the standard + operator on the elements.
   //cout << "\nAdding 5 to each element of intTable"
   //     << " and doubleTable.\n";
   //for (count = 0; count < SIZE; count++)
   //{
   //   intTable[count] = intTable[count] + 5;
   //   doubleTable[count] = doubleTable[count] + 5.0;
   //}
   //
   //// Display the values in the SimpleVectors.
   //cout << "These values are in intTable:\n";
   //for (count = 0; count < SIZE; count++)
   //   cout << intTable[count] << " ";
   //cout << endl;
   //cout << "These values are in doubleTable:\n";
   //for (count = 0; count < SIZE; count++)
   //   cout << doubleTable[count] << " ";
   //cout << endl;
   //
   //// Use the standard ++ operator on the elements.
   //cout << "\nIncrementing each element of intTable and"
   //    << " doubleTable.\n";
   //for (count = 0; count < SIZE; count++)
   //{
   //   intTable[count]++;
   //   doubleTable[count]++;
   //}
   //
   //// Display the values in the SimpleVectors.
   //cout << "These values are in intTable:\n";
   //for (count = 0; count < SIZE; count++)
   //   cout << intTable[count] << " ";
   //cout << endl;
   //cout << "These values are in doubleTable:\n";
   //for (count = 0; count < SIZE; count++)
   //   cout << doubleTable[count] << " ";
   //cout << endl;

   return 0;
}