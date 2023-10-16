//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

//Preprocessor Directives
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

//Namespace Declaration
using namespace std;

//Constructor
SavingsAccount::SavingsAccount(double balance)
{
    savingsBalance = balance;
}

//Destructor
SavingsAccount::~SavingsAccount()
{
    cout << "SavingsAccount Object Destroyed" << endl;
}

//Static Variable initialization
double SavingsAccount::annualInterestRate = 0.0;

//Function to calculate monthly interest
void SavingsAccount::calculateMonthlyInterest()
{
    //Calculate Monthly Interest
    savingsBalance += (savingsBalance * annualInterestRate) / 12;
}

//Static Function to modify interest rate
void SavingsAccount::modifyInterestRate(double rate)
{
    annualInterestRate = rate;
}

//Function to get savings balance
double SavingsAccount::getSavingsBalance()
{
    return savingsBalance;
}