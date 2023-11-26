#include "Tickets.h"

Tickets::Tickets() {
	//this->tickets = nullptr;
	this->nrTickets = 0;
}

Tickets::Tickets(int nrTickets, Ticket* tickets)
:nrTickets(0), tickets(nullptr)
{
	this->nrTickets = nrTickets;
	this->tickets = new Ticket * [nrTickets];
	for (int i = 0; i < nrTickets; i++) {
		this->tickets[i] = &tickets[i];
	}
}
//copy cTor
Tickets::Tickets(const Tickets& source)
	:nrTickets(0), tickets(nullptr)
{
	this->nrTickets = source.nrTickets;
	this->tickets = new Ticket * [source.nrTickets];
	for (int i = 0; i < source.nrTickets; i++) {
		this->tickets[i] = source.tickets[i];
	}
}
//op =
Tickets& Tickets::operator=(const Tickets& source) {
	if (this != &source) {
		this->nrTickets = source.nrTickets;

		if (this->tickets != nullptr) {
			delete[] this->tickets;
		}
		this->tickets = new Ticket * [source.nrTickets];
		for (int i = 0; i < source.nrTickets; i++) {
			this->tickets[i] = source.tickets[i];
		}
	}
	return *this;
}

Tickets::~Tickets() {
	if (this->tickets != nullptr) {
		delete[] this->tickets;
	}
}


int Tickets::getNrTickets() const { return this->nrTickets; }
Ticket** Tickets::getTickets() const { return this->tickets; } 


void Tickets::setTickets(int nrTickets, Ticket* tickets)
{
	if (nrTickets > 0 && tickets != nullptr)
	{
		this->nrTickets = nrTickets;

		if (this->tickets != nullptr)
			delete[] this->tickets;

		this->tickets = new Ticket * [nrTickets];
		for (int i = 0; i < nrTickets; i++)
		{
			this->tickets[i] = &tickets[i];
		}
	}
	else
	{
		throw new std::exception("Invalid ticket vector");
	}
}


