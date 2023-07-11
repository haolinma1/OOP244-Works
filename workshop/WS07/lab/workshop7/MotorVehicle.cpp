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
#include "Utils.h"
using namespace std;
namespace sdds {

	MotorVehicle::MotorVehicle(const char* plate, unsigned yearnum) {
		strCpy(plateNum, plate);
		year = yearnum;
		strCpy(location, "Factory");
	}

	void MotorVehicle::moveTo(const char* address) {
		if (strCmp(location, address)!=0)
		{
			cout << "|";
			cout.setf(ios::right);
			cout.width(8);
			cout << plateNum;
			cout << "| |";
			cout.width(20);
			cout << location;
			cout << " ---> ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(20);
			cout << address;
			cout << "|" << endl;
			strCpy(location, address);
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os)const {
		os << "| " << year << " | " << plateNum << " | " << location;
		return os;
	}

	std::istream& MotorVehicle::read(std::istream& in) {
		cout << "Built year: ";
		in >> year;
		cout << "License plate: ";
		in >> plateNum;
		cout << "Current location: ";
		in >> location;
		return in;
	}

	MotorVehicle& operator>>(std::istream& in, MotorVehicle& vehicle) {
		vehicle.read(in);
		return vehicle;
	}

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle) {
		return vehicle.write(os);
	}
}