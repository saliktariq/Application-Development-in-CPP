#include "database.h"

class AirlineBookingSystem {
public:
    AirlineBookingSystem(Database& db) : db_(db) {}

    void addFlight(std::string departure, std::string arrival, std::string date, std::string time, double price, int seatsAvailable) {
        db_.addFlight(departure, arrival, date, time, price, seatsAvailable);
    }

    void updateFlight(int id, std::string departure, std::string arrival, std::string date, std::string time, double price, int seatsAvailable) {
        db_.updateFlight(id, departure, arrival, date, time, price, seatsAvailable);
    }

    std::vector<Flight> searchFlights(std::string departure, std::string arrival, std::string date) {
        return db_.searchFlights(departure, arrival, date);
    }

    void addPassenger(std::string name, std::string email, std::string password, std::string address) {
        db_.addPassenger(name, email, password, address);
    }

    Passenger getPassenger(std::string email, std::string password) {
        return db_.getPassenger(email, password);
    }

    void addBooking(int flightId, int passengerId, int seatNum, bool upgrade, bool paid) {
        db_.addBooking(flightId, passengerId, seatNum, upgrade, paid);
    }

    void updateBooking(int id, int seatNum, bool upgrade, bool paid) {
        db_.updateBooking(id, seatNum, upgrade, paid);
    }

    void deleteBooking(int id) {
        db_.deleteBooking(id);
    }

private:
    Database& db_;
};