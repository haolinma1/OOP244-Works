#include "Streamable.h"
namespace sdds {
	Streamable::~Streamable() {
		// do nothing
	}

	std::ostream& operator<<(std::ostream& os, const Streamable& streamable) {
		if (streamable)
		{
			return streamable.write(os);
		}
		else return os;
	}

	std::istream& operator>>(std::istream& is, Streamable& streamable) {
		return streamable.read(is);
	}
}