//#include <iostream>
//#include "Event.h"
using namespace std;
//int main() {
//
//
//	/*Event concert("Horia Brenciu", "15-11-2023");
//	concert.setEventType(Event::EVENT_TYPE::CONCERT);
//	concert.setDuration(120);
//
//	Event movie("Superman", "20-11-2023");
//	movie.setEventType(Event::EVENT_TYPE::MOVIE);
//	movie.setDuration(150);
//
//	std::cout << "Concert Event:" << std::endl << concert << std::endl;
//	std::cout << "Movie Event:" << std::endl << movie << std::endl;*/
//	
//	//Idee cum sa afisez evenimentele - ?
//	//std::list<Event> eventList;
//	//Event myEvent;
//	//try {
//	//	std::cin >> myEvent;
//	//	eventList.push_back(myEvent);
//	//}
//	//catch(const std::exception& e){
//	//	std::cout << "Error: " << e.what() << std::endl;
//	//}
//	//for (int i = 0; i < eventList.size(); i++) {
//	//	std::cout << eventList[i] << std::endl;
//	//}
//
//
//	//cout << myEvent.getTotalNrOfEvents();
//
// 
//
//
//
//}

#include <iostream>
#include "Event.h"
#include "Ticket.h"

int main() {
    // Test Event class
    Event concert("Music Festival", "15-11-2023");
    concert.setEventType(Event::EVENT_TYPE::CONCERT);
    concert.setDuration(120);

    std::cout << "Event Details:" << std::endl;
    std::cout << concert << std::endl;

    // Test Ticket class
    try {
        Ticket ticket("John Doe", 50.0, &concert);
        ticket.setIdRow(1);
        ticket.setIdSeat(10);

        std::cout << "Ticket Details:" << std::endl;
        std::cout << ticket << std::endl;

        // Modify ticket details
        ticket.setPrice(60.0);
        ticket.setHolder("Jane Doe");

        std::cout << "Updated Ticket Details:" << std::endl;
        std::cout << ticket << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
