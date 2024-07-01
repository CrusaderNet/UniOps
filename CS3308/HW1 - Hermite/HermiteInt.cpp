//Homework 3 - Hermite Interpolation
//CS 3308 - Numerical Methods
//Seth Tourish
//Sam Holden
//Kharel Laxman

#include <iostream> 

using namespace std;

int main(){

    //QUESTION 2(b) HERMITE INTERPOLATION
    cout << "Question 2(b) Hermite Interpolation:: " << endl;
    //Take inputs from user and declare each hermite polynomial and coefficients for Q.2(b)
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
    cout << "Polynomial Is:: " << Q0 << " + " << Q1 << "(x - " << x0 << ") + " << Q2 << "(x - " << x0 << ")^2 + " << Q3 << "(x - " << x0 << ")(x - " << x1 << ")" << endl;
    cout << "Hermite interpolation at x = " << x << " is " << h3 << endl;
    cout << endl << "--------------------------------------------" << endl << endl;

    //QUESTION 2(c) HERMITE INTERPOLATION
    //Take inputs from user and declare each hermite polynomial and coefficients for Q.2(c)
    double x2, f2, f2_prime, Q4, h4;

    cout << "Question 2(c) Hermite Interpolation:: " << endl;
    //Take inputs from user and declare each hermite polynomial and coefficients
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
    cout << "Enter x2: ";
    cin >> x2;
    cout << "Enter f2: ";
    cin >> f2;
    cout << "Enter f2_prime: ";
    cin >> f2_prime;
    cout << "Enter x: ";
    cin >> x;

    //Calculate coefficients for hermite interpolation
    Q0 = f0;
    Q1 = f0_prime;
    Q2 = (((f1-f0)/(x1-x0)) - f0_prime)/(x1-x0);
    Q3 = (((f1_prime - ((f1-f0)/(x1-x0)))/(x1-x0)) - Q2)/(x1 - x0);
    Q4 = (((f2_prime - ((f2-f1)/(x2-x1))/(x2-x1)) - Q3)/(x2-x1) - Q2)/(x2-x1);

    //Calculate hermite interpolation
    h0 = Q0;
    h1 = h0 + Q1*(x-x0);
    h2 = h1 + Q2*(x-x0)*(x-x0);
    h3 = h2 + Q3*(x-x0)*(x-x0)*(x-x1);
    h4 = h3 + Q4*(x-x0)*(x-x0)*(x-x1)*(x-x2);

    //Print out the results
    cout << endl;
    cout << "Polynomial Is:: " << Q0 << " + " << Q1 << "(x - " << x0 << ") + " << Q2 << "(x - " << x0 << ")^2 + " << Q3 << "(x - " << x0 << ")(x - " << x1 << ") + " << Q4 << "(x - " << x0 << ")(x - " << x1 << ")(x - " << x2 << ");" << endl;
    cout << "Coefficients are:: " << endl << "Constant: " << Q0 << endl << "Linear: " << Q1 << endl << "Quadratic: " << Q2 << endl << "Cubic: " << Q3 << endl;
    cout << "Hermite interpolation at x = " << x << " is " << h3 << endl;

    return 0;
}