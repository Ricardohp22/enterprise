
#include <Wire.h>
#include <SoftwareSerial.h>
#include <avr/wdt.h>
#include <EEPROM.h>
#define xoffset -10
#define yoffset 0
//Memoria EEPROM
//Dreccion    variable
//0           estado/modo
//1           conexion bluetooth

SoftwareSerial bt(9, 10);

//#define xxPin A0 //ejex joystick
//#define yyPin A1 //ejey joystick
#define ppPin A2//potenciometro
#define pinAct 4
#define frenos 7
#define MotIzq 5
#define MotDer 6

//#define MotIzqA 8
//#define MotIzqB 9
//#define MotDerA 2
//#define MotDerB 3

#define ymax 112
#define ymin -112
#define xmax 152
#define xmin -152

#define rangeJoystick 255

#define intervalLostConnection 1000
unsigned long timeLastConnection = 0;
boolean btConnected = false;
String datoBT = "";

//variables para el control de los motores
double pwm_izquierda;
double pwm_derecha;

int valAntIzq = 127;    
int valAntDer = 127;
int velST=0;
unsigned long brakeTime;

int xx_ = 0;
int yy_ = 0;
int pp_ = 0;
int pp_cambio = 0;

int vel = 0;
int seccion;
byte puntoMuerto=40;

boolean motorIzqDireccion;
boolean motorDerDireccion;
boolean actBrake = 0;

void reportaActividad()
{
  if(actBrake == 1) 
  {
    digitalWrite(pinAct, HIGH);
  }else if((pp_ > (pp_cambio+1)) || (pp_ < (pp_cambio-1))) 
  {
    pp_cambio = pp_;
    digitalWrite(pinAct, HIGH);
    delay(200);
    Serial.println("entra delay");
  }else
  {
    digitalWrite(pinAct, LOW);
  } 
}
    //Funcion para habilitar o desabilitar frenos electricos
    //NOTA: Esta funcion se debe colocar antes de enviar el comando de velocidad al Moto-Driver
    //NOTA 2: Los comandos de velocidad que se manden deben contener a las variables "valAntIzq" y "valAntDer"
    void controlFrenado()
    {
      if ((valAntIzq != 127) || (valAntDer != 127))// 127 representan aceleracion 0 en los motores 
      {
        digitalWrite(frenos,HIGH);
        brakeTime = millis();
        actBrake = 1;
      }
      else
      {
        if ((millis() - brakeTime) >= (map(pp_,0,1024,200,3500)))//Pone frenos electricos despues de un tiempo proporcional a la velocidad que oscila entre 200 y 2500 milisegundos
        {
          digitalWrite(frenos,LOW);
          actBrake = 0;
        }
      }
    }
