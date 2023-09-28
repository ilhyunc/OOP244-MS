#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H
#include <iostream>

namespace sdds
{
    class Error
    {
        char* m_errMsgPtr{};

    public:
        Error(const char* msg = nullptr);
        Error(const Error& other);
        ~Error();

        Error& operator=(const Error& other);
        Error& operator=(const char* errMsg);
        operator bool() const;

        Error& clear();
        std::ostream& getMsg(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Error& err);
}

#endif