#include"TicketAutomat.hpp"
#include"Funktionen.hpp"

int main ()
{   
    int SAR =0;  //Summe Automat Rueckgeld.
    std::list<int> Automat_Rueckgeld;

    Automat_Rueckgeld = LeseDatei_Rueckgeld();
    for (auto n : Automat_Rueckgeld)
        SAR += n;
    Wiederholung(SAR, Automat_Rueckgeld);
}

/**
 * @brief Hauptfunktion, die den Ablauf des Ticketautomaten steuert.
 * 
 * @param SAR: Summe des Rückgelds im Automaten.
 * @param Automat_Rueckgeld: Liste des Rückgelds im Automaten.
 * @return Rückgabe einer Statusvariable, die den Ablauf steuert.
 */
int Wiederholung(int &SAR, std::list<int> &Automat_Rueckgeld)
{
    int Linie, Grenze_Betrag, Anzahl;
    double Preis;
    std::string HS1, HS2;
    std::list<std::string> Fahrplan;

    std::cout << "Summe in Rueckgeldreservoir: " << SAR << std::endl << std::endl;

    std::cout << "Willkommen zum Ticketautomat der Stadt Leipzig!" << std::endl;
    std::cout << "Drucken Sie Enter, um fortzufahren.";
    std::cin.ignore();  //Macht weiter nur wenn Enter gedrueckt ist.
    std::cout << std::endl;
    
    Linie = Linie_Eingabe();

    Fahrplan = LeseDatei_Linie(Linie);
    Drucke_Fahrplan(Linie, Fahrplan);

    //Clear Input Buffer. Fehlervermeidung
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\nAnfangshaltestelle: ";
    HS1 = Eingabe_HS(Fahrplan);
    
    std::cout << "\nGeben Sie ihr Ziel ein: ";
    HS2 = Eingabe_HS(Fahrplan);

    std::cout << std::endl;

    Ticketautomat Ticket1(Linie, HS1, HS2, Fahrplan);  //Erzeugt ein neues Ticket mit den angegebenen Informationen.
    
    std::cout << "Wie viele Tickets brauchen Sie?: ";
    
    while (!(std::cin >> Anzahl))
    {
        std::cout << "Ungueltige Eingabe. Geben Sie bitte eine Zahl ein: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    Preis = Ticket1.Berechne_Preis(Anzahl);
    Ticket1.set_Preis(Preis);

    std::cout << "Der Fahrpreis von " << HS1 << " nach " << HS2 << " betraegt: " << Preis << " Geldeinheiten.\n";
    
    std::cout << std::endl << "Moechten Sie fortfahren? \n";    
    std::cin.clear();
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (! Fortfahren())
    {
        return 0;
    }

    //Grenze_Betrag wichtig fuer Eingabe_Betrag() und Berechne_Rueckgeld()
    //Repraesentiert dem hoechste zulaessige Betrag
    Grenze_Betrag = Preis + SAR;
    Ticket1.Eingabe_Geldbetrag(Grenze_Betrag, SAR, Automat_Rueckgeld);

    std::cout << std::endl << "Vielen Dank fuer ihren Kauf!\n\n";
    //Druckt so viele Tickets wie vom User gewuenschten.
    for (int i = 1; i <= Anzahl; i++)
        Ticket1.Drucke_Ticket();

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\nWuenschen Sie einen weiteren Ticket kaufen?\n";
    if (! Fortfahren())
    {
        return 0;
    }

    //Wird nur ausgefuehrt wenn User weitere Tickets kaufen kann.
    SAR = SAR_Aktuallisieren(Automat_Rueckgeld);
    Wiederholung(SAR, Automat_Rueckgeld);

return 0;
}
