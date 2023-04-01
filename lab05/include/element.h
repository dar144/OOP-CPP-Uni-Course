#pragma once

#include <iostream>
#include <cmath>
#include "option.h"

class Point: public Drawable {
    public:
        Point(double x, double y): _x(x), _y(y) {}

        double getX() const { return _x; }
        double getY() const { return _y; }
        // void setX(double x) { _x = x; }
        void setPosition(double x, double y)
        {
            _x += x;
            _y += y;
        }
    
        double distanse(Point point) const 
        {
            return sqrt(pow(_x - point.getX(), 2) + pow(_y - point.getY(), 2));
        }

        friend std::ostream &operator<< (std::ostream& stream, const Point& point);


    private:
        double _x;
        double _y;
};

class Circle: public Drawable, public ClosedShape, public Transformable {
    public:
        Circle(Point point, double radius): _point(point), _radius(radius) {}

        void draw() override
        {
            std::cout << "Rysujemy kolo o srodku " << _point << " i promieniu " << _radius << std::endl;
        } 

        double length() override
        {
            return 2*M_PI*_radius;
        } 

        void shift(double x, double y) override
        {
            _point.setPosition(x, y);
        }

        double area() const override
        {
            return M_PI * pow(_radius, 2);
        }


    private:
        Point _point;
        double _radius;
};

class Section: public Drawable, public Transformable {
    public:
        Section(Point beggin, Point end): _beginning(beggin), _end(end) {}

        Point getBeginning() const { return _beginning; }
        Point getEnd() const { return _end; }

        void draw() override
        {
            std::cout << "Rysujemy odcinek od " << _beginning << " do " << _end << std::endl;
        } 

        double length() override
        {
            return _beginning.distanse(_end);
        }

        void shift(double x, double y) override
        {
            _beginning.setPosition(x, y);
            _end.setPosition(x, y);
        }


    private:
        Point _beginning;
        Point _end;
};

// Deltoid delt1(diag1, diag2); 		

class Deltoid: public Drawable, public ClosedShape, public Transformable {
    public:
        Deltoid(Section diag1, Section diag2): _diag1(diag1), _diag2(diag2) {}
        Deltoid(Point p1, Point p2, Point p3, Point p4): _diag1(p1, p3), _diag2(p2, p4) {}

        void draw() override
        {
            std::cout << "Rysujemy deltoid o wierzcholkach " << _diag1.getBeginning() << ", " <<
            _diag2.getBeginning() << ", " << _diag1.getEnd() << ", " << _diag2.getEnd() << std::endl;
        } 

        double length() override
        {
            double sum = 0;
            sum += _diag1.getBeginning().distanse(_diag2.getEnd());
            sum += _diag2.getEnd().distanse(_diag1.getEnd());
            sum += _diag1.getEnd().distanse(_diag2.getBeginning());
            sum += _diag2.getBeginning().distanse(_diag1.getBeginning());

            return sum;
        }

        void shift(double x, double y) override
        {
            _diag1.shift(x, y);
            _diag2.shift(x, y);
        }

        double area() const override
        {
            double ar = 1;
            ar *= _diag1.getBeginning().distanse(_diag1.getEnd());
            ar *= _diag2.getBeginning().distanse(_diag2.getEnd());
            return ar;
        }


    private:
        Section _diag1;
        Section _diag2;
};


