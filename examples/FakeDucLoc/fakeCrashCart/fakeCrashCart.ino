#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include <U8x8lib.h>

U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);
unsigned long DELAY_TIME = 10000; // 1.5 sec
unsigned long delayStart = 0; // the time the delay started
bool delayRunning = false; // true if still waiting for delay to finish

#define SS      18
#define RST     14
#define DI0     26
#define BAND    915E6

void setupDisplay()
{
  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("CrashCart C1");
  setupLoRa();
  setupDisplay();
  
  u8x8.drawString(0, 1, "CrashCart C1");
    
  delayStart = millis();   // start delay
  delayRunning = true; // not finished yet
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize > 0) {
    Serial.println("Ping Received");
    int rssi = LoRa.packetRssi();
    String fromWho = LoRa.readString();
    if (fromWho.length() == 2) {
      String payMe = "C1:" + fromWho + ":" + rssi;
//      Serial.println("Ping Received");
//      delay(1500);
//      Serial.println("Ping Sent");
      LoRa.beginPacket();
      LoRa.print(payMe);
      LoRa.endPacket();
      Serial.println(payMe);
      esp_restart();
    }
  }
}

// Initial LoRa settings
void setupLoRa()
{
  SPI.begin(5, 19, 27, 18);
  LoRa.setPins(SS, RST, DI0);
  LoRa.setTxPower(20);
  //LoRa.setSignalBandwidth(62.5E3);
  //Initialize LoRa
  if (!LoRa.begin(BAND))
  {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  else
  {
    Serial.println("LoRa On");
  }
  //  LoRa.setSyncWord(0xF3);         // ranges from 0-0xFF, default 0x34
  LoRa.enableCrc();             // Activate crc
}
