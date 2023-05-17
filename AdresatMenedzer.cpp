#include "AdresatMenedzer.h"

AdresatMenedzer :: AdresatMenedzer()
{
    idOstatniegoAdresata = 0;
}

vector <Adresat> AdresatMenedzer :: dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    PlikZAdresatami plikZAdresatami;
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return adresaci;
}

Adresat AdresatMenedzer :: podajDaneNowegoAdresata()
 {
    Adresat adresat;
    adresat.ustawId(++idOstatniegoAdresata);
    adresat.pobierzIdUzytkownika();

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

int AdresatMenedzer :: wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    if (adresaci.empty())
    {
        PlikZAdresatami plikZAdresatami;
        idOstatniegoAdresata = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
        return idOstatniegoAdresata;
    }
    else
        return idOstatniegoAdresata = 0;
}
