
#include "matrixType.h"
#include <iostream>
using namespace std;

int main()
{
	int R1,R2,C1,C2;
	cout << "The size of the first array? (with a space between the two numbers)" << endl;
	cin >> R1 >> C1;
	cout << "The size of the secod array?(with a space between the two numbers)"  << endl;
	cin >> R2 >> C2;

	if (R1 <= 0 || C1 <= 0 || R2 <= 0 || C2 <= 0)
	{
		cout << "You must have a positive number for both your rows and colums.";
		return 0;
	}
	matrixType Mat1(R1, C1);
	matrixType Mat2(R2, C2);

	cout << "What are the numbers in the first Matrix?" << endl;
	cin >> Mat1;
	cout << "What is the numbers in the second Matrix?" << endl;
	cin >> Mat2;

	matrixType sum = Mat1 + Mat2;
	cout << "The sum of the two matrices are " << sum << endl;

	matrixType diffr = Mat1 - Mat2;
	cout << "The difrence of the two matrices are " << diffr << endl;

	matrixType prod = Mat1 * Mat2;
	cout << "The product of the Two matrices are " << prod << endl;


	return 0;
}