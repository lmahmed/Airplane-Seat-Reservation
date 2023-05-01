/*
Author: Latif Ahmed
Creation Date: 11/29/21
Modification Date: 11/29/21
Purpose: Calls other functions based on user's choice.
*/
#include "Header.h"
int main()
{
	cout << "Start of program" << endl; // Start of program
	Plane plane1;
	plane1.Read();
	int choice = Menu();
	while (choice != 7)
	{
		switch (choice)
		{
		case 1: plane1.Display();
			break;
		case 2: plane1.Reserve();
			break;
		case 3: plane1.Cancel();
			break;
		case 4: plane1.Save();
			break;
		case 5: plane1.Statistics();
			break;
		case 6: Help();
			break;
		}
		choice = Menu();
	}
	cout << "----------- Thank you for using this program ------------" << endl << endl;
	return 0;
}
