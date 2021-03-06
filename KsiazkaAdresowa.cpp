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
   if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager = new AdresatManager (nazwaPlikuZAdresatami, uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    }
};

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
   uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
};

void KsiazkaAdresowa::wylogujUzytkownika()
{
   uzytkownikManager.wylogujUzytkownika();
   delete adresatManager;
   adresatManager= NULL;
};

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
   uzytkownikManager.czyUzytkownikJestZalogowany();
};


void KsiazkaAdresowa::dodajAdresata()
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager->dodajAdresata();
    }
    else
    {
        cout << "Nie udalo sie dodac adresata- zaloguj sie ponownie" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatManager->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::usunAdresata()
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager->usunAdresata();
    }
    else
    {
        cout << "Nie udalo sie usunac adresata- zaloguj sie ponownie" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::edytujAdresata()
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager->edytujAdresata();
    }
    else
    {
        cout << "Nie udalo sie usunac adresata- zaloguj sie ponownie" << endl;
        system("pause");
    }


}

void KsiazkaAdresowa::wyszukajPoImieniu()
{
     adresatManager->wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyszukajPoNazwisku()
{
     adresatManager->wyszukajAdresatowPoNazwisku();
}
