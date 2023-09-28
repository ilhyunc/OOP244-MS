#include<iostream>
#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H

namespace sdds 
{
    class PosApp 
    {
        char m_fileName[255 + 1]{};
        void validateInput(int& input);

    public:
        PosApp(const char* fileName = nullptr);

        PosApp(const PosApp& rep) = delete;
        PosApp& operator=(const PosApp& rep) = delete;

        std::ostream& addItem(std::ostream& ostr = std::cout);
        std::ostream& removeItem(std::ostream& ostr = std::cout);
        std::ostream& stockItem(std::ostream& ostr = std::cout);
        std::ostream& listItems(std::ostream& ostr = std::cout) const;
        std::ostream& pos(std::ostream& ostr = std::cout) const;
        std::ostream& saveRecs(std::ostream& ostr = std::cout);
        std::ostream& loadRecs(std::ostream& ostr = std::cout);

        PosApp& menu();
        PosApp& run();
    };
}

#endif
