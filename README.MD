Parking Lot

Object: The goal of this project is to create a Parking Lot system, which can show how many vacant spots out there, as well
as monitor the time that a vehicle has been at the spot for.

class Car inherited from class Vehicle. Vehicle only has one member field that is the plate number.
However, in the future we might need the type of the car or the size of the car to customize like normal
spot and compact spot. The inheritance allow us to build based on the Vehicle. In the Car class, the 
member function "getPlate" is implemented, because it is what will actually be instantiated. Furthermore,
for memeory management purpose, Vehicle has a virtual destructor so that when a "Car" gets destructed,
we make sure that the "plate" field that it inherited from will be destroyed as well, thus avoiding 
memory leak.

class ParkingSpot represents the properities of an indivitual spots, it might be for people with disability.
It has an ID number, and a boolean field occupied indicating whether it is available to the public. For
the ID number of ParkingSpot, I used template T. Because owner can decide whether they want to use integer
or string or even a mix as the ID.

Obviously, class ParkingLot is a vector of ParkingSpots that handles the overall parking lot.

In the main function, which is basically one operation of the parking lot. I initialized the parking lot with a 
lambda function because the initializing ID function will probabiliy be used for just once.
The importance of move semantics and copy & swap couldn't really be shown in this program, because each spot
and each vehicle is unique. So there does not involve much transfer of ownership between objects.
