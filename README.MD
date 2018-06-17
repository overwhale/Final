Parking Lot

Object: The goal of this project is to create a Parking Lot system, which can show how many vacant spots out there.

class Car inherited from class Vehicle. Vehicle only has one member field that is the plate number. However, in the future we might need the type of the car or the size of the car to customize like normal spot and compact spot. The inheritance allow us to build based on the Vehicle. In the Car class, the member function "getPlate" is implemented, because it is what will actually be instantiated. Furthermore, for memeory management purpose, Vehicle has a virtual destructor so that when a "Car" gets destructed, we make sure that the "plate" field that it inherited from will be destroyed as well, thus avoiding 
memory leak.

class ParkingSpot represents the properities of an indivitual spots, it might be for people with disability. It has an ID number, and a boolean field occupied indicating whether it is available to the public. Also a member field "car" to record which car is on the spot. ID number of the parking spot is usually integer.

Obviously, class ParkingLot is a vector of ParkingSpots that handles the overall parking lot. ParkingLot has two important functions, one is initialize parking according to the input compacity and number of disabled that user determines.  I initialized the parking lot with a lambda function because the initializing ID function will probabiliy be used for just once. The other important function is Park(). It is where vehicle interacts with the Parking Lot. In this function, I want to use the generic algorithm for_each to go through the vector of parking spots, print out the ID of available spots and a vehicle get to decide which spot it wants to take. And then I use an iterator to go through the container to find that spot and changes its status accordingly. Finally I want to use a hash map to record the one-to-one relationship between each car and its parking spot. 

In the main function, where basically the operation of the parking lot takes place.
The importance of move semantics and copy & swap couldn't really be shown in this program, because each spot
and each vehicle is unique. So there does not involve much transfer of ownership between objects.
