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

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "LibApp.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	bool LibApp::confirm(const char* message)
	{
		Menu m(message);
		m << "Yes";
		return m.run() == 1;
	}

	void LibApp::load()
	{
		cout << "Loading Data" << endl;
		ifstream is(m_fileName);

		char ch;
		int llrn = 0;

		do
		{
			ch = '\0';
			is >> ch;
			if (ch == 'P')
			{
				m_ppa[m_nolp] = new Publication();
			}
			else if (ch == 'B')
			{
				m_ppa[m_nolp] = new Book();
			}

			if (ch == 'P' || ch == 'B')
			{
				is >> *m_ppa[m_nolp];
				llrn = m_ppa[m_nolp++]->getRef();
			}

		} while (is);

		m_llrn = llrn;
	}

	void LibApp::save()
	{
		cout << "Saving Data" << endl;
		ofstream os(m_fileName);

		for (int i = 0; i < m_nolp; i++)
		{
			if (m_ppa[i]->getRef() != 0)
			{
				os << *m_ppa[i] << endl;
			}
		}
	}

	int LibApp::search(int mode)
	{
		PublicationSelector ps("Select one of the following found matches:");

		int select = m_pubType.run();
		char temp[256];
		int result = 0;

		if (select == 1)
		{
			cout << "Publication Title: ";
			cin.getline(temp, 255);
			for (int i = 0; i < m_nolp; i++) 
			{
				if (m_ppa[i] && m_ppa[i]->type() == 'B' && *m_ppa[i] == temp) 
				{
					if (mode == 0) 
					{
						ps << m_ppa[i];
					}
					else if (mode == 1)
					{
						if (m_ppa[i]->onLoan())
							ps << m_ppa[i];
					}
					else if (mode == 2) 
					{
						if (!m_ppa[i]->onLoan())
							ps << m_ppa[i];
					}
				}
			}

			if (ps) 
			{
				ps.sort();
				if ((result = ps.run()) == 0)
					cout << "Aborted!" << endl;
			}
			else 
			{
				cout << "No matches found!" << endl;
			}
		}
		else if (select == 2) 
		{
			cout << "Publication Title: ";
			cin.getline(temp, 255);
			for (int i = 0; i < m_nolp; i++)
			{
				if (m_ppa[i] && m_ppa[i]->type() == 'P' && *m_ppa[i] == temp)
				{
					if (mode == 0) 
					{
						ps << m_ppa[i];
					}
					else if (mode == 1)
					{
						if (m_ppa[i]->onLoan())
							ps << m_ppa[i];
					}
					else if (mode == 2) 
					{
						if (!m_ppa[i]->onLoan())
							ps << m_ppa[i];
					}
				}
			}

			if (ps) 
			{
				ps.sort();
				if ((result = ps.run()) == 0)
					cout << "Aborted!" << endl;
			}
			else
			{
				cout << "No matches found!" << endl;
			}
		}
		else if (select == 0)
		{
			cout << "Aborted!" << endl;
		}

		return result;
	}

	void LibApp::returnPub()
	{
		cout << "Return publication to the library" << endl;

		int ref = search(1);

		if (ref != 0) 
		{
			Publication* selected = getPub(ref);
			selected->write(cout);
			cout << endl;
			if (confirm("Return Publication?"))
			{
				int dateDiff = Date() - selected->checkoutDate();
				cout << setprecision(2) << fixed;
				if (dateDiff > 15) 
				{
					cout << "Please pay $" << (dateDiff - 15) * 0.5 << " penalty for being " << dateDiff - 15 << " days late!" << endl;
				}

				selected->set(0);
				m_changed = true;
				cout << "Publication returned" << endl;
			}
		}
	}

	void LibApp::newPublication()
	{
		if (m_nolp == SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!" << endl;
		}
		else
		{
			cout << "Adding new publication to the library" << endl;

			int select = m_pubType.run();

			if (select == 1 || select == 2)
			{
				Publication* pptr;

				if (select == 1)
				{
					pptr = new Book();
				}
				else
				{
					pptr = new Publication();
				}

				if (!(pptr->read(cin)))
				{
					cin.ignore(1000, '\n');
					cout << "Aborted!" << endl;
				}
				else
				{
					if (confirm("Add this publication to the library?"))
					{
						if (*pptr)
						{
							pptr->setRef(++m_llrn);
							m_ppa[m_nolp++] = pptr;
							m_changed = true;
							cout << "Publication added" << endl;
						}
						else
						{
							cout << "Failed to add publication!" << endl;
							delete pptr;
						}
					}
					else
					{
						cout << "Aborted!" << endl;
					}
				}

			}
			else
			{
				cout << "Aborted!" << endl;
			}
		}
	}

	void LibApp::removePublication()
	{
		cout << "Removing publication from the library" << endl;

		int ref = search(0);

		if (ref != 0) 
		{
			Publication* selected = getPub(ref);
			selected->write(cout);
			cout << endl;
			if (confirm("Remove this publication from the library?"))
			{
				selected->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}
	}

	void LibApp::checkOutPub()
	{

		cout << "Checkout publication from the library" << endl;

		int ref = search(2);

		if (ref != 0) 
		{
			Publication* selected = getPub(ref);
			selected->write(cout);
			cout << endl;
			if (confirm("Check out publication?"))
			{
				cout << "Enter Membership number: ";
				int membership = getIntForMemberShip(10000, 99999);
				selected->set(membership);
				m_changed = true;
				cout << "Publication checked out" << endl;
			}
		}
	}

	LibApp::LibApp(const char* filename) :m_fileName{ "" }, m_ppa{ nullptr }, m_nolp{ 0 }, m_llrn{ 0 }, m_pubType{ "Choose the type of publication:" }, m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
	{
		strcpy(m_fileName, filename);
		m_pubType << "Book" << "Publication";
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		load();
	}

	void LibApp::run()
	{
		bool flag = false;
		int selection = -1;

		do
		{
			flag = true;

			selection = m_mainMenu.run();

			if (selection == 1) newPublication();
			else if (selection == 2) removePublication();
			else if (selection == 3) checkOutPub();
			else if (selection == 4) returnPub();
			else
			{
				if (m_changed)
				{
					selection = m_exitMenu.run();
					if (selection == 1)
					{
						save();
						flag = false;
					}
					else if (selection == 0)
					{
						if (confirm("This will discard all the changes are you sure?"))
						{
							flag = false;
						}
					}
				}
				else flag = false;
			}
			cout << endl;

		} while (flag);

		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}

	Publication* LibApp::getPub(int libRef) const
	{
		Publication* result = nullptr;

		for (int i = 0; i < m_nolp && !result; i++)
		{
			if (m_ppa[i]->getRef() == libRef)
				result = m_ppa[i];
		}

		return result;
	}

	LibApp::~LibApp()
	{
		for (int i = 0; i < m_nolp; i++) {
			delete m_ppa[i];
		}
	}
}