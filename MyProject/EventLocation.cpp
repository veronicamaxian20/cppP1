#include "EventLocation.h"

int EventLocation::reservedSeats = 0;

EventLocation::EventLocation()
	:locationName(""), address(nullptr), maxNrOfSeats(0), nrOfRows(0), idSeat(nullptr),
	seatType(SEAT_TYPE::BASIC), isFull(false) {
    this->maxNrOfSeats = 220;
    this->nrOfRows = this->maxNrOfSeats / EventLocation::NR_SEATS_PER_ROW;
    this->idSeat = new int* [nrOfRows];
    for (int i = 0; i < nrOfRows; i++) {
        this->idSeat[i] = new int[NR_SEATS_PER_ROW];
        for (int j = 0; j < NR_SEATS_PER_ROW; j++) {
            this->idSeat[i][j] = j + 1;
        }
    }
}


EventLocation::EventLocation(std::string locationName,int maxNrOfSeats, SEAT_TYPE seatType)
	: locationName(locationName), address(nullptr), maxNrOfSeats(0), nrOfRows(0), idSeat(nullptr),
	seatType(seatType), isFull(false) {

    this->locationName = locationName;
    this->maxNrOfSeats = maxNrOfSeats;
    this->nrOfRows = this->maxNrOfSeats / EventLocation::NR_SEATS_PER_ROW;
    this->idSeat = new int* [nrOfRows];
    for (int i = 0; i < nrOfRows; i++) {
        this->idSeat[i] = new int[NR_SEATS_PER_ROW];
        for (int j = 0; j < NR_SEATS_PER_ROW; j++) {
            this->idSeat[i][j] = j + 1;
        }
    }
    this->seatType = seatType;

}


