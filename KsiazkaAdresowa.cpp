#include "KsiazkaAdresowa.h"

KsiazkaAdresowa:: KsiazkaAdresowa()
{
    uzytkownikManager.wczytajUzytkownikowZPiku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
uzytkownikManager.rejestracjaUzytkownika ();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}


