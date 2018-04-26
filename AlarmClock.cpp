#include "AlarmClock.h"

AlarmClock::AlarmClock()
{
	a_hours = 0;
	a_minutes = 0;
	this->a_isPM = true;
}

AlarmClock::AlarmClock(int hh, int mm, bool isPM, int a_hh, int a_mm, bool a_isPM)
{
	a_hours = a_hh;
	a_minutes = a_mm;
	this->a_isPM = a_isPM;
	Clock::Clock(hh, mm, isPM);
}

void AlarmClock::Tick()
{
	Clock::Tick();
}

void AlarmClock::printTime() const
{
	Clock::printTime();
}
