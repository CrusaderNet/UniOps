//Group 7
//Seth Tourish, Diego Moya, Jonathan Lopez
//April 25th, 2023
//Grade Calculator that takes in a set of student's names and 4 test scores for each student, and calculates the average test score and final letter grade for each student. Prints out the results of the calculations.

//Preprocessor Directives
#include <iostream>
#include <iomanip>
#include <array>
#include <string>
using namespace std;

//Function Prototypes
void getInputData(string [], int, double [], int);
void calculateGrade(double [], int, char [], int, double [], int);
void displayGrade(string [], int, char [], int, double [], int);

//Main Function
int main() {

	//Declare and Initialize Constants
	const int studentSize = 5;
	const int gradeSize = 4;

	//Declare Arrays
	string studentNames[studentSize];
	char letterGrades[studentSize];
	double student1Scores[gradeSize], student2Scores[gradeSize], student3Scores[gradeSize], student4Scores[gradeSize], student5Scores[gradeSize], averageScores[studentSize];
	
	//Get inputs for Student Data
	getInputData(studentNames, studentSize, student1Scores, gradeSize);
	getInputData(studentNames, studentSize, student2Scores, gradeSize);
	getInputData(studentNames, studentSize, student3Scores, gradeSize);
	getInputData(studentNames, studentSize, student4Scores, gradeSize);
	getInputData(studentNames, studentSize, student5Scores, gradeSize);

	//Calculate letter grades for Students
	calculateGrade(student1Scores, gradeSize, letterGrades, studentSize, averageScores, studentSize);
	calculateGrade(student2Scores, gradeSize, letterGrades, studentSize, averageScores, studentSize);
	calculateGrade(student3Scores, gradeSize, letterGrades, studentSize, averageScores, studentSize);
	calculateGrade(student4Scores, gradeSize, letterGrades, studentSize, averageScores, studentSize);
	calculateGrade(student5Scores, gradeSize, letterGrades, studentSize, averageScores, studentSize);

	//Display Grades
	displayGrade(studentNames, studentSize, letterGrades, studentSize, averageScores, studentSize);

	return 0;
}

//Function to gather a Student's Name and 4 test scores for the student.
void getInputData(string studentNames[], int studentSize, double scores[], int gradeSize) {

	//declare variables
	static int count = 0;
	double grade = -1.0;

	//Take in the student's name
	cout << "-----------------------------------------------------" << endl;
	cout << "Please enter Student " << count + 1 << "'s name: ";
	cin >> studentNames[count];
	cout << endl;

	//Loop to take in 4 test scores for the student
	for (int i = 0; i < gradeSize; i++) {
		cout << "Please enter " << studentNames[count] << "'s Test Grade " << i + 1 << ": ";
		cin >> grade;
		cout << endl;

		//Test Score validation to make sure grade is within the allowed range of 0 to 100
		while ((grade < 0) || (grade > 100)) {
			cout << "Invalid Grade Entered, please try again: ";
			cin >> grade;
			cout << endl;
		}

		//Add grade to current student grade array
		scores[i] = grade;
	}
	//Increment the counter to move to the next student name place
	count++;
}

//Function to calculate a student's average test score and letter grade
void calculateGrade(double scores[], int scoreSize, char letterGrades[], int letterSize, double averageScores[], int avgSize) {
	
	//Declare Variables
	static int count = 0;
	double totalPoints = 0;
	double numGrade = 0;
	char grade = 'Z';

	//Add up the student's test scores
	for (int i = 0; i < scoreSize; i++) {
		totalPoints += scores[i];
	}

	//Take the average of the student's test scores
	numGrade = totalPoints / 4;

	//If Else statements to assign the student a letter grade based upon their average test score
	if (numGrade >= 90)
		grade = 'A';
	else if (numGrade < 90 && numGrade >= 80)
		grade = 'B';
	else if (numGrade < 80 && numGrade >= 70)
		grade = 'C';
	else if (numGrade < 70 && numGrade >= 60)
		grade = 'D';
	else
		grade = 'F';

	//Add the student's average test score and letter grade to the appropriate arrays
	letterGrades[count] = grade;
	averageScores[count] = numGrade;

	//Count incrementer to move on to the next student
	count++;
}

//Function that is used to display all of the students final data: Their Name, Average Test Score, and Letter Grade
void displayGrade(string names[], int studentSize, char letterGrades[], int letterGradeSize, double averageScores[], int avgSize) {

	//Formatting
	cout << "------------------------------------------------------------------------" << endl;

	//For loop used to display the student data onto the console
	for (int i = 0; i < studentSize; i++) {
		//Formatting
		cout << fixed << showpoint << setprecision(2);

		//Print the student data from the appropriate arrays
		cout << "Student Name: " << names[i] << " || Average Test Score: " << averageScores[i] << " || Letter Grade: " << letterGrades[i] << endl;
	}

	//Formatting
	cout << "------------------------------------------------------------------------" << endl;
}