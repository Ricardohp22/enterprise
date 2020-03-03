
#define BUTTON_A 11
#define BUTTON_B 12


void setup() {
  Serial.begin(9600); // Bluetooth RX TX
  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT);
}

void loop() {
 if(digitalRead(BUTTON_A) == HIGH){
  Serial.write('1');
  delay(200);
 }
 else if(digitalRead(BUTTON_B) == HIGH){
  Serial.write('0');
  delay(200);
 }
}
