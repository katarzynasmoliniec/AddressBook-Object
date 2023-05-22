#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa :: rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa :: wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa :: pobierzIdZalogowanegoUzytkownika()
{
    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

char KsiazkaAdresowa :: wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze :: wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa :: wybierzOpcjeZMEnuUzytkownika()
{
    uzytkownikMenedzer.wybierzOpcjeZMEnuUzytkownika();
}

void KsiazkaAdresowa :: logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa :: zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa :: wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa :: wyswietlWszystkichAdresatow()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
         adresatMenedzer->wyswietlWszystkichAdresatow();
    }
    else
    {
        cout << "Aby wyswietlic wszystkich adresatow, nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}

void KsiazkaAdresowa :: dodajAdresata()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
         adresatMenedzer->dodajAdresata();
    }
    else
    {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}

void KsiazkaAdresowa :: wyszukajAdresatowPoImieniu()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
         adresatMenedzer->wyszukajAdresatowPoImieniu();
    }
    else
    {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}

void KsiazkaAdresowa :: wyszukajAdresatowPoNazwisku()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
         adresatMenedzer->wyszukajAdresatowPoNazwisku();
    }
    else
    {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}
