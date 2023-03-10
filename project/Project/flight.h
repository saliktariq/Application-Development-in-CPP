#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

class Flight {
public:
    Flight(int id, std::string departure, std::string arrival, std::string date, std::string time, double price, int capacity);

    int getId() const;
    std::string getDeparture() const;
    std::string getArrival() const;
    std::string getDate() const;
    std::string getTime() const;
    double getPrice() const;
    int getCapacity() const;

    std::string toString() const;

private:
    int id_;
    std::string departure_;
    std::string arrival_;
    std::string date_;
    std::string time_;
    double price_;
    int capacity_;
};

#endif // FLIGHT_H
