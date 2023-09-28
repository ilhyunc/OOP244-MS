#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>

#include "Date.h"
#include "Error.h"
#include "POS.h"
#include "Utils.h"


using namespace std;

namespace sdds
{
	bool Date::validDate()
	{
		if (!errMsg)
		{
			(m_year > MAX_YEAR || m_year < MIN_YEAR) ? errMsg = "Invalid Year" : errMsg;
		}

		if (!errMsg)
		{
			(m_month > 12) ? errMsg = "Invalid Month" : errMsg;
		}

		if (!errMsg)
		{
			(m_day > daysOfMonth(m_year, m_month)) ? errMsg = "Invalid Day" : errMsg;
		}

		if (!errMsg && !m_dateOnly)
		{
			if (m_hour > 23)     
			{
				errMsg = "Invalid Hour";
			}
			else if (m_min > 59)
			{
				errMsg = "Invlid Minute";
			}
		}

		return errMsg;
	}

	void Date::clearDate()
	{
		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_hour = 0;
		m_min = 0;
		m_dateOnly = true;
		errMsg.clear();
	}

	Date::Date()
	{
		getSystemDate(m_year, m_month, m_day, m_hour, m_min, m_dateOnly);
	}

	Date::Date(int year, int month, int day)
	{
		m_year = year;
		m_month = month;
		m_day = day;
		m_hour = -1;
		m_min = -1;
		m_dateOnly = true;
		validDate();
	}

	Date::Date(int year, int month, int day, int hour, int min)
	{
		m_year = year;
		m_month = month;
		m_day = day;
		m_hour = hour;
		m_min = min;
		m_dateOnly = false;
		validDate();
	}

	Error Date::error() const
	{
		return errMsg;
	}

	bool Date::operator==(const Date& other) const
	{
		return uniqueDateValue(m_year, m_month, m_day, m_hour, m_min) == uniqueDateValue(other.m_year, other.m_month, other.m_day, other.m_hour, other.m_min);
	}

	bool Date::operator!=(const Date& other) const
	{
		return uniqueDateValue(m_year, m_month, m_day, m_hour, m_min) != uniqueDateValue(other.m_year, other.m_month, other.m_day, other.m_hour, other.m_min);
	}

	bool Date::operator<(const Date& other) const
	{
		return uniqueDateValue(m_year, m_month, m_day, m_hour, m_min) < uniqueDateValue(other.m_year, other.m_month, other.m_day, other.m_hour, other.m_min);
	}

	bool Date::operator>(const Date& other) const
	{
		return uniqueDateValue(m_year, m_month, m_day, m_hour, m_min) > uniqueDateValue(other.m_year, other.m_month, other.m_day, other.m_hour, other.m_min);
	}

	bool Date::operator<=(const Date& other) const
	{
		return uniqueDateValue(m_year, m_month, m_day, m_hour, m_min) <= uniqueDateValue(other.m_year, other.m_month, other.m_day, other.m_hour, other.m_min);
	}

	bool Date::operator>=(const Date& other) const
	{
		return uniqueDateValue(m_year, m_month, m_day, m_hour, m_min) >= uniqueDateValue(other.m_year, other.m_month, other.m_day, other.m_hour, other.m_min);
	}

	Date::operator bool() const
	{
		return !errMsg;
	}

	Date& Date::dateOnly(bool value)
	{
		m_dateOnly = value;
		if (m_dateOnly) 
		{
			m_hour = 0;
			m_min = 0;
		}
		validDate();

		return *this;
	}

	std::istream& Date::read(std::istream& istr)
	{
		int year{}, month{}, day{}, hour{}, min{};
		Error tempErr;
		char delim;
		errMsg.clear();
		if (!(istr >> year))                       errMsg = "Cannot read year entry";
		istr >> delim;
		if (!errMsg && !(istr >> month))           errMsg = "Cannot read month entry";
		istr >> delim;
		if (!errMsg && !(istr >> day))             errMsg = "Cannot read day entry";
		if (!this->m_dateOnly) {
			istr >> delim;
			if (!errMsg && !(istr >> hour))        errMsg = "Cannot read hour entry";
			istr >> delim;
			if (!errMsg && !(istr >> min))         errMsg = "Cannot read minute entry";
			tempErr = errMsg;
			*this = Date(year, month, day, hour, min);
		}
		else {
			tempErr = errMsg;
			*this = Date(year, month, day);
		}
		errMsg = tempErr;
		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr) const
	{
		if (errMsg)
		{
			ostr << errMsg << "(" << m_year << "/" << setfill('0') << setw(2) << m_month << "/" << setfill('0') << setw(2) << m_day;

			if (!m_dateOnly)    
			{
				ostr << ")";
			}
			else           
			{
				ostr << ", " << setfill('0') << setw(2) << m_hour << ":" << setfill('0') << setw(2) << m_min << ")";
			}
		}
		else 
		{

			ostr << m_year << "/" << setfill('0') << setw(2) << m_month << "/" << setfill('0') << setw(2) << m_day;

			if (!m_dateOnly)  
			{
				ostr << ", " << setfill('0') << setw(2) << m_hour << ":" << setfill('0') << setw(2) << m_min;
			}
		}
		return ostr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& date)
	{
		return date.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Date& date)
	{
		return date.read(istr);
	}

}