#pragma once
#include <iostream>
#include <string>
#include "Event.h"


class Ticket {
	static constexpr int PRICE_BASIC = 45;
	static constexpr int PRICE_VIP = 75;
	static constexpr int PRICE_WHEELCHAIR = 40;
	
	static int* idRandom;
	static int contor;
private:
	int idTicket;
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

	int getId() const;
	std::string getHolder()const;
	double getPrice() const;
	Event* getEvent() const;
	int getIdRow() const;
	int getIdSeat() const;

	void setHolder(std::string);
	void setPrice(double );
	void setEvent(const Event&);
	void setIdRow(int);
	void setIdSeat(int);


	void generateRandomID();
	static int customRandom();

	friend std::ostream& operator<<(std::ostream&, const Ticket&);
	friend std::istream& operator>>(std::istream&, Ticket&);

	explicit operator double() {
		return this->price;
	}

	//operator +=  add val to price
	void operator+=(double val);



};