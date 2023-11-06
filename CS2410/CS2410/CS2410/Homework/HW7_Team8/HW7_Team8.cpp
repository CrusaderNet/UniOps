//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

//Preprocessor Directives
#include "matrixType.h"
#include <iostream>

using namespace std;

int main()
{
	int R1,R2,C1,C2;

	//Take size inputs for the first matrix and make sure they are positive numbers, if not ask for them again.
	do
	{
		cout << "The size of the first matrix? (with a space between the two numbers)" << endl;
		cin >> R1 >> C1;
		cout << endl;
		if(R1 <= 0 || C1 <= 0)
			cout << "You must have a positive number for both your rows and columns." << endl;
	} while(R1 <= 0 || C1 <= 0);

	//Take size inputs for the second matrix and make sure they are positive numbers, if not ask for them again.
	do
	{
		cout << "The size of the second matrix? (with a space between the two numbers)"  << endl;
		cin >> R2 >> C2;
		cout << endl;

		if(R2 <= 0 || C2 <= 0)
			cout << "You must have a positive number for both your rows and columns." << endl;
	} while(R2 <= 0 || C2 <= 0);

	//Create the two matrices
	matrixType Mat1(R1, C1);
	matrixType Mat2(R2, C2);

	//Take inputs for the two matrices
	cout << "What are the numbers in the first Matrix?" << endl;
	cin >> Mat1;
	cout << endl;
	cout << "What are the numbers in the second Matrix?" << endl;
	cin >> Mat2;
	cout << endl;

	//Formatting
	cout << "RESULTS:" << endl;
	cout << "----------------------------------------" << endl;

	//Print out the sum of the two matrices, and the difference of the two matrices using the same dimensions test
	//If the dimensions are not the same, print out that they cannot be added or subtracted
	if(Mat1.getRSize() != Mat2.getRSize() || Mat1.getCSize() != Mat2.getCSize())
	{
		cout << "Cannot add because the matrices do not have the same dimensions " << endl;
		cout << "Cannot subtract because the matrices do not have the same dimensions " << endl;
	}
	else
	{
		//Print out the sum and difference of the two matrices
		matrixType sum = Mat1 + Mat2;
		cout << "The sum of the two matrices are " << sum << endl;

		matrixType diff = Mat1 - Mat2;
		cout << "The difference of the two matrices are " << diff << endl;
	}

	//Print out the product of the two matrices
	if (Mat1.getCSize() != Mat2.getRSize())
	{
		cout << "Cannot multiply because the matrices are not compatible (Column Size of Matrix 1 does not equal Row Size of Matrix 2) " << endl;
	}
	else
	{
		matrixType mult = Mat1 * Mat2;
		cout << "The product of the Two matrices are " << mult << endl;
	}
	//End the program
	return 0;
}