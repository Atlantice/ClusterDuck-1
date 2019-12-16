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
    /* There was a problem detecting the BMP085 ... check your connections */
    Serial.print("Ooops, no BMP085 detected ... Check your wiring or I2C ADDR!");
  } else {
    Serial.println("here");
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
  //T = bmp.readTemperature();
  Serial.println(T);
  bmp.getPressure(&P);
  //P = bmp.readPressure();
  Serial.println(P);

  Serial.println("Temp: " + String(T) + " Pres: " + String(P));
  
  vals = "Temp: " + String(T) + " Pres: " + String(P); //Store Data

  duck.sendPayloadMessage(vals);
  
  return true;
}
