//Homework 6 - LU Factorization
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

//Declare the Maximum Size of the Matrix
const int MAX = 4;

//Function for LU Factorization
void luFactorization(const double A[][MAX], double U[][MAX], double L[][MAX], int n){
    //Declare Sum Variables
    double summationU = 0.0;
    double summationL = 0.0;
    double summationUII = 0.0;

    //Check if the Factorization is Possible
    if((L[0][0] * U[0][0]) == 0){
        cout << "Factorization Impossible" << endl;
        return;
    }

    //Set the First Element of L and U
    L[0][0] = 1.0;
    U[0][0] = A[0][0];

    //Calculate the First Row and Column of L and U
    for(int j = 1; j < n; j++){
        U[0][j] = A[0][j] / L[0][0];
        L[j][0] = A[j][0] / U[0][0];
    }

    //Calculate the Remaining Rows and Columns of L and U
    for(int i = 1; i <= n - 1; i++){

        //Reset the Summation Variables
        summationUII = 0.0;

        //Calculate the Summation for U[i][i]
        for(int k = 0; k < i; k++){
            //Summation for U[i][i]
            summationUII += L[i][k] * U[k][i];
        }

        L[i][i] = 1.0;
        U[i][i] = A[i][i] - summationUII;

        //Calculate the Remaining Columns of U
        for(int j = i + 1; j < n; j++){
            //Reset the Summation Variables
            summationU = 0.0;

            //Calculate the Summation for U
            for(int k = 0; k < i; k++){
                //Summation for U
                summationU += L[i][k] * U[k][j];
            }
            //Calculate the Value of U
            U[i][j] = (A[i][j] - summationU) / L[i][i];

            //Reset the Summation Variable
            summationL = 0.0;

            //Calculate the Summation for L
            for(int k = 0; k < i; k++){
                //Summation for L
                summationL += L[j][k] * U[k][i];
            }
            //Calculate the Value of L
            L[j][i] = (A[j][i] - summationL) / U[i][i];
            
        }
    }
}


//Main Function
int main(){

    //**    TEXTBOOK QUESTION 6(b) CALCULATIONS */
    //Set Question 1 Variables (Textbook Question 6(b))
    double A1[][MAX] = {{1.0/3.0, 1.0/2.0, -1.0/4.0}, {1.0/5.0, 2.0/3.0, 3.0/8.0}, {2.0/5.0, -2.0/3.0, 5.0/8.0}};
    double U1[][MAX] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
    double L1[][MAX] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
    int n1 = 3;

    //Perform LU Factorization :: Operations performed on the original matrices
    luFactorization(A1, U1, L1, n1);

    //Output the Results
    cout << "Question 6(b) Results::" << endl;
    cout << "Matrix A:" << endl;
    //Output the Matrix A
    for(int i = 0; i < n1; i++){
        cout << "|"; //Output Formatting
        for(int j = 0; j < n1; j++){
            cout << setw(10)<< A1[i][j] << " ";
        }
        cout << "|" << endl; //Output Formatting
    }

    //Output the Matrix L
    cout << "Matrix L:" << endl;
    for(int i = 0; i < n1; i++){
        cout << "|";  //Output Formatting
        for(int j = 0; j < n1; j++){
            cout << setw(10) << L1[i][j] << " ";
        }
        cout << "|" << endl; //Output Formatting
    }

    //Output the Matrix U
    cout << "Matrix U:" << endl;
    for(int i = 0; i < n1; i++){
        cout << "|"; //Output Formatting
        for(int j = 0; j < n1; j++){
            cout << setw(10) << U1[i][j] << " ";
        }
        cout << "|" << endl; //Output Formatting
    }

    //Output Formatting
    cout << endl;
    cout << "--------------------------------" << endl << endl;

    //**    TEXTBOOK QUESTION 6(d) CALCULATIONS */
    //Set Question 2 Variables (Textbook Question 6(d))
    double A2[][MAX] = {{2.121, -3.460, 0, 5.217}, {0, 5.193, -2.197, 4.206}, {5.132, 1.414, 3.141, 0}, {-3.111, -1.732, 2.718, 5.212}};
    double U2[][MAX] = {{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}};
    double L2[][MAX] = {{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}};
    int n2 = 4;

    //Perform LU Factorization :: Operations performed on the original matrices
    luFactorization(A2, U2, L2, n2);

    //Output the Results
    cout << "Question 6(d) Results::" << endl;
    //Output the Matrix A
    cout << "Matrix A:" << endl;
    for(int i = 0; i < n2; i++){
        cout << "|"; //Output Formatting
        for(int j = 0; j < n2; j++){
            cout << setw(12) << A2[i][j] << " ";
        }
        cout << "|" << endl; //Output Formatting
    }

    //Output the Matrix L
    cout << "Matrix L:" << endl;
    for(int i = 0; i < n2; i++){
        cout << "|";
        for(int j = 0; j < n2; j++){
            cout << setw(12) << L2[i][j] << " ";
        }
        cout << "|" << endl;
    }

    //Output the Matrix U
    cout << "Matrix U:" << endl;
    for(int i = 0; i < n2; i++){
        cout << "|";  //Output Formatting
        for(int j = 0; j < n2; j++){
            cout <<  setw(12) << U2[i][j] << " ";
        }
        cout << "|" << endl;  //Output Formatting
    }

    return 0; //End the Program
}

