#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "booking.h"
#include "flight.h"
#include "passenger.h"
#include <windows.h>
#include <sstream>
#include <iomanip>

using namespace std;

void print_menu();
std::string escape_json_string(const std::string& str);

vector<Booking> bookings;
vector<Flight> flights;
vector<Passenger> passengers;

std::string hash_password(const std::string& password) {
    // Helper function to hash a password (this is just an example, not a secure hash function)
    std::hash<std::string> hasher;
    return std::to_string(hasher(password));
}



std::string escape_json_string(const std::string& str) {
    // Helper function to escape special characters in a JSON string
    std::ostringstream oss;
    for (char c : str) {
        switch (c) {
        case '\"': oss << "\\\""; break;
        case '\\': oss << "\\\\"; break;
        case '\b': oss << "\\b"; break;
        case '\f': oss << "\\f"; break;
        case '\n': oss << "\\n"; break;
        case '\r': oss << "\\r"; break;
        case '\t': oss << "\\t"; break;
        default: oss << c; break;
        }
    }
    return oss.str();
}

void json_feed_bookings(const std::vector<Booking>& bookings) {
    std::cout << "[\n";
    for (size_t i = 0; i < bookings.size(); ++i) {
        const Booking& b = bookings[i];
        std::cout << "  {\n";
        std::cout << "    \"id\": " << b.getId() << ",\n";
        std::cout << "    \"flight\": {\n";
        std::cout << "      \"id\": " << b.getFlightId() << ",\n";
        std::cout << "      \"departure\": \"" << escape_json_string(b.flight_.getDeparture()) << "\",\n";
        std::cout << "      \"arrival\": \"" << escape_json_string(b.flight_.getArrival()) << "\",\n";
        std::cout << "      \"date\": \"" << escape_json_string(b.flight_.getDate()) << "\",\n";
        std::cout << "      \"time\": \"" << escape_json_string(b.flight_.getTime()) << "\",\n";
        std::cout << "      \"price\": " << std::fixed << std::setprecision(2) << b.flight_.getPrice() << ",\n";
        std::cout << "      \"capacity\": " << b.flight_.getCapacity() << "\n";
        std::cout << "    },\n";
        std::cout << "    \"passenger\": {\n";
        std::cout << "      \"id\": " << b.getPassengerId() << ",\n";
        std::cout << "      \"name\": \"" << escape_json_string(b.passenger_.getName()) << "\",\n";
        std::cout << "      \"email\": \"" << escape_json_string(b.passenger_.getEmail()) << "\"\n";
        std::cout << "    },\n";
        std::cout << "    \"seat_num\": " << b.getSeatNum() << ",\n";
        std::cout << "    \"upgrade\": " << std::boolalpha << b.isUpgrade() << ",\n";
        std::cout << "    \"paid\": " << std::boolalpha << b.isPaid() << ",\n";
        std::cout << "    \"price\": " << std::fixed << std::setprecision(2) << b.getPrice() << "\n";
        std::cout << "  }";
        if (i < bookings.size() - 1) {
            std::cout << ",";
        }
        std::cout << "\n";
    }
    std::cout << "]\n";
}

