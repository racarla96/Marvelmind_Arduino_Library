# Marvelmind Arduino Library
Based on [https://github.com/MarvelmindRobotics/marvelmind.c](Marvelmind C library).
## About the library
Marvelmind Arduino Library library provides an example of building the system for receiving coordinates from Marvelmind mobile beacons via hardware serial port for Arduino.
## How it works
For testing the example, you need an Arduino with two serial ports, with a hardware serial port and serial object. But you can use the library only with hardware serial port for real purpose using. Then, you can customize the library for example for Software Serial.
The example is easy, begin for initialize the library and the you need to run read in the main thread of the arduino. If you block the arduino, maybe you could lost the packets.
## Useful Functions
- bool getPositionFromMarvelmindHedgeByAddress(PositionValue *position, uint8_t address);
- bool getPositionFromMarvelmindHedge(PositionValue *position);
- bool getStationaryBeaconsPositionsFromMarvelmindHedge(StationaryBeaconsPositions *positions);
- bool getRawDistancesFromMarvelmindHedge(RawDistances *rawDistances);
- bool getRawIMUFromMarvelmindHedge(RawIMUValue *rawIMU);
- bool getFusionIMUFromMarvelmindHedge(FusionIMUValue *fusionIMU);
- bool getTelemetryFromMarvelmindHedge(TelemetryData *telemetry);
- bool getQualityFromMarvelmindHedge(QualityData *quality);
- void printPositionFromMarvelmindHedge(bool onlyNew);
- void printStationaryBeaconsPositionsFromMarvelmindHedge(bool onlyNew);
- void printRawDistancesFromMarvelmindHedge(bool onlyNew);
- void printRawIMUFromMarvelmindHedge(bool onlyNew);
- void printFusionIMUFromMarvelmindHedge(bool onlyNew);
- void printTelemetryFromMarvelmindHedge(bool onlyNew);
- void printQualityFromMarvelmindHedge(bool onlyNew);

## Note
Any errors or grammatical errors please notify my email, thank you.
