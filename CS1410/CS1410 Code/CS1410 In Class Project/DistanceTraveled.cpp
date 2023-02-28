#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	double speed, timeTraveled, distance, time;

	cout << " Enter the speed of the vehicle in mph: ";
	cin >> speed;

	while (speed < 0.00) {
		cout << "Speed must be non-negative. Check and reenter: ";
		cin >> speed;
	}

	cout << "Enter the time traveled in hours: ";
	cin >> timeTraveled;

	while (timeTraveled < 1.00) {
		cout << "Time Traveled must at least 1 hour. Check and reenter: ";
		cin >> timeTraveled;
	}

	cout << setw(6) << left << "Hour" << "Distance Traveled in Miles\n";
	cout << "---------------------------------------\n";

	for (time = 1; time <= timeTraveled; time++) {

		distance = time * speed;

		cout << setw(6) << left << time << distance << endl;

	}


	return 0;
}