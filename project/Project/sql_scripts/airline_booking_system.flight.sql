CREATE TABLE airline_booking_system.flight (
    id INT NOT NULL AUTO_INCREMENT,
    number VARCHAR(10) NOT NULL,
    departure VARCHAR(50) NOT NULL,
    arrival VARCHAR(50) NOT NULL,
    date DATE NOT NULL,
    time TIME NOT NULL,
    economy_capacity INT NOT NULL,
    premium_economy_capacity INT NOT NULL,
    business_capacity INT NOT NULL,
    PRIMARY KEY (id)
);