/*
This C++ program defines three classes: 'Point', 'Circle', and 'Cylinder'.
The 'Point' class represents a point in 2D space with x and y coordinates.
It has constructors to initialize the coordinates and getters to access them.

The 'Circle' class represents a circle in 2D space and is defined using its center point (an instance of the 'Point' class) 
and radius. The class contains functions to get the radius and center coordinates of the circle, as well as 
a function to check if a given point lies on the circle.

The 'Cylinder' class represents a cylinder in 3D space. It is defined by its height, two circles (top and bottom) to 
represent the base, and their respective radii. The class includes a constructor to initialize the cylinder and 
functions to get its height. It also has a function to check if a given point lies on the cylinder, either on 
its top and bottom circles or between them along the height.

In the 'main' function, the program demonstrates the usage of these classes.
It creates an instance of the 'Point' class, sets its coordinates, and displays them. It then creates an instance of 
the 'Circle' class, sets its center point and radius, and checks if the previously created point lies on the circle.
Similarly, it creates an instance of the 'Cylinder' class, sets its attributes, and checks if the point lies on the cylinder.
The program then prints the results of these checks.
*/

#include <iostream>
using namespade std;


class Point() {
    private:
        int* x;
        int* y;
    
    public:
        // Constructors, get/set, destructor
        Point(int, int);
        int getX();
        int getY();
        ~Point();
        void display();
        void setX(int);
        void setY(int);

};

Point::Point(int x, int y) {
    this->x = new int;
    this->y = new int;

    *x = x;
    *y = y;
}