#include "Event.h"

int Event::TOTAL_EVENTS = 0;

int Event::getTotalNrOfEvents() {
	return Event::TOTAL_EVENTS;
}
char* Event::getEventName() {
	return this->eventName;
}
EVENT_TYPE Event::getEventType() {
	return this->eventType;
}
char* Event::getDate() {
	return this->date;
}
double Event::getDuration() {
	return this->duration;
}


void Event::setEventName(const char* name) {
	if (this->eventName != nullptr) {
		delete[] this->eventName;
	}
	if (name != nullptr) {
		this->eventName = new char[strlen(name) + 1];
		strcpy_s(this->eventName, strlen(name) + 1, name);
	}
	else { this->eventName = nullptr; }
}
void Event::setEventType(EVENT_TYPE eventType) {
	this->eventType = eventType;
}
void Event::setDate(const char* newDate) {
	if (strlen(newDate) != 10) {
		throw std::exception("Invalid date format. Use DD-MM-YYYY");
	}
	if (newDate[2] != '-' || newDate[5] != '-') {
		throw std::exception("Wrong date format. Use '-'!");
	}
	strcpy_s(this->date, 10, newDate);
}
void Event::setDuration(double duration) {
	this->duration = duration;
}

Event::Event() : eventName(nullptr), duration(0.0)  {
	this->setEventName("None");
	this->setDate("00-00-0000");
	Event::TOTAL_EVENTS+=1;
}

Event::Event(const char* eventName, const char* date) {
	this->setEventName(eventName);
	this->setDate(date);
	Event::TOTAL_EVENTS += 1;
}

Event::~Event() {
	if (eventName != nullptr) {
		delete[] this->eventName;
	}
	if (date != nullptr) {
		delete[] this->date;
	}
	Event::TOTAL_EVENTS--;
}

Event::Event(const Event& copy) {
	if (copy.eventName != nullptr) {
		this->eventName = new char[strlen(copy.eventName) + 1];
		strcpy_s(this->eventName, strlen(copy.eventName) + 1, copy.eventName);
	}
	this->eventType = copy.eventType;
	this->setDate(copy.date);
	this->duration = copy.duration;

	Event::TOTAL_EVENTS++;
}

Event& Event::operator=(const Event& source) {
	if (this != &source) {
		if (this->eventName != nullptr) {
			delete[] this->eventName;
		}

		if (source.eventName != nullptr) {
			this->eventName = new char[strlen(source.eventName) + 1];
			strcpy_s(this->eventName, strlen(source.eventName) + 1, source.eventName);
		}
		else{
			this->eventName = nullptr;
		}
		this->eventType = source.eventType;
		this->setDate(source.date);
		this->duration = source.duration;

		Event::TOTAL_EVENTS++;
	}

	return *this;
}