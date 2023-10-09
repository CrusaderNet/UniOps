//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

//Preprocessor Directives
#include <iostream>
#include "Rectangle.h"

//Namespace Declaration
using namespace std;

//Constructor Implementation
Rectangle::Rectangle()
{
    //Set Lenght, Width, Perimeter, Area to Default 0
    length = 0;
    width = 0;
    perimeter = 0;
    area = 0;
    //Set isSquare to false and isRectangle to true
    isSquare = false;
    isRectangle = true;
    //Call setPoints Function
    setPoints();
}

//Set Points Function
void Rectangle::setPoints()
{
    //Get Points from User into temp x and y variables
    int x1, y1, x2, y2, x3, y3, x4, y4;
    //Get point 1 values from user
    cout << "Enter the x and y coordinates for point 1: ";
    cout << endl << "x: ";
    cin >> x1;
    //Input Validation for x1
    while(x1 < 0 || x1 > 20)
    {
        cout << "Invalid input. Please enter a value between 0 and 20: ";
        cin >> x1;
    }
    cout << "y: ";
    cin >> y1;
    //Input Validation for y1
    while(y1 < 0 || y1 > 20)
    {
        cout << "Invalid input. Please enter a value between 0 and 20: ";
        cin >> y1;
    }
    //Get point 2 values from user
    cout << "Enter the x and y coordinates for point 2: ";
    cout << endl << "x: ";
    cin >> x2;
    //Input Validation for x2
    while(x2 < 0 || x2 > 20)
    {
        cout << "Invalid input. Please enter a value between 0 and 20: ";
        cin >> x2;
    }
    cout << "y: ";
    cin >> y2;
    //Input Validation for y2
    while(y2 < 0 || y2 > 20)
    {
        cout << "Invalid input. Please enter a value between 0 and 20: ";
        cin >> y2;
    }
    //Get point 3 values from user
    cout << "Enter the x and y coordinates for point 3: ";
    cout << endl << "x: ";
    cin >> x3;
    //Input Validation for x3
    while(x3 < 0 || x3 > 20)
    {
        cout << "Invalid input. Please enter a value between 0 and 20: ";
        cin >> x3;
    }
    cout << "y: ";
    cin >> y3;
    //Input Validation for y3
    while(y3 < 0 || y3 > 20)
    {
        cout << "Invalid input. Please enter a value between 0 and 20: ";
        cin >> y3;
    }
    //Get point 4 values from user
    cout << "Enter the x and y coordinates for point 4: ";
    cout << endl << "x: ";
    cin >> x4;
    //Input Validation for x4
    while(x4 < 0 || x4 > 20)
    {
        cout << "Invalid input. Please enter a value between 0 and 20: ";
        cin >> x4;
    }
    cout << "y: ";
    cin >> y4;
    //Input Validation for y4
    while(y4 < 0 || y4 > 20)
    {
        cout << "Invalid input. Please enter a value between 0 and 20: ";
        cin >> y4;
    }

    //Here we check if points match up x and y values to form a rectangle

    //BEGIN CORNER SORTING ALGORITHM

    //Check if point1 x is equal to point2 x to form a vertical pair
    if(x1 == x2)
    {   
        //Check if there is a second vertical pair of the other points
        if(x3 == x4)
        {
            //Check if point1 x is less than point3 x to determine left side
            if(x1 < x3)
            {
                //Check if point1 y is less than point2 y to determine left top side
                if(y1 < y2)
                {
                    topLeft.x = x2;
                    topLeft.y = y2;
                    bottomLeft.x = x1;
                    bottomLeft.y = y1;
                }
                //Check for the opposite case
                else if(y1 > y2)
                {
                    topLeft.x = x1;
                    topLeft.y = y1;
                    bottomLeft.x = x2;
                    bottomLeft.y = y2;
                }
                //set isRectangle to false if points y value are equal
                else
                {
                    isRectangle = false;
                }
                //Check for if point3 y is less than point4 y to determine top right and bottom right
                if(y3 < y4)
                {
                    topRight.x = x4;
                    topRight.y = y4;
                    bottomRight.x = x3;
                    bottomRight.y = y3;
                }
                else if(y3 > y4)
                {
                    topRight.x = x3;
                    topRight.y = y3;
                    bottomRight.x = x4;
                    bottomRight.y = y4;
                }
                //set isRectangle to false if y value of the points are equal
                else
                {
                    isRectangle = false;
                }

            }
            //Check if point3 x is less than point1 x to determine left side - second case
            else if(x1 > x3)
            {
                //Check if point1 y is less than point2 y to determine right top side
                if(y1 < y2)
                {
                    topRight.x = x2;
                    topRight.y = y2;
                    bottomRight.x = x1;
                    bottomRight.y = y1;
                }
                //Check for the opposite case
                else if(y1 > y2)
                {
                    topRight.x = x1;
                    topRight.y = y1;
                    bottomRight.x = x2;
                    bottomRight.y = y2;
                }
                //set isRectangle to false if points y value are equal
                else
                {
                    isRectangle = false;
                }
                //Check if point3 y is less than point4 y to determine top right and bottom left
                if(y3 < y4)
                {
                    topLeft.x = x4;
                    topLeft.y = y4;
                    bottomLeft.x = x3;
                    bottomLeft.y = y3;
                }
                //Check for the opposite case
                else if(y3 > y4)
                {
                    topLeft.x = x3;
                    topLeft.y = y3;
                    bottomLeft.x = x4;
                    bottomLeft.y = y4;
                }
                //set isRectangle to false if y value of the points are equal
                else
                {
                    isRectangle = false;
                }
            }
            //set isRectangle to false if x value of the points are equal
            else
            {
                isRectangle = false;
            }
        }
        //set isRectangle to false if there is no second vertical pair
        else
        {
            isRectangle = false;
        }
    }
    //Second case of vertical pairings
    else if(x1 == x3)
    {
        //Check if there is a second vertical pair of the other points
        if(x2 == x4)
        {
            //Check if point1 x is less than point2 x to determine left side
            if(x1 < x2)
            {
                //Check if point1 y is less than point3 y to determine top side left
                if(y1 < y3)
                {
                    topLeft.x = x3;
                    topLeft.y = y3;
                    bottomLeft.x = x1;
                    bottomLeft.y = y1;
                }
                //Check for opposite case
                else if(y1 > y3)
                {
                    topLeft.x = x1;
                    topLeft.y = y1;
                    bottomLeft.x = x3;
                    bottomLeft.y = y3;
                }
                //set isRectangle to false if points y value are equal
                else
                {
                    isRectangle = false;
                }
                //Check if point2 y is less than point4 y to determine top right and bottom right
                if(y2 < y4)
                {
                    topRight.x = x4;
                    topRight.y = y4;
                    bottomRight.x = x2;
                    bottomRight.y = y2;
                }
                //Check for opposite case
                else if(y2 > y4)
                {
                    topRight.x = x2;
                    topRight.y = y2;
                    bottomRight.x = x4;
                    bottomRight.y = y4;
                }
                //set isRectangle to false if y value of the points are equal
                else
                {
                    isRectangle = false;
                }
            }
            //Check for if x1 point is the left side
            else if(x1 > x2)
            {
                //Check if point1 y is less than point3 y to determine right side top and bottom
                if(y1 < y3)
                {
                    topRight.x = x3;
                    topRight.y = y3;
                    bottomRight.x = x1;
                    bottomRight.y = y1;
                }
                //Check for opposite case
                else if(y1 > y3)
                {
                    topRight.x = x1;
                    topRight.y = y1;
                    bottomRight.x = x3;
                    bottomRight.y = y3;
                }
                //set isRectangle to false if points y value are equal
                else
                {
                    isRectangle = false;
                }
                //Check if point2 y is less than point4 y to determine left side top and bottom
                if(y2 < y4)
                {
                    topLeft.x = x4;
                    topLeft.y = y4;
                    bottomLeft.x = x2;
                    bottomLeft.y = y2;
                }
                //Check for opposite case
                else if(y2 > y4)
                {
                    topLeft.x = x2;
                    topLeft.y = y2;
                    bottomLeft.x = x4;
                    bottomLeft.y = y4;
                }
                ////set isRectangle to false if y value of the points are equal
                else
                {
                    isRectangle = false;
                }
            }
            //set isRectangle to false if x value of the points are equal
            else
            {
                isRectangle = false;
            }
        }
        //set isRectangle to false if there is no second vertical pair
        else
        {
            isRectangle = false;
        }
    }
    //Third case of vertical pairings
    else if(x1 == x4)
    {
        //Check if there is a second vertical pair of the other points
        if(x2 == x3)
        {
            //Check if point1 x is less than point2 x to determine left side
            if(x1 < x2)
            {
                //Check if point1 y is less than point4 y to determine left top side
                if(y1 < y4)
                {
                    topLeft.x = x4;
                    topLeft.y = y4;
                    bottomLeft.x = x1;
                    bottomLeft.y = y1;
                }
                //check for opposite case
                else if(y1 > y4)
                {
                    topLeft.x = x1;
                    topLeft.y = y1;
                    bottomLeft.x = x4;
                    bottomLeft.y = y4;
                }
                //set isRectangle to false if points y value are equal
                else
                {
                    isRectangle = false;
                }
                //Check if point2 y is less than point3 y to determine top right and bottom right
                if(y2 < y3)
                {
                    topRight.x = x3;
                    topRight.y = y3;
                    bottomRight.x = x2;
                    bottomRight.y = y2;
                }
                //Check for opposite case
                else if(y2 > y3)
                {
                    topRight.x = x2;
                    topRight.y = y2;
                    bottomRight.x = x3;
                    bottomRight.y = y3;
                }
                //set isRectangle to false if y value of the points are equal
                else
                {
                    isRectangle = false;
                }

            }
            //Check if point1 x is less than point2 x to determine right side
            else if(x1 > x2)
            {
                //Check if point1 y is less than point4 y to determine top and bottom side
                if(y1 < y4)
                {
                    topRight.x = x4;
                    topRight.y = y4;
                    bottomRight.x = x1;
                    bottomRight.y = y1;
                }
                //Check for opposite case
                else if(y1 > y4)
                {
                    topRight.x = x1;
                    topRight.y = y1;
                    bottomRight.x = x4;
                    bottomRight.y = y4;
                }
                //set isRectangle to false if points y value are equal
                else
                {
                    isRectangle = false;
                }
                //Check if point2 y is less than point3 y to determine left top and bottom side
                if(y2 < y3)
                {
                    topLeft.x = x3;
                    topLeft.y = y3;
                    bottomLeft.x = x2;
                    bottomLeft.y = y2;
                }
                //Check for opposite case
                else if(y2 > y3)
                {
                    topLeft.x = x2;
                    topLeft.y = y2;
                    bottomLeft.x = x3;
                    bottomLeft.y = y3;
                }
                //set isRectangle to false if y value of the points are equal
                else
                {
                    isRectangle = false;
                }
            }
            //set isRectangle to false if x value of the points are equal
            else
            {
                isRectangle = false;
            }
        }
        //set isRectangle to false if there is no second vertical pair
        else
        {
            isRectangle = false;
        }
    }
    //set isRectangle to false if there is no vertical pair
    else
    {
        isRectangle = false;
    }
}

