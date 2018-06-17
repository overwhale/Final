#include "ParkingLot.h"


string Vehicle::getPlate() {
    return plate;
}

Vehicle::~Vehicle() {}

Vehicle::Vehicle(string n = "A") : plate(n) {}

Car::Car(string n = "A", string t = "suv") : Vehicle(n), type(t) {}

string Car::getType() {
    return type;
}


ParkingLot::ParkingLot(int c = 0, int n = 0) : compacity(c), numSpots(n) {}

void ParkingLot::initialize(int numDisabled) {
    if (numDisabled > this->compacity)
        cerr << "Warning, too many spots than what we have.";
    for (int t = 0; t < this->compacity; t++) {
        int i = 1000;
        spots.addSpot([&i]() {return ParkingSpot(i, false); i++; });
    }
    for (auto t = spots.begin(); t != spots.begin() + numDisabled; t++) {
        *t.setDisabled(true);
    }
}

void ParkingLot::addSpot(ParkingSpot p) {
    spots.push_back(p);
}

bool ParkingLot::isFull() {
    return compacity == numSpots;
}

int ParkingLot::park(Car car) {
    int ID;
    if (!isFull()) {
        cout << "Here are the available space: " << endl;
        for_each(spots.begin(), spots.end(), printif());
        cout << "Which one do you want: " << endl;
        cin >> ID;
        for (auto t = spots.begin(); t != spots.end(); t++) {
            if (*t.getID() == ID) {
                *t.setOccupied(true);
                *t.setCar(car);
                return ID;
            }
        }
        return 0;
    }
    else {
        cout << "Sorry! Lot is full." << endl;
        return 0;
    }
}

void ParkingLot::printif(ParkingSpot a) {
    if (a.getOccupied() == false)
        cout << a.getID() << "  ";
}

ParkingLot::ParkingSpot::ParkingSpot(int id, bool disabled) {
    this->disabled = disabled;
    occupied = false;
    spotID = id;
}

bool ParkingLot::ParkingSpot::getDisabled() {
    return disabled;
}

bool ParkingLot::ParkingSpot::getOccupied() {
    return occupied;
}

Car ParkingLot::ParkingSpot::getCar() {
    return car;
}

int ParkingLot::ParkingSpot::getID() {
    return spotID;
}

void ParkingLot::ParkingSpot::setDisabled(bool b) {
    this->disabled = b;
}

void ParkingLot::ParkingSpot::setOccupied(bool b) {
    this->occupied = b;
}

void ParkingLot::ParkingSpot::setCar(Car car) {
    this->car = car;
}
