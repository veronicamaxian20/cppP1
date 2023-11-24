#include "Ticket.h"

int Ticket::contor = 1;
int* Ticket::idRandom = nullptr;

Ticket::Ticket() : idTicket(contor++) {
    if (!idRandom) {
        generateRandomID();
    }    
    holder = "";
    price = 0.0;
    event = nullptr;
    idRow = 0;
    idSeat = 0;
}

Ticket::Ticket(std::string holder, double price, Event* event) 
    :idTicket(contor++) {
    if (!idRandom) {
        generateRandomID();
    }
    this->holder = holder;
    this->price = price;
    this->event = event;
    idRow = 0;
    idSeat = 0;
}
Ticket::~Ticket(){
    delete[] idRandom;
    delete event;
}

Ticket::Ticket(const Ticket& source) 
    : idTicket(source.idTicket) 
{
    if (source.event) {
        this->event = new Event(*(source.event));
    }
    else {
        this->event = nullptr;
    }
    this->holder = source.holder;
    this->price = source.price;
    this->idRow = source.idRow;
    this->idSeat = source.idSeat;
}

Ticket& Ticket::operator=(const Ticket& source) {
    if (this != &source) {
        //delete event;

        if (source.event) {
            this->event = new Event(*(source.event));
        }
        else {
            this->event = nullptr;
        }
        this->holder = source.holder;
        this->price = source.price;
        this->idRow = source.idRow;
        this->idSeat = source.idSeat;
    }
    return *this;
}


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

int Ticket::getId() const {
    return this->idTicket;
}
std::string Ticket::getHolder() const {
    return this->holder;
}
double Ticket::getPrice() const {
    return this->price;
}
Event* Ticket::getEvent() const {
    return this->event;
}
int Ticket::getIdRow() const {
    return this->idRow;
}
int Ticket::getIdSeat() const {
    return this->idSeat;
}


void Ticket::setHolder(std::string) {
    if (holder != ""){
        this->holder = holder;
    }
    else
    {
        throw new std::exception("Empty holder");
    }
}
void Ticket::setPrice(double price) {
    if (price > 0.0)
    {
        this->price = price;
    }
    else
    {
        throw new std::exception("Invalid price");
    }
}
void Ticket::setEvent(const Event& obj) {
    *this->event = obj;
}
