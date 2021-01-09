#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
uzytkownikManager.rejestracjaUzytkownika ();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
   uzytkownikManager.logowanieUzytkownika();
};

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
   uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
};
