
#include <iostream>
#include <cstdlib>
#include <string>
#include "matrixType.h"

using namespace std;

matrixType:: matrixType()
{
	 RSize = 0;
	 CSize = 0;
}
matrixType::matrixType(int A, int B)
{
	Mat = new int* [RSize];
	for (int i = 0; i < RSize; i++)
	{

		Mat[i] = new int[CSize];
	}
	//RSize = A;
	//CSize = B;
}
matrixType::~matrixType()
{
	for (int i = 0; i < RSize; i++)
	{
		delete[] Mat[i];
	}
}
ostream &operator <<(ostream& os, const matrixType &right)
{
	for (int i = 0; i < right.RSize; i++)
	{
		for (int j = 0; j < right.CSize; j++)
		{
			os << right.Mat[i][j];
		}

	}
	return os;
}
istream& operator >>(istream& is, matrixType& right)
{
	for (int i = 0; i < right.RSize; i++)
	{
		for (int j = 0; j < right.CSize; j++)
		{
			is >> right.Mat[i][j];
		}
	}
	return is;
}
matrixType matrixType :: operator+(const matrixType& right)
{
	if (CSize != right.CSize || RSize != right.RSize )
	{
		cout << "Cannot add because the matrices are not the same ";
		return *this;
	}

	matrixType Tot(RSize,CSize);

	for (int i = 0; i < RSize; i++)
	{
		for (int j = 0; j < CSize; j++)
		{
			Tot.Mat[i][j] = Mat[i][j] + right.Mat[i][j];
		}
	}
	return Tot;
	
}
matrixType matrixType :: operator-(const matrixType& right)
{
	if (CSize != right.CSize || RSize != right.RSize)
	{
		cout << "Cannot subtract because the matrices are not the same ";
		return *this;
	}

	matrixType Tot(RSize, CSize);

	for (int i = 0; i < RSize; i++)
	{
		for (int j = 0; j < CSize; j++)
		{
			Tot.Mat[i][j] = Mat[i][j] - right.Mat[i][j];
		}
	}
	return Tot;

}

matrixType matrixType :: operator*(const matrixType& right)
{
	if (CSize != right.RSize)
	{
		cout << "Cannot multiply because the matrices are not compatible ";
		return *this;
	}

	matrixType Tot(RSize, CSize);

	for (int i = 0; i < RSize; i++)
	{
		for (int k = 0; k < right.CSize; k++)
		{
			for (int j = 0; j < CSize; j++)
			{
				Tot.Mat[i][k] += Mat[i][j] * right.Mat[j][k];
			}
		}
	}
	return Tot;

}