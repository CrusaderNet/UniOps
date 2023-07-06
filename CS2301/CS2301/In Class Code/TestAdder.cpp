#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool add(bool bit1, bool bit2, bool& carry)
{

	bool result;

	if (bit1 == 1 && bit2 == 1)
	{

		if (carry)
		{
			result = 1;
			carry = 1;
		}

		else
		{
			result = 0;
			carry = 1;
		}

	}

	else if (bit1 == 0 && bit2 == 0)
	{

		if (carry)
		{
			result = 1;
		}

		else
		{
			result = 0;
		}
		carry = 0;
	}

	else
	{

		if (carry)
		{
			result = 0;
			carry = 1;
		}
		else
		{
			result = 1;
			carry = 0;

		}

	}


}