//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

//Preprocessor Directives
#include <iostream>
#include <iomanip>
#include "Rectangle.cpp"

using namespace std;

//Begin Main Program
int main()
{
    //Create Rectangle Object
    Rectangle rectangle;

    //Check if the input points form a rectangle
    if(rectangle.getIsRectangle() == false)
    {
        //If not, display error message and end program
        cout << "The coordinates you entered do not form a rectangle." << endl;
        return 0;
    }
    //If so, continue with program
    else
    {
        //Set Length, Width, Perimeter, Area, and IsSquare
        rectangle.setLength();
        rectangle.setWidth();
        rectangle.setPerimeter();
        rectangle.setArea();
        rectangle.setIsSquare();
        //Display Results
        rectangle.display();
    }

    //End Program
    return 0;
}