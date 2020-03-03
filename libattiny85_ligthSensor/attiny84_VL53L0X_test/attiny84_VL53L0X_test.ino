#include "VL53L0X.h"
#include "TinyWireM.h"
#define KNOCK_BANG 1
#define led 4
//#include <TinyDebugKnockBang.h>

VL53L0X sensor;

//#ifdef KNOCK_BANG
//#define Serial Debug
//#endif

void setup() {
  
  //Serial.begin( 250000 );

  TinyWireM.begin();  

  sensor.init();
  sensor.setTimeout(500);
  pinMode(led,OUTPUT);
  
}

void loop() {

  sensor.writeReg(0x80, 0x01);   //set power mode to idle level 1
  uint8_t PMO = sensor.readReg(0x80);
  //Serial.print("ON: ");Serial.print(PMO);Serial.print(" ");Serial.println(sensor.readRangeSingleMillimeters());
  if(sensor.readRangeSingleMillimeters()>200){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
  sensor.writeReg(0x80, 0x00);   //set power mode to standby level 1
  uint8_t PMR = sensor.readReg(0x80);
  //Serial.print("OFF: ");Serial.println(PMR);
  delay(100);
 
}
