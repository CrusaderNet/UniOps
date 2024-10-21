#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// function to convert decimal to binary
void decToBinary(int bit, int n)
{

	vector<int> binaryNum(bit);
	// counter for binary array
	int i = 0;
	for (int i = 0; i < bit; ++i)
	{
		// storing remainder in binary array
		binaryNum[i] = n % 2;
		n = n / 2;
	}
	// printing binary array in reverse order
	for (int j = bit - 1; j >= 0; j--)
	{
		cout << binaryNum[j];
	}
	cout << endl;
}

// Driver program to test above function
int main()
{
	int M, num;
	char choice;
	cout << "Enter M of Excess M system: ";
	cin >> M;
	if (M <= 0)
	{
		return 0;
	}
	do
	{
		while (1)
		{
			cout << "Enter Number: ";
			cin >> num;
			if (num >= -pow(2, M - 1) && num <= (pow(2, M - 1) - 1))
			{
				break;
			}
			else
			{
				cout << "Oops! out of range" << endl;
			}
		}
		decToBinary(M, (num + pow(2, M - 1) -1));
		cout << "Enter Y to continue: ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');

	return 0;
}