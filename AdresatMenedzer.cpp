#include "AdresatMenedzer.h"

void AdresatMenedzer :: dodajAdresata()
{
    Adresat adresat;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();
    adresaci.push_back(adresat);
    if(plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany." << endl;
    else
        cout << "blad. Nie udalo sie dodac nowego adresata do pliku." << endl;
    system("pause");
}

Adresat AdresatMenedzer :: podajDaneNowegoAdresata()
 {
    Adresat adresat;
    adresat.ustawId( (plikZAdresatami.pobierzIdOstatniegoAdresata()+ 1) );
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze:: wczytajLinie());
    adresat.ustawImie(MetodyPomocnicze:: zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze:: wczytajLinie());
    adresat.ustawNazwisko(MetodyPomocnicze:: zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze:: wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze:: wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze:: wczytajLinie());

    return adresat;
}

void AdresatMenedzer :: wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (size_t i = 0; i < adresaci.size(); i++)
        {
            wyswietlDaneAdresata(adresaci[i]);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer :: wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer :: wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze :: wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (size_t i = 0; i < adresaci.size(); i++)
        {
            if (adresaci[i].pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(adresaci[i]);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer :: wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze :: wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (size_t i = 0; i < adresaci.size(); i++)
        {
            if (adresaci[i].pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(adresaci[i]);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer :: wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}
