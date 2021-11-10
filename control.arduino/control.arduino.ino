#include <CapacitiveSensor.h>
#include "json.h"

#define FSR1_PIN 0
#define FSR2_PIN 1
#define PHOTOCELL_PIN 2

// PIN 2 is the sensor pin, PIN 4 is Vin
CapacitiveSensor cs = CapacitiveSensor(4, 2);

void setup() {
  Serial.begin(9600);
  cs.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop() {
  // Read values from board
  uint16_t fsr1Val = analogRead(FSR1_PIN);
  uint16_t fsr2Val = analogRead(FSR2_PIN);
  uint16_t pcVal = analogRead(PHOTOCELL_PIN);
  uint16_t csVal = cs.capacitiveSensor(30);

  // Construct a message to send over Serial
  JSON message;
  message.add("fsr1", fsr1Val);
  message.add("fsr2", fsr2Val);
  message.add("pc", pcVal);
  message.add("cap", csVal);
  Serial.println(message.to_json());

  delay(100);
}
