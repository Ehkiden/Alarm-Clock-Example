#pragma once
#include "Clock.h"

#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H

class AlarmClock : public Clock
{
public:
	AlarmClock();
	AlarmClock(int hh, int mm, bool isPM, int a_hh, int a_mm, bool a_isPM);

	void Tick();

	void printTime() const;

private:
	int a_hours;
	int a_minutes;
	bool a_isPM;

};



#endif