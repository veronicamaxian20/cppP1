#pragma once
#include <iostream>
#include <string>

using namespace std;

enum EVENT_TYPE {CONCERT, MOVIE, SPORT, THEATRE, DIVERSE};

class Event {
private:
	const char* eventName;
	char date[11] = "";
	char time[6];
	double duration;
	EVENT_TYPE eventType;
	bool isACharityEvent;


public:
	//static int reservedSeats;
	static int TOTAL_EVENTS;

};


