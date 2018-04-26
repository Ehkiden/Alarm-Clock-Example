//course: CS215-004
//Project: Lab Assignment 9
//Date: 11/01/2016
//Purpose: it provides basic operations on time using objects of AlarmClock class.
//         
//Author: Jared Rigdon

#include <iostream>
#include <string>
#include <sstream>

#include "Clock.h"
#include "AlarmClock.h"

using namespace std;

//ask the user to input a time in the 12-hour format
bool read_time(string prompt, int& hh, int& mm, bool& isPM);

void pause_215(bool have_newline);

int main()
{
	int hh, mm;
	bool isPM;
	int a_hh, a_mm;
	bool a_isPM;
	while (true)
	{
		//Ask the user to type the starting time and the alarm time (both in 12-hour format)
		cout << "Please input starting time and the alarm time (Enter Q to quit)." << endl;
		if (!read_time("starting", hh, mm, isPM))
			break;
		if (!read_time("alarm", a_hh, a_mm, a_isPM))
			break;
		AlarmClock current(hh, mm, isPM, a_hh, a_mm, a_isPM);


		const int HOURS = 24;
		const int MINUTES_A_HOUR = 60;
		const int DAY = HOURS * MINUTES_A_HOUR;
		// create a loop to call "tick" function 60*24 = 1440 times
		// so that the clock runs through an entire day
		// print the clock's current time every 60 iterations of the loop
		for (int i = 0; i < DAY; i++)
		{
			if (i % 60 == 0)
				current.printTime();
			current.Tick();
		}
	}
	pause_215(false);
	return 0;
}


void pause_215(bool have_newline)
{
	if (have_newline) {
		// Ignore the newline after the user's previous input.
		cin.ignore(256, '\n');
	}

	// Prompt for the user to press ENTER, then wait for a newline.
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(256, '\n');
}

/**
Purpose: ask the user to input a time in the 12-hour format
Reads a time(in 12-hour format) from cin and store the data in arguments(call by reference)
@param prompt that displays prompt message(what kind of time) for the user
@param hh reference parameter that represents the hours
@param mm reference parameter that represents the minutes
@param isPM reference parmater that represents AM (flase) or PM (true)
@return void
*/
bool read_time(string prompt, int& hh, int& mm, bool& isPM)
{
	bool valid = false;
	string time;
	do {
		cout << "Please input the " << prompt << " time (hh:mm AM or PM) in 12-hour format ";
		getline(cin, time);

		if (time == "Q" || time == "q")
			break;
		istringstream is_time(time);

		if (!(is_time >> hh))
		{
			cout << "Invalid time." << endl;
			continue;
		}
		//get rid of :
		char c;
		is_time.get(c);

		if (!(is_time >> mm))
		{
			cout << "Invalid time." << endl;
			continue;
		}
		if (hh < 0 || mm < 0)
		{
			cout << "The time cannot be a negative number." << endl;
			continue;
		}
		string am_pm;
		is_time >> am_pm;
		if (am_pm.substr(0, 1) == "P" || am_pm.substr(0, 1) == "p")
		{
			isPM = true;
			valid = true;
		}
		else if (am_pm.substr(0, 1) == "A" || am_pm.substr(0, 1) == "a")
		{
			isPM = false;
			valid = true;
		}
		else
			cout << "Invalid time (missing AM or PM)" << endl;
	} while (!valid);
	return valid;
}