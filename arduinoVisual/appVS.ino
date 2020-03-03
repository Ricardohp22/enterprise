//Programa 1
#define buzzer 4
#define led 0
const int Trigger = 2; //Pin digital 2 para el Trigger del sensor
const int Echo = 3;    //Pin digital 3 para el Echo del sensor
int pauseTime = 0;
int sensorR12Area2 = 0;

void setup()
{
    //Serial.begin(9600);//iniciailzamos la comunicación
    pinMode(Trigger, OUTPUT);   //pin como salida
    pinMode(led, OUTPUT);       //pin como salida
    pinMode(buzzer, OUTPUT);    //pin como salida
    pinMode(Echo, INPUT);       //pin como entrada
    digitalWrite(Trigger, LOW); //Inicializamos el pin con 0
}

void loop()
{

    long t; //timepo que demora en llegar el eco
    long d; //distancia en centimetros
    /* digitalWrite(buzzer, HIGH); */

    digitalWrite(Trigger, HIGH);
    delayMicroseconds(10); //Enviamos un pulso de 10us
    digitalWrite(Trigger, LOW);

    t = pulseIn(Echo, HIGH, 6000); //obtenemos el ancho del pulso
    d = t / 59;                    //escalamos el tiempo a una distancia en cm
    if ((d < 40) && (d > 1))
    {
        pauseTime = map(d, 0, 40, 5, 500);
        digitalWrite(buzzer, HIGH);
        delay(40);
        digitalWrite(buzzer, LOW);
        delay(pauseTime);
    }
    else
    {
        d = 100;
    }
    if (d < 20)
    {
        digitalWrite(led, HIGH);
    }
    else
    {
        digitalWrite(led, LOW);
    }

    //  Serial.print("Distancia: ");
    //  Serial.print(d);      //Enviamos serialmente el valor de la distancia
    //  Serial.print("cm");
    //  Serial.println();
    //delay(100);          //Hacemos una pausa de 100ms
}