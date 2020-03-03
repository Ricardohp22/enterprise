long unsigned antes = millis();
long unsigned ahora;

void setup()
{
  Serial.begin(9600);
}
 
void loop()
{
  ahora = millis();

  if(ahora - antes > 5000)
  {
    antes = millis();
    Serial.print("1");
  }
}
