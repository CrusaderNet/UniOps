//Seth Tourish
//CS 3308 HW 1
#include <iostream> 

using namespace std;

int main(){

    //Take inputs from user and declare each hermite polynomial and coefficients
    double x0, x1, f0, f1, f0_prime, f1_prime, x, h0, h1, h2, h3, Q0, Q1, Q2, Q3;
    cout << "Enter x0: ";
    cin >> x0;
    cout << "Enter f0: ";
    cin >> f0;
    cout << "Enter f0_prime: ";
    cin >> f0_prime;
    cout << "Enter x1: ";
    cin >> x1;
    cout << "Enter f1: ";
    cin >> f1;
    cout << "Enter f1_prime: ";
    cin >> f1_prime;
    cout << "Enter x: ";
    cin >> x;

    //Calculate coefficients for hermite interpolation
    Q0 = f0;
    Q1 = f0_prime;
    Q2 = (((f1-f0)/(x1-x0)) - f0_prime)/(x1-x0);
    Q3 = (((f1_prime - ((f1-f0)/(x1-x0)))/(x1-x0)) - Q2)/(x1 - x0);

    //Calculate hermite interpolation
    h0 = Q0;
    h1 = h0 + Q1*(x-x0);
    h2 = h1 + Q2*(x-x0)*(x-x0);
    h3 = h2 + Q3*(x-x0)*(x-x0)*(x-x1);

    //Print out the results
    cout << endl;
    cout << "Coefficients are:: " << endl << "Constant: " << Q0 << endl << "Linear: " << Q1 << endl << "Quadratic: " << Q2 << endl << "Cubic: " << Q3 << endl;
    cout << "Hermite interpolation at x = " << x << " is " << h3 << endl;

    return 0;
}