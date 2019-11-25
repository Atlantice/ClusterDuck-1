#ifndef CD
#define CD

#if (ARDUINO >=100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <SPI.h>
#include <LoRa.h>
#include <WiFi.h>
#include <U8x8lib.h>

#include <DNSServer.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "index.h"

typedef struct
{
  String senderId;
  String messageId;
  String payload;
  String path;
} Packet;

class ClusterDuck {
  public:
    //Constructor
    ClusterDuck(String deviceId = "", const int formLength = 10);

    //Exposed Methods
    void begin(int baudRate = 115200);
    void setupLoRa(long BAND = 915E6, int SS = 18, int RST = 14, int DI0 = 26, int TxPower = 20);
    void setupDisplay();
    void setupPortal(const char *AP = " 🆘 DUCK EMERGENCY PORTAL");
    bool runCaptivePortal();

    void setupDuckLink();
    void setupMamaDuck();
    void runDuckLink();
    void runMamaDuck();
    
    String * getPortalData();
    String * getPacketData(int pSize);

    void repeatLoRaPacket(int packetSize);

    String duckID();

    int _rssi = 0;
    float _snr;
    long _freqErr;
    int _availableBytes;

    String getDeviceId();

  protected:
    Packet _lastPacket;
    
  private:
    String _deviceId = "";

    int _packetSize = 0;
    bool _packetAvailable = false;

    static void packetAvailable(int pSize);

    DNSServer dnsServer;
    const byte DNS_PORT = 53;
    const char *DNS  = "duck";
    const char *AP;
    String portal = MAIN_page;

    String id = "";
    String iAm = "Civ";
    String runTime;

    void restartDuck();
    void couple(byte byteCode, String outgoing);
    void sendPayload(String senderId, String messageId, String * arr, String path = "");
    String readMessages(byte mLength);
    bool reboot(void *);
    String uuidCreator();
    char * readPath(byte mLength);
    bool checkPath(String path);

    String * formArray;
    int fLength;

    byte byteCodes[16] = {0xA1,0xA2,0xA3,0xA4,0xA5,0xB1,0xB2,0xB3,0xB4,0xC1,0xC2,0xD1,0xD2,0xD3,0xE4,0xF4};

    // QuackPack
    byte senderId_B   = 0xF5;
    byte messageId_B  = 0xF6;
    byte payload_B    = 0xF7;
    byte iamhere_B    = 0xF8;
    byte path_B       = 0xF3;

};

#endif
