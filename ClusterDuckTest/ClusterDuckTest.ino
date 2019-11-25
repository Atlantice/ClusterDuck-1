#include "ClusterDuck.h"

ClusterDuck duck("Device ID");

void setup() {
  // put your setup code here, to run once:
  duck.begin();
  duck.setupMamaDuck();

}

void loop() {
  // put your main code here, to run repeatedly:
  duck.runMamaDuck();
}
