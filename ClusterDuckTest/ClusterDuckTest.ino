#include "ClusterDuck.h"
#include <SimpleDHT.h>
#include "timer.h"

ClusterDuck duck;
auto timer2 = timer_create_default(); // create a timer with default settings


// set up DHT temp/humidity sensor
int pinDHT11 = 13;
SimpleDHT11 dht11(pinDHT11);


void setup() {
  // put your setup code here, to run once:
  duck.begin();
  duck.setDeviceId("Z", 10);
  duck.setupMamaDuck();

  timer.every(300000, runSensor);
}
void loop() {
  // put your main code here, to run repeatedly:
  duck.runMamaDuck();
  
}

bool runSensor(void *) {
  /////// DHT11 Temperature/humidity sensor
  byte temperature = 0;
  byte ftemperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  ftemperature = ((float)temperature*1.8) + 32;
  Serial.println((float)ftemperature); Serial.print(" ftemp ");
  Serial.print((float)temperature); Serial.print(" *C, "); 
  Serial.print((float)humidity); Serial.println(" H");

  String values = temperature + "C " + humidity + " H";

  duck.sendPayloadMessage(values);

  return true;
}
