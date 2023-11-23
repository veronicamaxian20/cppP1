#pragma once
#include <iostream>
#include <string>
#include "Event.h"


class EventLocation {
public:
	enum class SEAT_TYPE { BASIC = 0, VIP = 1, WHEELCHAIR = 2 };
private:
	static constexpr const int  NR_SEATS_PER_ROW = 20;
	static int reservedSeats;

	std::string locationName;
	char* address;
	int maxNrOfSeats;
	int nrOfRows;
	int** idSeat;
	SEAT_TYPE seatType;
	bool isFull;	
public:
	EventLocation();
	EventLocation(std::string,int, SEAT_TYPE);
	EventLocation(const EventLocation&);
	~EventLocation();
	EventLocation& operator=(const EventLocation&);

	int getReservedSeats() const;
	std::string getLocationName() const;
	char* getAddress() const;
	int getMaxNrOfSeats() const;
	int getNrOfRows() const;
	int** getIdSeat() const;
	SEAT_TYPE getSeatType() const;
	bool getIfIsFull() const;

	void setReservedSeats(int);
	void setLocationName(std::string);
	void setAddress(char*);
	void setMaxNrOfSeats(int);
	void setNrOfRows(int);
	void setIdSeat(int, int**);
	void setSeatType(SEAT_TYPE);
	void setIfIsFull(bool);


	void setSeatType(SEAT_TYPE);

};
