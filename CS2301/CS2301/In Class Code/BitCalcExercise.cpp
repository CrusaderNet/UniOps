#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

void takeInput(int& size, string& type) {

	cout << "Input a whole number followed by a unit of measurement (TB, GB, MB, KB, B)" << endl << "Example: 1 KB" << endl;

	cin >> size >> type;

	while (size < 0 || type != "TB" && type != "GB" && type != "MB" && type != "KB" && type != "B") {

		cout << "Input a valid whole number and unit of measurement" << endl;

		cout << "Input a whole number followed by a unit of measurement (TB, GB, MB, KB, B)" << endl << "Example: 1 KB" << endl;

		cin >> size >> type;

	}

}

long long bitCalc(int size, string type) {

	long long bitsTemp = 0;

	if (type == "B")
		bitsTemp = size * 8;
	else if (type == "KB")
		bitsTemp = size * 1024 * 8;
	else if (type == "MB")
		bitsTemp = size * pow(1024, 2) * 8;
	else if (type == "GB")
		bitsTemp = size * pow(1024, 3) * 8;
	else if (type == "TB")
		bitsTemp = size * pow(1024, 4) * 8;

	return bitsTemp;

}


int main() {

	int size = 0;
	string type = " ";
	long long bits = 0;
	char continueVal = 'Y';

	do {

		takeInput(size, type);
		bits = bitCalc(size, type);

		cout << bits << " b" << endl;

		cout << "Do you wish to have another conversion? Type Y or y to continue." << endl;
		cin >> continueVal;

		cout << endl;

	} while (continueVal == 'Y' || continueVal == 'y');




}