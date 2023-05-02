//Group 7
//Seth Tourish, Diego Moya, Jonathan Lopez
//April 25th, 2023
//PURPOSE

//Preprocessor Directives
#include <iostream>
#include <iomanip>
#include <array>
#include <string>
using namespace std;

void getInputData(string [], int, double [], int);
void calculateGrade(double [], int, char [], int, double [], int);
void displayGrade(string [], int, char [], int, double [], int);

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

void getInputData(string studentNames[], int studentSize, double scores[], int gradeSize) {

	static int count = 0;
	double grade = -1.0;

	cout << "-----------------------------------------------------" << endl;
	cout << "Please enter Student " << count + 1 << "'s name: ";
	cin >> studentNames[count];
	cout << endl;

	for (int i = 0; i < gradeSize; i++) {
		cout << "Please enter " << studentNames[count] << "'s Test Grade " << i + 1 << ": ";
		cin >> grade;
		cout << endl;

		while ((grade < 0) || (grade > 100)) {
			cout << "Invalid Grade Entered, please try again: ";
			cin >> grade;
			cout << endl;
		}

		scores[i] = grade;
	}
	count++;
}

void calculateGrade(double scores[], int scoreSize, char letterGrades[], int letterSize, double averageScores[], int avgSize) {

	static int count = 0;
	double totalPoints = 0;
	double numGrade = 0;
	char grade = 'Z';

	for (int i = 0; i < scoreSize; i++) {
		totalPoints += scores[i];
	}

	numGrade = totalPoints / 4;

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

	letterGrades[count] = grade;
	averageScores[count] = numGrade;
	count++;

}

void displayGrade(string names[], int studentSize, char letterGrades[], int letterGradeSize, double averageScores[], int avgSize) {

	cout << "------------------------------------------------------------------------" << endl;

	for (int i = 0; i < studentSize; i++) {
		cout << fixed << showpoint << setprecision(2);
		cout << "Student Name: " << names[i] << " || Average Test Score: " << averageScores[i] << " || Letter Grade: " << letterGrades[i] << endl;
	}

	cout << "------------------------------------------------------------------------" << endl;

}