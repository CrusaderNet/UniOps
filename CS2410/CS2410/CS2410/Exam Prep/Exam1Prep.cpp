#include <iostream>

using namespace std;

struct GradeInfo
{
    string name;
    int *testScores;
    float average;
};

int main()
{
    //Defines stPtr as a pointer to a GradeInfo structure
    GradeInfo grades;
    GradeInfo *stPtr = nullptr;
    stPtr = &grades;

    struct GradeInfo studentInfo[2] = {{"John", new int[3]{90, 80, 70}},
                                       {"Mary", new int[3]{80, 70, 60}}};

    cout << studentInfo[0].name << endl;

}