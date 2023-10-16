//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

//Header File for SavingsAccount Class

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

//SavingsAccount CLass Declaration
class SavingsAccount
{
    //Private Variables
    private:
        //Static Variable
        static double annualInterestRate;
        double savingsBalance;
    //Public Variables
    public:
        //Constructor and Destructor
        SavingsAccount(double);
        ~SavingsAccount();
        //Functions to calculate monthly interest, modify interest rate, and get savings balance
        void calculateMonthlyInterest();
        //Static Function to modify interest rate
        static void modifyInterestRate(double);
        double getSavingsBalance();
};

#endif