void save_feed_bookings(const std::vector<Booking>& bookings) {
    std::ofstream file("booking_feed.json");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file for writing\n";
        return;
    }

    file << "[\n";
    for (size_t i = 0; i < bookings.size(); ++i) {
        const Booking& b = bookings[i];
        file << "  {\n";
        file << "    \"id\": " << b.getId() << ",\n";
        file << "    \"flight\": {\n";
        file << "      \"id\": " << b.getFlightId() << ",\n";
        file << "      \"departure\": \"" << escape_json_string(b.flight_.getDeparture()) << "\",\n";
        file << "      \"arrival\": \"" << escape_json_string(b.flight_.getArrival()) << "\",\n";
        file << "      \"date\": \"" << escape_json_string(b.flight_.getDate()) << "\",\n";
        file << "      \"time\": \"" << escape_json_string(b.flight_.getTime()) << "\",\n";
        file << "      \"price\": " << std::fixed << std::setprecision(2) << b.flight_.getPrice() << ",\n";
        file << "      \"capacity\": " << b.flight_.getCapacity() << "\n";
        file << "    },\n";
        file << "    \"passenger\": {\n";
        file << "      \"id\": " << b.getPassengerId() << ",\n";
        file << "      \"name\": \"" << escape_json_string(b.passenger_.getName()) << "\",\n";
        file << "      \"email\": \"" << escape_json_string(b.passenger_.getEmail()) << "\",\n";
        file << "      \"address\": \"" << escape_json_string(b.passenger_.getAddress()) << "\"\n";
        file << "    },\n";
        file << "    \"seat_num\": " << b.getSeatNum() << ",\n";
        file << "    \"upgrade\": " << std::boolalpha << b.isUpgrade() << ",\n";
        file << "    \"paid\": " << std::boolalpha << b.isPaid() << ",\n";
        file << "    \"price\": " << std::fixed << std::setprecision(2) << b.getPrice() << "\n";
        file << "  }";
        if (i < bookings.size() - 1) {
            file << ",";
        }
        file << "\n";
    }
    file << "]\n";

    file.close();
    cout << "All data exported to booking_feed.json in current execution directory!\n";
}


void json_feed_flight(const std::vector<Flight>& flights) {
    std::cout << "[\n";
    for (size_t i = 0; i < flights.size(); ++i) {
        const Flight& f = flights[i];
        std::cout << "  {\n";
        std::cout << "    \"id\": " << f.getId() << ",\n";
        std::cout << "    \"departure\": \"" << escape_json_string(f.getDeparture()) << "\",\n";
        std::cout << "    \"arrival\": \"" << escape_json_string(f.getArrival()) << "\",\n";
        std::cout << "    \"date\": \"" << escape_json_string(f.getDate()) << "\",\n";
        std::cout << "    \"time\": \"" << escape_json_string(f.getTime()) << "\",\n";
        std::cout << "    \"price\": " << std::fixed << std::setprecision(2) << f.getPrice() << ",\n";
        std::cout << "    \"capacity\": " << f.getCapacity() << "\n";
        std::cout << "  }";
        if (i < flights.size() - 1) {
            std::cout << ",";
        }
        std::cout << "\n";
    }
    std::cout << "]\n";
}

void save_feed_flight(const std::vector<Flight>& flights) {
    std::ofstream file("flight_feed.json");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file for writing\n";
        return;
    }

    file << "[\n";
    for (size_t i = 0; i < flights.size(); ++i) {
        const Flight& f = flights[i];
        file << "  {\n";
        file << "    \"id\": " << f.getId() << ",\n";
        file << "    \"departure\": \"" << escape_json_string(f.getDeparture()) << "\",\n";
        file << "    \"arrival\": \"" << escape_json_string(f.getArrival()) << "\",\n";
        file << "    \"date\": \"" << escape_json_string(f.getDate()) << "\",\n";
        file << "    \"time\": \"" << escape_json_string(f.getTime()) << "\",\n";
        file << "    \"price\": " << std::fixed << std::setprecision(2) << f.getPrice() << ",\n";
        file << "    \"capacity\": " << f.getCapacity() << "\n";
        file << "  }";
        if (i < flights.size() - 1) {
            file << ",";
        }
        file << "\n";
    }
    file << "]\n";

    file.close();
    cout << "All data exported to flight_feed.json in current execution directory!\n";
}

void json_feed_passengers(const std::vector<Passenger>& passengers) {
    std::cout << "[\n";
    for (size_t i = 0; i < passengers.size(); ++i) {
        const Passenger& p = passengers[i];
        std::cout << "  {\n";
        std::cout << "    \"id\": " << p.getId() << ",\n";
        std::cout << "    \"name\": \"" << escape_json_string(p.getName()) << "\",\n";
        std::cout << "    \"email\": \"" << escape_json_string(p.getEmail()) << "\",\n";
        std::cout << "    \"password_hash\": \"" << hash_password(p.getPassword()) << "\",\n";
        std::cout << "    \"address\": \"" << escape_json_string(p.getAddress()) << "\"\n";
        std::cout << "  }";
        if (i < passengers.size() - 1) {
            std::cout << ",";
        }
        std::cout << "\n";
    }
    std::cout << "]\n";
}

