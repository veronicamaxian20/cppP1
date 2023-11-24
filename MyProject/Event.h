#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "EventLocation.h"
#include <list>;


class Event 
{
public:
	enum class EVENT_TYPE { CONCERT = 1, MOVIE, SPORT, THEATRE, DIVERSE };

private:
	char* eventName;
	EVENT_TYPE eventType;
	char date[11]; // Format: DD-MM-YYYY
	double duration; //in min

	static int TOTAL_EVENTS;
	//bool isACharityEvent;
	//EventLocation location;

public:
	static int getTotalNrOfEvents();

	char* getEventName();
	EVENT_TYPE getEventType();
	char* getDate();
	double getDuration();

	//EventLocation getEventLocation() const;
	//bool getIfIsACharityEvent() const;

	void setEventName(const char*);
	void setEventType(EVENT_TYPE);
	void setDate(const char* newDate);
	void setDuration(double);
	//void setLocation(const EventLocation&);
	//void setIfIsACharityEvent(bool);

	Event();
	Event(const char* eventName, const char* date);

	~Event();
	Event(const Event&);
	Event& operator=(const Event&);

	
	friend std::ostream& operator<<(std::ostream&, const Event&);
	friend std::istream& operator>>(std::istream&, Event&);
	
	
	//2 generic methods


	//2 operatori - cred ca merge op[]

};


