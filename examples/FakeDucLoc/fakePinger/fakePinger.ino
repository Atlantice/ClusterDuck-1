#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include <U8x8lib.h>

U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);

int rando = 0;
int hopDelay = 0;
unsigned long DELAY_TIME = 30000; // 30 sec
unsigned long delayStart = 0; // the time the delay started
bool delayRunning = false; // true if still waiting for delay to finish

String myName = "P1";

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
  Serial.println(myName + " Online");
  setupLoRa();
  setupDisplay();

  srand (972134234);
  //DELAY_TIME = ((rand() % 10 + 1)*1000)+1000;
  DELAY_TIME = 5000;
  //Serial.println(DELAY_TIME);
  
  u8x8.setCursor(0, 16);
  u8x8.print(myName + " Online");
  
  delayStart = millis();   // start delay
  delayRunning = true; // not finished yet
}

void loop() {
  
  if (delayRunning && ((millis() - delayStart) >= DELAY_TIME)) {
    delayStart += DELAY_TIME; // this prevents drift in the delays
    ///DELAY_TIME = ((rand() % 10 + 1)*1000)+1000;
    DELAY_TIME = 10000;
    ///Serial.println(DELAY_TIME);
    Serial.println("Ping");
    LoRa.beginPacket();
    LoRa.print(myName);
    LoRa.endPacket();
  }

//  int packetSize = LoRa.parsePacket();
//  if (packetSize > 0) {
////    int rssi = LoRa.packetRssi();
//    String fromWho = LoRa.readString();
//    int fromWhoLen = fromWho.length();
//    if (fromWhoLen > 2 && fromWho.indexOf(myName) < 1 && fromWhoLen < 20) {
//      
//      String payMe = fromWho + ":" + myName;
//      hopDelay = ((rand() % 10 + 1)*200);
//      delay(1000);
//      LoRa.beginPacket();
//      LoRa.print(payMe);
//      LoRa.endPacket();
//      LoRa.receive();
//    }
//  }
}

// Initial LoRa settings
void setupLoRa()
{
  SPI.begin(5, 19, 27, 18);
  LoRa.setPins(SS, RST, DI0);
  LoRa.setTxPower(20);
  // LoRa.setSignalBandwidth(62.5E3);
  
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