void save_feed_passengers(const std::vector<Passenger>& passengers) {
    std::ofstream file("passenger_feed.json");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file for writing\n";
        return;
    }

    file << "[\n";
    for (size_t i = 0; i < passengers.size(); ++i) {
        const Passenger& p = passengers[i];
        file << "  {\n";
        file << "    \"id\": " << p.getId() << ",\n";
        file << "    \"name\": \"" << escape_json_string(p.getName()) << "\",\n";
        file << "    \"email\": \"" << escape_json_string(p.getEmail()) << "\",\n";
        file << "    \"password_hash\": \"" << hash_password(p.getPassword()) << "\",\n";
        file << "    \"address\": \"" << escape_json_string(p.getAddress()) << "\"\n";
        file << "  }";
        if (i < passengers.size() - 1) {
            file << ",";
        }
        file << "\n";
    }
    file << "]\n";

    file.close();
    cout << "All data exported to passenger_feed.json in current execution directory!\n";

}


void beep() {
    Beep(800, 50);
}

void backup_menu() {

    int op;
    do {

        cout << "\033[10;8H\033[1;33;44m  SYSTEM BACKUP  \033[0m";
        cout << "\033[11;8H\033[1;33m------------------\033[0m" << endl;
        cout << "\033[12;8H\033[1;33m1. Backup flight data to disk\033[0m" << endl;
        cout << "\033[13;8H\033[1;33m2. Backup bookings data to disk\033[0m" << endl;
        cout << "\033[14;8H\033[1;33m3. Backup passenger data to disk\033[0m" << endl;
        cout << "\033[15;8H\033[1;31m0. Back\033[0m" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> op;
        switch (op) {

        case 0:
        {
            beep();
            system("cls");
            print_menu();
            break;
        }
        case 1:
        {
            json_feed_flight(flights);
            break;


        }
        case 2:
        {
            json_feed_bookings(bookings);
            break;
        }
        case 3:
        {
            json_feed_passengers;
            break;

        }
        default:
        {
            cout << "Please select a valid option.\n";
            break;
        }
        }

    } while (op != 0);

}

void json_menu() {

    int ch;
    do {

        cout << "\033[10;8H\033[1;33;44m  JSON FEEDS  \033[0m";
        cout << "\033[11;8H\033[1;33m------------------\033[0m" << endl;
        cout << "\033[12;8H\033[1;33m1. View all flights as JSON\033[0m" << endl;
        cout << "\033[13;8H\033[1;33m2. View all bookings as JSON\033[0m" << endl;
        cout << "\033[14;8H\033[1;33m3. View all passengers as JSON\033[0m" << endl;
        cout << "\033[15;8H\033[1;31m0. Back\033[0m" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {

        case 0:
        {
            beep();
            system("cls");
            print_menu();
            break;
        }
        case 1:
        {
            json_feed_flight(flights);
            break;


        }
        case 2:
        {
            json_feed_bookings(bookings);
            break;
        }
        case 3:
        {
            json_feed_passengers;
            break;

        }
        default:
        {
            cout << "Please select a valid option.\n";
            break;
        }
     }

    } while (ch != 0);

}

