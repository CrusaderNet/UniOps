

#ifndef _MATRIXTYPE_H
#define _MATRIXTYPE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class matrixType
{
private:
	int RSize = 0;
	int CSize = 0;
	 int **Mat;

public:
	matrixType();
	matrixType(int A, int B);
	~matrixType();
	friend ostream &operator <<(ostream& os, const matrixType &obj);
	friend istream &operator >>(istream& is, matrixType& obj);
	matrixType operator+(const matrixType &right);
	matrixType operator-(const matrixType& right);
	matrixType operator*(const matrixType& right);
	
};

#endif 
