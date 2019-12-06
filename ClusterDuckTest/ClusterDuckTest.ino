#define PAPA //TODO: try to get away from using this
#include "ClusterDuck.h"

ClusterDuck duck("Device ID");

void setup() {
  // put your setup code here, to run once:
  duck.begin();
  duck.setupPapaDuck("quickstart", "PAPA", "", "HEINEKEN", "duckduckowl");

}

void loop() {
  // put your main code here, to run repeatedly:
  duck.runPapaDuck();
}
