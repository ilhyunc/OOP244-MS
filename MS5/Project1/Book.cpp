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

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iomanip>

#include "Book.h"

using namespace std;
namespace sdds {
	Book::Book() : m_authorName{nullptr}
	{
	}

	Book::Book(const Book& I) : m_authorName{ nullptr }
	{
		*this = I;
	}

	Book& Book::operator=(const Book& other)
	{
		if (this != &other) {
			Publication::operator=(other);
			if (other.m_authorName) {
				delete[] m_authorName;
				m_authorName = new char[strlen(other.m_authorName) + 1];
				strcpy(m_authorName, other.m_authorName);
			}
		}

		return *this;
	}

	Book::~Book()
	{
		delete[] m_authorName;
	}

	char Book::type() const 
	{
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const
	{
		Publication::write(os);
		if (conIO(os))
		{
			os << ' ';
			if (strlen(m_authorName) > SDDS_AUTHOR_WIDTH)
			{
				for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++)
				{
					os << m_authorName[i];
				}
			}
			else
			{
				os << setw(SDDS_AUTHOR_WIDTH);
				os << m_authorName;
			}
			os << " |";
		}
		else
		{
			os << '\t' << m_authorName;
		}

		return os;
	}

	std::istream& Book::read(std::istream& is)
	{
		char temp[256];

		Publication::read(is);
		delete[] m_authorName;
		if (conIO(is))
		{
			is.ignore();
			cout << "Author: ";
			is.get(temp, 256);
		}
		else
		{
			is.ignore();
			is.get(temp, 256);
		}

		if (is)
		{
			m_authorName = new char[strlen(temp) + 1];
			strcpy(m_authorName, temp);
		}

		return is;
	}

	void Book::set(int member_id)
	{
		Publication::set(member_id);
		Publication::resetDate();
	}

	Book::operator bool() const
	{
		return Publication::operator bool() && m_authorName && m_authorName[0] != '\0';
	}
}