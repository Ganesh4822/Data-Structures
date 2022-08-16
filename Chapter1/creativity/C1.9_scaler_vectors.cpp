/*
C-1.9 Write a C++ class Vector2, that stores the (x,y) coordinates of a twodimensional vector, where x and y are of type double. Show how to
override various C++ operators in order to implement the addition of two
vectors (producing a vector result), the multiplication of a scalar times
a vector (producing a vector result), and the dot product of two vectors
(producing a double result).
*/

class vector2
{
    private:
        double x;
        double y;

    public:
        vector2(double _x, double _y)
        {
            x = _x;
            y = _y;

        } 
        double operator *(const vector2& vec1)
        {
            return (this->x * vec1.x + this->y  * vec1.x);
        }

        vector2 operator *(double s)
        {
            return vector2(this->x * s, this->y * s );
        }

        vector2 operator +(const vector2& vec)
        {
            return(vector2(this->x + vec.x , this->y + vec.y));
        }
};