#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <ctime>

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
    time_t t = std::time(0);
    Car(string n = "A", string t = "suv") 
        : Vehicle(n), type(t){}
    string getType();
    time_t exitTime();
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
    void exit(int ID);
    void calculateFee(time_t t);

    class ParkingSpot {
    public:
        bool disabled;  // whether the spot is for people with disability.
        bool occupied;  // whether the spot is occupied.
        Car car;
        struct printif;
    public:
        int spotID;       // the id of the spot.
        ParkingSpot(int ID, bool disabled);
        ParkingSpot(const ParkingSpot& a); 
        //ParkingSpot(ParkingSpot&& a);  move constructor
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