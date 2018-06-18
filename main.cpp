#include "ParkingLot.h"
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <String>
using namespace std;
int main(){
    ParkingLot pl(30);
    pl.initialize(0);
    // set up a one to one connection between ParkingSpot and Car
    // so that we can find a car by the spot number or the other way.
    unordered_map<string, int> map;

    // Cars get initialized, it means that they enter the parking lot.
    // Then the clock start timing.
    Car c1("A1", "compact");
    Car c2("A2", "compact");
    Car c3("A3", "compact");

    // Map records a one-to-one relationship between car and its spot.
    map.emplace(c1.getPlate(), pl.park(c1));
    map.emplace(c2.getPlate(), pl.park(c2));

    // When c2 needs to leave, we record the duration of c2 in the parking lot.
    // And change the parking lot status accordingly.
    //cout << map.at(c2.getPlate()) <<endl; for debugging purpose
    auto t = c2.exitTime(); 
    //cout << t << endl;; for debugging purpose
    pl.calculateFee(t);
    pl.exit(map.at(c2.getPlate()));
    map.erase(c2.getPlate());
    
    system("Pause");
}