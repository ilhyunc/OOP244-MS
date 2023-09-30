/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	==================================================
	MS2
	==================================================
	Name   : ilhyun cho
	ID     : 116342221
	Email  : icho8@myseneca.ca
	Section: ZBB
*/

#include <iostream>
#include "LibApp.h"

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
	}

	void LibApp::save()
	{
		cout << "Saving Data" << endl;
	}

	void LibApp::search()
	{
		cout << "Searching for publication" << endl;
	}

	void LibApp::returnPub()
	{
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
	}

	void LibApp::newPublication()
	{
		cout << "Adding new publication to library" << endl;
		if (confirm("Add this publication to library?"))
		{
			m_changed = true;
			cout << "Publication added" << endl;
		}
	}

	void LibApp::removePublication()
	{
		cout << "Removing publication from library" << endl;
		search();
		if (confirm("Remove this publication from the library?"))
		{
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	}

	void LibApp::checkOutPub()
	{
		search();
		if (confirm("Check out publication?"))
		{
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	}

	LibApp::LibApp() :m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
	{
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

}