#pragma once
#include <iostream>
#include <string>
#include "Event.h"


class Ticket {
	static constexpr const int PRICE_BASIC = 45;
	static constexpr const int PRICE_VIP = 75;
	static constexpr const int PRICE_WHEELCHAIR = 40;
	static int* idRandom;
protected:
	const int idTicket;
	std::string holder;
	double price;
	Event* event;
	int idRow;
	int idSeat;

public:
	Ticket();
	Ticket(std::string, double, Event*);
	Ticket(const Ticket&);
	~Ticket();
	Ticket& operator=(const Ticket& source);

	const int getId() const;
	std::string getHolder()const;
	double getPrice() const;
	Event* getEvent() const;
	int getIdRow() const;
	int getIdSeat() const;

	void setHolder(std::string);
	void setPrice(double);
	void setEvent(const Event&);


};