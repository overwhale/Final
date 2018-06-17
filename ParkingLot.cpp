#include "ParkingLot.h"


string Vehicle::getPlate() {
    return plate;
}

Vehicle::~Vehicle() {}

string Car::getType() {
    return type;
}

time_t Car::exitTime(){
    time_t exitT = std::time(0);
    time_t duration = exitT - this->t;
}

bool ParkingLot::isFull() {
    return compacity == numSpots;
}


void ParkingLot::initialize(int numDisabled) {
    if (numDisabled > this->compacity)
        cerr << "Warning, too many spots than what we have.";
    for (int t = 0; t < this->compacity; t++) {
        int i = 1000;
        spots.emplace_back(
            [&i](){return ParkingSpot(i++, false);}
        );
    }
    for (auto t = spots.begin(); t != spots.begin() + numDisabled; t++) {
        (*t).setDisabled(true);
    }
}

int ParkingLot::park(Car car) {
    struct printif {
        printif(){}
        void operator()(ParkingSpot a) const {
            if (a.getOccupied() == false)
                cout << a.getID() << "  ";
        }
    };
    int ID;
    if (!isFull()) {
        cout << "Here are the available space: " << endl;
        for_each(spots.begin(), spots.end(), printif());
        cout << "Which one do you want: " << endl;
        cin >> ID;
        for (auto t = spots.begin(); t != spots.end(); t++) {
            if ((*t).getID() == ID) {
                (*t).setOccupied(true);
                (*t).setCar(car);
                numSpots++;
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

void ParkingLot::exit(int ID) {
        for (auto t = spots.begin(); t != spots.end(); t++) {
            if ((*t).getID() == ID) {
                (*t).setOccupied(false);
                (*t).setCar(Car());
                numSpots++;
            }
        }
        return;
}

void ParkingLot::calculateFee(time_t t) {
    // We can calculate the fee of parking if necessary.
}

ParkingLot::ParkingSpot::ParkingSpot(int id, bool disabled) :
    disabled(false), occupied(false), car(nullptr), spotID(0) {
    this->disabled = disabled;
    occupied = false;
    spotID = id;
}

ParkingLot::ParkingSpot::ParkingSpot(const ParkingSpot& a) : 
    disabled(false), occupied(false), car(nullptr), spotID(0) {
    this->disabled = a.disabled;
    occupied = a.occupied;
    spotID = a.spotID;
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
