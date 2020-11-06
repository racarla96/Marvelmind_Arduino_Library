# Marvelmind Arduino Library
Based on [Marvelmind C library](https://github.com/MarvelmindRobotics/marvelmind.c).
## About the library
Marvelmind Arduino Library library provides an example of building the system for receiving coordinates and another information like orientation (IMU) or battery level from Marvelmind mobile beacons via hardware serial port for Arduino.
## How it works
For testing the example, you need an Arduino with two serial ports, with a hardware serial port and serial object. But you can use the library only with hardware serial port for real purpose using. Then, you can customize the library for example for Software Serial.

The example is easy, begin for initialize the library and the you need to run read in the main thread of the arduino. If you block the arduino main thread (loop function), maybe you could lost the packets.

## Note
Any errors or grammatical errors please notify my email, thank you. racarla96@gmail.com
