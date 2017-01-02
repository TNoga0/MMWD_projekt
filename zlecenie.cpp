#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "zlecenie.hpp"


zlecenie:: zlecenie()
{
    rozmiar=0;
    ile_samolotow=0;
    lista_przewozowa=NULL;
    koszt_tankowania=NULL;
    odleglosci=NULL;
    czasy_przelotow=NULL;
    oplata_lotniskowa=NULL;
    n_zabr=0;
    zabronienia=NULL;
    n_wyniku=0;
    best_wynik=NULL;
    tmp_wynik=NULL;
    zaladowanie_samolotu=NULL;
    sasiedztwo=NULL;
    ladunek_samolotu=NULL;
}

zlecenie::~zlecenie()
{
    rozmiar=0;
    ile_samolotow=0;
    lista_przewozowa=NULL;
    koszt_tankowania=NULL;
    odleglosci=NULL;
    czasy_przelotow=NULL;
    oplata_lotniskowa=NULL;
     n_zabr=0;
    zabronienia=NULL;
    n_wyniku=0;
    best_wynik=NULL;
    tmp_wynik=NULL;
    zaladowanie_samolotu=NULL;
    sasiedztwo=NULL;
    ladunek_samolotu=NULL;
}


zlecenie::zlecenie(int n, int maxliczba, int ileSamolotow)
{
    rozmiar=n;
    ile_samolotow=ileSamolotow;
    srand( time( NULL ) );
    lista_przewozowa = new int * [rozmiar];
    koszt_tankowania = new int * [rozmiar];
    odleglosci = new int * [rozmiar];
    czasy_przelotow = new int * [rozmiar];
    oplata_lotniskowa = new int[rozmiar];
    for (int i = 0; i<rozmiar; i++)
    {
        lista_przewozowa[i] = new int  [rozmiar];
        koszt_tankowania[i] = new int  [rozmiar];
        odleglosci[i] = new int  [rozmiar];
        czasy_przelotow[i] = new int  [rozmiar];

    }


	for(int i =0; i<rozmiar; i++)
    {
        for (int j =0; j<rozmiar; j++)
        {
            lista_przewozowa[i][j]=( std::rand() % maxliczba );
            koszt_tankowania[i][j]=( std::rand() % 5000+1000 );
            odleglosci[i][j]=( std::rand() % 1500 );
            czasy_przelotow[i][j]=( std::rand() % 100 );
        }
       oplata_lotniskowa[i]=( std::rand() % 500+100 );
    }
}

zlecenie::zlecenie(int n, int ileSamolotow)
{
    rozmiar=n;
    ile_samolotow=ileSamolotow;
    lista_przewozowa = new int * [rozmiar];
    koszt_tankowania = new int * [rozmiar];
    odleglosci = new int * [rozmiar];
    czasy_przelotow = new int * [rozmiar];
    oplata_lotniskowa = new int[rozmiar];
    for (int i = 0; i<rozmiar; i++)
    {

        lista_przewozowa[i] = new int [rozmiar];
        koszt_tankowania[i] = new int [rozmiar];
        odleglosci[i] = new int [rozmiar];
        czasy_przelotow[i] = new int [rozmiar];
    }

	for(int i =0; i<rozmiar; i++)
    {
        for (int j =0; j<rozmiar; j++)
        {
            lista_przewozowa[i][j]=0;
            koszt_tankowania[i][j]=0;
            odleglosci[i][j]=0;
            czasy_przelotow[i][j]=0;
        }
        oplata_lotniskowa[i]=0;
}
}

void zlecenie::show_lista()
{
    std::cout<<"Lista Przewozowa: \n";
    for(int i =0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar;j++)
            std::cout<<lista_przewozowa[i][j]<<" ";
        std::cout<<"\n";
    }
     std::cout<<"\n";
     std::cout<<"Koszt tankowania: \n";
    for(int i =0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar;j++)
        {
            std::cout.width(6);
            std::cout<<koszt_tankowania[i][j]<<" ";
        }

        std::cout<<"\n";
    }
     std::cout<<"\n";
     std::cout<<"Odleglosci: \n";
    for(int i =0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar;j++)
        {
            std::cout.width(5);
            std::cout<<odleglosci[i][j]<<" ";
        }

        std::cout<<"\n";
    }
     std::cout<<"\n";
     std::cout<<"Czasy przelotow: \n";
    for(int i =0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar;j++)
        {
            std::cout.width(5);
            std::cout<<czasy_przelotow[i][j]<<" ";
        }

        std::cout<<"\n";
    }
     std::cout<<"\n";
     std::cout<<"Oplata lotniskowa: \n";
    for(int i =0;i<rozmiar;i++)
    {
        std::cout.width(5);
    std::cout<<oplata_lotniskowa[i]<<" ";
    }
    std::cout<<"\n";
    std::cout<<"\n"<<"Mamy: "<<ile_samolotow<<" samolotow"<<"\n";
}

