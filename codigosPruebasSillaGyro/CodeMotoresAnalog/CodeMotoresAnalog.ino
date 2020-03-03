#include <Wire.h>
#include<SoftwareSerial.h>
#define pinAct 4
#define frenos 7
#define MotIzq 5
#define MotDer 6

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
//variables para el control de los motoresEND



void setup() 
{
  
  Wire.onReceive(getDatos);     //Funcion para recibir datos por I2C
  Wire.begin(2);
  //ST.begin(9600);
  Serial.begin(9600);
  pinMode(frenos,OUTPUT);
  pinMode(pinAct, OUTPUT);
  pinMode(MotIzq, OUTPUT);
  pinMode(MotDer, OUTPUT);
  //Pone los motores en velocidad 0 
  //ST.write(64);
  //ST.write(192);
  Serial.println("Inicia Motores");
}
//Indica mediante un pin digital si hay actividad por parte del usuario
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
  }else
  {
    digitalWrite(pinAct, LOW);
  } 
}
// Recibe los datos del joystick por el puerto I2C
void getDatos(int bytes) 
    {
      String datosEnt="";
      while(Wire.available()) 
      {
        char c = Wire.read();
        datosEnt = datosEnt + c;
        Serial.print(c);
      }
      Serial.println("");
      //Serial.println("");
      xx_ = datosEnt.substring(datosEnt.indexOf("x")+1, datosEnt.indexOf("y")).toInt()-510;
      yy_ = datosEnt.substring(datosEnt.indexOf("y")+1, datosEnt.indexOf("p")).toInt()-510;
      pp_ = datosEnt.substring(datosEnt.indexOf("p")+1,datosEnt.length() ).toInt();

      Serial.print(xx_);
      Serial.print("  ");
      Serial.print(yy_);
      Serial.print("  ");
      Serial.println(pp_);
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
   
    if(velocidadIzq > 255)
    {
      velocidadIzq=255;
    }
    if(velocidadDer > 255)
    {
      velocidadDer=255;
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
            analogWrite(MotIzq,valAntIzq);
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
            analogWrite(MotIzq,valAntIzq);
          }
          else
          {
            controlFrenado();
            analogWrite(MotIzq,valAntIzq);
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
            analogWrite(MotIzq,valAntIzq);
          }
          else if(valAntIzq > velST)
          {
            valAntIzq -= desacelerador;
            if(valAntIzq < velST)
            {
              valAntIzq = velST;
            }
            controlFrenado();
            analogWrite(MotIzq,valAntIzq);
          }
          else
          {
            controlFrenado();
            analogWrite(MotIzq,valAntIzq);
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
            analogWrite(MotDer,valAntDer);
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
            analogWrite(MotDer,valAntDer);
          }
          else
          {
            controlFrenado();
            analogWrite(MotDer,valAntDer);
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
            analogWrite(MotDer,valAntDer);
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
            analogWrite(MotDer,valAntDer);
          }
          else
          {
            controlFrenado();
            analogWrite(MotDer,valAntDer);
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

     if(sqrt(((yy)*(yy)) + ((xx)*(xx))) <= puntoMuerto )
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
        pwm_izquierda=((sqrt((xx*xx)+(yy*yy)))*(pp/300));
        pwm_derecha=(((grados - 22.5) * (sqrt((xx*xx)+(yy*yy)))*(pp/300)) / 67.5);//listo
        motorIzqDireccion = 1;
        motorDerDireccion = 1;
      break;
      case 2:
        
         vizq = sqrt((xx*xx)+(yy*yy))*(pp/300);
//        pwm_izquierda=map(yy,510,0, vizq, vizq/2 );////reduccion a la mitad
//        pwm_derecha=(((grados - 22.5)* (sqrt((xx*xx)+(yy*yy)))*(pp/300)) / 22.5)/2;//reduccion a mitad
        pwm_izquierda=map(yy,510,0, vizq, vizq );////reduccion a la mitad
        pwm_derecha=(((grados - 22.5)* (sqrt((xx*xx)+(yy*yy)))*(pp/300)) / 22.5);//reduccion a mitad
        motorIzqDireccion = 1;
        motorDerDireccion = 0;
      break;
      case 3:
        vizq = (-((360-grados - 22.5)* (sqrt((xx*xx)+(yy*yy)))*(pp/300)) / 22.5);
//        pwm_izquierda=map(yy,0,-510, vizq/2, vizq );//reduccion a la mitad
//        pwm_derecha=(-(sqrt((xx*xx)+(yy*yy)))*(pp/300))/2;//reduccion a la mitad
        pwm_izquierda=map(yy,0,-510, vizq, vizq );//reduccion a la mitad
        pwm_derecha=(-(sqrt((xx*xx)+(yy*yy)))*(pp/300));//reduccion a la mitad

        motorIzqDireccion = 1;
        motorDerDireccion = 0;
      break;
      case 4:
        pwm_izquierda=(-((360-grados - 22.5)* (sqrt((xx*xx)+(yy*yy)))*(pp/300)) / 67.5);
        pwm_derecha=(-(sqrt((xx*xx)+(yy*yy)))*(pp/300));

        motorIzqDireccion = 0;
        motorDerDireccion = 0;
        break;
        case 5:
        pwm_izquierda=(-(sqrt((xx*xx)+(yy*yy)))*(pp/300));
        pwm_derecha=(-((grados-180 - 22.5)* (sqrt((xx*xx)+(yy*yy)))*(pp/300)) / 67.5);

        motorIzqDireccion = 0;
        motorDerDireccion = 0;
      break;
      case 6:
       vder = (-((grados-180- 22.5)* (sqrt((xx*xx)+(yy*yy)))*(pp/300)) / 22.5);
//        pwm_izquierda=(-(sqrt((xx*xx)+(yy*yy)))*(pp/300))/2;//reduccion a la mitad
//        pwm_derecha=map(yy, 0, 510, vder/2, vder );//reduccion a la mitad
        pwm_izquierda=(-(sqrt((xx*xx)+(yy*yy)))*(pp/300));//reduccion a la mitad
        pwm_derecha=map(yy, 0, 510, vder, vder );//reduccion a la mitad
        motorIzqDireccion = 0;
        motorDerDireccion = 1;
      break;
      case 7:
       vder = ((sqrt((xx*xx)+(yy*yy)))*(pp/300));
//        pwm_izquierda=(((180-grados - 22.5)* (sqrt((xx*xx)+(yy*yy)))*(pp/300)) / 22.5)/2;//reduccion a la mitad
//        pwm_derecha=map(yy, 510, 0, vder, vder/2 );//reduccion a la mitad
        pwm_izquierda=(((180-grados - 22.5)* (sqrt((xx*xx)+(yy*yy)))*(pp/300)) / 22.5);//reduccion a la mitad
        pwm_derecha=map(yy, 510, 0, vder, vder );//reduccion a la mitad
        motorIzqDireccion = 0;
        motorDerDireccion = 1;
      break;
      case 8:
        pwm_izquierda=(((180-grados - 22.5)* (sqrt((xx*xx)+(yy*yy)))*(pp/300)) / 67.5);
        pwm_derecha=((sqrt((xx*xx)+(yy*yy)))*(pp/300));

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
     
     ControlGradual(motorIzqDireccion, pwm_izquierda, motorDerDireccion, pwm_derecha);

  }

void loop() 
{
  controlMotores();
  reportaActividad();
}
