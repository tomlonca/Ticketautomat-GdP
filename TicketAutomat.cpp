// Implementación der Methoden der Klasse Ticketautomat.

#include"TicketAutomat.hpp"

int Ticketautomat::get_HS_Nummer(std::string HS)
{
    int counter = 0;
    for (const std::string& n : Fahrplan)
    {
        counter++;
        if (HS == n)
        {    
            return counter -1;
        }
    }
    return -1;
}

int Ticketautomat::Berechne_Preis(int Anzahl)
{
    // Berechnung des Preises basierend auf der Differenz der Positionen der Haltestellen im Fahrplan und der Anzahl der Tickets
    return fabs( get_HS_Nummer(Haltestelle1) - get_HS_Nummer(Haltestelle2)) * 3 * Anzahl;
}

Ticketautomat::~Ticketautomat()
{
    // Destruktor
    std::cout << "Vorgang beendet! " << std::endl;
}

Ticketautomat::Ticketautomat(int Linie, std::string HS1, std::string HS2, std::list<std::string> FahrP)
{
    // Konstruktor
    LinienNr = Linie;
    Haltestelle1 = HS1;
    Haltestelle2 = HS2;
    Fahrplan = FahrP;
    Preis = 0;
    Geld = 0;
    Rueckgeld = {};
}

void Ticketautomat::set_Geld(int n, std::list<int> m)
{
    // Setzen des eingegebenen Betrags und des Rückgelds
    Geld = n;
    Rueckgeld = m;
}

void Ticketautomat::set_Preis(int p)
{
    // Setzen des Preises
    Preis = p;
}

std::list<int> Ticketautomat::Berechne_Rueckgeld(int Betrag, std::list<int> &Automat_Rueckgeld)
{
    // Berechnung des Rückgelds
    std::list<int> Rueckgeld;
    int restbetrag = Betrag - Preis;
    for ( auto i = Automat_Rueckgeld.begin(); i != Automat_Rueckgeld.end(); )
    {
        restbetrag -= *i;   // *i, um den Wert zu parametrisieren.
        if (restbetrag < 0)
        {
            restbetrag += *i;
            i++;
        }
        else if (restbetrag > 0)
        {
            Rueckgeld.push_back(*i);
            i = Automat_Rueckgeld.erase(i);
        }
        else
        {
            Rueckgeld.push_back(*i);
            i = Automat_Rueckgeld.erase(i);
        }
    }
    return Rueckgeld;
}

int Ticketautomat::Eingabe_Geldbetrag(int Grenze_Betrag, int SAR, std::list<int> &Automat_Rueckgeld)
{
    // Eingabe des Geldbetrags und Berücksichtigung der Grenze und des verfügbaren Rückgelds im Automaten
    std::cout << "Zahlen Sie bitte den Betrag ein: ";
    int Betrag;
    do
    {
        std::cin >> Betrag;
        if (Betrag < Preis)
            std::cout << "Unzureichendes Geld. Versuchen Sie es nochmal: ";
        else if (Betrag > Grenze_Betrag)
        {
            std::cout << "Das Automat hat nicht genuegend Rueckgeld, um diesen Betrag anzunehmen.\n";
            std::cout << "Versuchen Sie es bitte nochmal mit einem kleineren Betrag: ";
        }
    } while (Betrag < Preis || Betrag > Grenze_Betrag);

    if (Betrag > Preis)
    {
        std::list<int> Rueckgeld = Berechne_Rueckgeld(Betrag, Automat_Rueckgeld);
        set_Geld(Betrag, Rueckgeld);
    }
    else
    {
        // Ist der gegebene Betrag passend, so wird Berechne_Rueckgeld() nicht aufgerufen.
        std::cout << "Betrag passend! \n";
        set_Geld(Betrag, {});
    }
    return Betrag;
}

void Ticketautomat::Drucke_Ticket()
{
    // Drucken des Tickets mit relevanten Informationen
    std::cout << "##########################################################################" << std::endl;
    std::cout << "|  Vor Fahrtantritt, bitte entwerten. / Please validate before use." << std::endl << "|  " << std::endl;
    std::cout << "|  Linie: " << LinienNr << std::endl;
    std::cout << "|  Von " << Haltestelle1 << " nach " << Haltestelle2 << std::endl;
    std::cout << "|  Preis: " << Preis << std::endl;
    std::cout << "|  Bezahlter Betrag: " << Geld << std::endl;
    std::cout << "|  Rueckgeld: ";
    for (auto n : Rueckgeld)
    {
        std::cout << n << "Geld   ";
    }
    std::cout << std::endl << "|  " << std::endl;
    std::cout << "|  Wir wuenschen Sie eine angenehme Reise.\n" << "|  " << std::endl;
    std::cout << "##########################################################################" << std::endl << std::endl;
}