//Funcion para generar un control de aceleracion gradual
   void ControlGradual(boolean direccionIzq, byte velocidadIzq, boolean direccionDer, byte velocidadDer  )
   {
    byte inc = 1;
    byte diferi;
    byte diferd;
   
    if(velocidadIzq > rangeJoystick)
    {
      velocidadIzq=rangeJoystick;
    }
    if(velocidadDer > rangeJoystick)
    {
      velocidadDer=rangeJoystick;
    }
    int acelerador = 1;     // velocidad para acelerar
    int desacelerador = 1;  // velocidad para desacelerar


    //******************INICIA SECCION DE 4 BLOQUES PARA CONSEGUIR UN CONTROL DE VELOCIDAD ASISTIDO******************

    //==========================BLOQUE 1 MOTOR IZQUIERDA==============================
       
       
        if(direccionIzq==0)
        {
          velST = map(velocidadIzq,0,255,127,0);   //Desacelera from reversa 1-64
//          diferi = abs(velST - valAntIzq);        //Diferencia entre la velocidad asistida y la no asistida
//          
//          if(diferi > 64)
//          {
//            diferi = 64;
//          }
          
          if(valAntIzq < velST)//desacelera
          {
            valAntIzq +=desacelerador;
            if(valAntIzq > velST)
            {
              valAntIzq = velST;
            }
            controlFrenado();
            //analogWrite(MotIzq,valAntIzq);
          }
          else if(valAntIzq > velST) //acelera-reversa
          {
            
            if(valAntIzq > 127)
            {
              valAntIzq -=(desacelerador + 2);              
            }else
            {
              valAntIzq -=acelerador;
            }

            if(valAntIzq < velST)
            {
              valAntIzq = velST;
            }
            
            controlFrenado();
            //analogWrite(MotIzq,valAntIzq);
          }
          else
          {
            controlFrenado();
            //analogWrite(MotIzq,valAntIzq);
          }          
        }
        //==========================BLOQUE 2 MOTOR IZQUIERDA==============================
        else
        {
          velST = map(velocidadIzq,0,255,127,255); //acelera adelante from 64-127
//          diferi = abs(velST - valAntIzq);
//          if(diferi > 64)
//          {
//            diferi = 64;
//          }
          
          if(valAntIzq < velST) // acelera adelante
          {
            if(valAntIzq < 127)
            {
              valAntIzq += (desacelerador + 2);
            }else
            {
              valAntIzq += acelerador;
            }
            if(valAntIzq > velST)
            {
              valAntIzq = velST;
            }
            controlFrenado();
            //analogWrite(MotIzq,valAntIzq);
          }
          else if(valAntIzq > velST)
          {
            valAntIzq -= desacelerador;
            if(valAntIzq < velST)
            {
              valAntIzq = velST;
            }
            controlFrenado();
            //analogWrite(MotIzq,valAntIzq);
          }
          else
          {
            controlFrenado();
            //analogWrite(MotIzq,valAntIzq);
          }
          
        }
 //==========================BLOQUE 3 MOTOR DERECHA==============================
       
       
        if(direccionDer==0)
        {
          velST = map(velocidadDer,0,255,127,0);//desacelera from reversa 127-192
//          diferd = abs(velST - valAntDer);  
//          
//          if(diferd > 64)
//          {
//            diferd = 64;
//          }
          
          if(valAntDer < velST)//desacelera
          {
            valAntDer +=desacelerador;
            if(valAntDer > velST)
            {
              valAntDer = velST;
            }
            controlFrenado();
            //analogWrite(MotDer,valAntDer);
          }
          else if(valAntDer > velST) //acelera-reversa
          {
            
            if(valAntDer > 127)
            {
              valAntDer -=(desacelerador + 2);              
            }else
            {
              valAntDer -=acelerador;
            }

            if(valAntDer < velST)
            {
              valAntDer = velST;
            }
            
            controlFrenado();
            //analogWrite(MotDer,valAntDer);
          }
          else
          {
            controlFrenado();
            //analogWrite(MotDer,valAntDer);
          }          
        }
        //==========================BLOQUE 4 MOTOR DERECHA==============================
        else
        {
          velST = map(velocidadDer,0,255,127,255); //acelera adelante from 192-255
//          diferd = abs(velST - valAntDer);
//          if(diferd > 64)
//          {
//            diferd = 64;
//          }
          
          if(valAntDer < velST) // acelera adelante
          {
            if(valAntDer < 127)
            {
              valAntDer += (desacelerador + 2);
            }else
            {
              valAntDer += acelerador;
            }
            if(valAntDer > velST)
            {
              valAntDer = velST;
            }
            controlFrenado();
            //analogWrite(MotDer,valAntDer);
            //Serial.print
          }
          else if(valAntDer > velST)
          {
            valAntDer -= desacelerador;
            if(valAntDer < velST)
            {
              valAntDer = velST;
            }
            controlFrenado();
            //analogWrite(MotDer,valAntDer);
          }
          else
          {
            controlFrenado();
            //analogWrite(MotDer,valAntDer);
          }
          
        }
//     Serial.print("izq: ");
//     Serial.print(valAntIzq);
//     Serial.print("   Der:");
//     Serial.println(valAntDer);
        
   }   
   //******************TERMINA SECCION DE 4 BLOQUES PARA CONSEGUIR UN CONTROL DE VELOCIDAD ASISTIDO******************
