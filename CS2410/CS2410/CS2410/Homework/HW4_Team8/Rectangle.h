//Header File for Rectangle Class 

//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

#ifndef RECTANGLE_H
#define RECTANGLE_H

//Struct for Points
struct Point
{
    int x = 0;
    int y = 0;
};

//Rectangle Class Declaration
class Rectangle
{
//Private Data Members
private:
    //Coordinate Points
    Point topLeft;
    Point topRight;
    Point bottomLeft;
    Point bottomRight;
    //Length, Width, Perimeter, and Area
    int length;
    int width;
    int perimeter;
    int area;
    //Boolean for Square and Rectangle
    bool isSquare;
    bool isRectangle;

//Public Member Functions
public:
    //Constructor
    Rectangle();
    //Destructor
    ~Rectangle();
    //Accessor
    bool getIsRectangle();
    //Mutators
    void setPoints();
    void setLength();
    void setWidth();
    void setPerimeter();
    void setArea();
    void setIsSquare();
    //Display Function
    void display();
};

#endif