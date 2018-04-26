#pragma once
/*
* File:   Clock.h
* Purpose: provide the declaration of the Clock class
* Author: pike
*
*/

#ifndef CLOCK_H
#define	CLOCK_H
#include <iostream>

class Clock
{
public:
	Clock(); // default constructor
	Clock(int hh, int mm, bool isPM); 	//constructor

										//set the time given an hour, minutes, and a boolean flag for PM
	void setTime(int hh, int mm, bool isPM);

	//increase time by one minute
	void Tick();

	//print time in hours:minutes am(or pm) format
	void printTime() const;

	//compare two Clock objects
	// return true if it is equal, otherwise return false
	bool isEqual(Clock C) const;

private:
	// Declare data members of the class
	// 1 <= hours <=12, 0 <= minutes < 60,
	// isPM is true when it is in PM, otherwise it is false when it is in AM.
	int hours, minutes;
	bool isPM;

	//make sure the data members are in the valid range
	// 1 <= hours <= 12; 0 <= minutes < 60; 
	// 11:59pm ticks to 12:00am; 11:59am ticks to 12:00pm
	// 12:59am ticks to 1:00am; 12:59pm ticks to 1:00pm
	void adjustClock();
};


#endif	/* CLOCK_H */
