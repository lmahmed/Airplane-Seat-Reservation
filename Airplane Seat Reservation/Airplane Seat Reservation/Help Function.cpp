/*
Author: Latif Ahmed
Creation Date: 11/29/21
Modification Date: 11/29/21
Purpose: Display help menu that includes information about each option.
*/
#include "Header.h"
void Help()
{
	cout << "------------------------- Help --------------------------" << endl << endl;
	cout << "Option 1: This option displays the current seat chart." << endl << endl;
	cout << "Option 2: This option reserves a seat. You must enter the seat you want to reserve in the form: 4A , 6C etc. "
		<< "If available, the seat will be reserved." << endl << endl;
	cout << "Option 3: This option cancels a reservation. You must enter the seat you want to cancel in the form: 2B , 7D etc. "
		<< "If seat is reserved, the reservation will be canceled." << endl << endl;
	cout << "Option 4: This option saves the current seat chart to a file. The name of this file is provided by you." << endl <<
		endl;
	cout << "Option 5: This option displays the number of seats available,"
		<< " percentage of seats that are reserved, list of window seats that are available,"
		<< " list of aisle seats that are available" << endl
		<< "A window seat is the first and last seat in a row; all other seats are considered aisle seats." << endl <<
		endl;
	return;
}