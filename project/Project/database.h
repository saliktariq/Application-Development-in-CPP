#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "flight.h"
#include "passenger.h"
#include "booking.h"
#include <cppconn/driver.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/connection.h>


class Database {
public:

    Database(const std::string& host, const std::string& username, const std::string& password, const std::string& databaseName)
        : host_(host), user_(username), password_(password), database_(databaseName) {}

    void connect() {
        try {
            sql::Driver* driver = get_driver_instance();
            std::string connectionString = "tcp://" + host_ + ";username=" + user_ + ";password=" + password_ + ";database=" + database_;
            std::string url = "tcp://" + host_;
            std::string user = user_;
            std::string password = password_;
            connection_ = std::unique_ptr<sql::Connection>(driver->connect(url, user, password));
            connection_->setSchema(database_);
        }
        catch (const sql::SQLException& e) {
            std::cerr << "Error connecting to database: " << e.what() << std::endl;
        }
    }

    void disconnect() {
        if (connection_ != nullptr) {
            connection_->close();
            connection_.reset();
        }
    }

    sql::Connection* getConnection() {
        connect();
        return connection_.get();
    }

    void addFlight(const std::string& departure, const std::string& arrival, const std::string& date, const std::string& time, double price, int seatsAvailable) {
        try {
            std::unique_ptr<sql::PreparedStatement> pstmt(connection_->prepareStatement("INSERT INTO flights(departure, arrival, date, time, price, seats_available) VALUES(?,?,?,?,?,?)"));
            pstmt->setString(1, departure);
            pstmt->setString(2, arrival);
            pstmt->setString(3, date);
            pstmt->setString(4, time);
            pstmt->setDouble(5, price);
            pstmt->setInt(6, seatsAvailable);
            pstmt->executeUpdate();
        }
        catch (const sql::SQLException& e) {
            std::cerr << "Error adding flight to database: " << e.what() << std::endl;
        }
    }

    void updateFlight(int id, const std::string& departure, const std::string& arrival, const std::string& date, const std::string& time, double price, int seatsAvailable) {
        try {
            std::unique_ptr<sql::PreparedStatement> pstmt(connection_->prepareStatement("UPDATE flights SET departure=?, arrival=?, date=?, time=?, price=?, seats_available=? WHERE id=?"));
            pstmt->setString(1, departure);
            pstmt->setString(2, arrival);
            pstmt->setString(3, date);
            pstmt->setString(4, time);
            pstmt->setDouble(5, price);
            pstmt->setInt(6, seatsAvailable);
            pstmt->setInt(7, id);
            pstmt->executeUpdate();
        }
        catch (const sql::SQLException& e) {
            std::cerr << "Error updating flight in database: " << e.what() << std::endl;
        }
    }

    std::vector<Flight> searchFlights(std::string departure, std::string arrival, std::string date) {
        std::vector<Flight> flights;
        try {
            std::unique_ptr<sql::PreparedStatement> pstmt(connection_->prepareStatement(
                "SELECT * FROM flights WHERE departure=? AND arrival=? AND date=?"
            ));
            pstmt->setString(1, departure);
            pstmt->setString(2, arrival);
            pstmt->setString(3, date);
            std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
            while (res->next()) {
                int id = res->getInt("id");
                std::string departure = res->getString("departure");
                std::string arrival = res->getString("arrival");
                std::string date = res->getString("date");
                std::string time = res->getString("time");
                double price = res->getDouble("price");
                int seatsAvailable = res->getInt("seats_available");

                Flight flight(id, departure, arrival, date, time, price, seatsAvailable);
                flights.push_back(flight);
            }
        }
        catch (sql::SQLException& e) {
            std::cerr << "Error executing query: " << e.what() << std::endl;
        }
        return flights;
    }

    void addPassenger(std::string name, std::string email, std::string password, std::string address) {
        try {
            sql::PreparedStatement* pstmt = connection_->prepareStatement("INSERT INTO passengers (name, email, password, address) VALUES (?, ?, ?, ?)");
            pstmt->setString(1, name);
            pstmt->setString(2, email);
            pstmt->setString(3, password);
            pstmt->setString(4, address);
            pstmt->execute();
            delete pstmt;
            pstmt = nullptr;
        }
        catch (sql::SQLException& e) {
            std::cerr << "Error adding passenger to database: " << e.what() << std::endl;
        }
    }

   




    void addBooking(int flightId, int passengerId, int seatNum, bool upgrade, bool paid) {
        try {
            std::unique_ptr<sql::PreparedStatement> pstmt(connection_->prepareStatement("INSERT INTO bookings(flight_id, passenger_id, seat_num, upgrade, paid) VALUES (?, ?, ?, ?, ?)"));
            pstmt->setInt(1, flightId);
            pstmt->setInt(2, passengerId);
            pstmt->setInt(3, seatNum);
            pstmt->setBoolean(4, upgrade);
            pstmt->setBoolean(5, paid);
            pstmt->executeUpdate();
        }
        catch (const sql::SQLException& e) {
            std::cerr << "Error adding booking to database: " << e.what() << std::endl;
        }
    }


    void updateBooking(int id, int seatNum, bool upgrade, bool paid) {
        try {
            std::unique_ptr<sql::PreparedStatement> pstmt(connection_->prepareStatement("UPDATE bookings SET seat_num = ?, upgrade = ?, paid = ? WHERE id = ?"));
            pstmt->setInt(1, seatNum);
            pstmt->setBoolean(2, upgrade);
            pstmt->setBoolean(3, paid);
            pstmt->setInt(4, id);
            pstmt->executeUpdate();
        }
        catch (const sql::SQLException& e) {
            std::cerr << "Error updating booking in database: " << e.what() << std::endl;
        }
    }


    void deleteBooking(int id) {
        try {
            std::unique_ptr<sql::PreparedStatement> pstmt(connection_->prepareStatement("DELETE FROM bookings WHERE id = ?"));
            pstmt->setInt(1, id);
            pstmt->executeUpdate();
        }
        catch (const sql::SQLException& e) {
            std::cerr << "Error deleting booking from database: " << e.what() << std::endl;
        }
    }

    Passenger getPassenger(std::string email, std::string password) {

        Passenger passenger = Passenger(-1, "", "", "", "");
        try {
            std::unique_ptr<sql::PreparedStatement> pstmt(connection_->prepareStatement("SELECT * FROM passengers WHERE email = ? AND password = ?"));
            pstmt->setString(1, email);
            pstmt->setString(2, password);
            std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
            if (res->next()) {
                int id = res->getInt("id");
                std::string name = res->getString("name");
                std::string address = res->getString("address");
                passenger = Passenger(id, name, email, password, address);
            }

        }
        catch (const sql::SQLException& e) {
            std::cerr << "Error getting passenger from database: " << e.what() << std::endl;
        }
        return passenger;
    }


private:
    std::string host_;
    std::string user_;
    std::string password_;
    std::string database_;

    std::unique_ptr<sql::Connection> connection_;


};

#endif