#include <iostream>
#include "zlecenie.hpp"
using namespace std;


int main()
{
    bool k;
    zlecenie firma1(8,7,3);
    //firma1.show_lista();
    cout<<"\n\n\n";
    k=firma1.WczytajzPliku("lista.txt","tankowanie.txt","odleglosc.txt","czasy.txt","oplata.txt",8);
       if(k!=0)
        firma1.show_lista();
        firma1.InitialSolution();
        firma1.test();
        firma1.czyscplik();
        firma1.dopliku();
      cout<<"\n";
    firma1.generuj_tabu();
    for(int i=0;i<100;i++)
    {
        cout<<"\nSasiedztwo: \n";
        firma1.wykonaj_sasiedztwo();
        
        cout<<"\nZLOTA RACZKA:\n";
        firma1.zlota_raczka();
        firma1.dekremTabu();
        firma1.test();
        firma1.dopliku();
        cout<<"\niteracja:"<<i<<"\n";
    }

        firma1.usun();

    return 0;
}
