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

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include "PublicationSelector.h"
#include "Book.h"
#include "Lib.h"
#include "Menu.h"

namespace sdds {
	class LibApp {
		char m_fileName[256];
		Publication* m_ppa[SDDS_LIBRARY_CAPACITY];
		int m_nolp;
		int m_llrn;
		Menu m_pubType;

		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		bool confirm(const char* message);
		void load();  // prints: "Loading Data"<NEWLINE>
		void save();  // prints: "Saving Data"<NEWLINE>
		int search(int mode);  // prints: "Searching for publication"<NEWLINE>

		void returnPub();  /*  Calls the search() method.
							   prints "Returning publication"<NEWLINE>
							   prints "Publication returned"<NEWLINE>
							   sets m_changed to true;
						   */
		void newPublication();
		void removePublication();
		void checkOutPub();
	public:
		LibApp(const char* filename);
		~LibApp();
		void run();
		Publication* getPub(int libRef)const;
	};
}
#endif // !SDDS_LIBAPP_H