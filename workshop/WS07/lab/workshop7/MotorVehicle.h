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
namespace sdds {
	class MotorVehicle {
		char plateNum[9];
		char location[64];
		unsigned year;
	public:
		MotorVehicle(const char* plate, unsigned yearnum); // constructor
		void moveTo(const char* address); // move to new address if the argument address is different from the orginal
		std::ostream& write(std::ostream& os); // display year, plate and location in fixed format
		std::istream& read(std::istream& in); // read the information inputted by the user
		unsigned getYear()const; // get the year of the vehicle
		const char* getPlate()const; // get the plate number
		const char* getAddress()const;
	};

	MotorVehicle& operator>>(std::istream& in, MotorVehicle& vehicle); // overload the >> to insert information to MotorVehicle
	std::ostream& operator<<(std::ostream& os, MotorVehicle& vehicle); // overload << to display the information of the vechile
}
