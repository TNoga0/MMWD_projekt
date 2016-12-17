#ifndef ZLECENIE_HPP_INCLUDED
#define ZLECENIE_HPP_INCLUDED
#include "taboo.hpp"

class zlecenie : public taboo
{
public:
    int rozmiar;  //ilosc miast
    int **lista_przewozowa;
    int **koszt_tankowania;
    int **odleglosci;
    int **czasy_przelotow;
    int ile_samolotow;
    int *oplata_lotniskowa;

public:
    zlecenie();
    ~zlecenie();
    void usun();
    void show_lista(); //pokazuje liste przewozowa i liczbe samolotow
    bool WczytajzPliku(std:: string plikLista, std:: string PlikTankowanie,std:: string plikOdl,
    std:: string plikCzasy,std:: string plikOplata, int rozmiarTabl);
    zlecenie(int n, int maxliczba,int ileSamolotow);  //wczytanie losowe
    zlecenie(int n, int ileSamolotow);  //wczytanie pustej listy
};


#endif // ZLECNIE_HPP_INCLUDED
