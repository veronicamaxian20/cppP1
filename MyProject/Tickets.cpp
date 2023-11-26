#include "Tickets.h"

Tickets::Tickets() {
	this->tickets = nullptr;
	this->nrTickets = 0;
}

Tickets::Tickets(int nrTickets, Ticket** tickets) : nrTickets(nrTickets), tickets(nullptr) {
	if (nrTickets > 0 && tickets != nullptr) {
		this->tickets = new Ticket * [nrTickets];
		for (int i = 0; i < nrTickets; i++) {
			this->tickets[i] = new Ticket(*(tickets[i]));
		}
	}
	else {
		throw new std::exception("Invalid ticket vector");
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

void Tickets::setTickets(int nrTickets, Ticket** tickets)
{
	if (nrTickets > 0 && tickets != nullptr)
	{
		this->nrTickets = nrTickets;
		if (this->tickets != nullptr)
		{
			for (int i = 0; i < this->nrTickets; i++)
			{
				delete this->tickets[i];
			}
			delete[] this->tickets;
		}

		this->tickets = new Ticket * [nrTickets];
		for (int i = 0; i < nrTickets; i++)
		{
			this->tickets[i] = new Ticket(*(tickets[i]));
		}
	}
	else
	{
		throw new std::exception("Invalid ticket vector");
	}
}

bool Tickets::validateTicket(int ticketId) {
	for (int i = 0; i < nrTickets; i++)
	{
		if (ticketId == this->tickets[i]->getId())
		{
			return true;
		}
	}

	return false;
}

void Tickets::addTicket(const Ticket& ticket)
{
	Ticket** temp = new Ticket * [this->nrTickets + 1];
	Ticket* t = new Ticket(ticket);

	for (int i = 0; i < this->nrTickets; i++)
	{
		temp[i] = this->tickets[i];
	}

	temp[nrTickets] = t;

	delete[] this->tickets;
	this->tickets = temp;
	this->nrTickets++;
}


void Tickets::displayTicket(int id)
{
	for (int i = 0; i < nrTickets; i++)
	{
		if (id == (*this->tickets[i]).getId())
		{
			std::cout << *this->tickets[i];
			return;
		}
	}
}


void Tickets::operator+=(double val) {
	for (int i = 0; i < nrTickets; ++i) {
		(*(tickets[i])) += val;
	}
}
