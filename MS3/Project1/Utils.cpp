/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Utils.h"
namespace sdds {
	int getInt(int min, int max)
	{
		int val;
		int flag = 0;
		do {
			cin >> val;// int로 선언 되어있기 때문에
			if (cin.fail())// 자동으로 입력값이 int인지 확인.
			{
				cout << "Invalid Selection, try again: ";
				cin.clear();
				//cin.ignore(1000,'\n');
				while (cin.get() != '\n');
			}
			else if (cin.get() != '\n')//'\n'으로 끝나 지 않았을 경우 .
			{
				cout << "Invalid Selection, try again: ";
				while (cin.get() != '\n');
			}
			else if (val<min || val>max) {
				cout << "Invalid Selection, try again: ";
			}
			else flag = 1;

		} while (flag == 0);
		return val;
	}
}