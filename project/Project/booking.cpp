#include "booking.h"
#include <sstream>

Booking::Booking(int id, const Flight& flight, const Passenger& passenger, int seatNum, bool upgrade, bool paid) : id_(id), flight_(flight), passenger_(passenger), seatNum_(seatNum), upgrade_(upgrade), paid_(paid), price_(flight.getPrice()) {}

int Booking::getId() const {
    return id_;
}

int Booking::getFlightId() const {
    return flight_.getId();
}

int Booking::getPassengerId() const {
    return passenger_.getId();
}

int Booking::getSeatNum() const {
    return seatNum_;
}

bool Booking::isUpgrade() const {
    return upgrade_;
}

bool Booking::isPaid() const {
    return paid_;
}

double Booking::getPrice() const {
    return price_;
}

std::string Booking::toString() const {
    std::ostringstream out;
    out << "Booking #" << id_ << " - Flight #" << flight_.getId() << ", Seat #" << seatNum_;
    if (upgrade_) {
        out << " (upgraded)";
    }
    if (paid_) {
        out << " (paid)";
    }
    return out.str();
}
