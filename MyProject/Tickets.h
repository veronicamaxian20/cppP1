#pragma once
#include "Ticket.h"

class Tickets {
private:
	int nrTickets;
	Ticket** tickets;

//public:
//	int getNrTickets() const; //const p/u ca nu vrem sa se modif nimic
//	Tickets** getTickets() const;
//
//	void setTickets(int, Ticket*);
//
//	Tickets();
//	Tickets(int, Ticket*);
//	Tickets(const Tickets&);
//	~Tickets();
//	Tickets& operator=(const Tickets&);
//
//	bool validateTicket(int);
//	void addTicket(const Ticket&);
//	void displayTicket(int);
};