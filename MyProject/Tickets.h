#pragma once
#include "Ticket.h"

class Tickets {
private:
	int nrTickets;
	Ticket** tickets;

public:
	Tickets();
	Tickets(int, Ticket*);
	Tickets(const Tickets&);
	~Tickets();
	Tickets& operator=(const Tickets&);

	int getNrTickets() const; //const p/u ca nu vrem sa se modif nimic
	Ticket** getTickets() const;

	void setTickets(int, Ticket*);

	

	bool validateTicket(int);
	void addTicket(const Ticket&);
	void displayTicket(int);
};