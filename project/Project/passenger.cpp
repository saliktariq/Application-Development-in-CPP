#include "passenger.h"
#include <iostream>

Passenger::Passenger(int id, std::string name, std::string email, std::string password, std::string address): id_(id), name_(name), email_(email), password_(password), address_(address){}

int Passenger::getId() const {
    return id_;
}

std::string Passenger::getName() const {
    return name_;
}

std::string Passenger::getEmail() const {
    return email_;
}

std::string Passenger::getPassword() const {
    return password_;
}

std::string Passenger::getAddress() const {
    return address_;
}

std::string Passenger::toString() const {
    return "Passenger: { ID: " + std::to_string(id_) + ", Name: " + name_ + ", Email: " + email_ + ", Address: " + address_ + " }";
}

