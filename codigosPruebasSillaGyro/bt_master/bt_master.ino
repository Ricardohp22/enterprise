#define LED 13

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char cad;
 
  if( Serial.available() > 0)
  {
    delay(5);
    cad = Serial.read();
    Serial.flush();

    if(cad == '1')
    {
      cad = ' ';
      digitalWrite(LED,HIGH);
      delay(500);
      digitalWrite(LED,LOW);
    }
  }
}
