#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{
    vector <Adresat> adresaci;
    int idZalogowanegoUzytkownika;

    Adresat podajDaneNowegoAdresata();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void wyswietlDaneAdresata(Adresat adresat);
    int pobierzIdNowegoAdresata();
    PlikZAdresatami plikZAdresatami;

public:
    AdresatMenedzer(string nazwaPlizuZAdresatami) : plikZAdresatami(nazwaPlizuZAdresatami){
    idZalogowanegoUzytkownika = 0;
    };
    void dodajAdresata();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wyswietlWszystkichAdresatow();
    void ustawIdZalogowanegoUzytkownika(int nowyIdUzytkownika);
    void usuwanieAdresatowZpamieci();
};
#endif
