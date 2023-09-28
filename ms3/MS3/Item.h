
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include <fstream>

#include "PosIO.h"
#include "POS.h"
#include "Error.h"

namespace sdds 
{
    class Item : public PosIO
    {
        char m_sku[MAX_SKU_LEN + 1]{};
        char* m_itemName = nullptr;
        double m_price{};
        bool m_isTaxed{};
        int m_quantity{};

    protected:
        int m_displayType{};
        Error err{};

    public:
        Item();
        ~Item();
        Item(const Item& other);
        Item& operator=(const Item& other);
        bool operator==(const char* name)  const;
        bool operator>(const Item& other)  const;
        int operator+=(const int value);
        int operator-=(const int value);
        operator bool() const;

        virtual char itemType() const = 0;
        double cost()  const;
        int quantity() const;

        Item& clear();
        Item& displayType(int posValue);
        std::ostream& bprint(std::ostream& ostr) const;
        std::ostream& write(std::ostream& ostr)  const override;
        std::istream& read(std::istream& istr)         override;
        std::ofstream& save(std::ofstream& ostr)  const override;
        std::ifstream& load(std::ifstream& istr)        override;

    };

    double operator+=(double& value, const Item& ROp);

}

#endif