#include "flight.h"
#include <sstream>

Flight::Flight(int id, std::string departure, std::string arrival, std::string date, std::string time, double price, int capacity) : id_(id), departure_(departure), arrival_(arrival), date_(date), time_(time), price_(price), capacity_(capacity) {}

int Flight::getId() const {
    return id_;
}

std::string Flight::getDeparture() const {
    return departure_;
}

std::string Flight::getArrival() const {
    return arrival_;
}

std::string Flight::getDate() const {
    return date_;
}

std::string Flight::getTime() const {
    return time_;
}

double Flight::getPrice() const {
    return price_;
}

int Flight::getCapacity() const {
    return capacity_;
}

std::string Flight::toString() const {
    std::ostringstream out;
    out << "Flight #" << id_ << " - " << departure_ << " to " << arrival_ << " on " << date_ << " at " << time_ << " for $" << price_;
    return out.str();
}
