#define _CRT_SECURE_NO_WARNINGS

#include "PosApp.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sdds
{
    std::ostream& PosApp::addItem(std::ostream& ostr)
    {
        ostr << ">>>> Adding Item to the store................................................"
            << endl << "Running addItem()";
        return ostr;
    }

    std::ostream& PosApp::removeItem(std::ostream& ostr)
    {
        ostr << ">>>> Remove Item............................................................."
            << endl << "Running removeItem()";
        return ostr;
    }

    std::ostream& PosApp::stockItem(std::ostream& ostr)
    {
        ostr << ">>>> Select an item to stock................................................."
            << endl << "Running stockItem()";
        return ostr;
    }

    std::ostream& PosApp::listItems(std::ostream& ostr) const
    {
        ostr << ">>>> Listing Items..........................................................."
            << endl << "Running listItems()";
        return ostr;
    }

    std::ostream& PosApp::pos(std::ostream& ostr) const
    {
        ostr << ">>>> Starting Point of Sale.................................................."
            << endl << "Running POS()";
        return ostr;
    }

    std::ostream& PosApp::saveRecs(std::ostream& ostr)
    {
        ostr << ">>>> Saving Data............................................................."
            << endl << "Saving data in " << this->m_fileName;
        return ostr;
    }

    std::ostream& PosApp::loadRecs(std::ostream& ostr)
    {
        ostr << ">>>> Loading Items..........................................................."
            << endl << "Loading data from " << this->m_fileName;
        return ostr;
    }

    PosApp& PosApp::menu()
    {
        cout << "The Sene-Store" << endl;
        cout << "1- List items" << endl;
        cout << "2- Add item" << endl;
        cout << "3- Remove item" << endl;
        cout << "4- Stock item" << endl;
        cout << "5- Point of Sale" << endl;
        cout << "0- exit program" << endl;

        return *this;
    }

    PosApp& PosApp::run()
	{
        int selection;
        
        loadRecs() << endl;
        do
        {
            menu();
            validateInput(selection);
            switch (selection) 
            {
                case 0:
                saveRecs() << endl << "Goodbye!" << endl;
                break;

            case 1:
                listItems() << endl;
                break;

            case 2:
                addItem() << endl;
                break;

            case 3:
                removeItem() << endl;
                break;

            case 4:
                stockItem() << endl;
                break;

            case 5:
                pos() << endl;
                break;
            }

        } while (selection);

        return *this;
	}

    void PosApp::validateInput(int& input)
    {
        bool flag = true;
        while (flag)
        {
            cin >> input;
            if (cin.fail())
            {
                cout << "Invalid Integer, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (input > 5 || input < 0)
            {
                cout << "[0<=value<=5], retry: > ";
            }
            else
            {
                flag = false;
            }
        }
    }

    PosApp::PosApp(const char* fileName)
    {
        if (fileName != nullptr && fileName[0] != '\0') 
        {
            strncpy(m_fileName, fileName, 255);
            m_fileName[255] = '\0';
        }
        else 
        {
            m_fileName[0] = '\0';
        }
    }
}