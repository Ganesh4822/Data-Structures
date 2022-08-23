/*
P-2.5 Write a C++ program that has a Polygon interface that has abstract functions, area(), and perimeter(). Implement classes for Triangle, Quadrilateral, Pentagon, Hexagon, and Octagon, which implement this interface, with the obvious meanings for the area() and perimeter() functions.
Also implement classes, IsoscelesTriangle, EquilateralTriangle, Rectangle, and Square, which have the appropriate inheritance relationships. Finally, write a simple user interface that allows users to create polygons of
the various types, input their geometric dimensions, and then output their
area and perimeter. For extra effort, allow users to input polygons by specifying their vertex coordinates and be able to test if two such polygons are
similar.
*/


//TODO

#include<iostream>

class polygon
{
    public:
        virtual double area() = 0;
        virtual double perimeter() = 0;
};

class Triangle : public polygon
{
    
};

class Quadrilateral: public polygon
{

};

class pentagon : public polygon
{

};

class hexagon : public polygon
{

};

//Class Triagle derived functions

class EquilateralTriangle : public Triangle
{

};

class IsoscelesTriangle : public Triangle
{

};


//class square derived classes

class Rectangle : public Quadrilateral 
{

};

class Square : public Quadrilateral
{

};

