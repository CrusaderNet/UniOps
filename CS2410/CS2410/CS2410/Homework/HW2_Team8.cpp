//Team-8 (Seth Tourish 33%, Milly Flores 33%, Matthew Miller 33%)

#include <iostream>
#include <iomanip>

using namespace std;

//Function prototypes
void calculateAverage(int *, int);
void selectionSort(int *, int);
void calcMedian(int *, int);
void displayGraph(int *, int);

//Main function
int main()
{
    //Declare variables
    int *array = nullptr;
    int size;
    int total = 0;

    //Take input for the number of students surveyed
    cout << "Enter the number of Students surveyed: ";
    cin >> size;

    //Input Validation to check for negative numbers
    while (size < 0)
    {
        cout << "Please enter a positive number: ";
        cin >> size;
    }

    //Dynamically allocate an array
    array = new int[size];

    //Take inputs for the number of movies each student has seen
    for (int i = 0; i < size; i++)
    {
        cout << "How many movies did Student " << i + 1 << " see? ";
        cin >> *(array + i);

        //Input Validation to check for negative numbers
        while (*(array + i) < 0)
        {
            cout << "Please enter a positive number for Student " << i + 1 << ": ";
            cin >> *(array + i);
        }
    }

    //Output Formatting
    cout << endl << "Graph: " << endl << "-------------------------" << endl;
    
    //Display the results
    displayGraph(array, size);

    //Output Formatting
    cout << "-------------------------" << endl  << endl << "Statistics: " << endl << "-------------------------" << endl;

    //Find and Display the Median
    calcMedian(array, size);

    //Calculate and Display the Average
    calculateAverage(array, size);

    //Output Formatting
    cout << endl;

    //Deallocate the array.
    delete[] array;
    array = nullptr;

    //Terminate Program
    return 0;
}

//Function to calculate the average
void calculateAverage(int *array, int size)
{
    //Declare variables
    float average = 0;
    float total = 0;

    //Calculate the total
    for (int i = 0; i < size; i++)
    {
        total += *(array + i);
    }

    //Calculate the average
    average = total / size;

    cout << "The Average is: " << average << endl;
}

//Function to sort the array
void selectionSort(int *array, int size)
{
    //Declare variables
	int minIndex, minValue;

    //Sort the array
	for (int num = 0; num < (size - 1); num++)
	{
		minIndex = num;
		minValue = *(array + num);
		for (int i = num + 1; i < size; i++)
		{
			if (*(array + i) < minValue)
			{
				minValue = *(array + i);
				minIndex = i;
			}
		}
        //Swap the values
		*(array + minIndex) = *(array + num);
		*(array + num) = minValue;
	}
}

//Function to find the median
void calcMedian(int *array, int size)
{
    //Declare variables
    float median;

    //Sort the Array
    selectionSort(array, size);

    //If the size of the array is even
    if (size % 2 == 0)
    {
        median = (*(array + (size / 2)) + *(array + ((size / 2) - 1))) / 2.0;
    }
    //If the size of the array is odd
    else
    {
        median = *(array + (size / 2));
    }

    cout << "The Median is: " << median << endl;
}

//Function to display the graph
void displayGraph(int *array, int size)
{
    //Declare variables
    int count = 0;

    //Display the graph
    for (int i = 0; i < size; i++)
    {
        cout << "S" << i + 1 << ": ";
        for (int j = 0; j < *(array + i); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}