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

#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_

#include "Publication.h"
#include "Lib.h"

namespace sdds {
    class Book : public Publication
    {
        char* m_authorName;
    
    public:
        Book();

        Book(const Book& I);
        Book& operator=(const Book& other);
        ~Book();

        char type() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);
        void set(int member_id);
        operator bool() const;
    };
}

#endif // !SDDS_BOOK_H_