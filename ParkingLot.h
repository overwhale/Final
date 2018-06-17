#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
class Vehicle {
public:
    string plate;
    string getPlate();
    virtual ~Vehicle();
    Vehicle(string n = "A") : plate(n) {}
};

class Car : public Vehicle {
public:
    string type;
    Car(string n = "A", string t = "suv") : Vehicle(n), type(t) {}
    string getType();
    friend class ParkingLot;
};

class ParkingLot {
    friend class Car;
    class ParkingSpot;

public:
    vector<ParkingSpot> spots;
    // compacity is a const number that how many cars can the lot hold
    const int compacity;
    // numSpots indicates how many spots are occupied in the lot.
    int numSpots;

public:
    ParkingLot(int c = 0, int n = 0) : compacity(c), numSpots(n) {}
    void initialize(int numDisabled);
    bool isFull();
    int park(Car car);

private:
    // A helper function to addSpots
    void addSpot(ParkingSpot p);
    // A helper function to print out the available spots.
    void printif(ParkingSpot a);

    class ParkingSpot {
    public:
        bool disabled;  // whether the spot is for people with disability.
        bool occupied;  // whether the spot is occupied.
        Car car;
    public:
        int spotID;       // the id of the spot.
        ParkingSpot(int ID, bool disabled);
        // accessor
        bool getDisabled();
        bool getOccupied();
        Car getCar();
        int getID();
        // mutator
        void setDisabled(bool b);
        void setOccupied(bool b);
        void setCar(Car car);
    };
};