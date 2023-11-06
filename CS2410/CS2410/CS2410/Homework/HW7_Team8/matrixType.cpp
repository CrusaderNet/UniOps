//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

//Preprocessor Directives
#include <iostream>
#include "matrixType.h"

using namespace std;

//Default constructor
matrixType::matrixType()
{
	 RSize = 0;
	 CSize = 0;
}

//Constructor
matrixType::matrixType(int A, int B)
{
	RSize = A;
	CSize = B;
	Mat = new int* [RSize];
	for(int i = 0; i < RSize; i++)
	{
		Mat[i] = new int[CSize];
	}
}

//Destructor
matrixType::~matrixType()
{
	//Delete each row of the matrix
	for(int i = 0; i < RSize; i++)
	{
		delete [] Mat[i];
	}

	//Delete the matrix
	delete [] Mat;
}

//Copy constructor
matrixType::matrixType(const matrixType& right)
{
	RSize = right.RSize;
	CSize = right.CSize;
	Mat = new int* [RSize];
	for(int i = 0; i < RSize; i++)
	{
		Mat[i] = new int[CSize];
	}
	for(int i = 0; i < RSize; i++)
	{
		for(int j = 0; j < CSize; j++)
		{
			Mat[i][j] = right.Mat[i][j];
		}
	}
}

//Getters
int matrixType::getRSize() const
{
	return RSize;
}

int matrixType::getCSize() const
{
	return CSize;
}

//Output overload operator
ostream &operator<<(ostream& os, const matrixType &right)
{
	os << "\n";
	for(int i = 0; i < right.RSize; i++)
	{
		for(int j = 0; j < right.CSize; j++)
		{
			os << right.Mat[i][j];
			os << " ";
		}
		os << "\n";

	}
	return os;
}

//Input overload operator
istream& operator>>(istream& is, matrixType& right)
{
	for(int i = 0; i < right.RSize; i++)
	{
		for(int j = 0; j < right.CSize; j++)
		{
			cout << "Enter the number for row " << i + 1 << " and column " << j + 1 << ": ";
			is >> right.Mat[i][j];
		}
	}
	return is;
}

//Matrix addition overload operator
matrixType matrixType::operator+(const matrixType& right)
{
	matrixType Tot(RSize, CSize);

	for(int i = 0; i < RSize; i++)
	{
		for(int j = 0; j < CSize; j++)
		{
			Tot.Mat[i][j] = Mat[i][j] + right.Mat[i][j];
		}
	}
	return Tot;
}

//Matrix subtraction overload operator
matrixType matrixType::operator-(const matrixType& right)
{
	matrixType Tot(RSize, CSize);

	for(int i = 0; i < RSize; i++)
	{
		for(int j = 0; j < CSize; j++)
		{
			Tot.Mat[i][j] = Mat[i][j] - right.Mat[i][j];
		}
	}
	return Tot;

}

//Matrix multiplication overload operator
matrixType matrixType::operator*(const matrixType& right)
{
	matrixType Tot(RSize, right.CSize);

	for(int i = 0; i < RSize; i++)
	{
		for(int k = 0; k < right.CSize; k++)
		{
			Tot.Mat[i][k] = 0;
			for(int j = 0; j < right.RSize; j++)
			{
				Tot.Mat[i][k] += Mat[i][j] * right.Mat[j][k];
			}
		}
	}
	return Tot;

}