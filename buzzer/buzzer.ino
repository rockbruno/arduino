#include <NewPing.h>
#include <NewTone.h>

#define TRIGGER_PIN  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters).

#define ALARM 9

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200);
  delay(5000);
  pinMode(ALARM,OUTPUT);
}

void loop() {
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  unsigned int distance = uS / US_ROUNDTRIP_CM;
  Serial.println(distance);
  if(distance < 100){
    NewTone(ALARM,440);
  }
}