void zlecenie::usun()
{
    for (int i = 0; i<rozmiar; i++)
    {

        delete [] lista_przewozowa[i];
        delete [] koszt_tankowania[i];
        delete [] odleglosci[i];
        delete [] czasy_przelotow[i];

    }

delete [] lista_przewozowa;
delete [] koszt_tankowania;
delete [] odleglosci;
delete [] czasy_przelotow;
delete [] oplata_lotniskowa;
}

bool zlecenie::WczytajzPliku(std:: string plikLista, std:: string PlikTankowanie,std:: string plikOdl,
                          std:: string plikCzasy,std:: string plikOplata, int rozmiarTabl)
{
    if(rozmiarTabl!=rozmiar)
        return false;
    int i=0;
    int j=0;
    int n=0;
   std::ifstream przew;
    przew.open( plikLista.c_str() );
    if( !przew.good() )
         return false;
   while( przew >> lista_przewozowa[ i ][ j ] ) {
        if( ++j >= rozmiar ) {
            j = 0;
            i++;
        }
        n++;
        if( n >= (rozmiar*rozmiar) ) break;

    }
    przew.close();

    i=0;
    j=0;
    n=0;
   std::ifstream tank;
    tank.open( PlikTankowanie.c_str() );
    if( !tank.good() )
         return false;
   while( tank >> koszt_tankowania[ i ][ j ] ) {
        if( ++j >= rozmiar ) {
            j = 0;
            i++;
        }
        n++;
        if( n >= (rozmiar*rozmiar) ) break;

    }
    tank.close();

    i=0;
    j=0;
    n=0;
   std::ifstream odl;
    odl.open( plikOdl.c_str() );
    if( !odl.good() )
         return false;
   while( odl >> odleglosci[ i ][ j ] ) {
        if( ++j >= rozmiar ) {
            j = 0;
            i++;
        }
        n++;
        if( n >= (rozmiar*rozmiar) ) break;

    }
    odl.close();

    i=0;
    j=0;
    n=0;
   std::ifstream czas;
    czas.open( plikCzasy.c_str() );
    if( !czas.good() )
         return false;
   while( czas >> czasy_przelotow[ i ][ j ] ) {
        if( ++j >= rozmiar ) {
            j = 0;
            i++;
        }
        n++;
        if( n >= (rozmiar*rozmiar) ) break;

    }
    czas.close();
    i=0;
    j=0;
    n=0;
   std::ifstream hajs;
    hajs.open( plikOplata.c_str() );
    if( !hajs.good() )
         return false;
   while( hajs >> oplata_lotniskowa[ i ] ) {
        i++;
        if( i >=rozmiar ) break;

    }
    hajs.close();

    return true;
}

void zlecenie:: oblicz_zaladowanie(int **wynik) //oblicza za³adowanie dla ka¿dego z kroków algorytmu
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

//int zlecenie:: sprawdz_dopuszczalnosc(int ** rozw)
//{
//    int dist_plane1;
//    int dist_plane2;
 //   int dist_plane3;

   // for(int k=0;k<n_wyniku-2;k++)
    //{
      //  dist_plane1 = odleglosci[rozw[0][k]][rozw[0][k+1]];
        //dist_plane2 = odleglosci[rozw[1][k]][rozw[1][k+1]];
        //dist_plane3 = odleglosci[rozw[2][k]][rozw[2][k+1]];
        //if(dist_plane1>dist_plane2 && dist_plane1>dist_plane3 && dist_plane2>dist_plane3);


    //}
//}



//int zlecenie:: ObliczFCelu(int **rozw)
//{
//  int temporary_result = 0;
//  for(int w=0;w<3;w++)
//    for(int k=1;rozw[w][k]='/0';k++)
//      temporary_result = temporary_result + oplata_lotniskowa[k-1]+koszt_tankowania[(rozw[w][k-1])-1][(rozw[w][k])-1]+zaladowanie_samolotu[w][k-1]*odleglosci[wynik[w][k-1]-1][wynik[w][k]-1]*spalanie;
//}

