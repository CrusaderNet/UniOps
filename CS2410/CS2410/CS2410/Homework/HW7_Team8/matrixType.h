//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

//Preprocessor Directives
#ifndef _MATRIXTYPE_H
#define _MATRIXTYPE_H
#include <iostream>

using namespace std;

//Class matrixType
class matrixType
{
//Private variables
private:
	int RSize = 0;
	int CSize = 0;
	int **Mat;
	bool add, sub, mult;

//Public functions
public:
	//Constructors
	matrixType();
	matrixType(int A, int B);
	//Destructor
	~matrixType();
	//Copy Constructor
	matrixType(const matrixType& right);
	//Getters
	int getRSize() const;
	int getCSize() const;
	//IO Overload Operators
	friend ostream &operator <<(ostream& os, const matrixType &obj);
	friend istream &operator >>(istream& is, matrixType& obj);
	//Operator Overload Functions
	matrixType operator+(const matrixType &right);
	matrixType operator-(const matrixType& right);
	matrixType operator*(const matrixType& right);
};

#endif 
