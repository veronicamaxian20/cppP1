#include <iostream>
#include "Event.h"
using namespace std;
int main() {

	/*Event concert("Horia Brenciu", "15-11-2023");
	concert.setEventType(Event::EVENT_TYPE::CONCERT);
	concert.setDuration(120);

	Event movie("Superman", "20-11-2023");
	movie.setEventType(Event::EVENT_TYPE::MOVIE);
	movie.setDuration(150);

	std::cout << "Concert Event:" << std::endl << concert << std::endl;
	std::cout << "Movie Event:" << std::endl << movie << std::endl;*/
	Event myEvent;

	try {
		std::cin >> myEvent;
		std::cout << "Event details:" << std::endl << myEvent;
	}
	catch (const std::exception& e) {
		std::cout<< "Error: " << e.what() << std::endl;
	}


 

}