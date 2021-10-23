
# Simple-Recorder

## Overview

This README is designed to give users an understanding of how to use the SparkFun MEMS microphone with the mbed platform. Using a $10 chip from Sparkfun allows one to build a recording device by interfacing with the mbed platform. Since the chip is provided on an IC breakout board it can be directly wired to the mbed without the need for an additional circuit to control the chip output. This allows for quick development time and saves cost, especially useful for prototyping. An example code is given to show users how to implement simple recording and playback functionality. A YouTube video is also provided as a live demo for the user.

[Click here](https://www.sparkfun.com/products/9868) to order the MEMS microphone from Sparkfun. 

[Click here](http://www.analog.com/media/en/technical-documentation/obsolete-data-sheets/ADMP401.pdf) for the datasheet.

## Using a Microphone for Analog Input

In order to input an accurate Analog Output into the mbed, Vcc should be connected to 3.3V and the microphone AUD output will float at one half Vcc when there is no sound. The amplifier on the chip has a gain of 67 and produces a peak-to-peak output of 200mV when the microphone is spoken into at arms length at normal conversation levels. 

## Wiring

Table 1 describes how to wire the microphone to the mbed. In additon Table 2 displays the connections between the speaker, the record button, and playback button are connected to the mbed. See the linked pages in the demo section for more information on how to hook up these components.

|Microphone  | MBED |
|--|--|
| AUD |  P15 (AnalogIn) |
| GND |  GND |
|Vcc	|VOUT (3.3V)|

Table 1: A table showing how to connect the microphone to the mbed. 

|Component	|MBED|
|--|--|
|Speaker	|P18 (AnalogOut)|
|Record Button|	P5|
|Play Button|	P6|
|Red LED	|P7|

Table 2: A table showing proper connections between the mbed, speaker, record button, play button and LED. 

## Schematics

Figure 1 is a schematic [1] of the MEMS chip that produces microphone functionality. Since the microphone is connected to other parts on a breakout board, wiring the microphone to the mbed is simple. It is possible to increase the sensitivity of the microphone by adding more resistors in series with the connection to the mbed. 

![image](https://user-images.githubusercontent.com/8340687/138538238-e6b68e0a-6edd-40f5-a562-02fcda3d4bd4.png)

Figure 1: A schematic of the MEMS chip. [1] 

## Demo

The following demo records the input from the microphone for one second when the recording push button is pressed. The audio on the speaker is played back when the playback push button is pressed. A red LED lights up when recording, and the on-board mbed LEDs light up depending on the volume of the sound detected. [Here is a video of the demo.](https://youtu.be/o50xb9mtHl4)

The following components are required for the demo:

[Two Parallax Pushbutton [2]](https://developer.mbed.org/users/4180_1/notebook/pushbuttons/?compage=1#c6483)

[One Speaker [3]](https://developer.mbed.org/users/4180_1/notebook/using-a-speaker-for-audio-output/)

[One Red LED (see example four) [4]](https://developer.mbed.org/users/yoonghm/notebook/digital-output/)

[One SparkFun MEMS Microphone [5]](https://www.sparkfun.com/products/9868)

## SetUp
