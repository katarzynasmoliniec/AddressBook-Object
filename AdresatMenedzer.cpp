#include "AdresatMenedzer.h"

AdresatMenedzer :: AdresatMenedzer()
{
    idOstatniegoAdresata = pobierzIdNowegoAdresata();
}

void AdresatMenedzer :: dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    PlikZAdresatami plikZAdresatami;
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}

int AdresatMenedzer :: pobierzIdNowegoAdresata()
{
    PlikZAdresatami plikZAdresatami;
    idOstatniegoAdresata = plikZAdresatami.pobierzIdNowegoAdresata();
    return idOstatniegoAdresata;
}

Adresat AdresatMenedzer :: podajDaneNowegoAdresata()
 {
    Adresat adresat;
    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(0);

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

void AdresatMenedzer :: wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    if (adresaci.empty())
    {
        PlikZAdresatami plikZAdresatami;
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    }
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
