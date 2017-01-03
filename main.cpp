#include <iostream>
#include "zlecenie.hpp"



int main()
{
    std::cout << "siemanko\n" << std::endl;
    bool k;
    zlecenie firma1(8,7,3);
    firma1.show_lista();
    std::cout<<"\n\n\n";
    k=firma1.WczytajzPliku("lista.txt","tankowanie.txt","odleglosc.txt","czasy.txt","oplata.txt",8);
       if(k!=0)
        firma1.show_lista();
         
        firma1.InitialSolution();
        //int cosik = firma1.ObliczFCelu(firma1.best_wynik);
        firma1.test();
        //std::cout<<cosik;
    firma1.usun();

    return 0;
}
