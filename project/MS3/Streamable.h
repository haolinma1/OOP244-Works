#pragma once
#include <iostream>
namespace sdds {
	class Streamable {
	public:
		virtual std::ostream& write(std::ostream& os)const = 0; // pure virtual function
		virtual std::istream& read(std::istream&) = 0; // pure virtual function
		virtual bool conIO(std::ios& IOS)const=0; // this function will determine if the incoming ios object is a console IO object or not.
		virtual operator bool() const=0; // return if the Streamable object true or not, pure virtual function
		virtual ~Streamable() ; // virtual empty destructor


	};
	std::ostream& operator<<(std::ostream& os, const Streamable& streamable);
	std::istream& operator>>(std::istream& is, Streamable& streamable);
}
