//GND - GND
//VCC - VCC
//SDA - Pin A4
//SCL - Pin A5
//INT - Pin 2
//Aqui voy a incluir el titulo del codigo solo para probar git
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif
#include <avr/wdt.h>

/* #define yawOfst 60
#define pitchOfst 179
#define rollOfst 175 */
int yawOfst = 0;
int pitchOfst = -8;
int rollOfst = 0;

#define timeToSend 100
unsigned long timeToSendCompare = 0;

#define estabilizaTime 12000

int yawZero = 0;
int pitchZero = 0;
int rollZero = 0;

// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68
// AD0 high = 0x69
MPU6050 mpu;
//MPU6050 mpu(0x69); // <-- use for AD0 high

#define INTERRUPT_PIN 2
#define LED_PIN 4
#define buzzer 3
#define offset 6
bool blinkState = false;

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

Quaternion q;        // [w, x, y, z]
VectorInt16 aa;      // [x, y, z]
VectorInt16 aaReal;  // [x, y, z]
VectorInt16 aaWorld; // [x, y, z]
VectorFloat gravity; // [x, y, z]
float ypr[3];        // [yaw, pitch, roll]

volatile bool mpuInterrupt = false;
void dmpDataReady()
{
    mpuInterrupt = true;
}

void setup()
{
// join I2C bus (I2Cdev library doesn't do this automatically)
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    //Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
#endif
    pinMode(LED_PIN, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(offset, INPUT_PULLUP);

    //digitalWrite(LED_PIN2, HIGH);
    wdt_disable();
    Serial.begin(9600);
    wdt_enable(WDTO_2S);
    alertOn();
    // Iniciar MPU6050
    //Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);

    // Comprobar  conexion
    //Serial.println(F("Testing device connections..."));
    //Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    // Iniciar DMP
    //Serial.println(F("Initializing DMP..."));

    devStatus = mpu.dmpInitialize();

    // Valores de calibracion
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1688);

    // Activar DMP
    if (devStatus == 0)
    {
        //Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // Activar interrupcion
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        //Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    }
    else
    {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        //Serial.print(F("DMP Initialization failed (code "));
        //Serial.print(devStatus);
        //Serial.println(F(")"));
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

boolean readyFlag = 1;
boolean ready = 0;
#define maxTimeToSleep 15000
unsigned long lastTimeActive = 0;
boolean isAwake = true;
byte gestoWakeup = 0;
void alertOn()
{
    tone(buzzer, 523);
    delay(80);
    noTone(buzzer);
    delay(20);
    tone(buzzer, 523);
    delay(80);
    wdt_reset();
    noTone(buzzer);
}
void alertBeep()
{
    tone(buzzer, 523);
    delay(80);
    noTone(buzzer);
}
void alertSleep()
{
    tone(buzzer, 523);
    delay(120);
    tone(buzzer, 400);
    delay(350);
    noTone(buzzer);
}
void alertWakeup()
{
    tone(buzzer, 400);
    delay(350);
    tone(buzzer, 523);
    delay(120);
    noTone(buzzer);
}
void alertReady()
{
    tone(buzzer, 440);
    delay(300);
    tone(buzzer, 523);
    delay(300);
    wdt_reset();
    tone(buzzer, 400);
    delay(300);
    tone(buzzer, 523);
    delay(400);
    noTone(buzzer);
    wdt_reset();
}
void loop()
{
    // Si fallo al iniciar, parar programa
    //if (!dmpReady) return;

    // Ejecutar mientras no hay interrupcion
    /* while (!mpuInterrupt && fifoCount < packetSize)
    {
        // AQUI EL RESTO DEL CODIGO DE TU PROGRRAMA
        
    } */

    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();

    // Obtener datos del FIFO
    fifoCount = mpu.getFIFOCount();

    // Controlar overflow
    if ((mpuIntStatus & 0x10) || fifoCount == 1024)
    {
        mpu.resetFIFO();
        //Serial.println(F("FIFO overflow!"));
    }
    else if (mpuIntStatus & 0x02)
    {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize)
            fifoCount = mpu.getFIFOCount();

        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);

        // track FIFO count here in case there is > 1 packet available
        // (this lets us immediately read more without waiting for an interrupt)
        fifoCount -= packetSize;

        // MMostrar Yaw, Pitch, Roll
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

        yawZero = (ypr[0] * 180 / M_PI);
        pitchZero = (ypr[1] * 180 / M_PI);
        rollZero = (ypr[2] * 180 / M_PI);

        wdt_reset();
        //delay(50);

        if (yawZero < 0)
        {
            yawZero += 360;
        }
        if (pitchZero < 0)
        {
            pitchZero += 360;
        }
        if (rollZero < 0)
        {
            rollZero += 360;
        }

        //filtro de valores anormales
        if ((yawZero >= (lastYaw - 5)) && (yawZero <= (lastYaw + 5)))
        {
            if ((lastYaw2 >= (lastYaw - 5)) && (lastYaw2 <= (lastYaw + 5)))
            {
                yawFin = yawZero - yawOfst;
            }
        }
        if ((pitchZero >= (lastPitch - 5)) && (pitchZero <= (lastPitch + 5)))
        {
            if ((lastPitch2 >= (lastPitch - 5)) && (lastPitch2 <= (lastPitch + 5)))
            {
                pitchFin = pitchZero - 180 - pitchOfst;
            }
        }
        if ((rollZero >= (lastRoll - 5)) && (rollZero <= (lastRoll + 5)))
        {
            if ((lastRoll2 >= (lastRoll - 5)) && (lastRoll2 <= (lastRoll + 5)))
            {
                rollFin = rollZero - 180 - rollOfst;
            }
        }
        //boton de offset
        if (!digitalRead(offset))
        {
            //btn ofset
            rollOfst += rollFin;
            pitchOfst += pitchFin;
            alertOn();
            delay(250);
        }

        // ajuste por el offset
        /* if (yawFin < -180)
        {
            yawFin += 360;
        } */
        if (pitchFin < -180)
        {
            pitchFin += 360;
        }
        if (rollFin < -180)
        {
            rollFin += 360;
        }

        //Asignacion de sentido

        /* if (yawFin > 180)
        {
            yawFin -= 360;
        }
        if (pitchFin > 180)
        {
            pitchFin -= 360;
        }
        if (rollFin > 180)
        {
            rollFin -= 360;
        } */

        if (millis() > estabilizaTime)
        {

            ready = 1;
            if (readyFlag)
            {
                readyFlag = 0;
                alertReady();
                lastTimeActive = millis();
            }
            //     Serial.print("\tfinales\t");
            //     Serial.print(yawFin);
            //     Serial.print("\t");
            //     Serial.print(pitchFin);
            //     Serial.print("\t");
            //     Serial.println(rollFin);

            if ((millis() - timeToSendCompare) > timeToSend)
            {

                timeToSendCompare = millis();
                //descomentar para produccion
                /* Serial.print(rollFin);
                Serial.print("/");
                Serial.print(pitchFin); */

                //Monitoreo de tiempo inacctivo
                //magnitud del Vector
                int vectorMagnitude = sqrt((rollFin * rollFin) + (pitchFin * pitchFin));
                if (vectorMagnitude > 10)
                {
                    lastTimeActive = millis();
                }
                if ((millis() - lastTimeActive) > maxTimeToSleep)
                {
                    if (isAwake)
                    {
                        alertSleep();
                    }
                    isAwake = false;
                }
                else
                {
                    
                    if (isAwake)
                    {
                        
                        Serial.print(rollFin);
                        Serial.print("/");
                        Serial.print(pitchFin);
                    }else{
                        if(gestoWakeup == 0){
                            if(rollFin > 20){
                                gestoWakeup++;
                                alertBeep();
                            }
                        }else if(gestoWakeup == 1){
                            if(rollFin < -20){
                                gestoWakeup++;
                                alertBeep();
                            }else if((pitchFin > 10) || (pitchFin < -10)){
                                gestoWakeup = 0;
                            }
                        }else if(gestoWakeup == 2){
                            if(vectorMagnitude < 12){
                                gestoWakeup++;
                            }
                        }else{
                            gestoWakeup = 0;
                            alertWakeup();
                            isAwake = true;
                        }
                    }
                }

                delay(10);
            }

            digitalWrite(LED_PIN, HIGH);
            delay(5);
            digitalWrite(LED_PIN, LOW);
        }
        else
        {
            //Serial.println("Estabilizando lecturas MPU6050");
            digitalWrite(LED_PIN, HIGH);
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
