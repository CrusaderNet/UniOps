//Team 8 - (Seth Tourish 50%, Milly Flores 50%)

#include <iostream>
#include <iomanip>
#include "Rectangle.cpp"

using namespace std;

int main()
{
    Rectangle rectangle;

    if(rectangle.getIsRectangle() == false)
    {
        cout << "The coordinates you entered do not form a rectangle." << endl;
        return 0;
    }
    else
    {
        rectangle.setLength();
        rectangle.setWidth();
        rectangle.setPerimeter();
        rectangle.setArea();
        rectangle.setIsSquare();
        rectangle.display();
    }

    return 0;
}