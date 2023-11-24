#include <iostream>
#include "Event.h"
#include "Ticket.h"
using namespace std;
int main() {
	Event concert("Horia Brenciu", "15-11-2023");
	concert.setEventType(Event::EVENT_TYPE::CONCERT);
	concert.setDuration(120);

	Event movie("Superman", "20-11-2023");
	movie.setEventType(Event::EVENT_TYPE::MOVIE);
	movie.setDuration(150);

	std::cout << "Concert Event:" << std::endl << concert << std::endl;
	std::cout << "Movie Event:" << std::endl << movie << std::endl;
	
	Ticket ticket;

	std::cout << "Enter Ticket details:" << std::endl;
	std::cin >> ticket;

	// Display the entered ticket details
	std::cout << "Ticket details entered:" << std::endl;
	std::cout << ticket;

	return 0;
}


