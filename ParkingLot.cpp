#include "ParkingLot.h"

class Vehicle{
public:
    string plate;
    virtual string getPlate(){}
    virtual ~Vehicle(){}
    Vehicle(string n = "A") : plate(n){}
};

class Car: public Vehicle {
public:
    string type;
    Car(string n = "A", string t = "suv") : Vehicle(n), type(t){}

    string getPlate(){ 
        return plate;
    }

    friend class ParkingLot;
};


class ParkingLot {
    class ParkingSpot;
    public:
        vector<ParkingSpot> spots;
        const int compacity;
        int numSpots;

    public:
        ParkingLot(int c = 0, int n =0): compacity(c), numSpots(n)  {}
    
        void initializeParkingLot(int numDisabled){
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

        void addSpot(ParkingSpot p){
            spots.push_back(p);
        }

        bool isFull(){
            return compacity == numSpots;
        }

        int park(Car car) {
            int ID;
            if (!isFull()) {
                cout << "Here are the available space: " << endl;
                for_each(spots.begin(), spots.end(), printif());
                cout << "Which one do you want: " << endl;
                cin >> ID;
                for (auto t = spots.begin(); t != spots.end(); t++) {
                    if (*t.getID() == ID){
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
        
        void printif(ParkingSpot a) {
            if (a.getOccupied() == false)
                cout << a.getID() << "  ";
        }


    friend class Car;

    class ParkingSpot {
    public:
        bool disabled;
        bool occupied;
        Car car;

    public:
        int spotID;

        ParkingSpot(int id, bool disabled) {
            this->disabled = disabled;
            occupied = false;
            spotID = id;
        }

        bool getDisabled() {
            return disabled;
        }

        bool getOccupied() {
            return occupied;
        }

        Car getCar(){
            return car;
        }

        int getID() {
            return spotID;
        }

        void setDisabled(bool b) {
            this->disabled = b;
        }

        void setOccupied(bool b) {
            this->occupied = b;
        }

        void setCar(Car car){
            this->car = car;
        }
    };
};