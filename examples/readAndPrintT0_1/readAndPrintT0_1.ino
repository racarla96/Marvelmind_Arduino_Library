#include <Marvelmind.h>

MarvelmindHedge hedge;

unsigned long t1;
const unsigned long period = 100;
long baudrate = 115200;

void setup() {
  Serial.begin(baudrate);
  Serial2.begin(baudrate);

  hedge.begin(&Serial2, &Serial);
  t1 = millis();
}

void loop() {
  hedge.read();
  if(millis() - t1 > period){
    hedge.printPositionFromMarvelmindHedge(true);
    hedge.printStationaryBeaconsPositionsFromMarvelmindHedge(true);
    hedge.printRawDistancesFromMarvelmindHedge(true);
    hedge.printRawIMUFromMarvelmindHedge(true);
    hedge.printFusionIMUFromMarvelmindHedge(true);
//    hedge.printTelemetryFromMarvelmindHedge(true);
//    hedge.printQualityFromMarvelmindHedge(true);
    t1 = millis();
  }
}
