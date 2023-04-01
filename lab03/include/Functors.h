#pragma once

class DivisibleBy
{
    public:
        DivisibleBy(int i): divider(i) {}
        bool operator() (int i) { return i % divider == 0 ? true : false; }

    private:
        int divider;
};


class GreaterThan
{
    public:
        GreaterThan(int i): number(i) {}
        bool operator() (int i) { return i > number ? true : false; }

    private: 
        int number;
};
