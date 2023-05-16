#ifndef PLIKIZADRESATAMI_H
#define PLIKIZADRESATAMI_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "Adresat.h"
//#include "AdresatMenedzer.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
    string nazwaPlikuZAdresatami;

    bool czyPlikJestPusty();
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);


public:
    PlikZAdresatami();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void dopiszAdresataDoPliku(Adresat adresat);
};
#endif
