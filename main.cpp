//ECE 4180 Lab 2
//Keary Mobley

#include "mbed.h"

Serial pc(USBTX, USBRX);
AnalogIn ain(p15);
AnalogOut DACout(p18);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int main()
{
    while (1)
    {
        pc.printf("%.4f", ain);
        led1 = (ain > 0.5f) ? 1 : 0;
        led2 = (ain > 0.6f) ? 1 : 0;
        led3 = (ain > 0.7f) ? 1 : 0;
        led4 = (ain > 0.8f) ? 1 : 0;
        //wait(.002);
    }
}