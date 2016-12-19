#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "taboo.hpp"
#define ladownosc 25

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
       if(ladunek_samolotu[w][(wynik[w][k])]!=0) zaladowanie_samolotu[w][k
}
									 
void taboo:: oblicz_ladunek(int **wynik)
									 {
										 
									 }
  
  
int taboo:: ObliczFCelu(int **rozw)
{
  int temporary_result = 0;
  for(int w=0;w<3;w++)
    for(int k=1;rozw[w][k]='/0';k++)
      temporary_result = temporary_result + oplata_lotniskowa[k-1]+koszt_tankowania[(rozw[w][k-1])-1][(rozw[w][k])-1]+zaladowanie_samolotu[w][k-1]*odleglosci[wynik[w][k-1]-1][wynik[w][k]-1]*spalanie;
}


int taboo:: sprawdz_dopuszczalnosc(int ** rozw)
{
    int dist_plane1;
    int dist_plane2;
    int dist_plane3;
    
    for(int k=0;k<n_wyniku-2;k++)
    {
        dist_plane1 = odleglosci[rozw[0][k]][rozw[0][k+1]];
        dist_plane2 = odleglosci[rozw[1][k]][rozw[1][k+1]];
        dist_plane3 = odleglosci[rozw[2][k]][rozw[2][k+1]];
        if(dist_plane1>dist_plane2 && dist_plane1>dist_plane3 && dist_plane2>dist_plane3)
	{
			
		
	}
    
    }
}



    

void taboo::resizeWynik(int n)
{
    int **nowa = new int * [n];
    for (int i = 0; i<3; i++)
    {

        nowa[i] = new int [n];
    }
    for(i=0;i<3;i++)
    {
        for(int j=0;j<n_wyniku;j++)
            nowa[i][j]=tmp_wynik[i][j];
            nowa[i][n]=0;
    }
    for (i = 0; i<3; i++)
        delete [] tmp_wynik[i];
    delete [] tmp_wynik;
    tmp_wynik=nowa;
    n_wyniku=n;
}

bool taboo::czyNiePuste()
{
    int k=0;
    for(int i=0,i<rozmiar;i++)
        {
        for(int j=0;j<rozmiar;j++)
            {
                if(lista_przewozowa[i][j]!=0)
                    k=1;
            }
        }
     if(k==1)
        return true
    if(k==0)
        return false;
}

void taboo::InitialSolution()
{
    int n_wyniku=1;
    int **tmp_wynik = new int * [n_wyniku];
    for (int i = 0; i<3; i++)
    {

        nowa[i] = new int [n];
    }
    int **temp1;
    int **temp2;
    int **temp3;

    temp1 = new int * [rozmiar];
    temp2 = new int * [rozmiar];
    temp3 = new int[rozmiar];
    for (int i = 0; i<rozmiar; i++)
    {
        temp1[i] = new int [rozmiar];
        temp2[i] = new int [rozmiar];
        temp3[i] = new int [rozmiar];
    }

	for(int i =0; i<rozmiar; i++)
    {
        for (int j =0; j<rozmiar; j++)
        {
            temp1[i][j]=0;
            temp2[i][j]=0;
            temp3[i][j]=0;

        }
    }
    int counter=0;
    int wziete=0;
    int wziete1=0;
    //duza petla
    while(czyNiePuste())
    {
        while((wziete1<3*ladownosc)&&czyNiePuste())
        {
            while(wziete<ladownosc)   //1 samolot
            {
                for(int i =0; i<rozmiar; i++)
                {
                    for (int j =0; j<rozmiar; j++)
                    {
                       if(lista_przewozowa[i][j]!=0)
                       {
                           if((wziete+lista_przewozowa[i][j])<=ladownosc)
                           {
                               temp1[i][j]=lista_przewozowa[i][j];
                               wziete=wziete+lista_przewozowa[i][j];
                               lista_przewozowa[i][j]=0;
                           }
                           else
                           {
                               if(wziete==25)
                                {
                                    //gowno robi
                                }
                               else
                                {
                                 temp1[i][j]=(lista_przewozowa[i][j]-(wziete+lista_przewozowa[i][j]-ladownosc));
                                 wziete=25;
                                 lista_przewozowa[i][j]=(wziete+lista_przewozowa[i][j]-ladownosc);
                                }

                           }
                       }

                    }
                }
            }
            wziete1=wziete1+wziete;
            wziete=0;
            while(wziete<ladownosc)   //2 samolot
            {
                for(int i =0; i<rozmiar; i++)
                {
                    for (int j =0; j<rozmiar; j++)
                    {
                       if(lista_przewozowa[i][j]!=0)
                       {
                           if((wziete+lista_przewozowa[i][j])<=ladownosc)
                           {
                               temp2[i][j]=lista_przewozowa[i][j];
                               wziete=wziete+lista_przewozowa[i][j];
                               lista_przewozowa[i][j]=0;
                           }
                           else
                           {
                               if(wziete==25)
                                {
                                    //gowno robi
                                }
                               else
                                {
                                 temp2[i][j]=(lista_przewozowa[i][j]-(wziete+lista_przewozowa[i][j]-ladownosc));
                                 wziete=25;
                                 lista_przewozowa[i][j]=(wziete+lista_przewozowa[i][j]-ladownosc);
                                }

                           }
                       }

                    }
                }
            }

            wziete1=wziete1+wziete;
            wziete=0;
            while(wziete<ladownosc)   //3 samolot
            {
                for(int i =0; i<rozmiar; i++)
                {
                    for (int j =0; j<rozmiar; j++)
                    {
                       if(lista_przewozowa[i][j]!=0)
                       {
                           if((wziete+lista_przewozowa[i][j])<=ladownosc)
                           {
                               temp3[i][j]=lista_przewozowa[i][j];
                               wziete=wziete+lista_przewozowa[i][j];
                               lista_przewozowa[i][j]=0;
                           }
                           else
                           {
                               if(wziete==25)
                                {
                                    //gowno robi
                                }
                               else
                                {
                                 temp3[i][j]=(lista_przewozowa[i][j]-(wziete+lista_przewozowa[i][j]-ladownosc));
                                 wziete=25;
                                 lista_przewozowa[i][j]=(wziete+lista_przewozowa[i][j]-ladownosc);
                                }

                           }
                       }

                    }
                }
            }
           wziete1=wziete1+wziete;
           wziete=0;


        }








    }
}



