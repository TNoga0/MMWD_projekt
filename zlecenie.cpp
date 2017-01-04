#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "zlecenie.hpp"
#define ILEITERACJI 10

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

//void zlecenie:: oblicz_zaladowanie(int **wynik) //oblicza zaÂładowanie dla kaÂżdego z krokĂłw algorytmu
//{
//  for(int w=0;w<3;w++)
//    for(int k =0;wynik[w][k+2]='/0';k++)
//      if(k=0)
//      {
//        zaladowanie_samolotu[w][k]=lista_przewozowa[wynik[w][k]-1][wynik[w][k+1]-1];
//      }
//      else
//      {
//      zaladowanie_samolotu[w][k]=zaladowanie_samolotu[w][k-1]+lista_przewozowa[wynik[w][k]-1][wynik[w][k+1]-1];
//      }
//}

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



int zlecenie:: ObliczFCelu(int **rozw)
{
	//std::cout<<"gówno";
  int temporary_result = 0;
  for(int w=0;w<3;w++)
  {
    for(int k=1;k<(n_wyniku-1);k++)
      temporary_result = temporary_result + oplata_lotniskowa[(rozw[w][k-1])]+koszt_tankowania[(rozw[w][k-1])][(rozw[w][k])]+zaladowanie_samolotu[w][k-1]*odleglosci[rozw[w][k-1]][rozw[w][k]]*spalanie;
  }
	return temporary_result;
}

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
        //nowa[i][n-1]=0;
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
    for(int w=0;w<3;w++)
    {

    	for(int k=0;k<n_wyniku;k++)
    	{

    		std::cout<<best_wynik[w][k]<<" ";

}
std::cout<<"\n";
}

