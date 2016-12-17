#include <iostream>
#include "firma.hpp"
#include "firma.cpp"


int main()
{
    std::cout << "siemanko\n" << std::endl;
    bool k;
    firma firma1(8,7,3);
    firma firma2(8,3);
    firma1.show_lista();
    std::cout<<"\n";
    firma2.show_lista();
    k=firma2.WczytajzPliku("pliczek.txt",8);
    if(k==0)
        std::cout<<"Wczytanie nieudane :ccccc\n";
    std::cout<<"\n";
    firma2.show_lista();
    firma1.usun();
    firma2.usun();
    return 0;
}
