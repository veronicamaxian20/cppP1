#pragma once
#include <iostream>
#include <string>
#include "Event.h"

using namespace std;

class EventLocation {

private:
	string* locationName;
	char* adress;
	Event* events;

	static int nrEvents;

public:
	static const int MAX_NR_OF_SEATS = 200;
	static const int  NR_SEATS_PER_ROW = 20;
	

};
