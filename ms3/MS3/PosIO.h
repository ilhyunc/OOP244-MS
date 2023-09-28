#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H

#include <iostream>

namespace sdds 
{
    class PosIO 
    {
    public:
        virtual std::ostream& write(std::ostream& ostr)  const = 0;
        virtual std::istream& read(std::istream& istr) = 0;
        virtual std::ofstream& save(std::ofstream& ofstr) const = 0;
        virtual std::ifstream& load(std::ifstream& ifstr) = 0;
    };

    std::ostream& operator<<(std::ostream& ostr, const PosIO& pos);
    std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& pos);

    std::istream& operator>>(std::istream& istr, PosIO& pos);
    std::ifstream& operator>>(std::ifstream& ifstr, PosIO& pos);
}

#endif