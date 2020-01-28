# API and Getting Started
Check out [Project OWL] for quickstart videos
### Quick Start
Open new sketch in Adruino IDE and include the ClusterDuck library

    #include "ClusterDuck.h"
Create ClusterDuck object

    ClusterDuck duck;
Initializes the ClusterDuck class object

##### In setup()

    duck.begin(baudRate);
Initializes the baude rate for serial printing and messaging. You can adust to your desired baude rate.
- int baudRate
-- Default is **115000**

Set device ID and captive portal form length.
    
    duck.setDeviceId(String deviceId, const int formLength);
- String deviceId
-- input the device ID used to identify your registered device on the web
-- do not leave null or empty string
- const int formLength 
-- (optional) define the number of captive portal form fields
-- Default is **10** to match our default captive portal template

Setup **DuckLink**

    duck.setupDuckLink();
    
``duck.setupMamaDuck`` can also be used here to setup a MamaDuck, however you **cannot** use both in the same sketch.

#### In loop()

Add cooresponding Duck run code. Must be of the same device type as used in ``setup()``. (e.g. if ``duck.setupMamaDuck()`` is used in ``setup()`` use ``duck.runMamaDuck()``)

    duck.runDuckLink();
    
Your sketch should look something like this:
    
    #include "ClusterDuck.h"
    ClusterDuck duck;
    
    void setup() {
    // put your setup code here, to run once:
        duck.begin();
        duck.setDeviceId("Z", 10);
        duck.setupDuckLink();
    }

    void loop() {
    // put your main code here, to run repeatedly:
        duck.runDuckLink();
    }

Now compile and upload to your device. If using a Heltec LoRa ESP32 board you should see a Duck Online message on the LED screen. You can now open your phone or laptop's wifi preferences and connect to the ``SOS DuckLink Network``!

## API
``setDeviceId(String deviceId, const int formLength)``
- Set device ID and captive portal form length. Do not leave **deviceId** *null* or as an empty string. **formLength** defaults to 10. Use in ``setup()``.

``void begin(int baudRate)``
- Initialize baude rate for serial. Use in ``setup()``.

``void setupDisplay(String deviceType)``
- Initializes LED screen on Heltec LoRa ESP32 and configures it to show status, device ID, and the device type. Use in ``setup()``.

``void setupLoRa(long BAND, int SS, int RST, int DI0, int TxPower)``
- Initializes LoRa radio. If using **Heltec LoRa ESP32** set **SS** to , **RST** to and **DIO** to . **TxPower** corresponds to the the transmit power of the radio (max value: 20). Use in ``setup()``.

``void setupPortal(const char *AP)``
- Initializes the captive portal code. ***AP** is the value that will be displayed when accessing the wifi settings of devices such as smartphones and laptops. Use in ``setup()``.

``bool runCaptivePortal()``
- Processes requests coming through the captive portal. Returns ``true`` if there is a new submission. Use this in your ``loop()`` function to run continuously. 

``void setupDuckLink()``
- Template for setting up a **DuckLink** device. Use in ``setup()``

``void runDuckLink()``
- Template for running core functionality of a **DuckLink**. Use in ``loop()``.

``void setupMamaDuck()``
- Template for setting up a **MamaDuck** device. Use in ``setup()``.

``void runMamaDuck()``
- Template for running core functionality of a **MamaDuck**. Use in ``loop()``.

``String * getPortalData()``
- Returns webserver arguments based on **formLength**.

``void sendPayloadMessage(String msg)``
- Packages **msg** into a LoRa packet and sends over LoRa. Will automatically set the current device's ID as the sender ID and create a UUID for the message.

``void sendPayload(String senderId, String messageId, String * arr, String lastPath)`` **TODO: Needs to be refactored into smaller parts**
- Similar to ``sendPayloadMessage()`` however is used to handle packets that have been recieved (used by **MamaDucks**). **senderId** is the ID of the originator of the message. **messageId** is the UUID of the message. **arr** is a pointer to the stored message payload. **lastPath** is the recorded pathway of the message and is used as a check to prevent devices from sending multiple of the same message.
- This function also handles the distinction between a data message and a **DetectorDuck** ping.

``void couple(byte byteCode, String outgoing)``
- Writes data to LoRa packet. **outgoing** is the payload data to be sent. **byteCode** is paired with the **outgoing** so it can be used to identify data on an individual level. Reference ``setDeviceId()`` for byte codes. In addition it writes the **outgoing** length to the LoRa packet. 
- Use between a ``LoRa.beginPacket()`` and ``LoRa.endPacket()`` (**note:** ``LoRa.endPacket()`` will send the LoRa packet)

``String readMessages(byte mLength)``
- Returns a String. Used after ``LoRa.read()`` to convert LoRa packet into a String.

``void repeatLoRaPacket(int packetSize)``
- Called when a packet has been recieved. Handles reading and repeating LoRa packet. Calls ``sendPayloadMessage()``.

``bool checkPath(String path)``
- Checks if the **path** contains **deviceId**. Returns bool.

``String * getPacketData(int pSize)``
- Called to iterate through received LoRa packet and return data as an array of Strings.

``void restartDuck()``
- If using the ESP32 architecture, calling this function will reboot the device.

``void reboot(void *)``
- Used to call ``restartDuck()`` when using a timer

``void imAlive(void *)``
- Used to send a '1' over LoRa on a timer to signify the device is still on and functional.

``String duckMac(boolean format)``
- Returns the MAC address of the device. Using ``true`` as an argument will return the MAC address formatted using ':'

``String uuidCreator()``
- Returns as String of 8 random characters and numbers

``String getDeviceId()``
- Returns the device ID





[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


[Project OWL]: <https://project-owl.com>
