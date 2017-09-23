/*************************************************************
* Oscar Lugo
* CS311 - Data Structures
* Lab1 - Review in LL
* 9/10/17
*/

#include "stdafx.h"
#include "Authorization.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

	int main()
	{
		/*
		Authorization CS311;
		CS311.AddMember(123,"Steve001","1234");
		CS311.PrintAll();
		cout << "Second member added" << endl;
		cout << " " << endl;
		CS311.AddMember(567,"May002","7954");
		CS311.PrintAll();
		*/
		
		Authorization obj1;
		int selection;
		bool isValid = false;

		while (!isValid)
		{
			cout << "*******************************************************" << endl;
			cout << "1)	Process a transaction file " << endl;
			cout << "2)	Saving the information in the configuration file " << endl;
			cout << "3)	Quit/Exit " << endl;
			cout << "******************************************************" << endl;

			cin >> selection;
			cin.clear();
			cin.ignore(1000, '\n');

			if (selection == 1 || selection == 2 || selection == 3)
			{
				switch (selection)
				{
				case 1:
					obj1.ProcessTransaction();
					break;
				case 2:
					obj1.SaveConfiguration();
					break;
				case 3:
					cout << "Program Terminated" << endl;
					isValid = true;
				}
			}
			else
			{
				isValid = false;
				cout << "Invalid election, enter 1,2 or 3, try again " << endl;
			}
		}
		
		return 0;
	}