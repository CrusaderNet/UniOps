//circles.h
//Team 8 - (Seth Tourish 50%, Milly Flores 50%)
#ifndef CIRCLES_H  
#define CIRCLES_H

class Circles
{
public:
	void setCenter(int x, int y);
	double findArea();
	double findCircumference();
	void printCircleStats();	// This outputs the radius and center of the circle. 
	Circles(float r);			// Constructor
	Circles();					// Default constructor 
    ~Circles();
private:
	float	radius;
	int	center_x = 0;
	int	center_y = 0;
};

#endif
