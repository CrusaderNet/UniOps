//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

//Driver Program

//Preprocessor Directives
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

//Namespace Declaration
using namespace std;

//Main Function
int main()
{
    //Create SavingsAccount objects
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    //Output Formatting
    cout << fixed << setprecision(2);

    //Output for Original Balances
    cout << "Saver 1's balance is: $" << saver1.getSavingsBalance() << endl;
    cout << "Saver 2's balance is: $" << saver2.getSavingsBalance() << endl;
    cout << endl;

    //Set Interest Rate to 3%
    SavingsAccount::modifyInterestRate(0.03);
    //Calculate Monthly Interest and new balances
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    //Output for New Balances
    cout << "Saver 1's balance with 3% interest for month 1 is: $" << saver1.getSavingsBalance() << endl;
    cout << "Saver 2's balance with 3% interest for month 1 is: $" << saver2.getSavingsBalance() << endl;
    cout << endl;

    //Set Interest Rate to 4%
    SavingsAccount::modifyInterestRate(0.04);
    //Calculate Monthly Interest and new balances
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    //Output for New Balances
    cout << "Saver 1's balance with 4% interest for month 2 is: $" << saver1.getSavingsBalance() << endl;
    cout << "Saver 2's balance with 4% interest for month 2 is: $" << saver2.getSavingsBalance() << endl;
    cout << endl;

    //Exit Program
    return 0;
}