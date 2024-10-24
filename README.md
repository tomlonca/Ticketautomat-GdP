# Ticketautomat Projekt GdP 🚊

~ This was my project in my first semester of university. The name of the subject was Grundlagen der Programmierung (german for basics of programming). It is a simple code to emulate a ticket machine for public transportation.

~ It is coded in C++ and the user interacts with it over the terminal. it contains only a couple of tram lines from Leipzig (Lines 9, 10 and 11).

~ It is not perfect at all, there are some details that needed to be taken care of, but at the time I didn't know how to do it 😅

~ There is a main file which is the controller of the machine itself. Then there is the file "TicketAutomat.hpp" which is a kind of interface for the class "TicketAutomat.cpp", which contains the implementation of all those methods of the class.

~ Thank you very much for stopping by. Hope you like it as much as I do 🤍.

# Functionality:
The user starts by entering a valid public transportation line followed by the origin and the destination of the ride. After that, they will be asked how many tickets with that jurney they need. To complete the transaction, price is displayed for the user to enter a valid amount of money to pay the price. The machine is able to give change back for amounts greater than the price of the ticket(s). At the end, the user will be asked if they need some more tickets. If not, the process ends and everything is resetted and the ticket(s) are displayed on the terminal. Else, the process starts again but with less change than it had before, since it gave it to the user in other transactions.
