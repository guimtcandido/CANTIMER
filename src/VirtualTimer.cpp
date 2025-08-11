/*
 * VirtualTimer.c
 *
 *  Created on: Jan 21, 2024
 *      Author: Candido
 */
#include "VirtualTimer.h"

#if FRAMEWORK == ARDUINO
#define currentTime(void) millis()
#elif FRAMEWORK == STM32
#define currentTime(void) HAL_GetTick()
#endif

virtualTimer ::virtualTimer(unsigned long time_Set, char type)
{

	switch (type)
	{
	case 's': // segundos
		timeSet = time_Set * 1000;
		break;
	case 'm': // min
		timeSet = time_Set * 60000;
		break;

	default: // ms
		timeSet = time_Set;
		break;
	}
}

uint8_t virtualTimer ::Q()
{
	if ((get_elapsedTime_raw() >= timeSet) && timerState)
	{
		return 1;
	}

	return 0;
}

void virtualTimer ::start()
{
	if (!timerState)
	{
		timerState = 1;
		timeNow = currentTime();
	}
}

void virtualTimer ::reset()
{
	timerState = 0;
}

unsigned long virtualTimer ::get_elapsedTime_raw()
{
	return currentTime() - timeNow;
}

unsigned long virtualTimer ::get_elapsedTime_seconds()
{
	return get_elapsedTime_raw() / 1000;
}

unsigned long virtualTimer ::get_elapsedTime_minutes()
{
	return get_elapsedTime_raw() / 60000;
}

unsigned long virtualTimer ::get_elapsedTime_hours()
{
	return get_elapsedTime_raw() / 3600000;
}

unsigned long virtualTimer ::get_startTime()
{
	return timeNow;
}

uint8_t virtualTimer ::get_timerState()
{
	return timerState;
}