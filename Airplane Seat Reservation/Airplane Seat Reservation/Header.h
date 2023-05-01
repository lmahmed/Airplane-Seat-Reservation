#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
// Functions
int Menu();
void Help();

// Classes
class Seat
{
public:
	string name;
	bool reserved;
	Seat(string n = "", bool r = false) { name = n; reserved = r; }
};
class Plane
{
private:
	vector<vector<Seat>> seatChart;
public:
	void Read();
	void Display();
	void Reserve();
	void Cancel();
	void Save();
	void Statistics();
};
