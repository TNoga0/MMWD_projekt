#ifndef ZLECENIE_HPP_INCLUDED
#define ZLECENIE_HPP_INCLUDED
#define spalanie 0.5   //wartosc z dupska
#define ladownosc 25
#define liczbaSamolotow 3

class zlecenie
{
private:
    int rozmiar;  //ilosc miast
    int **lista_przewozowa;
    int **koszt_tankowania;
    int **odleglosci;
    int **czasy_przelotow;
    int ile_samolotow;
    int *oplata_lotniskowa;
    int n_zabr;
    int **zabronienia;   // to bedzie tablela (symetryczna) gdzie damy np blokade na 3 iteracje

   // int **best_wynik;
    int **tmp_wynik;
    int **zaladowanie_samolotu;
    int **sasiedztwo;
    int **ladunek_samolotu;

public:
int n_wyniku;
struct element
{
    int dokad;
    int czas;
};

    struct element **tabu_list;
    int **best_wynik;
    zlecenie();
    ~zlecenie();
    void usun();
    void show_lista(); //pokazuje liste przewozowa i liczbe samolotow
    bool WczytajzPliku(std:: string plikLista, std:: string PlikTankowanie,std:: string plikOdl,
    std:: string plikCzasy,std:: string plikOplata, int rozmiarTabl);
    zlecenie(int n, int maxliczba,int ileSamolotow);  //wczytanie losowe
    zlecenie(int n, int ileSamolotow);  //wczytanie pustej listy
    void InitialSolution();
    bool czyNiePuste(int **tab);
    bool czyNiePuste(int *tab);
    void resizeWynik(int n);
    void resizeZaladowanie(int n);
    int ObliczFCelu(int **rozw);  //liczy na podstawie danych z tabel i z wyniku <- dla kazdego rozwiazania, nie wiem czy dobrze wklepane jako arg
    void showZabronienia();
    void showWynik();
    void oblicz_zaladowanie(int **wynik);
    int sprawdz_dopuszczalnosc(int ** rozw);
    int maximum(int *tab);
    void test();
    void roz0(int* zapelnieniee, int** ladunek_samolotue, int** tmp_przewozowae, int** rozwe, int tmpe, int n_wynikue, int ke);
    void roz1(int* zapelnieniee, int** ladunek_samolotue, int** tmp_przewozowae, int** rozwe, int tmpe, int n_wynikue, int ke);
    void roz2(int* zapelnieniee, int** ladunek_samolotue, int** tmp_przewozowae, int** rozwe, int tmpe, int n_wynikue, int ke);
    void zalad0(int* zapelnieniee, int** ladunek_samolotue, int** tmp_przewozowae, int** rozwe, int tmpe, int n_wynikue, int ke);
    void zalad1(int* zapelnieniee, int** ladunek_samolotue, int** tmp_przewozowae, int** rozwe, int tmpe, int n_wynikue, int ke);
    void zalad2(int* zapelnieniee, int** ladunek_samolotue, int** tmp_przewozowae, int** rozwe, int tmpe, int n_wynikue, int ke);
    void wykonaj_sasiedztwo();
    void generuj_tabu();
    void zlota_raczka();
    void dekremTabu();
    void dopliku();
    void czyscplik();
};


#endif // ZLECNIE_HPP_INCLUDED
