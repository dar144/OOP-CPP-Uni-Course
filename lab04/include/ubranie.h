#pragma once

#include "zelazko.h"


class Ubranie: public Produkt {
    public:
        void Prasuj(Zelazko z) {
            if(pogniecione_wyprasowane == 0) {
                if(z.getAktTemp() <= max_temp) {
                    std::cout << "---Prasuje " << nazwa << " zelazkiem o temp. " << z.getAktTemp() << "." << std::endl;
                    pogniecione_wyprasowane = 1;
                }
                else 
                    std::cout << "Zelazko za gorace." << std::endl;
            }
            else 
                std::cout << "--Ubranie nie wymaga prasowania." << std::endl;
        } 
        void Pogniec() {
            if(pogniecione_wyprasowane == 1) pogniecione_wyprasowane = 0;
        }

 
        Ubranie(std::string n, double c, int m_t): Produkt(n, c, m_t), pogniecione_wyprasowane(0) {}
        
        void Wypisz() {
            std::cout << nazwa << " cena: " << cena;
            if(pogniecione_wyprasowane == 0)
                std::cout << ". Pogniecione. ";
            else
                std::cout << ". Wyprasowane. ";
        }

    protected:

        bool pogniecione_wyprasowane;    
};


class Koszula: public Ubranie {
    public:

        Koszula(std::string n, double c, int m_t, bool r): Ubranie(n, c, m_t), rekaw(r) {}
        
        void SkrocRekawy() {
            if(rekaw == 1)
                rekaw = 0;
            else
                std::cout << "Nie mozna skracac krotkich rekawow." << std::endl; 
        }

        void Wypisz() {
            Ubranie::Wypisz();
            if(rekaw == 0)
                std::cout << "Krotki rekaw." << std::endl;
            else
                std::cout << "Dlugi rekaw." << std::endl;            
        }
    protected:
        bool rekaw;
};


class KoszulaBawelniana: public Koszula {
    public:

        KoszulaBawelniana(double cena, bool r): Koszula("Koszula bawelniana", cena, 7, r) {}
    private:
};


class KoszulaJedwabna: public Koszula {
    public:

        KoszulaJedwabna(double cena, bool r): Koszula("Koszula jedwabna", cena, 3, r) {}
    private:
};



class Spodnie: public Ubranie {
    public:
    Spodnie(std::string n, double c, int m_t): Ubranie(n, c, m_t), kanty(0) {}
    
    void PrasujKanty(Zelazko z) {
        if(kanty == 0) {
            std::cout << "Prasuje kanty " << nazwa << " zelazkiem o temp. " << z.getAktTemp() << "." << std::endl; 
            kanty = 1;
        }
        else {
            std::cout << "Ubranie ma kanty." << std::endl; 
        }
    }


    void Wypisz() {
        Ubranie::Wypisz();
        if(kanty == 0)
            std::cout << "Brak kantow." << std::endl;
        else
            std::cout << "Kanty." << std::endl;            
    }

protected:
    bool kanty;
};

class SpodnieBawelniane: public Spodnie {
    public:
        SpodnieBawelniane(double cena): Spodnie("Spodnie bawelniane", cena, 7) {}
    private: 
};

class SpodnieJedwabne: public Spodnie {
    public:
        SpodnieJedwabne(double cena): Spodnie("Spodnie jedwabne", cena, 3) {}
    private: 
};