void zlecenie::resizeWynik(int n)
{

    int **nowa = new int * [3];
    for (int i = 0; i<3; i++)
    {

        nowa[i] = new int [n];
    }

    for(int i=0;i<3;i++)
    {

        for(int j=0;j<n-1;j++)
        {
            nowa[i][j]=tmp_wynik[i][j];
        }

    nowa[i][n-1]=0;

    }
    for (int i = 0; i<3; i++)
        delete [] tmp_wynik[i];
    delete [] tmp_wynik;
    tmp_wynik=nowa;
    //n_wyniku=n_wyniku+1;
    //delete [] nowa;
    std::cout<<"kurwa\n";

}

void zlecenie::resizeZaladowanie(int n)
{
    int **nowa = new int * [3];
    for (int i = 0; i<3; i++)
    {

        nowa[i] = new int [n];
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n-1;j++)
            nowa[i][j]=zaladowanie_samolotu[i][j];
        nowa[i][n-1]=zaladowanie_samolotu[i][n-2];
    }
    for (int i = 0; i<3; i++)
        delete [] zaladowanie_samolotu[i];
    delete [] zaladowanie_samolotu;
    zaladowanie_samolotu=nowa;
    //delete [] nowa;

}

bool zlecenie::czyNiePuste(int **tab)
{
    int k=0;
    for(int i=0;i<rozmiar;i++)
        {
        for(int j=0;j<rozmiar;j++)
            {
                if(tab[i][j]!=0)
                    k=1;
            }
        }
     if(k==1)
        return true;
    if(k==0)
        return false;
}


bool zlecenie::czyNiePuste(int *tab)
{
    int k=0;
    for(int i=0;i<rozmiar;i++)
        {

        if(tab[i]!=0)
            k=1;
        }

     if(k==1)
        return true;
    if(k==0)
        return false;
}


int zlecenie::maximum(int *tab)
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

void zlecenie::test()
{
    bool k=0;
    k=czyNiePuste(lista_przewozowa);
    std::cout<<" "<<k<<"\n";
}


