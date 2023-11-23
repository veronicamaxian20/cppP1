#include "Ticket.h"

int Ticket::contor = 1;
int* Ticket::idRandom = nullptr;





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