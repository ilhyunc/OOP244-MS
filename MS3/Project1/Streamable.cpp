/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	==================================================
	MS3
	==================================================
	Name   : ilhyun cho
	ID     : 116342221
	Email  : icho8@myseneca.ca
	Section: ZBB
*/

#include "Streamable.h"

namespace sdds {

	std::ostream& operator<<(std::ostream& os, const Streamable& s)
	{
		if (s)
		{
			s.write(os);
		}

		return os;
	}

	std::istream& operator>>(std::istream& is, Streamable& s)
	{
		return s.read(is);
	}
}