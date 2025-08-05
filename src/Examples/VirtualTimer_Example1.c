/*
 * VirtualTimer.c
 *
 *  Created on: Aug 05, 2025
 *      Author: Candido
 */

virtualTimer vTimer1(100, '0'); // timer 100 ms
virtualTimer vTimer2(10, 's');  // timer 10s
virtualTimer vTimer3(1, 'm');   // timer 1m

void main()
{
    vTimer1.start();
    vTimer2.start();
    vTimer3.start();

    while (1)
    {
        if (vTimer1.Q())
        {
            vTimer1.reset();
        }

        if (randomInput)
        {
            vTimer1.start();
        }
    }
}