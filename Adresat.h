#ifndef ADRESAT_H
#define ADRESAT_H
#include <iostream>

using namespace std;

class Adresat {
    int idAdresata;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string numerTel;
    string email;
    string adres;

public:
    Adresat (int idAdresata=0, int idUzytkownika=0,string imie="",string nazwisko="",string numerTel="",string email="",string adres="" )
    {
        this->idAdresata= idAdresata;
        this->idUzytkownika= idUzytkownika;
        this->imie= imie;
        this->nazwisko= nazwisko;
        this->numerTel= numerTel;
        this->email=email;
        this->adres=adres;
    }

    void ustawIdAdresata (int noweIdAdresata);
    void ustawIdUzytkownika (int noweIdUzytkownika);
    void ustawImie (string noweImie);
    void ustawNazwisko (string noweNazwisko);
    void ustawNumerTel (string nowyNumerTel);
    void ustawEmail (string nowyEmail);
    void ustawAdres (string nowyAdres);

    int pobierzIdAdresata ();
    int pobierzIdUzytkownika ();
    string pobierzImie ();
    string pobierzNazwisko ();
    string pobierzNumerTel ();
    string pobierzEmail ();
    string pobierzAdres ();
};

#endif
