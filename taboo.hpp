#ifndef TABOO_HPP_INCLUDED
#define TABOO_HPP_INCLUDED

#define spalanie 0.5   //wartosc z dupska
#define ladownosc 25


class taboo{

private:
    int n_zabr;
    int **zabronienia;   // to bedzie tablela (symetryczna) gdzie damy np blokade na 3 iteracje
    int n_wyniku;
    int **best_wynik;
    int **tmp_wynik;
    int **zaladowanie_samolotu;
    int **ladunek_samolotu; //wiersze ->samoloty, kolumny ->numer lotniska, czyli 3x8
    int **sasiedztwo;

public:
    taboo();
    ~taboo();
    void InitialSolution();
    bool czyNiePuste(int **tab);
    void resizeWynik(int n);
    void resizeZaladowanie(int n);
    int ObliczFCelu(int **rozw);  //liczy na podstawie danych z tabel i z wyniku <- dla kazdego rozwiazania, nie wiem czy dobrze wklepane jako arg
    void showZabronienia();
    void showWynik();
    void oblicz_zaladowanie();
    void stworz_sasiedztwo();
    int sprawdz_dopuszczalnosc(int ** rozw);
    int maximum(int *tab);
    //modyfikacja wyniku
    //uwtorzenie listy zabronien
    //robienie sasiedztwa


};


#endif // TABOO_HPP_INCLUDED
