#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"


using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    int pobierzIdNowegoUzytkownika();
    PlikZUzytkownikami plikZUzytkownikami;

public:
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};
#endif
