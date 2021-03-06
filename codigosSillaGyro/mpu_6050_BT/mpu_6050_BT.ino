//GND - GND
//VCC - VCC
//SDA - Pin A4
//SCL - Pin A5
//INT - Pin 2
 
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
#include <avr/wdt.h>
#include <SoftwareSerial.h>

SoftwareSerial bt(9,10);

#define yawOfst 87
#define pitchOfst 178
#define rollOfst 159

#define timeToSend 100
unsigned long timeToSendCompare = 0;

#define estabilizaTime 12000

int yawZero = 0;
int  pitchZero = 0;
int  rollZero = 0;


 
// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68
// AD0 high = 0x69
MPU6050 mpu;
//MPU6050 mpu(0x69); // <-- use for AD0 high
 
 
#define INTERRUPT_PIN 2
#define LED_PIN 3
#define LED_PIN2 4
bool blinkState = false;
 
// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer
 
Quaternion q;           // [w, x, y, z]
VectorInt16 aa;         // [x, y, z]
VectorInt16 aaReal;     // [x, y, z]
VectorInt16 aaWorld;    // [x, y, z]
VectorFloat gravity;    // [x, y, z]
float ypr[3];           // [yaw, pitch, roll]
 
volatile bool mpuInterrupt = false;
void dmpDataReady() {
    mpuInterrupt = true;
}
 
void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        //Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
    pinMode(LED_PIN, OUTPUT);
    pinMode(LED_PIN2, OUTPUT);

    digitalWrite(LED_PIN2, HIGH);
    wdt_disable();
    Serial.begin(9600);
    bt.begin(9600);
    wdt_enable(WDTO_2S);
    // Iniciar MPU6050
    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);
 
    // Comprobar  conexion
    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));
 
    // Iniciar DMP
    Serial.println(F("Initializing DMP..."));
    
    devStatus = mpu.dmpInitialize();
 
    // Valores de calibracion
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1688);
 
    // Activar DMP
    if (devStatus == 0) {
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);
 
        // Activar interrupcion
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
 
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;
 
        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }
    
}
 
 int lastPitch = 0;
 int lastYaw = 0;
 int lastRoll = 0;
 
 int lastYaw2 = 0;
 int lastPitch2 = 0;
 int lastRoll2 = 0;
 
 int yawFin = 0;
 int pitchFin = 0;
 int rollFin = 0;
 

 //memoria dato anterior filtro 3
 int lastYaw3 = 0;
 int lastPitch3 = 0;
 int lastRoll3 = 0;
 boolean setValorInicial = 1;
 
 byte cuentaBasuraYaw = 0;
 byte cuentaBasuraPitch = 0;
 byte cuentaBasuraRoll = 0;

 boolean timeOff = 1;
 
 
