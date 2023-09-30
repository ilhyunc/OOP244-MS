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
			cin >> val;// int�� ���� �Ǿ��ֱ� ������
			if (cin.fail())// �ڵ����� �Է°��� int���� Ȯ��.
			{
				cout << "Invalid Selection, try again: ";
				cin.clear();
				//cin.ignore(1000,'\n');
				while (cin.get() != '\n');
			}
			else if (cin.get() != '\n')//'\n'���� ���� �� �ʾ��� ��� .
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