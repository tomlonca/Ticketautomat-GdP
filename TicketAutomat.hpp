// Einzige Klasse.
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

/**
 * @brief Die Klasse "Ticketautomat" repräsentiert einen Ticketautomaten für den öffentlichen Nahverkehr.
 * 
 * Alle Variablen zusammen bilden das eigentliche Ticket.
 * Werden am Ende des Programms auf dem Terminal ausgedrueckt.
 */
class Ticketautomat
{
private:
    int LinienNr, Geld, Preis; // Liniennummer, eingegebener Betrag, Preis der Fahrt
    std::list<int> Rueckgeld {}; // Liste für Rückgeld
    std::list<std::string> Fahrplan; // Liste aller Haltestellen
    std::string Haltestelle1, Haltestelle2; // Anfangs- und Endhaltestelle

public:
    /**
     * @brief Konstruktor der Klasse Ticketautomat.
     * 
     * @param Linie: Die Liniennummer.
     * @param HS1: Die Anfangshaltestelle.
     * @param HS2: Die Endhaltestelle.
     * @param FahrP: Der Fahrplan mit allen Haltestellen.
     */
    Ticketautomat(int Linie, std::string HS1, std::string HS2, std::list<std::string> FahrP);

    /**
     * @brief Destruktor der Klasse Ticketautomat.
     * 
     */
    ~Ticketautomat();

    /**
     * @brief Gibt die Position einer Haltestelle im Fahrplan zurück.
     * 
     * @param HS: Die Haltestelle, deren Position im Fahrplan gesucht wird.
     * @return Die Position der Haltestelle im Fahrplan.
     */
    int get_HS_Nummer(std::string HS);

    /**
     * @brief Gibt die Liste des Rückgelds zurück.
     * 
     * @return Die Liste des Rückgelds.
     */
    std::list<int> get_Rueckgeld();

    /**
     * @brief Setzt den Preis der Fahrt.
     * 
     * @param p: Der Preis der Fahrt.
     */
    void set_Preis(int p);

    /**
     * @brief Setzt den vom Kunden eingegebenen Betrag und das Rückgeld.
     * 
     * @param n: Der eingegebene Betrag.
     * @param m: Das Rückgeld.
     */
    void set_Geld(int n, std::list<int> m);

    /**
     * @brief Berechnet den Preis der Fahrt basierend auf der Anzahl der Tickets.
     * 
     * Der Preis wird auf 3 Geldeinheiten festgestellt.
     * 
     * @param Anzahl: Die Anzahl der gekauften Tickets.
     * @return Der Preis der Fahrt.
     */
    int Berechne_Preis(int Anzahl);

    /**
     * @brief Druckt das Ticket mit den relevanten Informationen.
     * 
     */
    void Drucke_Ticket();

    /**
     * @brief Ermöglicht die Eingabe des Geldbetrags und berücksichtigt die Grenze und das bereits im Automaten verfügbare Rückgeld.
     * 
     * @param Grenze_Betrag: Die Grenze für den eingegebenen Betrag.
     * @param summe_automat_rueckgeld: Die Summe des im Automaten verfügbaren Rückgelds.
     * @param Automat_Rueckgeld: Die Liste des im Automaten verfügbaren Rückgelds.
     * @return Der eingegebene Geldbetrag.
     */
    int Eingabe_Geldbetrag(int Grenze_Betrag, int summe_automat_rueckgeld, std::list<int> &Automat_Rueckgeld);

    /**
     * @brief Berechnet das Rückgeld basierend auf dem eingezahlten Betrag und dem verfügbaren Rückgeld im Automaten.
     * 
     * @param Betrag: Der eingezahlte Betrag.
     * @param Automat_Rueckgeld: Die Liste des im Automaten verfügbaren Rückgelds.
     * @return Die Liste des zurückzugebenden Rückgelds.
     */
    std::list<int> Berechne_Rueckgeld(int Betrag, std::list<int> &Automat_Rueckgeld);
};
