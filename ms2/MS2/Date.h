#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Error.h"


namespace sdds
{
	class Date
	{
        int m_year{};
        int m_month{};
        int m_day{};
        int m_hour{};
        int m_min{};
        bool m_dateOnly{};
        Error errMsg{};

        bool validDate();
        void clearDate();

    public:
        Date();
        Date(int year, int month, int day);
        Date(int year, int month, int day, int hour, int min = 0);

        Error error() const;

        bool operator==(const Date& other) const;
        bool operator!=(const Date& other) const;
        bool operator<(const Date& other) const;
        bool operator>(const Date& other) const;
        bool operator<=(const Date& other) const;
        bool operator>=(const Date& other) const;

        operator bool() const;

        Date& dateOnly(bool value);

        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
	};

    std::ostream& operator<<(std::ostream& ostr, const Date& date);
    std::istream& operator>>(std::istream& istr, Date& date);
}
#endif