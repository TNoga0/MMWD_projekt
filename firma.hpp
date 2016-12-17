#ifndef FIRMA_HPP_INCLUDED
#define FIRMA_HPP_INCLUDED
//#inclue "taboo.hpp"

class firma //: public taboo
{
private:
    int rozmiar;  //ilosc miast
    int **lista_przewozowa;
    int ile_samolotow;

public:
    firma();
    ~firma();
    void usun();
    void show_lista(); //pokazuje liste przewozowa i liczbe samolotow
    bool WczytajzPliku (std:: string NazwaPliku,int rozmiarTabl); //wczytanie z pliku
    firma(int n, int maxliczba,int ileSamolotow);  //wczytanie losowe
    firma(int n, int ileSamolotow);  //wczytanie pustej listy
};


#endif // FIRMA_HPP_INCLUDED
