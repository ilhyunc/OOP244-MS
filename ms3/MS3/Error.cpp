#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Error.h"

using namespace std;

namespace sdds
{
    Error::Error(const char* msg)
    {
        m_errMsgPtr = nullptr;

        if (msg != nullptr && msg[0] != '\0')
        {
            m_errMsgPtr = new char[strlen(msg) + 1];
            strcpy(m_errMsgPtr, msg);
            m_errMsgPtr[strlen(msg)] = '\0';
        }
    }

    Error::Error(const Error& other)
    {
        if (this != &other)
        {
            operator=(other);
        }
    }

    Error::~Error()
    {
        delete[] m_errMsgPtr;
        m_errMsgPtr = nullptr;
    }

    Error& Error::operator=(const Error& other)
    {
        if (other)
        {
            clear();
            m_errMsgPtr = new char[strlen(other.m_errMsgPtr) + 1];
            memcpy(m_errMsgPtr, other.m_errMsgPtr, strlen(other.m_errMsgPtr));
            m_errMsgPtr[strlen(other.m_errMsgPtr)] = '\0';
        }

        return *this;
    }

    Error& Error::operator=(const char* errMsg)
    {
        clear();

        if (errMsg)
        {
            m_errMsgPtr = new char[strlen(errMsg) + 1];
            strcpy(m_errMsgPtr, errMsg);
            m_errMsgPtr[strlen(errMsg)] = '\0';
        }

        return *this;
    }

    Error::operator bool() const
    {
        return m_errMsgPtr != nullptr;
    }

    Error& Error::clear()
    {
        if (m_errMsgPtr != nullptr)
        {
            delete[] m_errMsgPtr;
            m_errMsgPtr = nullptr;
        }

        return *this;
    }

    std::ostream& Error::getMsg(std::ostream& ostr) const
    {
        if (m_errMsgPtr != nullptr)
        {
            ostr << m_errMsgPtr;
        }

        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Error& err)
    {
        return err.getMsg(ostr);
    }

}