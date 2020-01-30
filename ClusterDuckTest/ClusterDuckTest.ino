#include "ClusterDuck.h"
//#include "timer.h"

//auto timer = timer_create_default(); // create a timer with default settings

ClusterDuck duck;
byte pinger = 0xA1;
String senderId;

void setup() {
  
  // put your setup code here, to run once:
  duck.begin();
  duck.setDeviceId("1", 10);

  duck.setupLoRa();
  LoRa.receive();
  duck.setupDisplay("Repeater");

  //timer.every(300000, runSensor);
}

void loop() {
  //timer.tick();
  
  // put your main code here, to run repeatedly:
  int packetSize = LoRa.parsePacket();
  if (packetSize != 0) {
    byte sender = LoRa.peek();
    if(sender == pinger) {
      int rssi = LoRa.packetRssi();
      String * packetData = duck.getPacketData(packetSize);
      String senderId = packetData[0];
      String msgId = packetData[1];
      
      String msg = msgId + "," + senderId + "," + rssi;
      Serial.println(msg);
      duck.sendPayloadMessage(msg);
      LoRa.receive();
    } else {
      duck.repeatLoRaPacket(packetSize);
    }
  }
}

bool runSensor(void *) {

  return true;
}

//#include "ClusterDuck.h"
//#include "timer.h"
//
//auto timer = timer_create_default(); // create a timer with default settings
//
//ClusterDuck duck;
//byte pinger = 0xA1;
//byte m_byte = 0xA2;
//String senderId;
//
//void setup() {
//  
//  // put your setup code here, to run once:
//  duck.begin();
//  duck.setDeviceId("Pinger", 10);
//
//  duck.setupLoRa();
//  duck.setupDisplay("Pinger");
//
//  timer.every(5000, runSensor);
//}
//
//void loop() {
//  timer.tick();
//  
//  // put your main code here, to run repeatedly:
//  
//}
//
//bool runSensor(void *) {
//  LoRa.beginPacket();
//  duck.couple(pinger, "Pinger");
//  duck.couple(m_byte, duck.uuidCreator());
//  LoRa.endPacket();
//
//  Serial.println("Packet sent");
//  
//  return true;
//}
