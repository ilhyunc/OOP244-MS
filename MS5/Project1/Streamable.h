/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	==================================================
	MS5
	==================================================
	Name   : ilhyun cho
	ID     : 116342221
	Email  : icho8@myseneca.ca
	Section: ZBB
*/

#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_

#include <iostream>

namespace sdds {
	class Streamable
	{
	public:
		virtual std::ostream& write(std::ostream& os) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool conIO(std::ios& io) const = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable() {};
	};

	std::ostream& operator<<(std::ostream& os, const Streamable& s);
	std::istream& operator>>(std::istream& is, Streamable& s);
}

#endif 