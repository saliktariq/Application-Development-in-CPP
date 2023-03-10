#ifndef BOOKING_H
#define BOOKING_H

#include "passenger.h"
#include "flight.h"

class Booking {
public:
    Booking(int id, const Flight& flight, const Passenger& passenger, int seatNum, bool upgrade, bool paid);
    int getId() const;
    int getFlightId() const;
    int getPassengerId() const;
    int getSeatNum() const;
    bool isUpgrade() const;
    bool isPaid() const;
    double getPrice() const;
    std::string toString() const;

private:
    int id_;
    const Flight& flight_; // reference to the Flight object
    const Passenger& passenger_; // reference to the Passenger object
    int seatNum_;
    bool upgrade_;
    bool paid_;
    double price_;
};

#endif
