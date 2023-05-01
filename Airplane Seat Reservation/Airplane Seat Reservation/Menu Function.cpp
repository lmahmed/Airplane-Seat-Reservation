/*
Author: Latif Ahmed
Creation Date: 11/29/21
Modification Date: 11/29/21
Purpose: Display menu and return user's choice
*/
#include "Header.h"
int Menu()
{
	int choice;
	cout << "------------------------ Menu ---------------------------" << endl << endl;
	cout << " 1. Display Seat Chart" << endl;
	cout << " 2. Reserve Seat" << endl;
	cout << " 3. Cancel Reservation" << endl;
	cout << " 4. Save Seat Chart to File" << endl;
	cout << " 5. Statistics" << endl;
	cout << " 6. Help" << endl;
	cout << " 7. Quit" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "Please Enter Your Choice (1-7): ";
	cin >> choice;
	while (cin.fail() || choice <= 0 || choice >= 8) // Validation of user input
	{
		cout << "Invalid choice. Please Enter Your Choice (1-7): ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choice;
}
