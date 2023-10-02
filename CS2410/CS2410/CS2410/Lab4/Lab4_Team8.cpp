// __________________________________________________________________
// Client section 
// __________________________________________________________________

//Team 8 - (Seth Tourish 50%, Milly Flores 50%)
#include <iostream>
#include "circles.cpp"

using namespace std;

int main()
{
    //Sphere Case 0
	Circles sphere(8, 9, 10);
	//sphere.setCenter(9, 10);
	sphere.printCircleStats();
    cout << "The area of the circle is " << sphere.findArea() << endl;
	cout << "The circumference of the circle is "
		 << sphere.findCircumference() << endl << endl;

    //Sphere Case 1
    Circles sphere1(2);
    sphere1.printCircleStats();
    cout << "The area of the circle is " << sphere1.findArea() << endl;
	cout << "The circumference of the circle is "
		 << sphere1.findCircumference() << endl << endl;

    //Sphere Case 2
    Circles sphere2;
    sphere2.printCircleStats();
    cout << "The area of the circle is " << sphere2.findArea() << endl;
	cout << "The circumference of the circle is "
		 << sphere2.findCircumference() << endl << endl;

    //Sphere Case 3
    Circles sphere3(15, 16);
    sphere3.printCircleStats();
    cout << "The area of the circle is " << sphere3.findArea() << endl;
	cout << "The circumference of the circle is "
		 << sphere3.findCircumference() << endl << endl;


    //Terminate Program
	return 0;
}