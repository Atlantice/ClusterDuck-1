#include <ClusterDuck.h>
//#include "timer.h"

auto timer = timer_create_default(); // create a timer with default settings

ClusterDuck duck;

byte ping = 0xF4;

void setup() {
  
  // put your setup code here, to run once:
  duck.begin();
  duck.setDeviceId("C0");
  duck.setupLoRa();
  LoRa.receive();
  duck.setupDisplay("C0");

  timer.every(120000, runSensor);
}

void loop() {
  
  int packetSize = LoRa.parsePacket();
  if (packetSize != 0) {
    byte whoIsIt = LoRa.peek();
    if(whoIsIt == ping) {
      int rssi = LoRa.packetRssi();
      String * msg = duck.getPacketData(packetSize);
      duck.sendPayloadStandard(msg[0] + ":" + rssi);
      LoRa.receive();
      Serial.println(msg[0] + ":" + rssi);
    } 
  }
  
}

bool runSensor(void *) {
  Serial.println("Restarting Duck...");
  ESP.restart();
  return true;
}
