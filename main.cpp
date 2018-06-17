#include "ParkingLot.cpp"
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <String>
using namespace std;
int main(){
    ParkingLot pl(30);
    pl.initializeParkingLot(0);
    // set up a one to one connection between ParkingSpot and Car
    // so that we can find a car by the spot number or the other way.
    unordered_map<int, string> map;


    Car c1("A1", "compact");
    Car c2("A2", "compact");
    Car c3("A3", "compact");
    if (static_cast<bool>(pl.park(c1)))
        map.insert(pl.park(c1),c1.getPlate());
        


    
}