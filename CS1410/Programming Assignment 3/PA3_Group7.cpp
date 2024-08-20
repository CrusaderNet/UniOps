//Group 7
//Seth Tourish, Diego Moya, Jonathan Lopez
//March 29th, 2023
//This is a program that opens a file, reads all the numbers from the file, and then calculates the number of numbers in the file, the highest and lowest number in the file,
//and the sum and average of all the numbers in the file.

//Preprocessor Directives
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Begin main program
int main() {

    //Declare Variables
    int count = 0;
    double num, total = 0, high = 0, low = 0;
    ifstream inFile;
    ofstream outFile;

    //Open Files and create output files
    inFile.open("Random.txt");
    outFile.open("PA3_Group7.txt");

    //Check if file is open, and if it is start the calculations. If not, display an error message.
    if (inFile.is_open()) {

        //Step through the file number by number, increasing count and total with each iteration
        while (inFile >> num) {
            count++;
            total += num;

            //Check if on the first iteration, if yes then set high and low number variables to current number
            if (high == 0 && low == 0) {
                high = num;
                low = num;
            }

            //Check if current number is higher than the stored high number, if yes then replace stored value with current number in the list
            if (high < num) { high = num; }

            //Check if current number is smaller than the stored low number, if yes then replace stored value with current number in the list
            if (low > num) { low = num; }

        }
        //Output formatting and output of the results of the calculations into a text file
        outFile << fixed << showpoint << setprecision(2);
        outFile << "The number of numbers in the file is: " << count << endl;
        outFile << "The highest number in the file is: " << high << endl;
        outFile << "The smallest number in the file is: " << low << endl;
        outFile << "The sum of all the numbers in the file is: " << total << endl;
        outFile << "The average of all the numbers in the file is: " << (total / count) << endl;

        cout << "Output File has been created!" << endl;

        //Close file
        inFile.close();
    }
    //Check if file did not open, and display an error message if file did not open
    else if (!inFile) {
        cout << "There has been an error opening the file!" << endl;
        outFile << "There has been an error opening the file!" << endl;
    }

    //Close output file
    outFile.close();

    //Return 0 and end program
    return 0;
}