void zlecenie::InitialSolution()
{
    int n_wyniku=1;
    int ktoraiteracja=0;
    zaladowanie_samolotu = new int * [n_wyniku];
    for (int i = 0; i<3; i++)
    {
    zaladowanie_samolotu[i] = new int [n_wyniku];
    }
    for (int i = 0; i<3; i++)
    {
    zaladowanie_samolotu[i][0] = 0;
    }
    tmp_wynik = new int * [n_wyniku];
    for (int i = 0; i<3; i++)
    {

        tmp_wynik[i] = new int [n_wyniku];
    }
    for (int i = 0; i<3; i++)
    {
    tmp_wynik[i][0] = 0;
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

    int odkad1=0;
    int odkad2=0;
    int odkad3=0;

    //duza petla
  while(czyNiePuste(lista_przewozowa))
    {

        while(((zaladowanie_samolotu[0][ktoraiteracja]+zaladowanie_samolotu[1][ktoraiteracja]+zaladowanie_samolotu[2][ktoraiteracja])<75)&&czyNiePuste(lista_przewozowa))
        {

            while((zaladowanie_samolotu[0][ktoraiteracja])<25&&czyNiePuste(lista_przewozowa))   //1 samolot
            {

                for(int i =odkad1; i<rozmiar; i++)
                {
                    for (int j =0; j<rozmiar; j++)
                    {
                       if(lista_przewozowa[i][j]!=0)
                       {
                           if(((zaladowanie_samolotu[0][ktoraiteracja])+lista_przewozowa[i][j])<=25)
                           {

                               temp1[j]=temp1[j]+lista_przewozowa[i][j];

                               zaladowanie_samolotu[0][ktoraiteracja]=zaladowanie_samolotu[0][ktoraiteracja]+lista_przewozowa[i][j];
                               lista_przewozowa[i][j]=0;

                           }
                           else
                           {
                               if(zaladowanie_samolotu[0][ktoraiteracja]==25)
                                {

                                }
                               else
                                {

                                 temp1[j]=temp1[j]+(lista_przewozowa[i][j]-(zaladowanie_samolotu[0][ktoraiteracja]+lista_przewozowa[i][j]-25));
                                 zaladowanie_samolotu[0][ktoraiteracja]=25;
                                 lista_przewozowa[i][j]=(zaladowanie_samolotu[0][ktoraiteracja]+lista_przewozowa[i][j]-25);

                                }

                           }
                       }

                    }
                }
            }

            while((zaladowanie_samolotu[1][ktoraiteracja])<25&&czyNiePuste(lista_przewozowa))   //2 samolot
            {

                for(int i =odkad2; i<rozmiar; i++)
                {
                    for (int j =0; j<rozmiar; j++)
                    {
                       if(lista_przewozowa[i][j]!=0)
                       {
                           if((zaladowanie_samolotu[1][ktoraiteracja]+lista_przewozowa[i][j])<=25)
                           {
                               temp2[j]=temp2[j]+lista_przewozowa[i][j];
                               zaladowanie_samolotu[1][ktoraiteracja]=zaladowanie_samolotu[1][ktoraiteracja]+lista_przewozowa[i][j];
                               lista_przewozowa[i][j]=0;

                           }
                           else
                           {
                               if(zaladowanie_samolotu[1][ktoraiteracja]==25)
                                {

                                }
                               else
                                {
                                 temp2[j]=temp2[j]+(lista_przewozowa[i][j]-(zaladowanie_samolotu[1][ktoraiteracja]+lista_przewozowa[i][j]-25));
                                 zaladowanie_samolotu[1][ktoraiteracja]=25;
                                 lista_przewozowa[i][j]=(zaladowanie_samolotu[1][ktoraiteracja]+lista_przewozowa[i][j]-25);

                                }

                           }
                       }

                    }
                }
            }


            while((zaladowanie_samolotu[2][ktoraiteracja])<25&&czyNiePuste(lista_przewozowa))   //3 samolot
            {
                for(int i =odkad3; i<rozmiar; i++)
                {
                    for (int j =0; j<rozmiar; j++)
                    {
                       if(lista_przewozowa[i][j]!=0)
                       {
                           if((zaladowanie_samolotu[2][ktoraiteracja]+lista_przewozowa[i][j])<=25)
                           {
                               temp3[j]=temp3[j]+lista_przewozowa[i][j];
                               zaladowanie_samolotu[2][ktoraiteracja]=zaladowanie_samolotu[2][ktoraiteracja]+lista_przewozowa[i][j];
                               lista_przewozowa[i][j]=0;
                           }
                           else
                           {
                               if(zaladowanie_samolotu[2][ktoraiteracja]==25)
                                {

                                }
                               else
                                {
                                 temp3[j]=temp3[j]+(lista_przewozowa[i][j]-(zaladowanie_samolotu[2][ktoraiteracja]+lista_przewozowa[i][j]-25));
                                 zaladowanie_samolotu[2][ktoraiteracja]=25;
                                 lista_przewozowa[i][j]=(zaladowanie_samolotu[2][ktoraiteracja]+lista_przewozowa[i][j]-25);
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
         std::cout<<"\nwynik:\n";
        for (int i = 0; i<3; i++)
        {
            for(int j=0;j<n_wyniku;j++)
            std::cout<<tmp_wynik[i][j]<<" ";
            std::cout<<"\n";
        }
         std::cout<<"\nzalado:\n";
        for (int i = 0; i<3; i++)
        {
            for(int j=0;j<n_wyniku;j++)
            std::cout<<zaladowanie_samolotu[i][j]<<" ";
            std::cout<<"\n";
        }
        std::cout<<"\ndupa\n";
        resizeWynik(n_wyniku+1);
        n_wyniku++;
        std::cout<<n_wyniku;
         std::cout<<"\nwynik:\n";
        for (int i = 0; i<3; i++)
        {
            for(int j=0;j<n_wyniku;j++)
            std::cout<<tmp_wynik[i][j]<<" ";
            std::cout<<"\n";
        }
        std::cout<<"\ndupa1\n";
        resizeZaladowanie(n_wyniku);
        std::cout<<"\nmarek to faja\n\n";
    std::cout<<"Lista Przewozowa: \n";
    for(int i =0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar;j++)
            std::cout<<lista_przewozowa[i][j]<<" ";
        std::cout<<"\n";
    }
     std::cout<<"\n\n";
     std::cout<<odkad3;



    }
    std::cout<<"po zalad";

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
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n_wyniku;j++)
            best_wynik[i][j]=tmp_wynik[i][j];

    }
    for (int i = 0; i<3; i++)
        delete [] tmp_wynik[i];
    delete [] tmp_wynik;



}

/*
int zlecenie:: sprawdz_dopuszczalnosc(int ** rozw)
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
*/

