#include "Adafruit_VL53L0X.h"

#define pwm 9
#define buzzer 10
#define distancia_maxima_deteccion 50
unsigned long timeIni = 0;
unsigned long timeEnd = 0;
boolean flagBuzzerOn = true;
boolean flagBuzzerOff = true;
int distancia = 200;
boolean bloqueaSonido = false;

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup()
{
  Serial.begin(9600);
  pinMode(pwm, OUTPUT);
  pinMode(buzzer, OUTPUT);
  // Iniciar sensor
  Serial.println("VL53L0X test");
  if (!lox.begin())
  {
    Serial.println(F("Error al iniciar VL53L0X"));
    while (1)
      ;
  }
  //generar tono de 440Hz durante 1000 ms
  tone(buzzer, 440);
  delay(300);
  //generar tono de 523Hz durante 500ms, y detenerlo durante 500ms.
  tone(buzzer, 523);
  delay(300);
  tone(buzzer, 400);
  delay(300);
  tone(buzzer, 523);
  delay(400);
  noTone(buzzer);
  timeIni = millis();
}
void beep(byte dis)
{
  int tiempoOFF = map(dis, 0, 60, 10, 1000);
  if ((millis() - timeIni) < 100)
  { //tiempo que dura encendido el buzzer
    if (bloqueaSonido)
    {
      noTone(buzzer);
    }
    else
    {
      tone(buzzer, 523);
    }

    if (flagBuzzerOn)
    {
      //Serial.println("           beep");
      flagBuzzerOn = false;
      timeIni = millis();
    }
    timeEnd = millis();
  }
  else
  {

    flagBuzzerOn = true;
    noTone(buzzer);
    if ((millis() - timeEnd) > tiempoOFF)
    {
      timeIni = millis();
      //Serial.println("           off");
    }
  }
}

int cont_sens[5];
byte cuenta = 0;
void loop()
{

  VL53L0X_RangingMeasurementData_t measure;

  lox.rangingTest(&measure, false); // si se pasa true como parametro, muestra por puerto serie datos de debug

  if (measure.RangeStatus != 4)
  {
    distancia = measure.RangeMilliMeter / 10;
    if (cuenta < 5)
    {
      cont_sens[cuenta];
      cuenta++;
    }else{
      
      for(byte i=0; i <= cuenta; i++){
        cont_sens[i]
      }
      cuenta = 0;//AQUI ME QUEDE HACIENDO EL FILTRO DE LECTURAS
    }
    
  }
  if (distancia > distancia_maxima_deteccion)
  {
    distancia = distancia_maxima_deteccion;
    bloqueaSonido = true;
    analogWrite(pwm, 0);
    Serial.println("pwmValue igual a 0");
  }
  else
  {
    bloqueaSonido = false;
    if (distancia < 5)
    {
      distancia = 5;
    }
    int pwmValue = map(distancia, 5, distancia_maxima_deteccion, 255, 50);
    Serial.println(pwmValue);
    analogWrite(pwm, pwmValue);
  }

  beep(distancia);
  delay(10);
}