int cel=ObliczFCelu(best_wynik);
std::cout<<"\n"<<cel;

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
    int odkad2=1;
    int odkad3=3;
    int cnt=0;
    //duza petla
  while(czyNiePuste(lista_przewozowa))
    {

cnt=0;
       // while(((zaladowanie_samolotu[0][ktoraiteracja]+zaladowanie_samolotu[1][ktoraiteracja]+zaladowanie_samolotu[2][ktoraiteracja])<75)&&czyNiePuste(lista_przewozowa))
        //{

            while((zaladowanie_samolotu[0][ktoraiteracja])<25&&czyNiePuste(lista_przewozowa)&&cnt<rozmiar+1)   //1 samolot
            {


                    for (int j =0; j<rozmiar; j++)
                    {
                        cnt++;
                       if(lista_przewozowa[odkad1][j]!=0)
                       {
                           if(((zaladowanie_samolotu[0][ktoraiteracja])+lista_przewozowa[odkad1][j])<=25)
                           {

                               temp1[j]=temp1[j]+lista_przewozowa[odkad1][j];//j=i

                               zaladowanie_samolotu[0][ktoraiteracja]=zaladowanie_samolotu[0][ktoraiteracja]+lista_przewozowa[odkad1][j];
                               lista_przewozowa[odkad1][j]=0;

                           }
                           else
                           {
                               if(zaladowanie_samolotu[0][ktoraiteracja]==25)
                                {

                                }
                               else
                                {
std::cout<<"   tutaj   \n";
                                 temp1[j]=temp1[j]+(lista_przewozowa[odkad1][j]-(zaladowanie_samolotu[0][ktoraiteracja]+lista_przewozowa[odkad1][j]-25));
                                 lista_przewozowa[odkad1][j]=(zaladowanie_samolotu[0][ktoraiteracja]+lista_przewozowa[odkad1][j]-25);
                                 zaladowanie_samolotu[0][ktoraiteracja]=25;


                                }

                           }
                       }


                }
            }

            while((zaladowanie_samolotu[1][ktoraiteracja])<25&&czyNiePuste(lista_przewozowa)&&cnt<2*rozmiar+2)   //2 samolot
            {


                    for (int j =0; j<rozmiar; j++)
                    {
                        cnt++;
                       if(lista_przewozowa[odkad2][j]!=0)
                       {
                           if((zaladowanie_samolotu[1][ktoraiteracja]+lista_przewozowa[odkad2][j])<=25)
                           {
                               temp2[j]=temp2[j]+lista_przewozowa[odkad2][j];
                               zaladowanie_samolotu[1][ktoraiteracja]=zaladowanie_samolotu[1][ktoraiteracja]+lista_przewozowa[odkad2][j];
                               lista_przewozowa[odkad2][j]=0;

                           }
                           else
                           {
                               if(zaladowanie_samolotu[1][ktoraiteracja]==25)
                                {

                                }
                               else
                                {
                                 temp2[j]=temp2[j]+(lista_przewozowa[odkad2][j]-(zaladowanie_samolotu[1][ktoraiteracja]+lista_przewozowa[odkad2][j]-25));
                                 lista_przewozowa[odkad2][j]=(zaladowanie_samolotu[1][ktoraiteracja]+lista_przewozowa[odkad2][j]-25);
                                 zaladowanie_samolotu[1][ktoraiteracja]=25;


                                }

                           }
                       }


                }

            }


            while((zaladowanie_samolotu[2][ktoraiteracja])<25&&czyNiePuste(lista_przewozowa)&&cnt<3*rozmiar+3)   //3 samolot
            {


                    for (int j =0; j<rozmiar; j++)
                    {
                        cnt++;
                    	if(lista_przewozowa[odkad3][j]!=0)
                       	{
                           if((zaladowanie_samolotu[2][ktoraiteracja]+lista_przewozowa[odkad3][j])<=25)
                           {
                               temp3[j]=temp3[j]+lista_przewozowa[odkad3][j];
                               zaladowanie_samolotu[2][ktoraiteracja]=zaladowanie_samolotu[2][ktoraiteracja]+lista_przewozowa[odkad3][j];
                               lista_przewozowa[odkad3][j]=0;
                           }
                           else
                           {
                               if(zaladowanie_samolotu[2][ktoraiteracja]==25)
                                {

                                }
                               else
                                {
                                 temp3[j]=temp3[j]+(lista_przewozowa[odkad3][j]-(zaladowanie_samolotu[2][ktoraiteracja]+lista_przewozowa[odkad3][j]-25));
                                 lista_przewozowa[odkad3][j]=(zaladowanie_samolotu[2][ktoraiteracja]+lista_przewozowa[odkad3][j]-25);
                                 zaladowanie_samolotu[2][ktoraiteracja]=25;

                                }

                           }
                       }


                }
            }



        //}
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
        std::cout<<"\n\n";
    }

     std::cout<<"\n\n";
     std::cout<<odkad3;
     std::cout<<" ";
     std::cout <<odkad1;



        std::cout<<"------------------------\n";
	std::cout<< "tmp : \n";

        for(int j=0;j<rozmiar;j++)
        {

            std::cout<<temp1[j]<<" ";
            std::cout<<temp2[j]<<" ";
            std::cout<<temp3[j]<<" ";
            std::cout<<"\n";

     	}
        std::cout<<"\n";
    }
    std::cout<<"po zalad";

	int tymczasowy = n_wyniku;
