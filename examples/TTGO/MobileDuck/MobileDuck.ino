#include <SPI.h>
#include <LoRa.h>

#define SCK     5    // GPIO5  -- SX1278's SCK
#define MISO    19   // GPIO19 -- SX1278's MISO
#define MOSI    27   // GPIO27 -- SX1278's MOSI
#define SS      18   // GPIO18 -- SX1278's CS
#define RST     14   // GPIO14 -- SX1278's RESET
#define DI0     26   // GPIO26 -- SX1278's IRQ(Interrupt Request)
#define BAND    915E6

String myName = "M1";

void setup() {
  setupTBeam();
  Serial.println(myName);
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize > 0) {
    Serial.println("Ping Received");
    String rssi = String(LoRa.packetRssi(), DEC);
    String fromWho = LoRa.readString();
    if (fromWho.length() == 2) {
      String payMe = myName + ":" + fromWho + ":" + rssi;
//      Serial.println("Ping Received");
//      delay(1500);
//      Serial.println("Ping Sent");
      LoRa.beginPacket();
      LoRa.print(payMe);
      LoRa.endPacket();
      Serial.println(payMe);
//      esp_restart();
    }
  }
}

void setupTBeam(){
  Serial.begin(115200);
  while (!Serial);
  Serial.println();
  SPI.begin(SCK,MISO,MOSI,SS);
  LoRa.setPins(SS,RST,DI0);  
  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
