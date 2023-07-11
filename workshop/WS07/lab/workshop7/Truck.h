#pragma once
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
#include "MotorVehicle.h"

namespace sdds {
	class Truck : public MotorVehicle {
		double maxWeight;
		double currentWeight;
	public:
		Truck(const char* plate, unsigned yearnum, double capacity, const char* address); // constructor
		bool addCargo(double cargo); // add the cargo weight by the argument
		bool unloadCargo(); // unload the cargo weight
		std::ostream& write(std::ostream& os)const; // display the information of truck
		std::istream& read(std::istream& in); // read the information from user
	};

	// helper function
	Truck& operator>>(std::istream& in, Truck& truck);
	std::ostream& operator<<(std::ostream& os, const Truck& truck);
	
}