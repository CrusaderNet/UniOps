//Homework 4 - Romberg Integration
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

//Function for Question 2(a)
double functionOne(double x){
    return (cos(x) * cos(x));
}

//Function for Question 2(c)
double functionTwo(double x){
    return ((sin(x)*sin(x)) - (2.0 * x * sin(x)) + 1.0);
}

int main(){

    //**    TEXTBOOK QUESTION 2(a) CALCULATIONS */
    //Set Question 1 Variables (Textbook Question 2(a))
    double rombergTable_2A[10][10];
    double h1, a1, b1;
    int n1 = 1;

    a1 = -1.0;
    b1 = 1.0;

    //Set the Initial Value of h
    h1 = (b1-a1)/n1;

    //Set the Initial Value of n
    n1 = 0;

    //Set the Initial Value of the Romberg Table, R1,1
    rombergTable_2A[0][0] = (h1 / 2.0) * (functionOne(a1) + functionOne(b1));

    //Calculate the Romberg Table
    do{
        //Increment n to the start of the next iteration
        n1++;

        //Calculate the new value of h
        h1 = h1 / 2.0;

        //Declare the variable in R(n,0)
        rombergTable_2A[n1][0] = 0.0;

        //Calculate the value of R(n,0)
        for(int k = 1; k <= pow(2, n1-1); k++){
            //Sum the values of the function at the subintervals
            rombergTable_2A[n1][0] += functionOne(a1 + (2 * k - 1) * h1);
        }

        //Calculate the value of R(n,0) using the previous value of R(n-1,0) and current sum of the function at the subintervals
        rombergTable_2A[n1][0] = rombergTable_2A[n1-1][0] / 2.0 + h1 * rombergTable_2A[n1][0];

        //Calculate the rest of the Romberg Table for the current iteration using the previous values of the Romberg Table
        for(int j = 1; j <= n1; j++){
            //Calculate the value of R(n,j) using the previous value of R(n,j-1) and R(n-1,j-1)
            rombergTable_2A[n1][j] = rombergTable_2A[n1][j-1] + (rombergTable_2A[n1][j-1] - rombergTable_2A[n1-1][j-1]) / (pow(4, j) - 1);
        }

        //Check if the difference between the current value of R(n,n) and the previous value of R(n-1,n-1) is less than 0.000001 (10^-6 accuracy)
        if(abs(rombergTable_2A[n1][n1] - rombergTable_2A[n1-1][n1-1]) < 0.000001){
            //If the difference is less than 0.000001, end Romberg Extrapolation
            break;
        }

    }while((n1 < 10)); //End the Romberg Extrapolation if number of iterations exceeds 10

    //OUTPUT ROMBERG TABLE AND ANSWER
    cout << "Question 2(a) Romberg Table:" << endl;
    //Print the Romberg Table
    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= i; j++){
            cout << setw(15) << setprecision(7) << rombergTable_2A[i][j];
        }
        cout << endl;
    }
    cout << "Romberg Extrapolation for Question 2(a) Result: " << rombergTable_2A[n1][n1] << endl;

    //**        END QUESTION 2(a) CALCULATIONS */


    //**    TEXTBOOK QUESTION 2(c) CALCULATIONS */
    //Set Question 2 Variables (Textbook Question 2(c))
    double rombergTable_2C[10][10];
    double h2, a2, b2;
    int n2 = 1;

    a2 = 1.0;
    b2 = 4.0;

    //Set the Initial Value of h
    h2 = (b2-a2)/n2;

    //Set the Initial Value of n
    n2 = 0;

    //Set the Initial Value of the Romberg Table, R1,1
    rombergTable_2C[0][0] = (h2 / 2.0) * (functionTwo(a2) + functionTwo(b2));

    //Calculate the Romberg Table
    do{
        //Increment n to the start of the next iteration
        n2++;

        //Calculate the new value of h
        h2 = h2 / 2.0;
        
        //Declare the variable in R(n,0)
        rombergTable_2C[n2][0] = 0.0;

        //Calculate the value of R(n,0)
        for(int i = 1; i <= pow(2, n2-1); i++){
            //Sum the values of the function at the subintervals
            rombergTable_2C[n2][0] += functionTwo(a2 + (2 * i - 1) * h2);
        }

        //Calculate the value of R(n,0) using the previous value of R(n-1,0) and current sum of the function at the subintervals
        rombergTable_2C[n2][0] = rombergTable_2C[n2-1][0] / 2.0 + h2 * rombergTable_2C[n2][0];

        //Calculate the rest of the Romberg Table for the current iteration using the previous values of the Romberg Table
        for(int m = 1; m <= n2; m++){
            //Calculate the value of R(n,j) using the previous value of R(n,j-1) and R(n-1,j-1)
            rombergTable_2C[n2][m] = rombergTable_2C[n2][m-1] + (rombergTable_2C[n2][m-1] - rombergTable_2C[n2-1][m-1]) / (pow(4, m) - 1);
        }

        //Check if the difference between the current value of R(n,n) and the previous value of R(n-1,n-1) is less than 0.000001 (10^-6 accuracy)
        if(abs(rombergTable_2C[n2][n2] - rombergTable_2C[n2-1][n2-1]) < 0.000001){
            //If the difference is less than 0.000001, end Romberg Extrapolation
            break;
        }
    }while((n2 < 10)); //End the Romberg Extrapolation if number of iterations exceeds 10

    cout << endl;

    //OUTPUT ROMBERG TABLE AND ANSWER
    cout << "Question 2(c) Romberg Table:" << endl;

    for(int i = 0; i <= n2; i++){
        for(int j = 0; j <= i; j++){
            cout << setw(15) << setprecision(7) << rombergTable_2C[i][j];
        }
        cout << endl;
    }

    cout << "Romberg Extrapolation for Question 2(c) Result: " << rombergTable_2C[n2][n2] << endl;

    //**        END QUESTION 2(c) CALCULATIONS */

    return 0;
}