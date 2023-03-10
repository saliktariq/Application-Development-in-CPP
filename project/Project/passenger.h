#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <vector>



class Passenger {
public:
    Passenger(int id, std::string name, std::string email, std::string password, std::string address);
    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getPassword() const;
    std::string getAddress() const;
    std::string toString() const;

private:
    int id_;
    std::string name_;
    std::string email_;
    std::string password_;
    std::string address_;
    std::string schema_;
};

#endif // PASSENGER_H
