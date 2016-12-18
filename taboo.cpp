#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "taboo.hpp"

taboo:: taboo()
{
    n_zabr = 0;
    n_wyniku = 0;
    zabronienia = NULL;
    best_wynik = NULL;
    tmp_wynik = NULL;
    zaladowanie_samolotu = NULL;
}

taboo::~taboo()
{
   n_zabr = 0;
    n_wyniku = 0;
    zabronienia = NULL;
    best_wynik = NULL;
    tmp_wynik = NULL;
  zaladowanie_samolotu = NULL;
}

void taboo:: oblicz_zaladowanie(int **wynik) //oblicza załadowanie dla każdego z kroków algorytmu
{                  
  for(int w=0;w<3;w++)
    for(int k =0;wynik[w][k+2]='/0';k++)
      if(k=0)
      {
        zaladowanie_samolotu[w][k]=lista_przewozowa[wynik[w][k]-1][wynik[w][k+1]-1];
      }
      else
      {
      zaladowanie_samolotu[w][k]=zaladowanie_samolotu[w][k-1]+lista_przewozowa[wynik[w][k]-1][wynik[w][k+1]-1];
      }
}
  
  
int taboo:: ObliczFCelu(int **rozw)
{
  int temporary_result = 0;
  for(int w=0;w<3;w++)
    for(int k=1;rozw[w][k]='/0';k++)
      temporary_result = temporary_result + oplata_lotniskowa[k-1]+koszt_tankowania[(rozw[w][k-1])-1][(rozw[w][k])-1]+zaladowanie_samolotu[w][k-1]*odleglosci[wynik[w][k-1]-1][wynik[w][k]-1]*spalanie;
}

void taboo:: stworz_sasiedztwo()
{
     for(
    
    
}
