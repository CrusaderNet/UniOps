// Include the required header files.

#include <iostream>

#include <vector>

// Use the standard namespace.

using namespace std;

// Define a helper function to return the

// Boolean sum of two input along with the

// carry and set the carry value.

bool add(bool value1, bool value2, bool& carry)

{

	bool result;

	// Case 1: Both the bits are 1.

	if (value1 == 1 && value2 == 1)

	{

		// If carry is 1, set the carry to 1

		// and set the result of the sum to 1.

		if (carry)

		{

			carry = 1;

			result = 1;

		}

		// Otherwise, set the carry to 1

		// and set the result of the sum to 0.

		else

		{

			carry = 1;

			result = 0;

		}

	}

	// Case 2: Both the bits are 0.

	else if (value1 == 0 && value2 == 0)

	{

		// If carry is 1, set the result of the sum to 1.

		if (carry)

		{

			result = 1;

		}

		// Otherwise, set the result of the sum to 0.

		else

		{

			result = 0;

		}

		// Set the carry to 0.

		carry = 0;

	}

	// Case 3: One bit is 0, other bit is 1.

	else

	{

		// If carry is 1, set the carry to 1

		// and set the result of the sum to 0.

		if (carry)

		{

			carry = 1;

			result = 0;

		}

		// Otherwise, set the carry to 0

		// and set the result of the sum to 1.

		else

		{

			carry = 0;

			result = 1;

		}

	}

	// Return the result.

	return result;

}

// Define the function Full_Adder().

vector<bool> Full_Adder(vector<bool> num1, vector<bool> num2)

{

	// Check if the size of both the input is

	// same or not.

	if (num1.size() != num2.size())

	{

		// Append 0 to the starting of the first input

		// if its length is less than the second input.

		if (num1.size() < num2.size())

		{

			// Start the loop to append 0.

			for (int i = num1.size(); i < num2.size(); i++)

			{

				num1.insert(num1.begin(), 0);

			}

		}

		// Otherwise, Append 0 to the starting of

		// the second input.

		else

		{

			// Start the loop to append 0.

			for (int i = num2.size(); i < num1.size(); i++)

			{

				num2.insert(num2.begin(), 0);

			}

		}

	}

	// Declare the required variables.

	bool carry = 0;

	vector<bool> result;

	// Start the loop to traverse the vectors from end to

	// start so that the least significant bits are added

	// first and the carry can be added to the next bit.

	for (int i = num1.size() - 1; i >= 0; i--)

	{

		// Call the function to add the values and store the

		// result in the result vector.

		// Pass the value of carry by reference so that

		// it can be set in the add function.

		result.push_back(add(num1.at(i), num2.at(i), carry));

	}

	// If there exists a carry, add it to the vector.

	if (carry)

	{

		result.push_back(carry);

	}

	int start = 0;

	int end = result.size() - 1;

	// Start the loop to reverse the result vector.

	while (start < end)

	{

		bool temp = result.at(start);

		result.at(start) = result.at(end);

		result.at(end) = temp;

		start++;

		end--;

	}

	// Return the vector.

	return result;

}

// Define a helper function to display the vector.

void display(vector<bool> vec)

{

	for (int i = 0; i < vec.size(); i++)

	{

		cout << vec.at(i);

	}

}

// Define a helper function to create and return

// a vector of Boolean values from the given string.

vector<bool> create_vector(string s1)

{

	vector<bool> number;

	for (int i = 0; i < s1.length(); i++)

	{

		number.push_back(s1[i] - '0');

	}

	return number;

}

// Define the main() function.

int main()

{

	// Declare the required variables.

	vector<bool> num1;

	vector<bool> num2;

	vector<bool> result;

	// Call the create_vector() function to

	// create vectors of different values and

	// test the Full_Adder() function.

	// Test case 1: 1+1

	cout << "FULL ADDER" << endl;

	num1 = create_vector("1");

	display(num1);

	cout << " + ";

	num2 = create_vector("1");

	display(num2);

	cout << " = ";

	result = Full_Adder(num1, num2);

	display(result);

	cout << endl;

	// Test case 2: 11+10

	num1 = create_vector("11");

	display(num1);

	cout << " + ";

	num2 = create_vector("10");

	display(num2);

	cout << " = ";

	result = Full_Adder(num1, num2);

	display(result);

	cout << endl;

	// Test case 3: 1+11

	num1 = create_vector("1");

	display(num1);

	cout << " + ";

	num2 = create_vector("11");

	display(num2);

	cout << " = ";

	result = Full_Adder(num1, num2);

	display(result);

	cout << endl;

	// Test case 4: 11+11

	num1 = create_vector("11");

	display(num1);

	cout << " + ";

	num2 = create_vector("11");

	display(num2);

	cout << " = ";

	result = Full_Adder(num1, num2);

	display(result);

	cout << endl;

	// Return 0 and exit the program.

	return 0;

}