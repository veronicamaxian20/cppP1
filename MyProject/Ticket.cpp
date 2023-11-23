#include "Ticket.h"

int Ticket::contor = 1;
int* Ticket::idRandom = nullptr;

//Ticket::Ticket() : idTicket(contor++) {
//    generateRandomID();
//    holder = "";
//    price = 0.0;
//    event = nullptr;
//    idRow = 0;
//    idSeat = 0;
//}
//
//Ticket::Ticket(std::string holder, double price, Event* event) : idTicket(contor++) {
//    generateRandomID();
//    this->holder = holder;
//    this->price = price;
//    this->event = event;
//    idRow = 0;
//    idSeat = 0;
//}



void Ticket::generateRandomID() {
    idRandom = new int[100];
    for (int i = 0; i < 100; i++) {
        idRandom[i] = customRandom();
    }
}

int Ticket::customRandom() {
    contor = (contor * 16807) % 701;
    return contor;
}