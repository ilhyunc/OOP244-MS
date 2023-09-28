#include "PosIO.h"

using namespace std;

namespace sdds
{
    ostream& operator<<(ostream& ostr, const PosIO& pos)
    {
        return pos.write(ostr);
    }

    ofstream& operator<<(ofstream& ofstr, const PosIO& pos)
    {
        return pos.save(ofstr);
    }

    istream& operator>>(istream& istr, PosIO& pos)
    {
        return pos.read(istr);
    }

    ifstream& operator>>(ifstream& ifstr, PosIO& pos)
    {
        return pos.load(ifstr);
    }
}