//Get isRectangle 
bool Rectangle::getIsRectangle()
{
    return isRectangle;
}

//Set length function
void Rectangle::setLength()
{
    if(topRight.x - topLeft.x < topLeft.y - bottomLeft.y)
    {
        length = topLeft.y - bottomLeft.y;
    }
    else
    {
        length = topRight.x - topLeft.x;
    }
}

//Set Width Function
void Rectangle::setWidth()
{
    if(topRight.x - topLeft.x > topLeft.y - bottomLeft.y)
    {
        width = topLeft.y - bottomLeft.y;
    }
    else
    {
        width = topRight.x - topLeft.x;
    }
}

//Set Perimeter Function
void Rectangle::setPerimeter()
{
    perimeter = (2 * length) + (2 * width);
}

//Set Area Function
void Rectangle::setArea()
{
    area = length * width;
}

//Set isSquare Function
void Rectangle::setIsSquare()
{
    if (length == width)
    {
        isSquare = true;
    }
    else
    {
        isSquare = false;
    }
}

//Display Function
void Rectangle::display()
{
    cout << "Rectangle Information" << endl;
    cout << "---------------------" << endl;
    cout << "Length: " << length << endl;
    cout << "Width: " << width <<   endl;
    cout << "Perimeter: " << perimeter <<   endl;
    cout << "Area: " << area << endl;
    if (isSquare)
    {
        cout << "This is a square." <<  endl;
    }
    else
    {
        cout << "This is not a square." <<  endl;
    }
}

//Destructor for Rectangle class
Rectangle::~Rectangle()
{
    cout << "Rectangle object destroyed." << endl;
}