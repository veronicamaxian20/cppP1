#pragma once
#include <iostream>
#include <string>
#include "EventLocation.h"


class Event 
{
public:
	enum EVENT_TYPE {CONCERT, MOVIE, SPORT, THEATRE, DIVERSE};
private:
	char* eventName;
	EVENT_TYPE eventType;
	EventLocation location;
	std::string dateAndTime; // Format: YYYY-MM-DD
	double duration;
	bool isACharityEvent;
public:
	static int TOTAL_EVENTS;

	char* getEventName() const;
	EVENT_TYPE getEventType() const;
	EventLocation getEventLocation() const;
	std::string getDateAndTime() const;
	double getDuration()const;
	bool getIfIsACharityEvent() const;

	void setEventName(const char*);
	void setEventType(EVENT_TYPE);
	void setLocation(const EventLocation&);
	void setDateAndTime(std::string);
	void setDuration(double);
	void setIfIsACharityEvent(bool);

	Event();
	Event(const char, EVENT_TYPE, EventLocation, std::string, double, bool);
	Event(const Event&);
	~Event();
	Event& operator=(const Event&);




};