void loop() {
    // Si fallo al iniciar, parar programa
    //if (!dmpReady) return;
 
    // Ejecutar mientras no hay interrupcion
//    while (!mpuInterrupt && fifoCount < packetSize) {
//        // AQUI EL RESTO DEL CODIGO DE TU PROGRRAMA
//        Serial.print("                                               ypr\t");
//       Serial.print(yawZero);
//       Serial.print("\t");
//       Serial.print(pitchZero);
//       Serial.print("\t");
//       Serial.println(rollZero);
//    }
 
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();
 
    // Obtener datos del FIFO
    fifoCount = mpu.getFIFOCount();
 
    // Controlar overflow
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        mpu.resetFIFO();
        //Serial.println(F("FIFO overflow!"));
    } 
    else if (mpuIntStatus & 0x02) {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
 
        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        // track FIFO count here in case there is > 1 packet available
        // (this lets us immediately read more without waiting for an interrupt)
        fifoCount -= packetSize;
 
   // MMostrar Yaw, Pitch, Roll
   mpu.dmpGetQuaternion(&q, fifoBuffer);
   mpu.dmpGetGravity(&gravity, &q);
   mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

   yawZero = (ypr[0] * 180/M_PI);
   pitchZero = (ypr[1] * 180/M_PI);
   rollZero = (ypr[2] * 180/M_PI);

   wdt_reset();
   //delay(50);
   

   if(yawZero < 0){
    yawZero += 360;
   }
   if(pitchZero < 0){
    pitchZero += 360;
   }
   if(rollZero < 0){
    rollZero += 360;
   }
//   Serial.print("ypr\t");
//   Serial.print(yawZero);
//   Serial.print("\t");
//   Serial.print(pitchZero);
//   Serial.print("\t");
//   Serial.print(rollZero);

   //filtro de valores anormales
   if((yawZero >= (lastYaw - 5)) && (yawZero <= (lastYaw + 5))){
    if((lastYaw2 >= (lastYaw - 5)) && (lastYaw2 <= (lastYaw + 5))){
      yawFin = yawZero - yawOfst;
     }
   }
   if((pitchZero >= (lastPitch - 5)) && (pitchZero <= (lastPitch + 5))){
    if((lastPitch2 >= (lastPitch - 5)) && (lastPitch2 <= (lastPitch + 5))){
      pitchFin = pitchZero - pitchOfst;
     }
   }
   if((rollZero >= (lastRoll - 5)) && (rollZero <= (lastRoll + 5))){
    if((lastRoll2 >= (lastRoll - 5)) && (lastRoll2 <= (lastRoll + 5))){
      rollFin = rollZero- rollOfst;
     }
   }
   

// ajuste por el offset
   if(yawFin < 0){
    yawFin += 360;
   }
   if(pitchFin < 0){
    pitchFin += 360;
   }
   if(rollFin < 0){
    rollFin += 360;
   }

   //Asignacion de sentido

   if(yawFin > 180){
    yawFin -= 360; 
   }
   if(pitchFin > 180){
    pitchFin -= 360; 
   }
   if(rollFin > 180){
    rollFin -= 360; 
   }

   //Nota: Filtro3
   if(setValorInicial){
    setValorInicial = 0;
    lastYaw3 = yawFin;
    lastPitch3 = pitchFin;
    lastRoll3 = rollFin;
    Serial.println("Valor inicial seteado--------------------------");
   }
   if((yawFin >= (lastYaw3 - 25)) && (yawFin <= (lastYaw3 + 25))){
    lastYaw3 = yawFin;
    cuentaBasuraYaw = 0;
   }else{
    
    cuentaBasuraYaw++;
    if(cuentaBasuraYaw > 20){
      lastYaw3 = yawFin;
      Serial.println("cuentaBasuraYaw OVERFLOW! Seteado a nuevo valor estable");
    }else{
      yawFin = lastYaw3;
    }
   }

   
   if((pitchFin >= (lastPitch3 - 25)) && (pitchFin <= (lastPitch3 + 25))){
    lastPitch3 = pitchFin;
    cuentaBasuraPitch = 0;
   }else{
    cuentaBasuraPitch++;
    if(cuentaBasuraPitch > 20){
      lastPitch3 = pitchFin;
      Serial.println("cuentaBasuraPitch OVERFLOW! Seteado a nuevo valor estable");
    }else{
      pitchFin = lastPitch3;
    }
   }

   
   if((rollFin >= (lastRoll3 - 25)) && (rollFin <= (lastRoll3 + 25))){
    lastRoll3 = rollFin;
    cuentaBasuraRoll = 0;
   }else{
    
    cuentaBasuraRoll++;
    if(cuentaBasuraRoll > 20){
      lastRoll3 = rollFin;
      Serial.print("cuentaBasuraRoll OVERFLOW! Seteado a nuevo valor estable");
    }else{
      rollFin = lastRoll3;
    }
   }

   if(millis() > estabilizaTime){
     Serial.print("\tfinales\t");
     Serial.print(yawFin);
     Serial.print("\t");
     Serial.print(pitchFin);
     Serial.print("\t");
     Serial.println(rollFin);

     if((millis() - timeToSendCompare) > timeToSend){
      
      timeToSendCompare =  millis();
       bt.print(pitchFin);
       bt.print('/');
       bt.print(rollFin);
       //bt.write(10);
     }
     
     digitalWrite(LED_PIN,HIGH);
     delay(5);
     digitalWrite(LED_PIN,LOW);
   }else{
    //Serial.println("Estabilizando lecturas MPU6050");
    digitalWrite(LED_PIN,HIGH);
   }
   
   lastYaw2 = lastYaw;
   lastYaw = yawZero;

   lastPitch2 = lastPitch;
   lastPitch = pitchZero;

   lastRoll2 = lastRoll;
   lastRoll = rollZero;
    
 
   
   // Mostrar aceleracion
//   mpu.dmpGetQuaternion(&q, fifoBuffer);
//   mpu.dmpGetAccel(&aa, fifoBuffer);
//   mpu.dmpGetGravity(&gravity, &q);
//   mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
//   Serial.print("areal\t");
//   Serial.print(aaReal.x);
//   Serial.print("\t");
//   Serial.print(aaReal.y);
//   Serial.print("\t");
//   Serial.println(aaReal.z);
    }
    
    //Serial.println("                                                            wdt_reset");
}
