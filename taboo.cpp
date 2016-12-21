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
	int ** tmp_przewozowa;
	tmp_przewozowa = lista_przewozowa; //pewnie trzeba będzie elemwnt-wise przekopiować
    int dist_plane1;
    int dist_plane2;
    int dist_plane3;
    int zapelnienie[3]; //jak bardzo sumarycznie zapelniony jest dany samolot w danej iteracji;
	
	for(int i=1;i<n_wyniku-1;i++) //nie wiem czy drugi warunek ok
	{
	ladunek_samolotu[0][rozw[0][i]-1] = tmp_przewozowa[(rozw[0][0])-1)][(rozw[0][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
	tmp_przewozowa[(rozw[0][0])-1)][(rozw[0][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
	zapelnienie[0]=zapelnienie[0]+ladunek_samolotu[0][rozw[0][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
		if(zapelnienie[0]>=25)
		{
			tmp=zapelnienie[0]-25; //tmp żeby było wiadomo ile ponad stan odjąć
			tmp_przewozowa[(rozw[0][0])-1)][(rozw[0][i])-1] = tmp_przewozowa[(rozw[0][0])-1)][(rozw[0][i])-1]+tmp; //dodaję do przewozowej
			ladunek_samolotu[0][rozw[0][i]-1] = ladunek_samolotu[0][rozw[0][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
			i=n_wyniku-1;//żeby wyjść z pętli
		}
	}
	
	for(int j=1;j<n_wyniku-1;j++)
	{
	ladunek_samolotu[1][rozw[1][j]-1] = tmp_przewozowa[(rozw[1][0])-1][(rozw[1][j])-1];
	tmp_przewozowa[(rozw[1][0])-1)][(rozw[1][j])-1] = 0;
	zapelnienie[1]=zapelnienie[1]+ladunek_samolotu[1][rozw[1][j]];
		
		if(zapelnienie[1]>=25)
		{
			tmp=zapelnienie[1]-25;
			tmp_przewozowa[(rozw[1][0])-1)][(rozw[1][j])-1] = tmp_przewozowa[(rozw[1][0])-1)][(rozw[1][j])-1]+tmp;
			ladunek_samolotu[1][rozw[1][j]-1] = ladunek_samolotu[1][rozw[1][j]-1]-tmp;
			j=n_wyniku-1;
		}
	}
	
	for(int k=1;k<n_wyniku-1;k++)
	{
	ladunek_samolotu[2][rozw[2][k]-1] = tmp_przewozowa[(rozw[2][0])-1][(rozw[2][k])-1];
	tmp_przewozowa[(rozw[2][0])-1)][(rozw[2][k])-1] = 0;
	zapelnienie[2]=zapelnienie[2]+ladunek_samolotu[2][rozw[2][k]];
		if(zapelnienie[2]>=25)
		{
			tmp=zapelnienie[2]-25;
			tmp_przewozowa[(rozw[2][0])-1)][(rozw[2][k])-1] = tmp_przewozowa[(rozw[2][0])-1)][(rozw[2][k])-1]+tmp;
			ladunek_samolotu[2][rozw[2][k]-1] = ladunek_samolotu[2][rozw[2][k]-1]-tmp;
			k=n_wyniku-1;
		}
		
	}
	
	//-------------------------------------------------- po pierwsze jiteracji
    for(int k=0;k<n_wyniku-2;k++)
    {
        dist_plane1 = odleglosci[rozw[0][k]][rozw[0][k+1]]; //odległość do kolejnego lotniska 1 samolotu, ma to na celu determinowanie który doleci pierwszy jeśli lecą na to samo lotnisko
        dist_plane2 = odleglosci[rozw[1][k]][rozw[1][k+1]];
        dist_plane3 = odleglosci[rozw[2][k]][rozw[2][k+1]];
        if(dist_plane1<=dist_plane2 && dist_plane1<=dist_plane3) //inaczej to będzie //sprawedzanie który doleci 1 na miejsce
	{
		//rozładunek samolotu (pierwszego)
		ladunek_samolotu[0][rozw[0][k+1]]=0; 
		//załadunek pierwszego samolotu
		if(zapelnienie[0]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
		{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[0][rozw[0][i]-1] = tmp_przewozowa[(rozw[0][k+1])-1][(rozw[0][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[0]=zapelnienie[0]+ladunek_samolotu[0][rozw[0][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[0]>=25)
				{
					tmp=zapelnienie[0]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1] = tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[0][rozw[0][i]-1] = ladunek_samolotu[0][rozw[0][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
		}
		
		if(dist_plane2<=dist_plane3)
		{
			ladunek_samolotu[1][rozw[1][k+1]]=0; 
			if(zapelnienie[1]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
			{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[1][rozw[1][i]-1] = tmp_przewozowa[(rozw[1][k+1])-1][(rozw[1][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[1]=zapelnienie[1]+ladunek_samolotu[1][rozw[1][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[1]>=25)
				{
					tmp=zapelnienie[1]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1] = tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[1][rozw[1][i]-1] = ladunek_samolotu[1][rozw[1][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
			}
			//oprozniamy trzeci samolot
			ladunek_samolotu[2][rozw[2][k+1]]=0; 
			if(zapelnienie[2]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
			{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[2][rozw[2][i]-1] = tmp_przewozowa[(rozw[2][k+1])-1][(rozw[2][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[2]=zapelnienie[2]+ladunek_samolotu[2][rozw[2][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[2]>=25)
				{
					tmp=zapelnienie[2]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1] = tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[2][rozw[2][i]-1] = ladunek_samolotu[2][rozw[2][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
			}
			
		} //sprawdzić czy dobra ilość klamerek, bo coś SIĘ MOGŁO POPIERDOLIĆ
		else
		{
			//oprozniamy trzeci samolot
			ladunek_samolotu[2][rozw[2][k+1]]=0; 
			if(zapelnienie[2]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
			{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[2][rozw[2][i]-1] = tmp_przewozowa[(rozw[2][k+1])-1][(rozw[2][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[2]=zapelnienie[2]+ladunek_samolotu[2][rozw[2][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[2]>=25)
				{
					tmp=zapelnienie[2]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1] = tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[2][rozw[2][i]-1] = ladunek_samolotu[2][rozw[2][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
			}
			ladunek_samolotu[1][rozw[1][k+1]]=0; 
			if(zapelnienie[1]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
			{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[1][rozw[1][i]-1] = tmp_przewozowa[(rozw[1][k+1])-1][(rozw[1][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[1]=zapelnienie[1]+ladunek_samolotu[1][rozw[1][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[1]>=25)
				{
					tmp=zapelnienie[1]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1] = tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[1][rozw[1][i]-1] = ladunek_samolotu[1][rozw[1][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
			}
		}
		
	}
    	else if(dist_plane2<=dist_plane1 && dist_plane2<=dist_plane3)
	{
	    ladunek_samolotu[1][rozw[1][k+1]]=0; 
		if(zapelnienie[1]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
		{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[1][rozw[1][i]-1] = tmp_przewozowa[(rozw[1][k+1])-1][(rozw[1][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[1]=zapelnienie[1]+ladunek_samolotu[1][rozw[1][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[1]>=25)
				{
					tmp=zapelnienie[1]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1] = tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[1][rozw[1][i]-1] = ladunek_samolotu[1][rozw[1][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
		}
	    if(dist_plane1<=dist_plane3)	   
	    {
		    //rozładunek samolotu (pierwszego)
		ladunek_samolotu[0][rozw[0][k+1]]=0; 
		//załadunek pierwszego samolotu
		if(zapelnienie[0]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
		{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[0][rozw[0][i]-1] = tmp_przewozowa[(rozw[0][k+1])-1][(rozw[0][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[0]=zapelnienie[0]+ladunek_samolotu[0][rozw[0][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[0]>=25)
				{
					tmp=zapelnienie[0]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1] = tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[0][rozw[0][i]-1] = ladunek_samolotu[0][rozw[0][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
		}
		//oprozniamy trzeci samolot
			ladunek_samolotu[2][rozw[2][k+1]]=0; 
			if(zapelnienie[2]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
			{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[2][rozw[2][i]-1] = tmp_przewozowa[(rozw[2][k+1])-1][(rozw[2][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[2]=zapelnienie[2]+ladunek_samolotu[2][rozw[2][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[2]>=25)
				{
					tmp=zapelnienie[2]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1] = tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[2][rozw[2][i]-1] = ladunek_samolotu[2][rozw[2][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
			}
		    
		    
	    }
	    else
	    {
		    ladunek_samolotu[2][rozw[2][k+1]]=0; 
			if(zapelnienie[2]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
			{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[2][rozw[2][i]-1] = tmp_przewozowa[(rozw[2][k+1])-1][(rozw[2][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[2]=zapelnienie[2]+ladunek_samolotu[2][rozw[2][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[2]>=25)
				{
					tmp=zapelnienie[2]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1] = tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[2][rozw[2][i]-1] = ladunek_samolotu[2][rozw[2][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
			}
		        //rozładunek samolotu (pierwszego)
		ladunek_samolotu[0][rozw[0][k+1]]=0; 
		//załadunek pierwszego samolotu
		if(zapelnienie[0]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
		{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[0][rozw[0][i]-1] = tmp_przewozowa[(rozw[0][k+1])-1][(rozw[0][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[0]=zapelnienie[0]+ladunek_samolotu[0][rozw[0][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[0]>=25)
				{
					tmp=zapelnienie[0]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1] = tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[0][rozw[0][i]-1] = ladunek_samolotu[0][rozw[0][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
		}
		    
		    
		    //...
	    }
	    
	}  
	else if(dist_plane3<=dist_plane1 && dist_plane3<=dist_plane2)
	{
		 ladunek_samolotu[2][rozw[2][k+1]]=0; 
			if(zapelnienie[2]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
			{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[2][rozw[2][i]-1] = tmp_przewozowa[(rozw[2][k+1])-1][(rozw[2][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[2]=zapelnienie[2]+ladunek_samolotu[2][rozw[2][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[2]>=25)
				{
					tmp=zapelnienie[2]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1] = tmp_przewozowa[(rozw[2][k+1])-1)][(rozw[2][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[2][rozw[2][i]-1] = ladunek_samolotu[2][rozw[2][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
			}
		if(dist_plane1<=dist_plane2)
		{
			      //rozładunek samolotu (pierwszego)
		ladunek_samolotu[0][rozw[0][k+1]]=0; 
		//załadunek pierwszego samolotu
		if(zapelnienie[0]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
		{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[0][rozw[0][i]-1] = tmp_przewozowa[(rozw[0][k+1])-1][(rozw[0][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[0]=zapelnienie[0]+ladunek_samolotu[0][rozw[0][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[0]>=25)
				{
					tmp=zapelnienie[0]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1] = tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[0][rozw[0][i]-1] = ladunek_samolotu[0][rozw[0][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
		}
		ladunek_samolotu[1][rozw[1][k+1]]=0; 
		if(zapelnienie[1]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
		{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[1][rozw[1][i]-1] = tmp_przewozowa[(rozw[1][k+1])-1][(rozw[1][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[1]=zapelnienie[1]+ladunek_samolotu[1][rozw[1][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[1]>=25)
				{
					tmp=zapelnienie[1]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1] = tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[1][rozw[1][i]-1] = ladunek_samolotu[1][rozw[1][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
		}	
		else
		{
			ladunek_samolotu[1][rozw[1][k+1]]=0; 
		if(zapelnienie[1]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
		{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[1][rozw[1][i]-1] = tmp_przewozowa[(rozw[1][k+1])-1][(rozw[1][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[1]=zapelnienie[1]+ladunek_samolotu[1][rozw[1][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[1]>=25)
				{
					tmp=zapelnienie[1]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1] = tmp_przewozowa[(rozw[1][k+1])-1)][(rozw[1][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[1][rozw[1][i]-1] = ladunek_samolotu[1][rozw[1][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
		}	
		}
			ladunek_samolotu[0][rozw[0][k+1]]=0; 
		//załadunek pierwszego samolotu
		if(zapelnienie[0]<25) //jesli miejsce w samolocie to ta sama funkcja zapełniająca co dla 1 iteracji, ale zwiększone i
		{
			for(i=k+2;i<n_wyniku-1;i++)
			{
				ladunek_samolotu[0][rozw[0][i]-1] = tmp_przewozowa[(rozw[0][k+1])-1][(rozw[0][i])-1]; //wrzucam paczki do pierwszego lotniska w kolejności. Koniecznie pierwsza współrzędna listy przewozowej stała bo biorę tylko z jednego lotniska
				tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1] = 0; //zeruję pole listy przewozowej, bo na początek wrzucam do samolotu wszystkie paczki do danego lotniska
				zapelnienie[0]=zapelnienie[0]+ladunek_samolotu[0][rozw[0][i]-1]; //dorzucam do sumarycznego zapełnienia ilość paczek
	
				if(zapelnienie[0]>=25)
				{
					tmp=zapelnienie[0]-25; //tmp żeby było wiadomo ile ponad stan odjąć
					tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1] = tmp_przewozowa[(rozw[0][k+1])-1)][(rozw[0][i])-1]+tmp; //dodaję do przewozowej
					ladunek_samolotu[0][rozw[0][i]-1] = ladunek_samolotu[0][rozw[0][i]-1]-tmp; //odejmuję z zapełnienia w danej iteracji od tego miejsca gdzie się przepełniło
					i=n_wyniku-1;//żeby wyjść z pętli
				}
			}	
		}
			
			
			
		}
		
	}
		
    }
	for(int w=0;w<8;w++)
		for(int k=0;k<8;k++)
			if(tmp_przewozowa[w][k]!=0) return 0;	
			else {}
	
	for(w=0;w<3;w++)
		for(int k=0;k<8;k++)
			if(ladunek_samolotu[w][k]!=0) return 0;
			else {}
				
				
	return 1;
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

void taboo::resizeZaladowanie(int n)
{
    int **nowa = new int * [n];
    for (int i = 0; i<3; i++)
    {

        nowa[i] = new int [n];
    }
    for(i=0;i<3;i++)
    {
        for(int j=0;j<n-1;j++)
            nowa[i][j]=zaladowanie_samolotu[i][j];
            nowa[i][n]=zaladowanie_samolotu[i][n-1];
    }
    for (i = 0; i<3; i++)
        delete [] zaladowanie_samolotu[i];
    delete [] zaladowanie_samolotu;
    zaladowanie_samolotu=nowa;

}
									 
									 
bool taboo::czyNiePuste(int **tab)
{
    int k=0;
    for(int i=0,i<rozmiar;i++)
        {
        for(int j=0;j<rozmiar;j++)
            {
                if(tab[i][j]!=0)
                    k=1;
            }
        }
     if(k==1)
        return true
    if(k==0)
        return false;
}
									 
int taboo::maximum(int *tab)
{
    int tmp=0;
    int wiersz;
    for(int i=0;i<rozmiar;i++)
    {
        if(tab[i]>tmp)
        {
             tmp=tab[i];
             wiersz=i;
        }

    }
    return wiersz;
}


void taboo::InitialSolution()
{
    int n_wyniku=1;
    int ktoraiteracja=0;
    int **tmp_wynik = new int * [n_wyniku];
    for (int i = 0; i<3; i++)
    {

        nowa[i] = new int [n_wyniku];
    }
    int *temp1;
    int *temp2;
    int *temp3;

    temp1 = new int[rozmiar];
    temp2 = new int[rozmiar];
    temp3 = new int[rozmiar];

	for(int i =0; i<rozmiar; i++)
    {
            temp1[i]=0;
            temp2[i]=0;
            temp3[i]=0;

    }
    int counter=0;
    int odkad1=0;
    int odkad2=0;
    int odkad3=0;
    //duza petla
    while(czyNiePuste(lista_przewozowa))
    {
        while(((zaladowanie_samolotu[0][ktoraiteracja]+zaladowanie_samolotu[1][ktoraiteracja]+zaladowanie_samolotu[2][ktoraiteracja])<3*ladownosc)&&czyNiePuste())
        {
            while((zaladowanie_samolotu[0][ktoraiteracja])<ladownosc)   //1 samolot
            {
                for(int i =odkad1; i<rozmiar; i++)
                {
                    for (int j =0; j<rozmiar; j++)
                    {
                       if(lista_przewozowa[i][j]!=0)
                       {
                           if(((zaladowanie_samolotu[0][ktoraiteracja])+lista_przewozowa[i][j])<=ladownosc)
                           {
                               temp1[j]=lista_przewozowa[i][j];
                               zaladowanie_samolotu[0][ktoraiteracja]=zaladowanie_samolotu[0][ktoraiteracja]+lista_przewozowa[i][j];
                               lista_przewozowa[i][j]=0;
                           }
                           else
                           {
                               if(zaladowanie_samolotu[0][ktoraiteracja]==25)
                                {
                                    //nic nie robi
                                }
                               else
                                {
                                 temp1[j]=(lista_przewozowa[i][j]-(zaladowanie_samolotu[0][ktoraiteracja]+lista_przewozowa[i][j]-ladownosc));
                                 zaladowanie_samolotu[0][ktoraiteracja]=25;
                                 lista_przewozowa[i][j]=(zaladowanie_samolotu[0][ktoraiteracja]+lista_przewozowa[i][j]-ladownosc);
                                }

                           }
                       }

                    }
                }
            }

            while((zaladowanie_samolotu[1][ktoraiteracja])<ladownosc)   //2 samolot
            {
                for(int i =odkad2; i<rozmiar; i++)
                {
                    for (int j =0; j<rozmiar; j++)
                    {
                       if(lista_przewozowa[i][j]!=0)
                       {
                           if((zaladowanie_samolotu[1][ktoraiteracja]+lista_przewozowa[i][j])<=ladownosc)
                           {
                               temp2[j]=lista_przewozowa[i][j];
                               zaladowanie_samolotu[1][ktoraiteracja]=zaladowanie_samolotu[1][ktoraiteracja]+lista_przewozowa[i][j];
                               lista_przewozowa[i][j]=0;
                           }
                           else
                           {
                               if(zaladowanie_samolotu[1][ktoraiteracja]==25)
                                {
                                    //nic nie robi
                                }
                               else
                                {
                                 temp2[j]=(lista_przewozowa[i][j]-(zaladowanie_samolotu[1][ktoraiteracja]+lista_przewozowa[i][j]-ladownosc));
                                 zaladowanie_samolotu[1][ktoraiteracja]=25;
                                 lista_przewozowa[i][j]=(zaladowanie_samolotu[1][ktoraiteracja]+lista_przewozowa[i][j]-ladownosc);
                                }

                           }
                       }

                    }
                }
            }


            while((zaladowanie_samolotu[2][ktoraiteracja])<ladownosc)   //3 samolot
            {
                for(int i =odkad3; i<rozmiar; i++)
                {
                    for (int j =0; j<rozmiar; j++)
                    {
                       if(lista_przewozowa[i][j]!=0)
                       {
                           if((zaladowanie_samolotu[2][ktoraiteracja]+lista_przewozowa[i][j])<=ladownosc)
                           {
                               temp3[j]=lista_przewozowa[i][j];
                               zaladowanie_samolotu[2][ktoraiteracja]=zaladowanie_samolotu[2][ktoraiteracja]+lista_przewozowa[i][j];
                               lista_przewozowa[i][j]=0;
                           }
                           else
                           {
                               if(zaladowanie_samolotu[2][ktoraiteracja]==25)
                                {
                                    //nic nie robi
                                }
                               else
                                {
                                 temp3[j]=(lista_przewozowa[i][j]-(zaladowanie_samolotu[2][ktoraiteracja]+lista_przewozowa[i][j]-ladownosc));
                                 zaladowanie_samolotu[2][ktoraiteracja]25;
                                 lista_przewozowa[i][j]=(zaladowanie_samolotu[2][ktoraiteracja]+lista_przewozowa[i][j]-ladownosc);
                                }

                           }
                       }

                    }
                }
            }



        }
        ktoraiteracja++;
//wyladowywanie

//samolot1
        if(czyNiePuste(temp1))
        {
        odkad1=maximum(temp1);
        tmp_wynik[0][n_wyniku-1]=odkad1;
        zaladowanie_samolotu[0][n_wyniku-1]=zaladowanie_samolotu[0][n_wyniku-1]-temp1[odkad1];
        temp1[odkad1]=0;
        }
        else{
            tmp_wynik[0][n_wyniku-1]=0;
        }
//samolot2
        if(czyNiePuste(temp2))
        {
        odkad2=maximum(temp2);
        tmp_wynik[1][n_wyniku-1]=odkad2;
        zaladowanie_samolotu[1][n_wyniku-1]=zaladowanie_samolotu[1][n_wyniku-1]-temp2[odkad2];
        temp2[odkad2]=0;
        }
        else{
            tmp_wynik[1][n_wyniku-1]=0;
        }
//samolot3
         if(czyNiePuste(temp3))
        {
        odkad3=maximum(temp3);
        tmp_wynik[2][n_wyniku-1]=odkad3;
        zaladowanie_samolotu[2][n_wyniku-1]=zaladowanie_samolotu[2][n_wyniku-1]-temp3[odkad3];
        temp3[odkad3]=0;
        }
        else{
            tmp_wynik[2][n_wyniku-1]=0;
        }

        resizeWynik(n_wyniku+1);
        resizeZaladowanie(n_wyniku+1);





    }

    while(czyNiePuste(temp1))
        {
        odkad1=maximum(temp1);
        tmp_wynik[0][n_wyniku-1]=odkad1;
        zaladowanie_samolotu[0][n_wyniku-1]=zaladowanie_samolotu[0][n_wyniku-1]-temp1[odkad1];
        temp1[odkad1]=0;
        }
    while(czyNiePuste(temp2))
        {
        odkad2=maximum(temp2);
        tmp_wynik[1][n_wyniku-1]=odkad2;
        zaladowanie_samolotu[1][n_wyniku-1]=zaladowanie_samolotu[1][n_wyniku-1]-temp2[odkad2];
        temp2[odkad2]=0;
        }
    while(czyNiePuste(temp3))
        {
        odkad3=maximum(temp3);
        tmp_wynik[2][n_wyniku-1]=odkad3;
        zaladowanie_samolotu[2][n_wyniku-1]=zaladowanie_samolotu[2][n_wyniku-1]-temp3[odkad3];
        temp3[odkad3]=0;
        }

    best_wynik = new int * [n_wyniku];
    for (int i = 0; i<3; i++)
    {

        best_wynik[i] = new int [n_wyniku];
    }
    for(i=0;i<3;i++)
    {
        for(int j=0;j<n_wyniku;j++)
            best_wynik[i][j]=tmp_wynik[i][j];

    }
    for (i = 0; i<3; i++)
        delete [] tmp_wynik[i];
    delete [] tmp_wynik;



}


