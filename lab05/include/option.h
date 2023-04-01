#pragma once


class Drawable {
    public:
        virtual void draw() {}
        virtual double length() { return 0; }
    private:
};

class Transformable {
    public:
        virtual void shift(double, double) {}
    private:
};

class ClosedShape {
    public:
        virtual double area() const { return 0; }
    private:   
};