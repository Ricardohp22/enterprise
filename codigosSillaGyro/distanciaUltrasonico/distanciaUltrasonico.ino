const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
int pauseTime =0;
#define buzzer 4
#define led 0

void setup() {
  //Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(led, OUTPUT); //pin como salida
  pinMode(buzzer, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
}
byte validador = 0;
void loop()
{

  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(20);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH, 6000); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm

  if((d < 40) && (d > 1)){
    if(validador > 19){
      validador = 19;
    }
    validador ++;
    
    
    //delay(1500);
  }else{
    if(validador < 1){
      validador = 1;
    }
    validador --;
  }
  if(validador==20){
    digitalWrite(led, HIGH);
  }else if(validador == 0){
    digitalWrite(led, LOW);
  }
  delay(10);
}
