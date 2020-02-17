#include <ClusterDuck.h>
#include "timer.h"

auto timer = timer_create_default();  //create a timer with default settings

ClusterDuck duck;

byte senderId = 0xF5;
byte ping = 0xF1;

void setup() {
  
   //put your setup code here, to run once:
  duck.begin();
  duck.setDeviceId("P3");
  duck.setupMamaDuck();

  timer.every(3000, runSensor);
}

void loop() {
  timer.tick();
  duck.runMamaDuck();
  
}

bool runSensor(void *) {
  LoRa.beginPacket();
  duck.couple(ping, duck.getDeviceId());
  LoRa.endPacket();
  
  return true;
}
