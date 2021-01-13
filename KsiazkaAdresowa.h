#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikManager.h"
#include "AdresatManager.h"

using namespace std;

class KsiazkaAdresowa {

    UzytkownikManager uzytkownikManager;
    AdresatManager *adresatManager;
    const string nazwaPlikuZAdresatami;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string NAZWA_PLIKU_Z_ADRESATAMI): uzytkownikManager(nazwaPlikuZUzytkownikami), nazwaPlikuZAdresatami(NAZWA_PLIKU_Z_ADRESATAMI){

    adresatManager = NULL;
    };
    ~ KsiazkaAdresowa()
    {
        delete adresatManager;
        adresatManager = NULL;
    };
    void rejestracjaUzytkownika ();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();
    bool czyUzytkownikJestZalogowany();
    void wyswietlWszystkichAdresatow();
    void dodajAdresata();
    void usunAdresata();
};
#endif
