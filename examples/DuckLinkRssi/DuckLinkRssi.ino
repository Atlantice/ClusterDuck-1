#include <ClusterDuck.h>
//#include "timer.h"

//auto timer = timer_create_default(); // create a timer with default settings

ClusterDuck duck;

byte senderId = 0xF5;
byte ping = 0xF1;

void setup() {
  
  // put your setup code here, to run once:
  duck.begin();
  duck.setDeviceId("C1");
  duck.setupLoRa();
  LoRa.receive();
  duck.setupDisplay("C1");

  //timer.every(300000, runSensor);
}

void loop() {
  //timer.tick();
  
  int packetSize = LoRa.parsePacket();
  if (packetSize != 0) {
    byte whoIsIt = LoRa.peek();
    if(whoIsIt == ping) {
      int rssi = LoRa.packetRssi();
      String * msg = duck.getPacketData(packetSize);
      duck.sendPayloadStandard(msg[0] + ":" + rssi);
    } 
  }
  
}

bool runSensor(void *) {

  return true;
}
