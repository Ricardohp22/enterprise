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

void loop()
{

  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH, 6000); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  if((d < 40) && (d > 1)){
//    pauseTime = map(d, 0,40, 5, 500);
//    digitalWrite(buzzer, HIGH);
//    delay(40);
//    digitalWrite(buzzer, LOW);
//    delay(pauseTime);
  }else{
    d = 100;
  }
  if(d < 80){
    digitalWrite(led, HIGH);
    delay(1500);
  }else{
    digitalWrite(led, LOW);
  }
}
