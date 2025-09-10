/*
 * VirtualTimer.h
 *
 *  Created on: Jan 21, 2024
 *      Author: Candido
 */

#ifndef INC_VIRTUALTIMER_H
#define INC_VIRTUALTIMER_H

#define ARDUINO 0
#define STM32 1





/*SET WORKING FRAMEWORK*/
#define FRAMEWORK ARDUINO 
/***********************/		

















#if FRAMEWORK == ARDUINO
#include "Arduino.h"
#elif FRAMEWORK == STM32
#include "stm32f1xx_hal.h"
#endif


class virtualTimer{
private:

	unsigned long timeSet = 0;
	unsigned long timeNow = 0;
	uint8_t timerState = 0;

public:
	virtualTimer(unsigned long time_Set, char type);
	uint8_t Q();
	void start();
	void reset();
	unsigned long get_startTime();
	unsigned long get_elapsedTime_raw();
	unsigned long get_elapsedTime_seconds();
	unsigned long get_elapsedTime_minutes();
	unsigned long get_elapsedTime_hours();
	uint8_t get_timerState();
	void set_Timer(unsigned long time_Set, char type);
};

#endif /* INC_VIRTUALTIMER_HPP_ */
