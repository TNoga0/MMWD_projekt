#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "firma.hpp"

firma:: firma()
{
    rozmiar=0;
    ile_samolotow=0;
    lista_przewozowa=NULL;
}

firma::~firma()
{
    rozmiar=0;
    ile_samolotow=0;
    lista_przewozowa=NULL;
}

firma::firma(int n, int maxliczba, int ileSamolotow)
{
    rozmiar=n;
    ile_samolotow=ileSamolotow;
    srand( time( NULL ) );
    lista_przewozowa = new int * [rozmiar];
    for (int i = 0; i<rozmiar; i++)
	lista_przewozowa[i] = new int [rozmiar];

	for(int i =0; i<rozmiar; i++)
    {
        for (int j =0; j<rozmiar; j++)
            lista_przewozowa[i][j]=( std::rand() % maxliczba );
    }
}

firma::firma(int n, int ileSamolotow)
{
    rozmiar=n;
    ile_samolotow=ileSamolotow;
    lista_przewozowa = new int * [rozmiar];
    for (int i = 0; i<rozmiar; i++)
	lista_przewozowa[i] = new int [rozmiar];
	for(int i =0; i<rozmiar; i++)
    {
        for (int j =0; j<rozmiar; j++)
            lista_przewozowa[i][j]=0;
    }
}

void firma::show_lista()
{
    for(int i =0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar;j++)
            std::cout<<lista_przewozowa[i][j]<<" ";
        std::cout<<"\n";
    }
    std::cout<<"\n"<<"Mamy: "<<ile_samolotow<<" samolotow"<<"\n";
}

void firma::usun()
{
    for (int i = 0; i<rozmiar; i++)
        delete [] lista_przewozowa[i];

delete [] lista_przewozowa;
}

bool firma::WczytajzPliku(std:: string NazwaPliku,int rozmiarTabl)
{
    if(rozmiarTabl!=rozmiar)
        return false;
    int i=0;
    int j=0;
    int n=0;
   std::ifstream plik;
    plik.open( NazwaPliku.c_str() );
    if( !plik.good() )
         return false;
   while( plik >> lista_przewozowa[ i ][ j ] ) {
        if( ++j >= rozmiar ) {
            j = 0;
            i++;
        }
        n++;
        if( n >= 64 ) break;

    }
    plik.close();
    std::cout<<"Wczytano: "<<n<<" wartosci\n";
    return true;
}
