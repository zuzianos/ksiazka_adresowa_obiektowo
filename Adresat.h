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