int tymczasowy1 = tymczasowy;
    while(czyNiePuste(temp1))
        {

        odkad1=maximum(temp1);
        tmp_wynik[0][n_wyniku-1]=odkad1;
        zaladowanie_samolotu[0][n_wyniku-1]=zaladowanie_samolotu[0][n_wyniku-1]-temp1[odkad1];
        temp1[odkad1]=0;
        resizeWynik(n_wyniku+1);
        n_wyniku++;
        resizeZaladowanie(n_wyniku);
        }
    while(czyNiePuste(temp2))
        {

//        odkad2=maximum(temp2);
//        tmp_wynik[1][n_wyniku-1]=odkad2;
//        zaladowanie_samolotu[1][n_wyniku-1]=zaladowanie_samolotu[1][n_wyniku-1]-temp2[odkad2];
//        temp2[odkad2]=0;

        if(n_wyniku>=tymczasowy1)
        {

        	odkad2=maximum(temp2);
        tmp_wynik[1][tymczasowy1-1]=odkad2;
        zaladowanie_samolotu[1][tymczasowy1-1]=zaladowanie_samolotu[1][tymczasowy1-1]-temp2[odkad2];
        temp2[odkad2]=0;
        	tymczasowy1++;
    	}
    	else
    	{

    		resizeWynik(tymczasowy1+1);

        	resizeZaladowanie(tymczasowy1+1);
        	odkad2=maximum(temp2);
        tmp_wynik[1][tymczasowy1-1]=odkad2;
        zaladowanie_samolotu[1][tymczasowy1-1]=zaladowanie_samolotu[1][tymczasowy1-1]-temp2[odkad2];

		temp2[odkad2]=0;
        	tymczasowy1++;
    	}
        }
    while(czyNiePuste(temp3))
        {

//        odkad3=maximum(temp3);
//        tmp_wynik[2][n_wyniku-1]=odkad3;
//        zaladowanie_samolotu[2][n_wyniku-1]=zaladowanie_samolotu[2][n_wyniku-1]-temp3[odkad3];
//        temp3[odkad3]=0;
        if(n_wyniku>=tymczasowy)
        {
        	odkad3=maximum(temp3);
        tmp_wynik[2][tymczasowy-1]=odkad3;
        zaladowanie_samolotu[2][tymczasowy-1]=zaladowanie_samolotu[2][tymczasowy-1]-temp3[odkad3];
        temp3[odkad3]=0;
        tymczasowy++;
    	}
    	else
    	{
    		resizeWynik(tymczasowy+1);
        	resizeZaladowanie(tymczasowy+1);
        	odkad3=maximum(temp3);
        tmp_wynik[2][tymczasowy-1]=odkad3;
        zaladowanie_samolotu[2][tymczasowy-1]=zaladowanie_samolotu[2][tymczasowy-1]-temp3[odkad3];
        temp3[odkad3]=0;
        tymczasowy++;
    	}

        }

        int biggest;
	if(n_wyniku>tymczasowy)
		biggest=n_wyniku;
	else
		biggest = tymczasowy;

		if(biggest>tymczasowy1)
		{
		}
		else
		biggest=tymczasowy1;



    best_wynik = new int * [3];
    for (int i = 0; i<3; i++)
    {

        best_wynik[i] = new int [n_wyniku];
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n_wyniku;j++)
            best_wynik[i][j]=tmp_wynik[i][j];

    }

    	 std::cout<<"\nwynik:\n";
        for (int i = 0; i<3; i++)
        {
            for(int j=0;j<n_wyniku;j++)
            std::cout<<tmp_wynik[i][j]<<" ";
            std::cout<<"\n";
        }


  std::cout<<"zaladowanko kuwa kuwa : \n";  //załadowanieeeeeeeeeeeee
    for(int i =0;i<3;i++)
    {
        for(int j=0;j<biggest;j++)
            std::cout<<zaladowanie_samolotu[i][j]<<" ";
        std::cout<<"\n";
    }

    std::cout<< "tmp : \n";

        for(int j=0;j<rozmiar;j++)
        {

            std::cout<<temp1[j]<<" ";
            std::cout<<temp2[j]<<" ";
            std::cout<<temp3[j]<<" ";
            std::cout<<"\n";

     	}
        std::cout<<"\n";
this->n_wyniku = biggest;

    //for (int i = 0; i<3; i++)
   //     delete [] tmp_wynik[i];
   // delete [] tmp_wynik;
n_wyniku = biggest;

}

void zlecenie::generuj_tabu()
{
    tabu_list = new element * [3];
    for (int i = 0; i<3; i++)
    {

        tabu_list[i] = new element [n_wyniku];
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n_wyniku;j++)
        {
            tabu_list[i][j].czas=0;
            //tabu_list[i][j].dokad=-1;
        }
    }
}



