#ifndef FIRMA_HPP_INCLUDED
#define FIRMA_HPP_INCLUDED
#include "taboo.hpp"

class firma //: public taboo
{
private:
    int rozmiar;  //ilosc miast
    int **lista_przewozowa;
    int **koszt_tankowania;
    int **odleglosci;
    int **czasy_przelotow;
    int ile_samolotow;
    int *oplata_lotniskowa;

public:
    firma();
    ~firma();
    void usun();
    void show_lista(); //pokazuje liste przewozowa i liczbe samolotow
    bool WczytajzPliku(std:: string plikLista, std:: string PlikTankowanie,std:: string plikOdl,
    std:: string plikCzasy,std:: string plikOplata, int rozmiarTabl);
    firma(int n, int maxliczba,int ileSamolotow);  //wczytanie losowe
    firma(int n, int ileSamolotow);  //wczytanie pustej listy
};


#endif // FIRMA_HPP_INCLUDED
