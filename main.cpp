#include "mbed.h"
 
AnalogIn mic(p15); //microphone input
AnalogOut speaker(p18); //speaker output 
 
DigitalOut led1(LED1); // following leds are used to visualy show amplitude of sound 
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);
DigitalOut red(p7);   //this powers a red LED that lights up when recording 
 
 
DigitalIn pbRec(p5); //pushbutton inputs to either begin recording or playback
DigitalIn pbPlay(p6);
 
void record(float* sampleArr) {
    //record sound for 1 second
    for(int i=0; i<8000; i++) {
        sampleArr[i] = mic.read(); //put samples in array
        wait(0.000125f); //sample rate of 8000 Hz
    }  
}
 
void play(float* sampleArr) {
    //playback recorded sound 
    wait(0.1); 
    for(int i=0; i<8000; i++) { 
        speaker = sampleArr[i];
        wait(0.000125f);
    }  
}
 
void volume(){
    //the following lights up the onboard LEDs depending on the amplitude of sound 
    led1 = (mic > 0.5f) ? 1 : 0;
    led2 = (mic > 0.6f) ? 1 : 0;
    led3 = (mic > 0.7f) ? 1 : 0;
    led4 = (mic > 0.8f) ? 1 : 0;
}
 
int main() { 
    float sampleArr[8000]; //used to store sound 
    pbRec.mode(PullDown); //use internal resistors for pushbuttons
    pbPlay.mode(PullDown);
    red = 0;
    while(1){
        volume();   
        
        if (pbRec == 1) {
            wait(0.2); 
            red = 1;
            record(sampleArr); 
            red = 0;
        }
        
        if (pbPlay == 1) {
            play(sampleArr);
        }
    }
}