void print_menu() {
       
    cout << "\033[2;6H\033[1;33;44m  FLIGHT BOOKING  \033[0m";
    cout << "\033[4;6H\033[1;33m------------------\033[0m" << endl;
    cout << "\033[5;6H\033[1;33m1. Add passenger\033[0m" << endl;
    cout << "\033[6;6H\033[1;33m2. Add flight\033[0m" << endl;
    cout << "\033[7;6H\033[1;33m3. Add booking\033[0m" << endl;
    cout << "\033[8;6H\033[1;34m4. View all passengers\033[0m" << endl;
    cout << "\033[9;6H\033[1;34m5. View all flights\033[0m" << endl;
    cout << "\033[10;6H\033[1;34m6. View all bookings\033[0m" << endl;
    cout << "\033[11;6H\033[1;34m7. View bookings for a passenger\033[0m" << endl;
    cout << "\033[12;6H\033[1;34m8. View bookings for a flight\033[0m" << endl;
    cout << "\033[13;6H\033[1;34m9. View JSON Feeds\033[0m" << endl;
    cout << "\033[14;6H\033[1;34m10. Backup data to local disk\033[0m" << endl;
    cout << "\033[15;6H\033[1;31m0. Exit\033[0m" << endl;
    cout << endl;
}

int main() {



    print_menu();

    int choice;
    do {

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name, email, password, address;
            cout << "\nEnter passenger ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter passenger name: ";
            getline(cin, name);
            cout << "Enter passenger email: ";
            getline(cin, email);
            cout << "Enter passenger password: ";
            getline(cin, password);
            cout << "Enter passenger address: ";
            getline(cin, address);
            passengers.push_back(Passenger(id, name, email, password, address));
            break;
        }
        case 2: {
            int id, capacity;
            string departure, arrival, date, time;
            double price;
            cout << "\nEnter flight ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter departure city: ";
            getline(cin, departure);
            cout << "Enter arrival city: ";
            getline(cin, arrival);
            cout << "Enter date (DD-MM-YYYY): ";
            getline(cin, date);
            cout << "Enter time (HH:MM): ";
            getline(cin, time);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter capacity: ";
            cin >> capacity;
            flights.push_back(Flight(id, departure, arrival, date, time, price, capacity));
            break;
        }
        case 3: {
            int id, passengerId, flightId, seatNum;
            bool upgrade, paid;
            cout << "\nEnter booking ID: ";
            cin >> id;
            cout << "Enter passenger ID: ";
            cin >> passengerId;
            cout << "Enter flight ID: ";
            cin >> flightId;
            cout << "Enter seat number: ";
            cin >> seatNum;
            cout << "Is this an upgrade? (0 for no, 1 for yes): ";
            cin >> upgrade;
            cout << "Has the booking been paid for? (0 for no, 1 for yes): ";
            cin >> paid;
            bookings.push_back(Booking(id, flights[flightId], passengers[passengerId], seatNum, upgrade, paid));
            break;
        }
        case 4: {
            cout << "\nPassengers:" << endl;
            for (const Passenger& passenger : passengers) {
                cout << passenger.toString() << endl;
            }
            break;
        }
        case 5: {
            cout << "\nFlights:" << endl;
            for (const Flight& flight : flights) {
                cout << flight.toString() << endl;
            }
            break;
        }
        case 6: {
            cout << "\nBookings:" << endl;
            for (const Booking& booking : bookings) {
                cout << booking.toString() << endl;
            }
            break;
        }
        case 7: {
            int passengerId;
            cout << "\nEnter passenger ID: ";
            cin >> passengerId;
            cout << "\nBookings for passenger " << passengers[passengerId].getName() << ":" << endl;
            for (const Booking& booking : bookings) {
                if (booking.getPassengerId() == passengerId) {
                    cout << booking.toString() << endl;
                }
            }
            break;
        }
        case 8: {
            int flightId;
            cout << "\nEnter flight ID: ";
            cin >> flightId;
            cout << "\nBookings for flight #" << flightId << ":" << endl;
            for (const Booking& booking : bookings) {
                if (booking.getFlightId() == flightId) {
                    cout << booking.toString() << endl;
                }
            }
            break;
        }

        case 9:
        {
            system("cls");
            json_menu();
            break;

        }

        case 10:
        {
            system("cls");
            backup_menu();
            break;
        }


        case 0: {
            beep();
            system("cls");
            cout << "\nExiting program..." << endl;
            break;
        }
        default: {
            cout << "\nInvalid choice. Please try again." << endl;
            break;
            
        }
        }
    } while (choice != 0);
    return 0;
}