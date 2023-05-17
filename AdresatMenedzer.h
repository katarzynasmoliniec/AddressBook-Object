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
    int idOstatniegoAdresata;

    Adresat podajDaneNowegoAdresata();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

public:
    AdresatMenedzer();

    vector <Adresat> dodajAdresata();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();

   // void wyswietlDaneAdresata(Adresat adresat);
    //void dopiszAdresataDoPliku(Adresat adresat);

};
#endif
