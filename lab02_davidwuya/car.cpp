// David Zhu 8264459
// Nevin Manimaran 6488159
// This is the only file to submit.

#include "car.hpp"
#include "perf.hpp"
#include "doors.hpp"
#include <cstddef>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

// Default constructor
Car::Car(){
	manufacturer = nullptr;
	model = nullptr;
	zeroToSixtyNs = 0;
	headonDragCoeff = 0.0;
	horsepower = 0;
	backseatDoors = None;
	seatCount = 0;
}
// Constructor
Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign){
	manufacturer = new char [strlen(manufacturerName) + 1];
	strcpy(manufacturer,manufacturerName);
	model = new char [strlen(modelName) + 1];
	strcpy(model,modelName);
	
	zeroToSixtyNs = perf.zeroToSixtyNs;
	headonDragCoeff = perf.headonDragCoeff;
	horsepower = perf.horsepower;
	backseatDoors = backseatDoorDesign;
	seatCount = numSeats;
}

// Copy constructor
Car::Car(Car const& o){
	manufacturer = new char [strlen(o.manufacturer) + 1];
	strcpy(manufacturer,o.manufacturer);
	model = new char [strlen(o.model) + 1];
	strcpy(model,o.model);
	zeroToSixtyNs = o.zeroToSixtyNs;
	headonDragCoeff = o.headonDragCoeff;
	horsepower = o.horsepower;
	backseatDoors = o.backseatDoors;
	seatCount = o.seatCount;
}

// Destructor
Car::~Car(){
	delete[] manufacturer;
	delete[] model;
}

// Overloaded assignment operator ‘=’ - WIP
Car& Car::operator=(Car const& o){
	if (this == &o){
		return *this;
	}
	if (o.manufacturer){
		manufacturer = new char [strlen(o.manufacturer) + 1];
		strcpy(manufacturer,o.manufacturer);
	}
	if (o.model){
		model = new char [strlen(o.model) + 1];
		strcpy(model,o.model);
	}
	zeroToSixtyNs = o.zeroToSixtyNs;
	headonDragCoeff = o.headonDragCoeff;
	horsepower = o.horsepower;
	backseatDoors = o.backseatDoors;
	seatCount = o.seatCount;
	return *this;
}
// Getters
char const* Car::getManufacturer() const{
	return manufacturer;
}

char const* Car::getModel() const{
	return model;
}

PerformanceStats Car::getStats() const{
	PerformanceStats stats {horsepower,zeroToSixtyNs,headonDragCoeff};
	return stats;
}

uint8_t Car::getSeatCount() const{
	return seatCount;
}

DoorKind Car::getBackseatDoors() const{
	return backseatDoors;
}

// Setters
void Car::manufacturerChange(char const* const newManufacturer){
	delete[] manufacturer;
	manufacturer = new char [strlen(newManufacturer) + 1];
	strcpy(manufacturer,newManufacturer);
}

void Car::modelNameChange(char const* const newModelName){
	delete[] model;
	model = new char [strlen(newModelName) + 1];
	strcpy(model,newModelName);
}

void Car::reevaluateStats(PerformanceStats newStats){
	horsepower = newStats.horsepower;
	zeroToSixtyNs = newStats.zeroToSixtyNs;
	headonDragCoeff = newStats.headonDragCoeff;
}

void Car::recountSeats(uint8_t newSeatCount){
	seatCount = newSeatCount;
}

void Car::reexamineDoors(DoorKind newDoorKind){
	backseatDoors = newDoorKind;
}

//int main(){
//	PerformanceStats stat = {5,5,0.5};
//	PerformanceStats newstat = {1,1,0.75};
//	Car testCar;
//	Car origin("A", "B", stat, 6, GullWing);
//	Car audi("audi", "Z", stat, 6, GullWing);
//	Car copy = origin;
//	cout << copy.getManufacturer();
//}