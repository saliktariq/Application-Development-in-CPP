CREATE TABLE airline_booking_system.booking (
    id INT NOT NULL AUTO_INCREMENT,
    flight_id INT NOT NULL,
    passenger_id INT NOT NULL,
    seat_num INT NOT NULL,
    class VARCHAR(20) NOT NULL,
    price DOUBLE NOT NULL,
    upgrade_price DOUBLE DEFAULT NULL,
    upgraded BOOL DEFAULT FALSE,
    cancelled BOOL DEFAULT FALSE,
    PRIMARY KEY (id),
    FOREIGN KEY (flight_id) REFERENCES flight(id),
    FOREIGN KEY (passenger_id) REFERENCES passenger(id)
);