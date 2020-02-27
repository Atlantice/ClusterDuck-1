#include <SPI.h>
#include <LoRa.h>

#define SCK     5    // GPIO5  -- SX1278's SCK
#define MISO    19   // GPIO19 -- SX1278's MISnO
#define MOSI    27   // GPIO27 -- SX1278's MOSI
#define SS      18   // GPIO18 -- SX1278's CS
#define RST     14   // GPIO14 -- SX1278's RESET
#define DI0     26   // GPIO26 -- SX1278's IRQ(Interrupt Request)
#define BAND  915E6

int rando = 0;
int hopDelay = 0;
unsigned long DELAY_TIME = 30000; // 30 sec
unsigned long delayStart = 0; // the time the delay started
bool delayRunning = false; // true if still waiting for delay to finish

String myName = "S3";

#define SS      18
#define RST     14
#define DI0     26
#define BAND    915E6

void setup() {
  setupTBeam();
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

  int packetSize = LoRa.parsePacket();
  if (packetSize > 0) {
    String fromWho = LoRa.readString();
    int fromWhoLen = fromWho.length();
    if (fromWhoLen > 2 && fromWho.indexOf(myName) < 1 && fromWhoLen < 20) {
      String payMe = fromWho + ":" + myName;
      hopDelay = ((rand() % 10 + 1)*200);
      delay(500);
      LoRa.beginPacket();
      LoRa.print(payMe);
      LoRa.endPacket();
      LoRa.receive();
    }
  }
}

void setupTBeam() {
  pinMode(16,OUTPUT);
  pinMode(2,OUTPUT);

  Serial.begin(115200);
  while (!Serial);
  Serial.println();
  Serial.println("LoRa Sender Test");
  
  SPI.begin(SCK,MISO,MOSI,SS);
  LoRa.setPins(SS,RST,DI0);
  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println(myName);
}
