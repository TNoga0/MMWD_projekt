#include <iostream>
#include "zlecenie.hpp"
using namespace std;


int main()
{
    cout << "siemanko\n" <<endl;
    bool k;
    zlecenie firma1(8,7,3);
    //firma1.show_lista();
    cout<<"\n\n\n";
    k=firma1.WczytajzPliku("lista.txt","tankowanie.txt","odleglosc.txt","czasy.txt","oplata.txt",8);
       if(k!=0)
        firma1.show_lista();
        firma1.InitialSolution();
        firma1.test();
      cout<<"\n";
    firma1.generuj_tabu();
    firma1.wykonaj_sasiedztwo();






        firma1.usun();

    return 0;
}
