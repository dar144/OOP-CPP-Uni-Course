#include "main.h"

void draw(Drawable *drawable) 
{
    drawable->draw();
}

std::ostream& operator<< (std::ostream& stream, const Point& point) 
{
    return stream << "(" << point.getX() << ", " << point.getY() << ")";
}