#include <CapacitiveSensor.h>

int fsrPinA = 0;
int fsrPinB = 1; 
int photoPin = 2; 

int fsrPinAVal = 0; 
int fsrPinBVal = 0; 
int photoPinVal = 0; 

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);    
int threshold = 100;

void setup() {
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); 
  Serial.begin(9600);

}

void loop() {
  fsrPinAVal = analogRead(fsrPinA);
  fsrPinBVal = analogRead(fsrPinB);

  long capVal =  cs_4_2.capacitiveSensor(30);

  int photoPinVal = analogRead(photoPin); 

  Serial.println(photoPinVal); 
  
  //Serial.println(capVal);
  
  //Serial.println(fsrPinAVal);  
  //Serial.println(fsrPinBVal);  

  delay(100); 

}
