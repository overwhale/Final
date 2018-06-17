#include <iostream>
#include <vector>

using namespace std;
class Vehicle{
public:
    int plate;
    virtual int getPlate(){}
    virtual ~Vehicle(){}
    Vehicle(int n = 0) : plate(n){}
};

class Car : public Vehicle {
public:
    string type;
    Car(int n = 0, string t = "suv") : Vehicle(n), type(t){}

    int getPlate(){ 
        return plate;
    }
};

template<typename T>
class ParkingLot {
private:
    vector<ParkingSpot> spots;
    // compacity is a const number that how many cars can the lot hold
    const int compacity;
    // numSpots indicates how many spots are occupied in the lot.
    int numSpots;
private:
    ParkingLot(int c = 0, int n =0): compacity(c), numSpots(n)  {}
    void addSpot(ParkingSpot p){
        spots.push_back(p);
    }

    int getOpenSpots(){
        return compacity - numSpots;
    }


};

template <typename T>
class ParkingSpot{
    private:
        bool disabled; // whether the spot is for people with disability.
        bool occupied;    // whether the spot is occupied.
public:
        T spotID;       // the id of the spot.

        ParkingSpot(T ID, bool disabled) {
            this->disabled = disabled;
            occupied = false;
            spotID = ID;
        }

        // accessor
        bool getDisabled(){
            return disabled;
        }
        
        bool getOccupied(){
            return occupied;
        }

        T getID(){
            return spotID;
        }

        // mutator
        void setDisabled(bool b){
            disabled = b;
        }

        void setOccupied(bool b){
            occupied = b;
        }
};