#include "Header.h"
#include "colors.h"
void Plane::Read()
{
	ifstream seatChartIn;
	seatChartIn.open("chartIn.txt");
		int rowNum;
	while (!seatChartIn.eof())
	{
		stringstream theRow;
		string theRowString;
		int columnPosition = 0;
		getline(seatChartIn, theRowString);
		theRow << theRowString;
		theRow >> rowNum;
		seatChart.push_back(vector<Seat>()); // Pushback empty row vector
		// ostringstream to "convert" int to string
		ostringstream row;
		row << rowNum;
		char reserve;
		while (theRow >> reserve) // False when end of line
		{
			string location = "";
			location += row.str();
			location += char(columnPosition + 65); // Not dependent on file
			columnPosition++;
			// Pushback an instance of Seat into row vector
			if (reserve == 'X')
			{
				seatChart.at(seatChart.size() - 1).push_back(Seat(location, true));
			}
			else
				seatChart.at(seatChart.size() - 1).push_back(Seat(location));
		}
	}
	seatChartIn.close();
}
void Plane::Display()
{
	for (int i = 0; i < seatChart.size(); i++) // Iterates through rows
	{
		cout << setw(4) << left << i + 1 << " "; // Cout of row number
		for (int n = 0; n < seatChart.at(i).size(); n++) // Iterates through collumns
		{
			// cout of collumn letter or X if reserved
			if (seatChart.at(i).at(n).reserved)
				cout << BOLD(FRED("X ")); // Uses colors.h
			else
				cout << char(n + 65) << " ";
		}
		cout << endl;
	}
	cout << "*X means seat is reserved*" << endl;
}
void Plane::Reserve()
{
	istringstream tempRow;
	string userSeat;
	int row, collumn;
	cout << "Enter seat desired in form of 3A , 10D etc: ";
	cin >> userSeat;
	bool seatFound = false;
	for (int i = 0; i < seatChart.size(); i++) // Iterates through rows
	{
		for (int n = 0; n < seatChart.at(i).size(); n++) // Iterates through collumns
		{
			if (seatChart.at(i).at(n).name == userSeat) // Checking if user's input is any seat's name.
			{
				seatFound = true;
				if (seatChart.at(i).at(n).reserved)
				{
					cout << "Seat " << userSeat << " is not available.";
				}
				else
				{
					seatChart.at(i).at(n).reserved = true;
					cout << "Seat " << userSeat << " has been reserved.";
				}
				break; // Breaks out of collumn loop
			}
		}
		if (seatFound) // Breaks out of row loop
			break;
	}
	if (!seatFound)
	{
		cout << "Seat does not exist.";
	}
	cout << endl;
}
void Plane::Cancel()
{
	istringstream tempRow;
	string userSeat;
	int row, collumn;
	cout << "Enter seat to cancel reservataion for in form of 3A , 10D etc: ";
	cin >> userSeat;
	bool seatFound = false;
	for (int i = 0; i < seatChart.size(); i++) // Iterates through rows
	{
		for (int n = 0; n < seatChart.at(i).size(); n++) // Iterates through collumns
		{
			if (seatChart.at(i).at(n).name == userSeat) // Checking if user's input is any seat's name.
			{
				seatFound = true;
				if (seatChart.at(i).at(n).reserved)
				{
					seatChart.at(i).at(n).reserved = false;
					cout << "Seat " << userSeat << " has been canceled.";
				}
				else
				{
					cout << "Seat " << userSeat << " cannot be canceled because it has not beenreserved.";
				}
				break; // Breaks out of collumn loop
			}
		}
		if (seatFound) // Breaks out of row loop
			break;
	}
	if (!seatFound)
	{
		cout << "Seat does not exist.";
	}
	cout << endl;
}
void Plane::Save()
{
	ofstream currentSeatChart;
	string fileName;
	cout << "Enter a file name: ";
	// User's desired file name added to specified location
	getline(cin, fileName);
	fileName += ".txt";
	currentSeatChart.open(fileName);
	for (int i = 0; i < seatChart.size(); i++) // Iterates through rows
	{
		currentSeatChart << setw(5) << left << i + 1 << " "; // ofstream of row number
		for (int n = 0; n < seatChart.at(i).size(); n++) // Iterates through collumns
		{
			// ofstream of collumn letter or X if reserved
			if (seatChart.at(i).at(n).reserved)
				currentSeatChart << "X ";
			else
				currentSeatChart << char(n + 65) << " ";
		}
		currentSeatChart << endl;
	}
	cout << fileName << " has been saved to program folder" << endl;
		currentSeatChart.close();
}
void Plane::Statistics()
{
	int numOfAvailableSeats = 0;
	int totalNumOfSeats = 0;
	// Loop to find total number of seats and number of available seats
	for (int i = 0; i < seatChart.size(); i++) // Iterates through rows
	{
		for (int n = 0; n < seatChart.at(i).size(); n++) // Iterates through collumns
		{
			totalNumOfSeats++;
			if (!(seatChart.at(i).at(n).reserved))
				numOfAvailableSeats++;
		}
	}
	cout << "Number of available seats: " << numOfAvailableSeats << endl;
	// totalNumOfSeats-numOfAvailableSeats = number of reserved seats
	cout << "Percentage of seats reserved: " << ((double)totalNumOfSeats - numOfAvailableSeats) / totalNumOfSeats <<
		endl;
	cout << "Window Seats Available: " << endl;
	for (int i = 0; i < seatChart.size(); i++) // Iterates through rows
	{
		if (!(seatChart.at(i).at(0).reserved)) // Look at first collumn in row
			cout << setw(5) << seatChart[i][0].name << " ";
		else cout << " ";
		if (!(seatChart.at(i).at(seatChart.at(i).size() - 1).reserved)) // Look at last collumn in row
			cout << setw(5) << seatChart.at(i).at(seatChart.at(i).size() - 1).name << " ";
		cout << endl;
	}
	cout << "Aisle Seats Available: " << endl;
	for (int i = 0; i < seatChart.size(); i++) // Iterates through rows
	{
		// Iterates through collumns between first and last collumn
		for (int n = 1; n <= seatChart.at(i).size() - 2; n++)
		{
			if (!(seatChart.at(i).at(n).reserved))
				cout << setw(5) << seatChart.at(i).at(n).name << " ";
			else cout << " ";
		}
		cout << endl;
	}
}