#include <iostream>
#include <vector>
#include <algorithm>
#include "booking.h"
#include "flight.h"
#include "passenger.h"

using namespace std;

int main() {
    vector<Booking> bookings;
    vector<Flight> flights;
    vector<Passenger> passengers;

    int choice;
    do {
        cout << "\n1. Add passenger" << endl;
        cout << "2. Add flight" << endl;
        cout << "3. Add booking" << endl;
        cout << "4. View all passengers" << endl;
        cout << "5. View all flights" << endl;
        cout << "6. View all bookings" << endl;
        cout << "7. View bookings for a passenger" << endl;
        cout << "8. View bookings for a flight" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name, email, password, address;
            cout << "\nEnter passenger ID: ";
            cin >> id;
            cout << "Enter passenger name: ";
            cin >> name;
            cout << "Enter passenger email: ";
            cin >> email;
            cout << "Enter passenger password: ";
            cin >> password;
            cout << "Enter passenger address: ";
            cin >> address;
            passengers.push_back(Passenger(id, name, email, password, address));
            break;
        }
        case 2: {
            int id, capacity;
            string departure, arrival, date, time;
            double price;
            cout << "\nEnter flight ID: ";
            cin >> id;
            cout << "Enter departure city: ";
            cin >> departure;
            cout << "Enter arrival city: ";
            cin >> arrival;
            cout << "Enter date (YYYY-MM-DD): ";
            cin >> date;
            cout << "Enter time (HH:MM): ";
            cin >> time;
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
        case 9: {
            cout << "\nExiting program..." << endl;
            break;
        }
        default: {
            cout << "\nInvalid choice. Please try again." << endl;
            break;
            
        }
        }
    } while (choice != 9);
    return 0;
}