CREATE TABLE airline_booking_system.passenger (
    id INT NOT NULL AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL,
    password VARCHAR(100) NOT NULL,
    address VARCHAR(200) NOT NULL,
    PRIMARY KEY (id)
);