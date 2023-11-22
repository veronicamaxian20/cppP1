#pragma once
#include <iostream>
#include <string>

using namespace std;

enum EVENT_TYPE {CONCERT, MOVIE, SPORT, THEATRE, DIVERSE};

class Event {
private:
	const char* eventName;


	double duration;
	EVENT_TYPE eventType;

	static int reservedSeats;

};