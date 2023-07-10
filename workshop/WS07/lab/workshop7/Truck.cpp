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
		this->moveTo(address);
	}

	bool Truck::addCargo(double cargo) {
		if (currentWeight+cargo>maxWeight)
		{
			return false;
		}
		else
		{
			currentWeight += cargo;
			return true;
		}
	}

	bool Truck::unloadCargo() {
		if (currentWeight==0)
		{
			return false;
		}
		else
		{
			currentWeight = 0;
			return true;
		}
	}

	ostream& Truck::write(ostream& os) {
		cout << "| " << this->getYear() << " | " << this->getPlate() << " | " << this->getAddress() << " | " << currentWeight / maxWeight;
	}

	istream& Truck::read(istream& in) {
		this->read(in);
		cout << "Capacity: ";
		in >> currentWeight;
		cout << "Cargo: ";
		in >> maxWeight;
		return in;
	}
}