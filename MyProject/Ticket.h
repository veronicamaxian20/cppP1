#pragma once
#include <iostream>
#include <string>
#include "Event.h"


enum SEAT_TYPE { BASIC = 0, VIP = 2, WHEELCHAIR = 3 };
class Ticket {
	static constexpr const int PRICE_BASIC = 45;
	static constexpr const int PRICE_VIP = 75;
	static constexpr const int PRICE_WHEELCHAIR = 40;
	static int* idRandom;
protected:
	const int idTicket;
	std::string titular;
	double price;
	SEAT_TYPE seatType;
	Event* event;
	int idRow;
	int idSeat;
};