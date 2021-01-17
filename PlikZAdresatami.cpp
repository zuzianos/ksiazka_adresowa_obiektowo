#include "PlikZAdresatami.h"

void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        cout << endl << "Dodano adresata." << endl;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    system("pause");
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdAdresata()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTel() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}


int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    int IdOstatniegoAdresata;
    int liczbalinijek = 0;
    string linia;
    ifstream plikTekstowy(pobierzNazwePliku());
    string ostatniaLinijka;
    while (getline(plikTekstowy, linia)) {
        ++liczbalinijek;
        ostatniaLinijka=linia;
    }
    if (ostatniaLinijka.size()>0){
    size_t position= ostatniaLinijka.find('|');
    ostatniaLinijka=ostatniaLinijka.erase(position,ostatniaLinijka.size());
    IdOstatniegoAdresata= stoi(ostatniaLinijka);
    return IdOstatniegoAdresata;
    }
    else {return 0;}
}

vector<Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    vector <Adresat> adresaci;
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return adresaci;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawIdAdresata(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTel(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}
string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

void PlikZAdresatami::usunWybranegoAdresataZPliku(int idUsuwanegoAdresata)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string idDoUsuniecia= MetodyPomocnicze::konwerjsaIntNaString(idUsuwanegoAdresata);
    string wczytanaLinia;
    string sprawdzanaLinia;
    string idWPliku;
    int numerWczytanejLinii=1;
    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);
    if (odczytywanyPlikTekstowy.good() == true && idUsuwanegoAdresata != 0)
    {   while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            sprawdzanaLinia = wczytanaLinia;
            size_t position= sprawdzanaLinia.find('|');
            idWPliku= sprawdzanaLinia.erase(position,sprawdzanaLinia.size());
            if (numerWczytanejLinii ==1 && idDoUsuniecia!=idWPliku){
            tymczasowyPlikTekstowy<<wczytanaLinia;
            numerWczytanejLinii++;
            }
            else if (numerWczytanejLinii >1 && idDoUsuniecia!=idWPliku){
               tymczasowyPlikTekstowy<<endl<< wczytanaLinia;
            numerWczytanejLinii++;
            }
            else if (numerWczytanejLinii== 1 && idDoUsuniecia==idWPliku){
                numerWczytanejLinii== numerWczytanejLinii;
            }
            else if (numerWczytanejLinii>1 && idDoUsuniecia==idWPliku)
            {
                numerWczytanejLinii++;
            }
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunOdczytywanyPlik(pobierzNazwePliku());
        zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(nazwaTymczasowegoPlikuZAdresatami, pobierzNazwePliku());
    }
}

void PlikZAdresatami::usunOdczytywanyPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(string nazwaTymczasowegoPlikuZRozszerzeniem, string nazwaPlikuZRozszerzeniem)
{
    if (rename(nazwaTymczasowegoPlikuZRozszerzeniem.c_str(), nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
    cout << "Nazwa pliku nie zostala zmieniona." << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata (Adresat adresat, int idEdytowanegoAdresata)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string idDoEdycji= MetodyPomocnicze::konwerjsaIntNaString(idEdytowanegoAdresata);
    string wczytanaLinia;
    string sprawdzanaLinia;
    string idWPliku;
    int numerWczytanejLinii=1;
    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);
    if (odczytywanyPlikTekstowy.good() == true && idEdytowanegoAdresata != 0)
    {   while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            sprawdzanaLinia = wczytanaLinia;
            size_t position= sprawdzanaLinia.find('|');
            idWPliku= sprawdzanaLinia.erase(position,sprawdzanaLinia.size());
            if (numerWczytanejLinii==1 && idDoEdycji!=idWPliku){
            tymczasowyPlikTekstowy<<wczytanaLinia;
            numerWczytanejLinii++;
            }
            else if (numerWczytanejLinii > 1 && idDoEdycji!=idWPliku){
            tymczasowyPlikTekstowy<<endl<<wczytanaLinia;
            numerWczytanejLinii++;
            }
            else if( numerWczytanejLinii == 1 && idDoEdycji==idWPliku){
            tymczasowyPlikTekstowy<<adresat.pobierzIdAdresata()<<"|"<<adresat.pobierzIdUzytkownika()<<"|"<<adresat.pobierzImie()<<"|"<<adresat.pobierzNazwisko()<<"|"<<adresat.pobierzNumerTel()
            <<"|"<<adresat.pobierzEmail()<<"|"<<adresat.pobierzAdres()<<"|";
            numerWczytanejLinii++;
            }
            else if( numerWczytanejLinii > 1 && idDoEdycji==idWPliku){
            tymczasowyPlikTekstowy<<endl<<adresat.pobierzIdAdresata()<<"|"<<adresat.pobierzIdUzytkownika()<<"|"<<adresat.pobierzImie()<<"|"<<adresat.pobierzNazwisko()<<"|"<<adresat.pobierzNumerTel()
            <<"|"<<adresat.pobierzEmail()<<"|"<<adresat.pobierzAdres()<<"|";
            numerWczytanejLinii++;
            }
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();
        usunOdczytywanyPlik(pobierzNazwePliku());
        zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(nazwaTymczasowegoPlikuZAdresatami, pobierzNazwePliku());
    }
}
