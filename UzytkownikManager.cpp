#include "UzytkownikManager.h"


void UzytkownikManager::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do {
        cout<< "Podaj login: ";
        cin>> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);
    string haslo;
    cout << "Podaj haslo: ";
    cin>> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}
int UzytkownikManager::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}
bool UzytkownikManager::czyIstniejeLogin(string login) {
    for (int i=0; i< uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }
    return false;

}

void UzytkownikManager::wypiszWszystkichUzytkownikow() {
    for (int i=0; i< uzytkownicy.size(); i++) {
        cout<< uzytkownicy[i].pobierzId()<<endl;
        cout<< uzytkownicy[i].pobierzLogin()<<endl;
        cout<< uzytkownicy[i].pobierzHaslo()<<endl;
    }

}

void UzytkownikManager::wczytajUzytkownikowZPiku()
{
uzytkownicy= plikZUzytkownikami.wczytajUzytkownikowZPilku();
}


int UzytkownikManager::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string nlogin = "", nHaslo = "";

    cout << endl << "Podaj login: ";
    nlogin = wczytajLinie();

   vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {

        if ((*itr).pobierzLogin()==nlogin  )
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                nHaslo = wczytajLinie();

                if ((*itr).pobierzHaslo() == nHaslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return (*itr).pobierzId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

string UzytkownikManager::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
