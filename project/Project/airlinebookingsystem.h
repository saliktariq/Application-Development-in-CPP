#ifndef AIRLINEBOOKINGSYSTEM_H
#define AIRLINEBOOKINGSYSTEM_H

#include <string>
#include <vector>
#include "database.h"
#include "flight.h"
#include "passenger.h"
#include "booking.h"

class AirlineBookingSystem {
public:
    AirlineBookingSystem();
    AirlineBookingSystem(const std::string& host, const std::string& user, const std::string& password, const std::string& schema);

    std::vector<Flight> searchFlights(const std::string& departure, const std::string& arrival, const std::string& date) const;
    Passenger createPassenger(const std::string& name, const std::string& email, const std::string& password, const std::string& address);
    Passenger getPassenger(const std::string& email, const std::string& password) const;
    Booking bookFlight(const Flight& flight, const Passenger& passenger, int seatNum);
    Booking getBooking(int bookingId) const;
    double getUpgradePrice(int flightId, bool upgrade) const;
    double getCancellationFee(int flightId) const;
    void upgradeBooking(Booking& booking, bool upgrade, double price);
    void cancelBooking(Booking& booking);

private:
    Database db_;
};

#endif // AIRLINEBOOKINGSYSTEM_H
