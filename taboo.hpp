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

public:
    taboo();
    ~taboo();
    void InitialSolution();
    int ObliczFCelu();  //liczy na podstawie danych z tabel i z wyniku <- dla kazdego rozwiazania
    void showZabronienia();
    void showWynik();
    //modyfikacja wyniku
    //uwtorzenie listy zabronien
    //robienie sasiedztwa


};


#endif // TABOO_HPP_INCLUDED
