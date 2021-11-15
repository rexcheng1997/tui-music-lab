#include <CapacitiveSensor.h>
#include "json.h"

#define FSR1_PIN 0
#define FSR2_PIN 1
#define PHOTOCELL_PIN 2
#define FSR3_PIN 3
#define FSR4_PIN 4

// PIN 2 is the sensor pin, PIN 4 is Vin
CapacitiveSensor cs = CapacitiveSensor(4, 2);

void setup() {
  Serial.begin(9600);
  cs.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop() {
  // Read values from sensors
  uint16_t fsr3Val = analogRead(FSR3_PIN);
  uint16_t fsr4Val = analogRead(FSR4_PIN);
  uint16_t pcVal = analogRead(PHOTOCELL_PIN);
  uint16_t csVal = cs.capacitiveSensor(30);

  // Construct a message to send over Serial
  JSON message;
  message.add("tapRight", fsr3Val);
  message.add("tapLeft", fsr4Val);
  message.add("pc", pcVal);
  message.add("cap", csVal);
  Serial.println(message.to_json());

  delay(1000);
}
