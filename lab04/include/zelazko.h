#pragma once

#include <iostream>
#include <cstring>


class Zelazko: public Produkt {
    public:

        Zelazko(std::string n, double c, int m_t): Produkt(n, c, m_t) {}

 
        void Wypisz() { std::cout << nazwa << " cena: " << cena << " Temperatura: " << akt_temp 
        << " Zakres: " << max_temp << std::endl; } 


        void UstawTemperature(int temp)
        { 
            if(max_temp >= temp)
                akt_temp = temp; 
            else
                std::cout << "Ten model nie obsluguje takiego zakresu temperatur." << std::endl;
        }


        int getAktTemp() const { return akt_temp; }

    protected:

        int akt_temp = 0;
};



class ZelazkoPhilips: public Zelazko {
    public:

        ZelazkoPhilips(double cena): Zelazko("Philips", cena, 5) {} 
};



class ZelazkoTefal: public Zelazko {
    public:

        ZelazkoTefal(double cena): Zelazko("Tefal", cena, 7) {}

};