void zlecenie::wykonaj_sasiedztwo()
{

    std::cout<<"\nwynik przed sasiedztwem:\n";
        for (int i = 0; i<3; i++)
        {
            for(int j=0;j<n_wyniku;j++)
            std::cout<<tmp_wynik[i][j]<<" ";
            std::cout<<"\n";
            std::cout<<"\n";
        }

    int temp=0;
    srand( time( NULL ) );
    int pierwszy_j1=rand() % n_wyniku;
    int pierwszy_j2=rand() % n_wyniku;
    int drugi_j1=rand() % n_wyniku;
    int drugi_j2=rand() % n_wyniku;
    int trzeci_j1=rand() % n_wyniku;
    int trzeci_j2=rand() % n_wyniku;
     std::cout<<"\npj1: "<<pierwszy_j1<<" pj2: "<<pierwszy_j2<<"\n";
std::cout<<"\ndj1: "<<drugi_j1<<" dj2: "<<drugi_j2<<"\n";
std::cout<<"\ntj1: "<<trzeci_j1<<" tj2: "<<trzeci_j2<<"\n";

    //zamiana pierwszy
    if((tabu_list[0][pierwszy_j1].czas==0&&tabu_list[0][pierwszy_j1].dokad!=pierwszy_j2)&&(tabu_list[0][pierwszy_j2].czas==0&&tabu_list[0][pierwszy_j2].dokad!=pierwszy_j1))
    {
    temp=tmp_wynik[0][pierwszy_j1];
    tmp_wynik[0][pierwszy_j1]=tmp_wynik[0][pierwszy_j2];
    tmp_wynik[0][pierwszy_j2]=temp;

    tabu_list[0][pierwszy_j1].czas=ILEITERACJI;
    tabu_list[0][pierwszy_j2].czas=ILEITERACJI;
    tabu_list[0][pierwszy_j1].dokad=pierwszy_j2;
    tabu_list[0][pierwszy_j2].dokad=pierwszy_j1;
    }


    //zamiana drugi
    if((tabu_list[1][drugi_j1].czas==0&&tabu_list[1][drugi_j1].dokad!=drugi_j2)&&(tabu_list[1][drugi_j2].czas==0&&tabu_list[1][drugi_j2].dokad!=drugi_j1))
    {
    temp=tmp_wynik[1][drugi_j1];
    tmp_wynik[1][drugi_j1]=tmp_wynik[1][drugi_j2];
    tmp_wynik[1][drugi_j2]=temp;

    tabu_list[1][drugi_j1].czas=ILEITERACJI;
    tabu_list[1][drugi_j2].czas=ILEITERACJI;
    tabu_list[1][drugi_j1].dokad=drugi_j2;
    tabu_list[1][drugi_j2].dokad=drugi_j1;
    }

    //zamiana trzeci
    if((tabu_list[2][trzeci_j1].czas==0&&tabu_list[2][trzeci_j1].dokad!=trzeci_j2)&&(tabu_list[2][trzeci_j2].czas==0&&tabu_list[2][trzeci_j2].dokad!=trzeci_j1))
    {
    temp=tmp_wynik[2][trzeci_j1];
    tmp_wynik[2][trzeci_j1]=tmp_wynik[2][trzeci_j2];
    tmp_wynik[2][trzeci_j2]=temp;

    tabu_list[2][trzeci_j1].czas=ILEITERACJI;
    tabu_list[2][trzeci_j2].czas=ILEITERACJI;
    tabu_list[2][trzeci_j1].dokad=trzeci_j2;
    tabu_list[2][trzeci_j2].dokad=trzeci_j1;
    }

    std::cout<<"\nwynik po sasiedztwie:\n";
        for (int i = 0; i<3; i++)
        {
            for(int j=0;j<n_wyniku;j++)
            std::cout<<tmp_wynik[i][j]<<" ";
            std::cout<<"\n";
        }


}

