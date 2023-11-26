#include "Ticket.h"
#include "EventLocation.h"

int Ticket::contor = 1;
//int* Ticket::idRandom = nullptr;

Ticket::Ticket() : idTicket(contor++) {
   /* if (!idRandom) {
        generateRandomID();
    }  */  
    holder = "";
    price = 0.0;
    event = nullptr;
    idRow = 0;
    idSeat = 0;
}

Ticket::Ticket(std::string holder, double price, Event* event) 
    :idTicket(contor++) {
   /* if (!idRandom) {
        generateRandomID();
    }*/
    this->holder = holder;
    this->price = price;
    this->event = event;
    idRow = 0;
    idSeat = 0;
}
Ticket::~Ticket(){
    //delete idRandom;
    delete event;
}

Ticket::Ticket(const Ticket& source) 
    : idTicket(source.idTicket) 
{
    if (source.event) {
        this->event = new Event(*(source.event));
    }
    else {
        this->event = nullptr;
    }
    this->holder = source.holder;
    this->price = source.price;
    this->idRow = source.idRow;
    this->idSeat = source.idSeat;
}

Ticket& Ticket::operator=(const Ticket& source) {
    if (this != &source) {
        //delete event;

        if (source.event) {
            this->event = new Event(*(source.event));
        }
        else {
            this->event = nullptr;
        }
        this->holder = source.holder;
        this->price = source.price;
        this->idRow = source.idRow;
        this->idSeat = source.idSeat;
    }
    return *this;
}


//void Ticket::generateRandomID() {
//    idRandom = new int[100];
//    for (int i = 0; i < 100; i++) {
//        idRandom[i] = customRandom();
//    }
//}
//int Ticket::customRandom() {
//    contor = (contor * 16807) % 701;
//    return contor;
//}

int Ticket::getId() const {
    return this->idTicket;
}
std::string Ticket::getHolder() const {
    return this->holder;
}
double Ticket::getPrice() const {
    return this->price;
}
Event* Ticket::getEvent() const {
    return this->event;
}
int Ticket::getIdRow() const {
    return this->idRow;
}
int Ticket::getIdSeat() const {
    return this->idSeat;
}


void Ticket::setHolder(std::string) {
    if (!holder.empty()){
        this->holder = holder;
    }else {
        throw new std::exception("Empty holder");
    }}
void Ticket::setPrice(double price) {
    if (price > 0.0)
    {
        this->price = price;
    }
    else
    {
        throw new std::exception("Invalid price");
    }
}
void Ticket::setEvent(const Event& obj) {
    if (!event) {
        event = new Event(obj);
    }
    else {
        *event = obj;
    }
}
void Ticket::setIdRow(int row) {
    if (row > 0 && row ) {
        this->idRow = row;
    }
    else {
        throw std::invalid_argument("Invalid row ID. Row ID should be greater than 0.");
    }
}

void Ticket::setIdSeat(int seat) {
    if (seat > 0) {
        this->idSeat = seat;
    }
    else {
        throw std::invalid_argument("Invalid seat ID. Seat ID should be greater than 0.");
    }
}



std::ostream& operator<<(std::ostream& out, const Ticket& obj)
{
    out << "============================== TICKET ==============================" << std::endl;
    out << "===== ID       : " << obj.getId() << std::endl;
    out << "===== HOLDER   : " << obj.getHolder() << std::endl;
    out << "===== PRICE    : " << obj.getPrice() << std::endl;
   /* out << "===== EVENT NAME   : " << obj.getEvent()->getEventName() << std::endl;
    out << "===== EVENT TYPE   : ";
        switch (obj.getEvent()->getEventType())
        {
        case Event::EVENT_TYPE::CONCERT:
            out << "Concert, ";
            break;
        case Event::EVENT_TYPE::MOVIE:
            out << "Movie, ";
            break;
        case Event::EVENT_TYPE::SPORT:
            out << "Sport, ";
            break;
        case Event::EVENT_TYPE::THEATRE:
            out << "Theatre, ";
            break;
        case Event::EVENT_TYPE::DIVERSE:
            out << "Diverse, ";
            break;
        default:
            break;
        }
    out << std::endl;*/
    out << "===== ROW      : " << obj.getIdRow() << std::endl;
    out << "===== SEAT     : " << obj.getIdSeat() << std::endl;
    out << "===================================================================" << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Ticket& obj) {
    //in.ignore();
    std::cout << "Enter Holder : "; 
    std::getline(in, obj.holder);

    std::string priceStr;
    //std::cout << "Enter price: ";
    //std::getline(in, priceStr);

    std::cout << "Enter price: ";
    in >> obj.price;
    //// Convert the string to double
    //try {
    //    obj.price = std::stod(priceStr);
    //}
    //catch (const std::invalid_argument&) {
    //    std::cerr << "Invalid price format. Please enter a valid number." << std::endl;
    //    //in.setstate(std::ios::failbit);  // Set the failbit to indicate a failure
    //    return in;
    //}
    std::cout << "Enter row: ";
    in >> obj.idRow;
    std::cout << "Enter seat: ";
    in >> obj.idSeat;
    /*std::cout << "Enter Event details:" << std::endl;*/
    //in >> *obj.event;

    return in;

}

void Ticket::operator+=(double val) {
    this->price += val;
}

bool Ticket::operator!() {
    return this->idRow == 1;
}