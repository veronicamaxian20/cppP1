#include <iostream>
#include <string>
#include "Event.h"
#include "Ticket.h"
#include "Tickets.h"
using namespace std;
int main() {


//Event concert("Horia Brenciu", "15-11-2023");
//concert.setEventType(Event::EVENT_TYPE::CONCERT);
//concert.setDuration(120);

//Event movie("Superman", "20-11-2023");
//movie.setEventType(Event::EVENT_TYPE::MOVIE);
//movie.setDuration(150);

//std::cout << "Concert Event:" << std::endl << concert << std::endl;
//std::cout << "Movie Event:" << std::endl << movie << std::endl;



//if (concert == movie) {
//	std::cout << "Event 1 is the same as Event 2" << std::endl;
//}
//else {
//	std::cout << "Event 1 is not the same as Event 2" << std::endl;
//}


//ticket += 20; //adds 20 to price


    Tickets tickets;
    Event event;

    int choice;
    do {
        cout << "\n=== MENU ===\n";
        cout << "[1] Add Ticket\n";
        cout << "[2] Validate Ticket\n";
        cout << "[3] Display Ticket\n";
        cout << "[4] Verify if Seat is in the First Row\n";
        cout << "[5] Add Event\n";
        cout << "[6] Display Event\n";
        cout << "[7] Reduce Duration of an Event\n";
        cout << "[8] Add $20 to the ticket's price\n";
        cout << "[0] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int numberOfTickets;
            cout << "How many tickets would you like to add? (1 or 2): ";
            cin >> numberOfTickets;
            // Clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (numberOfTickets) {
            case 1: {
                Ticket ticket1;
                cout << "\nEnter Ticket details for Ticket 1:" << endl;
                cin >> ticket1;
                tickets.addTicket(ticket1);
                break;
            }
            case 2: {
                Ticket ticket1, ticket2;
                cout << "\nEnter Ticket details for Ticket 1:" << endl;
                cin >> ticket1;
                // Clear the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "\nEnter Ticket details for Ticket 2:" << endl;
                cin >> ticket2;
                // Clear the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                tickets.addTicket(ticket1);
                tickets.addTicket(ticket2);
                break;
            }
            default:
                cout << "Invalid choice. Please enter 1 or 2.\n";
                break;
            }
            break;
        }
        case 2: {
            int ticketIdToValidate;
            cout << "Enter the ticket ID to validate: ";
            cin >> ticketIdToValidate;
            if (tickets.validateTicket(ticketIdToValidate)) {
                cout << "Ticket with ID " << ticketIdToValidate << " is valid.\n";
            }
            else {
                cout << "Ticket with ID " << ticketIdToValidate << " is not valid.\n";
            }
            break;
        }
        case 3: {
            int ticketIdToDisplay;
            cout << "Enter the ticket ID to display: ";
            cin >> ticketIdToDisplay;
            cout << "\nDisplaying details for Ticket with ID " << ticketIdToDisplay << ":\n";
            tickets.displayTicket(ticketIdToDisplay);
            break;
        }
        case 4: {
            int ticketIdToVerify;
            cout << "Enter the ticket ID to verify if the seat is in the first row: ";
            cin >> ticketIdToVerify;
            if (!ticketIdToVerify) {
                std::cout << endl << "The seat is not in the first row!";
                }
                else {
                std::cout << endl << "The seat is in the first row!";
                }
            break;
        }
        case 5: {
            cout << "\nEnter Event details:" << endl;
            // Clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> event;
            break;
        }
        case 6: {
            cout << "\nDisplaying details for the Event:\n";
            cout << event << endl;
            break;
        }
        case 7: {
            event -= 20;
            std::cout << "Event after duration reduction:" << std::endl << event << std::endl;
            break;
        }
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 0);

    return 0;
}
