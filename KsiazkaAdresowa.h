#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikManager.h"

using namespace std;

class KsiazkaAdresowa {

    UzytkownikManager uzytkownikManager;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami): uzytkownikManager(nazwaPlikuZUzytkownikami){
     uzytkownikManager.wczytajUzytkownikowZPiku();
    } ;
    void rejestracjaUzytkownika ();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();
    bool czyUzytkownikJestZalogowany();
};
#endif
