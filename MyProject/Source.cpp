#include <iostream>
#include <string>
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



	if (concert == movie) {
		std::cout << "Event 1 is the same as Event 2" << std::endl;
	}
	else {
		std::cout << "Event 1 is not the same as Event 2" << std::endl;
	}

	Ticket ticket;

	std::cout << "\nEnter Ticket details:" << std::endl;
	std::cin >> ticket;

	ticket += 20; //adds 20 to price


	std::cout << "\nWould you like to see your ticket? Y/N ";
	char response1;
	std::cin >> response1;
	if (response1 == 'Y') {
		// Display the entered ticket details
		std::cout << "\nTicket details entered:" << std::endl;
		std::cout << ticket;


		if (!ticket) {
			std::cout << endl << "The seat is in the first row!";
		}
		else {
			std::cout << endl << "The seat is not in the first row!";
		}
	}






	std::cout << "\nWould you like to reduce the duration of the event? Y/N ";
	char response;
	std::cin >> response;
	do
	{
		switch (response)
		{
		case 'Y':
			concert -= 20;
			std::cout << "Concert Event after duration reduction:" << std::endl << concert << std::endl;
			break;
		case 'N':
			std::cout << "Ok, goodby!\n";
		}
	} while (response != 'N');
	return 0;
}


