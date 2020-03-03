#include <SoftwareSerial.h>

SoftwareSerial bt(10, 11);

void setup() {
  // put your setup code here, to run once:
  bt.begin(9600);
  Serial.begin(9600);
  Serial.println("inicia programa");

}

void loop() {
  // put your main code here, to run repeatedly:
  if(bt.available()){
    Serial.write(bt.read());
  }
  if(Serial.available()){
    bt.write(Serial.read());
  }

//  for(byte i=0; i<128; i++){
//    Serial.write(i);
//    Serial.write(10);
//    delay(100);
//  }
//  
//  delay(10000);

}
