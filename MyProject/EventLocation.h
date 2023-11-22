#pragma once
#include <iostream>
#include <string>
#include "Event.h"


class EventLocation {

private:
	std::string* locationName;
	char* adress;
	Event* events;

public:
	static int nrEvents;
	static const int MAX_NR_OF_SEATS = 200;
	static const int  NR_SEATS_PER_ROW = 20;
	

};
