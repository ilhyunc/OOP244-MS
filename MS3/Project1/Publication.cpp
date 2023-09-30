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

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iomanip>
#include <iostream> 

#include "Publication.h"

using namespace std;
namespace sdds {

	bool Publication::conIO(std::ios& io) const
	{
		return &io == &cout || &io == &cin;
	}

	 std::ostream& Publication::write(std::ostream& os) const
	{
		 if (conIO(os))
		 {
			 os << "| " << m_shelfId << " | " << setw(30) << left << setfill('.') << m_title << " | ";
			 if (m_membership > 0 && m_membership < 100000)
				 os << m_membership;
			 else
				 os << " N/A ";

			 os << " | " << m_date << " |";
		 }
		 else
		 {
			 os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t' << m_title << '\t' << m_membership << '\t' << m_date;
		 }
		 return os;
	}

	 std::istream& Publication::read(std::istream& is)
	 {
		 delete[] m_title;
		 m_title = nullptr;
		 m_shelfId[0] = '\0';
		 m_membership = 0;
		 m_libRef = -1;
		 m_date = Date();

		 char tempTitle[31];
		 string tempShelf;

		 if (conIO(is))
		 {
			 cout << "Shelf No: ";
			 is >> tempShelf;
			 if (tempShelf.length() != 4)
			 {
				 is.setstate(std::ios::failbit);
			 }
			 else
			 {
				 strcpy(m_shelfId, tempShelf.c_str());
			 }
			 is.ignore(1000, '\n');

			 cout << "Title: ";
			 is.getline(tempTitle, 30);

			 cout << "Date: ";
			 is >> m_date;
			 if (!m_date) {
				 is.setstate(std::ios::failbit);
			 }
		 }
		 else
		 {
			 is >> m_libRef;
			 is.ignore();

			 is >> m_shelfId;
			 is.ignore();

			 is.getline(tempTitle, 30, '\t');

			 is >> m_membership;
			 is.ignore();

			 is >> m_date;
			 if (!m_date) {
				 is.setstate(std::ios::failbit);
			 }
		 }

		 if (is) 
		 {
			 m_title = new char[strlen(tempTitle) + 1];
			 strcpy(m_title, tempTitle);
		 }

		 return is;
	 }

	 Publication::operator bool() const
	 {
		 return m_title && m_title[0] != '\0' && m_shelfId[0] != '\0';
	 }

	 Publication::Publication() : m_title{}, m_shelfId{}, m_membership{}, m_libRef{ -1 }, m_date{}
	 {
	 }

	 Publication::Publication(const Publication& I) : m_title{}, m_shelfId{}, m_membership{}, m_libRef{ -1 }, m_date{}
	 {
		 *this = I;
	 }

	 Publication& Publication::operator=(const Publication& other)
	 {
		 if (this != &other)
		 {
			 if (other.m_title)
			 {
				 delete[] m_title;
				 m_title = new char[strlen(other.m_title) + 1];
				 strcpy(m_title, other.m_title);
			 }
			 strcpy(m_shelfId, other.m_shelfId);
			 m_membership = other.m_membership;
			 m_libRef = other.m_libRef;
			 m_date = other.m_date;
		 }

		 return *this;
	 }

	 Publication::~Publication()
	 {
		 delete[] m_title;
	 }

	 void Publication::set(int member_id)
	{
		if (member_id > 0 && member_id < 100000)
		{
			m_membership = member_id;
		}
		else m_membership = 0;
	}

	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	void Publication::resetDate()
	{
		m_date = Date();
	}

	char Publication::type() const
	{
		return 'P';
	}

	bool Publication::onLoan() const
	{
		return m_membership != 0;
	}

	Date Publication::checkoutDate() const
	{
		return m_date;
	}

	bool Publication::operator==(const char* title) const
	{
		return strstr(m_title,title);
	}

	Publication::operator const char* () const
	{
		return m_title;
	}

	int Publication::getRef() const
	{
		return m_libRef;
	}

}
