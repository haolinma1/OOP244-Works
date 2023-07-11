/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7 (P1)
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.07.10
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "Truck.h"
using namespace std;
namespace sdds {

	Truck::Truck(const char* plate, unsigned yearnum, double capacity, const char* address) : MotorVehicle(plate, yearnum) {
		currentWeight = 0;
		maxWeight = capacity;
		this->moveTo(address);
	}

	bool Truck::addCargo(double cargo) {
		if (currentWeight == maxWeight)
		{
			return false;
		}
		else
		{
			if (currentWeight+cargo>maxWeight)
			{
				currentWeight = maxWeight;
			}
			else
			{
				currentWeight += cargo;
			}
			return true;
		}
	}

	bool Truck::unloadCargo() {
		if (currentWeight == 0)
		{
			return false;
		}
		else
		{
			currentWeight = 0;
			return true;
		}
	}

	std::ostream& Truck::write(std::ostream& os)const {
		MotorVehicle::write(os);
		os << " | " << currentWeight << "/" << maxWeight;
		return os;
	}

	std::istream& Truck::read(std::istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> maxWeight;
		cout << "Cargo: ";
		in >> currentWeight;
		return in;
	}

	Truck& operator>>(std::istream& in, Truck& truck) {
		truck.read(in);
		return truck;
	}

	std::ostream& operator<<(std::ostream& os, const Truck& truck) {
		return truck.write(os);
	}
}