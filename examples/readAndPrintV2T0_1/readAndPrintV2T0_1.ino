#include <Marvelmind.h>

MarvelmindHedge hedge;
PositionValuePro positionVP;
RawDistancesPro rDistancesP;
RawIMUValue rIMUV;
FusionIMUValuePro fIMUVP;
char print_buffer [128];

const int res = 1; // Resolution to print values
float r2d = 57.2957795f; // radians to degrees
float roll, pitch, yaw;

unsigned long t1;
const unsigned long period = 100;
long baudrate = 115200;

void setup() {
  Serial.begin(baudrate);
  Serial2.begin(baudrate);

  hedge.begin(&Serial2);
  t1 = millis();
}

void loop() {
  hedge.read();
  if (millis() - t1 > period) {
    
    if (hedge.getPositionFromMarvelmindHedge(true, &positionVP)) {
      Serial.print("Position Hedge: ");
      Serial.print(" X=");
      Serial.print(positionVP.x, res);
      Serial.print(", Y=");
      Serial.print(positionVP.y, res);
      Serial.print(", Z=");
      Serial.print(positionVP.z, res);
      Serial.print(", Angle=");
      Serial.print(positionVP.angle, res);
      Serial.println();
    }

    if (hedge.getRawDistancesFromMarvelmindHedge(true, &rDistancesP)) {
      for (int i = 0; i < 4; i++)
      {
        sprintf(print_buffer, "Raw distance: %02d ==> %02d,  Distance=",
                (int)rDistancesP.address_hedge,
                (int)rDistancesP.address_beacons[i]);
        Serial.print(print_buffer);

        Serial.print(rDistancesP.distances[i], res);
        Serial.println();
      }
    }

    if (hedge.getRawIMUFromMarvelmindHedge(true, &rIMUV)) {
      sprintf(print_buffer, "Raw IMU: aX=%05d aY=%05d aZ=%05d  gX=%05d gY=%05d gZ=%05d  cX=%05d cY=%05d cZ=%05d \n",
              (int)rIMUV.acc_x, (int)rIMUV.acc_y, (int)rIMUV.acc_z,
              (int)rIMUV.gyro_x, (int)rIMUV.gyro_y, (int)rIMUV.gyro_z,
              (int)rIMUV.compass_x, (int)rIMUV.compass_y, (int)rIMUV.compass_z);
      Serial.print(print_buffer);
    }

    if (hedge.getFusionIMUFromMarvelmindHedge(true, &fIMUVP)) {
      Serial.print("IMU fusion: ");

      Serial.print(" X=");
      Serial.print(fIMUVP.x, res);
      Serial.print(", Y=");
      Serial.print(fIMUVP.y, res);
      Serial.print(", Z=");
      Serial.print(fIMUVP.z, res);

      roll = fIMUVP.roll * r2d;
      pitch = fIMUVP.pitch * r2d;
      yaw = fIMUVP.yaw * r2d;
      Serial.print(", R=");
      Serial.print(roll, res);
      Serial.print(", P=");
      Serial.print(pitch, res);
      Serial.print(", Y=");
      Serial.print(yaw, res);


      Serial.print(", Vx=");
      Serial.print(fIMUVP.vx, res);
      Serial.print(", Vy=");
      Serial.print(fIMUVP.vy, res);
      Serial.print(", Vz=");
      Serial.print(fIMUVP.vz, res);

      Serial.print(", Ax=");
      Serial.print(fIMUVP.ax, res);
      Serial.print(", Ay=");
      Serial.print(fIMUVP.ay, res);
      Serial.print(", Az=");
      Serial.print(fIMUVP.az, res);

      Serial.println();
    }

    Serial.println();
    
    t1 = millis();
  }
}
