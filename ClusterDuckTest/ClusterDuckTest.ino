#include "ClusterDuck.h"
#include "timer.h"

auto timer = timer_create_default(); // create a timer with default settings
int smokeA0 = 39;

ClusterDuck duck;

void setup() {

  // put your setup code here, to run once:
  duck.begin();
  duck.setDeviceId("Test", 10);
  duck.setupMamaDuck();

  pinMode(smokeA0, INPUT);
  timer.every(5000, runSensor);
}

void loop() {
  timer.tick();
  
  // put your main code here, to run repeatedly:
  duck.runMamaDuck();
}

bool runSensor(void *) {

  ////// Set up MQ-X Gas Sensor
  int analogSensor = analogRead(smokeA0);
  Serial.println("Reading:");
  Serial.println(analogSensor);
  Serial.println(" ");
  
  // duck.sendPayloadMessage(String(analogSensor));
  
  return true;
}
