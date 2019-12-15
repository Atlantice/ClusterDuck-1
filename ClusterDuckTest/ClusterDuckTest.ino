#include "ClusterDuck.h"
ClusterDuck duck;

void setup() {
  // put your setup code here, to run once:
  duck.begin();
  duck.setDeviceId("Z", 10);
  duck.setupMamaDuck();

}

void loop() {
  // put your main code here, to run repeatedly:
  duck.runMamaDuck();
}
