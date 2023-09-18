// This program demonstrates the use of dynamic arrays

// Team-8 (Seth Tourish 33%, Milly Flores 33%, Matthew Miller 33%)

#include <iostream>
#include <iomanip>
using namespace std;

float getAverage(float *, int);

int main()
{
	float *monthSales = nullptr;	// a pointer used to point to an array
	                                // holding monthly sales 

	float total = 0;	// total of all sales
	float average;		// average of monthly sales
	int numOfSales;		// number of sales to be processed 
	int count;			// loop counter

	cout << fixed << showpoint << setprecision(2);

	cout << "How many monthly sales will be processed? ";
	cin >> numOfSales;

	monthSales = new float[numOfSales];// Fill in the code to allocate memory for the array pointed to by
	// monthSales.

	if (!monthSales)
	{
		cout << "Error allocating memory!\n";
		return 1;
	}

	cout << "Enter the sales below\n";

	for (count = 0; count < numOfSales; count++)
	{
		cout << "Sales for Month number	"
		     << count + 1// Fill in code to show the number of the month
		     << ": ";

		// Fill in code to bring sales into an element of the array
		cin >> *(monthSales+count);
	}

	average = getAverage(monthSales, numOfSales); // Fill in code to calculate the average of all sales.

	cout << "Average Monthly sale is $" << average << endl;

	// Fill in the code to deallocate memory assigned to the array.
	delete [] monthSales;

	monthSales = nullptr;

	return 0;
}

//Write a function to compute average
float getAverage(float *arr, int size)
{
	float sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += *(arr + i);
	}
	return sum / size;
}