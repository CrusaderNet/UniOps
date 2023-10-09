
//Milly Flores, Seth Tourish
//Lab1_Group8
#include <iostream>
#include<array>
using namespace std;
int main()
{
const int SIZE = 5; //Set the array size
float scores[5] = { 0, 0, 0, 0, 0 };
//Declare Variables
float score;
//1. INPUTS
for (int i = 0; i < SIZE; i++)
{
cout << "Please Input the Score-" << i + 1 << ": ";
cin >> score;
cout << endl;
while (score < 0 || score > 100)
{
cout << "Score-" << i + 1 << " is invalid, please re-enter Score-" << i + 1 << ": ";
cin >> score;
cout << endl;
}
scores[i] = score;
}
//2. PROCESSING
//2a. Compute the Average Score
//Declare and initialize variables
float average = 0;
float sum = 0;
for (int i = 0; i < SIZE; i++)
{
sum += scores[i];
}
average = sum / SIZE;
//2b. Compute the highest score
float highest = scores[0];
for (int i = 0; i < SIZE; i++)
{
if (highest < scores[i])
highest = scores[i];
}
//2c. Compute the lowest score
float lowest = scores[0];
for (int i = 0; i < SIZE; i++)
{
if (lowest > scores[i])
lowest = scores[i];
}
//3. OUTPUTS
cout << "Summary" << endl;
cout << "=======" << endl;
cout << "The Average of all the scores is: " << average << endl;
cout << "Highest Score is: " << highest << endl;
cout << "Lowest Score is: " << lowest << endl;
}