#include <SoftwareSerial.h>
SoftwareSerial bt(9,10);
void setup() {
  Serial.begin(9600);
  bt.begin(57600);
}

void loop() {
  if(Serial.available()){
    bt.write(Serial.read());
  }
   if(bt.available()){
    Serial.write(bt.read());
  }

}