//Funcion general para relacionar valores del joystick con velocidad de las ruedas
  void controlMotores()
  {     
    float xx = xx_;
    float yy = yy_;
    float pp = pp_;
    float pm = sqrt(((yy)*(yy)) + ((xx)*(xx)));

    

     if(pm <= puntoMuerto )
     {
       xx=0;
       yy=0;
       
     }         
     pp=(pp/6 );

      
     double grados=(atan2(yy,xx)*(180/3.1416));
     if (grados<0)
     {
        grados=(360+grados); 
     }
     //---------Division en 8 secciones
     if((grados>=0)&&(grados<22.5))
     {
       seccion=2;
     }
     if((grados>=22.5)&&(grados<90))
     {
       seccion=1;
     }
     if((grados>=90)&&(grados<157.5))
     {
       seccion=8;
     }
     if((grados>=157.5)&&(grados<180))
     {
       seccion=7;
     }
     if((grados>=180)&&(grados<202.5))
     {
       seccion=6;
     }
     if((grados>=202.5)&&(grados<270))
     {
       seccion=5;
     }
     if((grados>=270)&&(grados<337.5))
     {
       seccion=4;
     }
     if((grados>=337.5)&&(grados<360))
     {
       seccion=3;
     }
     
     //Variables locales para operaciones internas
     int vizq;
     int vder;
     switch(seccion)
     {
      case 1:
        pwm_izquierda=((sqrt((xx*xx)+(yy*yy))));
        pwm_derecha=(((grados - 22.5) * (sqrt((xx*xx)+(yy*yy)))) / 67.5);//listo
        motorIzqDireccion = 1;
        motorDerDireccion = 1;
      break;
      case 2:
        
         vizq = sqrt((xx*xx)+(yy*yy));
//        pwm_izquierda=map(yy,510,0, vizq, vizq/2 );////reduccion a la mitad
//        pwm_derecha=(((grados - 22.5)* (sqrt((xx*xx)+(yy*yy)))) / 22.5)/2;//reduccion a mitad
        pwm_izquierda=map(yy,510,0, vizq, vizq );////reduccion a la mitad
        pwm_derecha=(((grados - 22.5)* (sqrt((xx*xx)+(yy*yy)))) / 22.5);//reduccion a mitad
        motorIzqDireccion = 1;
        motorDerDireccion = 0;
      break;
      case 3:
        vizq = (-((360-grados - 22.5)* (sqrt((xx*xx)+(yy*yy)))) / 22.5);
//        pwm_izquierda=map(yy,0,-510, vizq/2, vizq );//reduccion a la mitad
//        pwm_derecha=(-(sqrt((xx*xx)+(yy*yy))))/2;//reduccion a la mitad
        pwm_izquierda=map(yy,0,-510, vizq, vizq );//reduccion a la mitad
        pwm_derecha=(-(sqrt((xx*xx)+(yy*yy))));//reduccion a la mitad

        motorIzqDireccion = 1;
        motorDerDireccion = 0;
      break;
      case 4:
        pwm_izquierda=(-((360-grados - 22.5)* (sqrt((xx*xx)+(yy*yy)))) / 67.5);
        pwm_derecha=(-(sqrt((xx*xx)+(yy*yy))));

        motorIzqDireccion = 0;
        motorDerDireccion = 0;
        break;
      case 5:
        pwm_izquierda=(-(sqrt((xx*xx)+(yy*yy))));
        pwm_derecha=(-((grados-180 - 22.5)* (sqrt((xx*xx)+(yy*yy)))) / 67.5);

        motorIzqDireccion = 0;
        motorDerDireccion = 0;
      break;
      case 6:
       vder = (-((grados-180- 22.5)* (sqrt((xx*xx)+(yy*yy)))) / 22.5);
//        pwm_izquierda=(-(sqrt((xx*xx)+(yy*yy))))/2;//reduccion a la mitad
//        pwm_derecha=map(yy, 0, 510, vder/2, vder );//reduccion a la mitad
        pwm_izquierda=(-(sqrt((xx*xx)+(yy*yy))));//reduccion a la mitad
        pwm_derecha=map(yy, 0, 510, vder, vder );//reduccion a la mitad
        motorIzqDireccion = 0;
        motorDerDireccion = 1;
      break;
      case 7:
       vder = ((sqrt((xx*xx)+(yy*yy))));
//        pwm_izquierda=(((180-grados - 22.5)* (sqrt((xx*xx)+(yy*yy)))) / 22.5)/2;//reduccion a la mitad
//        pwm_derecha=map(yy, 510, 0, vder, vder/2 );//reduccion a la mitad
        pwm_izquierda=(((180-grados - 22.5)* (sqrt((xx*xx)+(yy*yy)))) / 22.5);//reduccion a la mitad
        pwm_derecha=map(yy, 510, 0, vder, vder );//reduccion a la mitad
        motorIzqDireccion = 0;
        motorDerDireccion = 1;
      break;
      case 8:
        pwm_izquierda=(((180-grados - 22.5)* (sqrt((xx*xx)+(yy*yy)))) / 67.5);
        pwm_derecha=((sqrt((xx*xx)+(yy*yy))));

        motorIzqDireccion = 1;
        motorDerDireccion = 1;
      break;
     }
     if((xx==0)&&(yy==0))
     { 

        pwm_izquierda=0;//listo
        pwm_derecha=0;
     }
     
     pwm_izquierda = abs(pwm_izquierda);
     pwm_derecha = abs(pwm_derecha);

     if(pwm_izquierda > rangeJoystick){
      pwm_izquierda = rangeJoystick;
     }
     if(pwm_derecha > rangeJoystick){
      pwm_derecha = rangeJoystick;
     }

//     Serial.print("pwm_izquierda: ");
//  Serial.print(pwm_izquierda);
//  
//  Serial.print("   pwm_derecha: ");
//  Serial.println(pwm_derecha);
     
     ControlGradual(motorIzqDireccion, pwm_izquierda, motorDerDireccion, pwm_derecha);

  }
