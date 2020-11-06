#include <Marvelmind.h>

MarvelmindHedge hedge;

unsigned long t1;
const unsigned long period = 1000;
long baudrate = 115200;

void setup() {
  hedge.begin(&Serial1, baudrate, &Serial, baudrate);
  t1 = millis();
}

void loop() {
  hedge.read();
  if(millis() - t1 > period){
//    hedge.printPositionFromMarvelmindHedge(true);
//    hedge.printStationaryBeaconsPositionsFromMarvelmindHedge(true);
//    hedge.printRawDistancesFromMarvelmindHedge(true);
//    hedge.printRawIMUFromMarvelmindHedge(true);
    hedge.printFusionIMUFromMarvelmindHedge(true);
//    hedge.printTelemetryFromMarvelmindHedge(true);
//    hedge.printQualityFromMarvelmindHedge(true);
    t1 = millis();
  }
}
