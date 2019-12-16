#include "ClusterDuck.h"
#include <Adafruit_BMP085_U.h>
#include "timer.h"

Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
auto timer = timer_create_default(); // create a timer with default settings

ClusterDuck duck;

void setup() {

  // put your setup code here, to run once:
  duck.begin();
  duck.setDeviceId("Test", 10);
  duck.setupMamaDuck();

  if (!bmp.begin())
  {
    Serial.print("Ooops, no BMP085 detected ... Check your wiring or I2C ADDR!");
  } else {
    Serial.println("BMP180 ON");
  }

  timer.every(300000, runSensor);
}

void loop() {
  timer.tick();
  
  // put your main code here, to run repeatedly:
  duck.runMamaDuck();
}

bool runSensor(void *) {
  float T,P;
  String vals;
  
  bmp.getTemperature(&T);
  Serial.println(T);
  
  bmp.getPressure(&P);
  Serial.println(P);
  
  vals = "Temp: " + String(T) + " Pres: " + String(P);
  Serial.println(vals);
  
  duck.sendPayloadMessage(vals);
  
  return true;
}
