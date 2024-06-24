//Homework 4 - Trapezoidal Rule
//CS 3308 - Numerical Methods
//Seth Tourish
//Sam Holden
//Kharel Laxman

//Preprocessor Directives
#include <iostream>
#include <iomanip>
#include <cmath>

//Namespace Declaration
using namespace std;

//Set Global Constant PI
const double PI = 3.14159265358979323846;

//Integrated Function for Question 1
double functionOne(double x){
    //Integrand for the Ellipse Circumference Function
    double result = sqrt(1 - (2.0/3.0) * sin(x) * sin(x));
    return result;
}

//Integrated Function for Question 2
double functionTwo(double x){
    //Integrand for the Work Done Function
    return 100 * x * sqrt(125 - pow(x, 3));
}

//Trapezoidal Rule Function for Question 1 -- Ellipse Circumference:: Take In Lower Bound, Upper Bound, and Number of Subintervals
double trapezoidalRuleOne(double a, double b, int n){
    //Start Sum with the first and last values of the function
    double sum = functionOne(a) + functionOne(b);
    double approx;

    //Calculate the subinterval
    double subInterval = (b - a)/n;
    
    //Sum the rest of the values of the function at the subintervals
    for(int i = 1; i < n; i++){
        sum += 2 * functionOne(a + i * subInterval);
    }

    //Calculate the Approximation, with the 8 * sqrt(3) factor
    approx =  8 * sqrt(3) * sum * (subInterval / 2);

    //Return the Approximation
    return approx;
}

//Trapezoidal Rule Function for Question 2 -- Work Done:: Take In Lower Bound, Upper Bound, and Number of Subintervals
double trapezoidalRuleTwo(double a, double b, int n){
    //Start Sum with the first and last values of the function
    double sum = functionTwo(a) + functionTwo(b);
    double approx;

    //Calculate the subinterval
    double subInterval = (b - a)/n;
    
    //Sum the rest of the values of the function at the subintervals
    for(int i = 1; i < n; i++){
        sum += 2 * functionTwo(a + i * subInterval);
    }

    //Calculate the Approximation
    approx = sum * (subInterval / 2);

    //Return the Approximation
    return approx;
}

int main(){

    //Output Formatting::
    cout << fixed << setprecision(5);

    //Question 1 Calculation:: using 0 to PI/2 as the bounds, and 10000 subintervals
    double q1_Result = trapezoidalRuleOne(0, PI/2, 10000);

    //Question 1 Output
    cout << "-----Question 1-----" << endl;
    cout << "Circumference of the Ellipse is approximately: " << q1_Result << endl << endl;

    //Question 2 Calculation:: using 0 to 5 as the bounds, and 10000 subintervals
    double q2_Result = trapezoidalRuleTwo(0, 5, 10000);

    //Question 2 Output
    cout << "-----Question 2-----" << endl;
    cout << "The Work done through one Cycle is approximately: " << q2_Result << " ft-lbs"<< endl;

}