void setup() 
{
  wdt_disable();
  Serial.begin(9600);
  bt.begin(9600);
  bt.setTimeout(50);
  
  Serial.println("Inicia");
  //pinMode(xxPin,INPUT);
  //pinMode(yyPin,INPUT);
  pinMode(ppPin,INPUT);
  pinMode(frenos,OUTPUT);
  pinMode(pinAct, OUTPUT);
  pinMode(MotIzq, OUTPUT);
  pinMode(MotDer, OUTPUT);
  
//  pinMode(MotIzqA, OUTPUT);
//  pinMode(MotIzqB, OUTPUT);
//  pinMode(MotDerA, OUTPUT);
//  pinMode(MotDerB, OUTPUT);

  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, HIGH);
  
    
  wdt_enable(WDTO_2S);
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
   return ((((x - in_min) * (out_max - out_min)) / (in_max - in_min) )+ out_min);
}
int vectorX[5] = {510,510,510,510,510};
int vectorY[5] = {510,510,510,510,510};
byte cont=0;
void leerJoystick(boolean bluetooth)
{  
  if(bluetooth)
  {
    xx_ = (datoBT.substring(0,datoBT.indexOf("/")).toInt())*2;
    yy_ = (datoBT.substring(datoBT.indexOf("/")+1,datoBT.length()).toInt())*2;

    pp_= 1000;

    yy_=yy_ - yoffset;// offset
    xx_=xx_ - xoffset;// offset
    

    if(yy_ > ymax){
      yy_ = ymax;
    }else if(yy_ < ymin){
      yy_ = ymin;
    }
    if(xx_ > xmax){
      xx_ = xmax;
    }else if(xx_ < xmin){
      xx_ = xmin;
    }
    yy_ = map(yy_, ymin, ymax, -rangeJoystick, rangeJoystick);
    xx_ = map(xx_, xmin, xmax, -rangeJoystick, rangeJoystick);
    Serial.print(xx_);
    Serial.print("  ");
    Serial.println(yy_);
    
 
  }else{
//  yy_= (analogRead(yyPin));
//  xx_= (analogRead(xxPin));
//  pp_= 1000; //analogRead(ppPin);
//  
//  vectorY[cont] = yy_;
//  vectorX[cont] = xx_;
//  cont++;
//  cont >= 5 ? cont=0: cont = cont;
//  int sumax=0;
//  int sumay=0;
//  for(byte i=0; i<5; i++)
//  {
//   sumax = sumax + vectorX[i];
//   sumay = sumay + vectorY[i];
//  }
//  xx_ = sumax/5;
//  yy_ = sumay/5;
//  
//  Serial.print("xx: ");
//  Serial.print(valAntIzq);
//  
//  Serial.print("   yy: ");
//  Serial.print(valAntDer);
//
//  Serial.print("   xx: ");
//  Serial.print(xx_);
//
//  Serial.print("   yy: ");
//  Serial.print(yy_);
//  
//  Serial.print("   pp: ");
//  Serial.println(pp_);
    yy_ = 0;
    xx_ = 0;
    pp_= 1000;
    
 
  }
  
}
int nuevoPwmI =0;
int nuevoPwmD =0; 
void loop() 
{
//  if(bt.available()){
//    Serial.println("BT disponible");
//    //leerJoystick(1);
//  }else{
//    //leerJoystick(0);
//  }

  if(bt.available()){
    timeLastConnection = millis();
    btConnected = true;
    datoBT = bt.readString();
    //Serial.println(datoBT);
  }
  if((millis()-timeLastConnection) > intervalLostConnection){
    btConnected = false;
  }
  if(btConnected){
    leerJoystick(1);
  }else{
    leerJoystick(0);
  }

 
//  if(yy_ >530){
//    digitalWrite(MotIzqA,HIGH);
//    digitalWrite(MotIzqB,LOW);
//    digitalWrite(MotDerA,HIGH);
//    digitalWrite(MotDerB,LOW);
//    nuevoPwmI = map(valAntIzq,127,255,150,255);
//  }else if(yy_ < 480){
//    digitalWrite(MotIzqA,LOW);
//    digitalWrite(MotIzqB,HIGH);
//    digitalWrite(MotDerA,LOW);
//    digitalWrite(MotDerB,HIGH);
//    nuevoPwmI = map(valAntIzq,127,0,150,255);
//    
//    }else if(xx_ >530){
//    digitalWrite(MotDerA,LOW);
//    digitalWrite(MotDerB,HIGH);
//    digitalWrite(MotIzqA,HIGH);
//    digitalWrite(MotIzqB,LOW);
//    nuevoPwmD = map(valAntDer,127,255,150,255);
//  }else if(xx_ < 480){
//    digitalWrite(MotDerA,HIGH);
//    digitalWrite(MotDerB,LOW);
//    digitalWrite(MotIzqA,LOW);
//    digitalWrite(MotIzqB,HIGH);
//    nuevoPwmD = map(valAntDer,127,0,150,255);
//    
//    }else{
//    digitalWrite(MotDerA,LOW);
//    digitalWrite(MotDerB,LOW);
//    digitalWrite(MotIzqA,LOW);
//    digitalWrite(MotIzqB,LOW);
//  }
//  analogWrite(MotIzq,nuevoPwmI);
//  analogWrite(MotDer,nuevoPwmD);
//
//  Serial.print("nuevoPwmI: ");
//  Serial.print(nuevoPwmI);
//  
//  Serial.print("   nuevoPwmD: ");
//  Serial.println(nuevoPwmD);

nuevoPwmI = valAntIzq;
nuevoPwmD = valAntDer;

//  if(valAntIzq >=127){
//    digitalWrite(MotIzqA,HIGH);
//    digitalWrite(MotIzqB,LOW);
//    nuevoPwmI = map(valAntIzq,127,255,0,255);
//  }else if(valAntIzq < 127){
//    digitalWrite(MotIzqA,LOW);
//    digitalWrite(MotIzqB,HIGH);
//    nuevoPwmI = map(valAntIzq,127,0,0,255);
//    
//    }else{
//    digitalWrite(MotIzqA,LOW);
//    digitalWrite(MotIzqB,LOW);
//  }
//    if(valAntDer >= 127){
//    digitalWrite(MotDerA,LOW);
//    digitalWrite(MotDerB,HIGH);
//    nuevoPwmD = map(valAntDer,127,255,0,255);
//  }else if(valAntDer < 127){
//    digitalWrite(MotDerA,HIGH);
//    digitalWrite(MotDerB,LOW);
//    nuevoPwmD = map(valAntDer,127,0,0,255);
//    
//    }else{
//    digitalWrite(MotDerA,LOW);
//    digitalWrite(MotDerB,LOW);
//  }
  analogWrite(MotIzq,nuevoPwmI);
  analogWrite(MotDer,nuevoPwmD);
  
//  Serial.print("valAntIzq: ");
//  Serial.print(valAntIzq);
//  
//  Serial.print("   valAntDer: ");
//  Serial.print(valAntDer);
//
//  Serial.print("   nuevoPwmI: ");
//  Serial.print(nuevoPwmI);
//  
//  Serial.print("   nuevoPwmD: ");
//  Serial.println(nuevoPwmD);

//  Serial.print("xx: ");
//  Serial.print(nuevoPwmI);
//  
//  Serial.print("   yy: ");
//  Serial.print(nuevoPwmD);
//
//   Serial.print("  xx: ");
//  Serial.print(valAntIzq);
//  
//  Serial.print("   yy: ");
//  Serial.println(valAntDer);
  
  
  controlMotores();
//  reportaActividad();
  //delay(20);
  wdt_reset();
}
