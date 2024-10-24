//Header-Datei mit zusaetzlichen Funktionen fuer die Main.

#pragma once
#include<string>
#include<cmath>
#include<vector>
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<list>
#include<limits>
#include<algorithm>


int Wiederholung(int &SAR, std::list<int> &Automat_Rueckgeld); // Hauptfunktion, die den Ablauf des Ticketautomaten steuert
int Linie_Eingabe();    //Eingabe einer gueltigen Linie
int SAR_Aktuallisieren(std::list<int> &Automat_Rueckgeld);  //Summe Automat Rueckgeld aktuellisieren.
std::list<std::string> LeseDatei_Linie(int Linie);
std::list<int> LeseDatei_Rueckgeld();   //Datei fuer das Rueckgeld lesen und in liste speichern.
std::string Eingabe_HS(const std::list<std::string>& Fahrplan);  //Eingabe der HS und prueft ob sie da ist mithilfe teste_HS()
void Drucke_Fahrplan(int Linie, std::list<std::string> &Fahrplan);
bool Fortfahren();

/**
 * @brief Überprüft, ob der Benutzer fortsetzen möchte.
 * 
 * @return True, wenn der Benutzer fortfahren möchte, False sonst.
 */
bool Fortfahren() {
    std::string input;
    std::cout << "[1]_Ja\n" << "[2]_Nein\n";
    std::getline(std::cin, input);

    if (input == "1") {
        return true;
    } else if (input == "2") {
        return false;
    } else {
        std::cout << "Ungueltige Eingabe. Bitte geben Sie 1 oder 2 ein:" << std::endl;
        return Fortfahren(); // Se llama a la función de nuevo si la entrada no es válida
    }
}

/**
 * @brief Liest den Fahrplan aus einer Datei ein.
 * 
 * @param Linie: Die Nummer der Straßenbahnlinie.
 * @return Eine Liste mit den Haltestellen des Fahrplans.
 */
std::list<std::string> LeseDatei_Linie(int Linie)
{
    std::ifstream file;
    std::string line;
    std::list<std::string> Fahrplan {}; 

    std::string filename = "Linie" + std::to_string(Linie) + ".txt";
    file.open(filename);

    if (file.is_open())
    {
        while (std::getline(file, line))
        Fahrplan.push_back(line);
        file.close();
    }
    else
        std::cout << "Fahrplan nicht gefunden" << std::endl;

//Rückgabe des Fahrplans als Vektor von Strings
return Fahrplan;
}

/**
 * @brief Liest die Rückgeldinformationen aus einer Datei ein.
 * 
 * @return Eine Liste mit den Rückgeldinformationen.
 */
std::list<int> LeseDatei_Rueckgeld()
{
    std::string line;
    std::string filename = "Rueckgeld.txt";
    std::ifstream file;
    std::list<int> Rueckgeld;

    file.open(filename);

    if (file.is_open()) 
    {
        while (std::getline(file, line))
        {
            int wert = std::stoi(line);
            Rueckgeld.push_back(wert);
        }
        file.close();
    } 
    else 
    {
        std::cerr << "Datei nicht gefunden. " << filename << std::endl;
    }
// Rückgabe der Liste mit Rückgeldinformationen
return Rueckgeld;
}

/**
 * @brief Eingabe einer Haltestelle und Überprüfung ihrer Gültigkeit.
 * 
 * @param Fahrplan: Liste der Haltestellen des Fahrplans.
 * @return Die eingegebene Haltestelle.
 */
std::string Eingabe_HS(const std::list<std::string>& Fahrplan)
{
    std::string HS;
    do
    {
        std::getline(std::cin, HS);

        if (!(std::find(Fahrplan.begin(), Fahrplan.end(), HS) != Fahrplan.end()))
        {    
            std::cout << "Haltestelle nicht vorhanden. Versuchen Sie es noch einmal.\n";
        }
    } while (!(std::find(Fahrplan.begin(), Fahrplan.end(), HS) != Fahrplan.end()));

return HS;
}

/**
 * @brief Eingabe einer gültigen Linie.
 * 
 * @return Die eingegebene Linie.
 */
int Linie_Eingabe()
{
    int Linie;
    std::cout << "Mit welcher Strassenbahnlinie moechten Sie heute fahren?\n";
    while (!(std::cin >> Linie) || (Linie != 10 && Linie != 11 && Linie != 9 && Linie != 16))
    {
        std::cout << "Ungueltige Eingabe. Geben Sie bitte eine gueltige Liniennummer (9, 10, oder 11) ein: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
return Linie;
}

/**
 * @brief Druckt den Fahrplan für eine bestimmte Linie.
 * 
 * @param Linie: Die Nummer der Straßenbahnlinie.
 * @param Fahrplan: Liste der Haltestellen des Fahrplans.
 */
void Drucke_Fahrplan(int Linie, std::list<std::string> &Fahrplan)
{
    if (!Fahrplan.empty())
    {
        std::cout << std::endl <<"Fahrplan fuer Linie " << Linie << ":\n";
        for (std::string& haltestelle : Fahrplan)
            std::cout << haltestelle << std::endl;
    }
}

/**
 * @brief Aktualisiert die Summe des Rückgelds im Automaten.
 * 
 * @param Automat_Rueckgeld: Liste des Rückgelds im Automaten.
 * @return Die aktualisierte Summe des Rückgelds.
 */
int SAR_Aktuallisieren(std::list<int> &Automat_Rueckgeld)
{
    int SAR = 0;
    for (auto n : Automat_Rueckgeld)
    {
        SAR += n;
    }
return SAR;
}
