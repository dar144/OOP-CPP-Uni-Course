#pragma once

#include <iostream>

class Produkt
{   
    public:
        Produkt(std::string n, double c, int m_t): nazwa(n), cena(c), max_temp(m_t) {}
    protected:
        std::string nazwa;
        double cena;
        int max_temp = 9;
};

