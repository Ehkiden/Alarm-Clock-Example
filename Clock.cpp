#include "Clock.h"
#include <iostream>

using namespace std;

Clock::Clock()
{
	hours = 0;
	minutes = 0;
	this->isPM = true;
}

Clock::Clock(int hh, int mm, bool isPM)
{
	hours = hh;
	minutes = mm;
	this->isPM = isPM;
	adjustClock();
}

void Clock::setTime(int hh, int mm, bool isPM)
{
	hours = hh;
	minutes = mm;
	this->isPM = isPM;
	adjustClock();
}


void Clock::printTime() const
{
	if (hours < 10) {
		cout << "0" << hours << " : ";
	}
	else {
		cout << hours << " : ";
	}
	if (minutes < 10) {
		cout << "0" << minutes;
	}
	else {
		cout << minutes;
	}
	if (isPM == true) {
		cout << " PM" << endl;
	}
	else {
		cout << " AM" << endl;
	}
}

bool Clock::isEqual(Clock C) const
{

	//this will check if the current clock matches the alarm clock
	if (C.hours == hours && C.minutes == minutes && C.isPM == isPM) {
		return true;
	}
	else {
		return false;
	}

}

void Clock::Tick()
{
	//this will increase the time by one minute, but should it call the alarm and print func as well?
	minutes++;
	adjustClock();
}

void Clock::adjustClock()
{
	if (minutes == 60) {
		minutes = 0;
		hours++;
		if (hours > 12) {
			hours = 1;
			if (isPM == false) {
				isPM = true;
			}
			else if (isPM == true) {
				isPM = false;
			}

		}
	}
}
