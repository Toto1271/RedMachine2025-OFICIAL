// Declaración de Librerias
#include <Servo.h>

#include <NewPing.h>
#include "Wire.h"
#include <MPU6050_light.h>

#include <Wire.h>		// incluye libreria bus I2C
#include <Pixy2.h>


Pixy2 pixy;


//ultrasonido izquierdo
#define TRIGGER_sensor_1  30
#define ECO_sensor_1  31

//ultrasonido central
#define TRIGGER_sensor_2  52
#define ECO_sensor_2  53

//ultrasonido derecho
#define TRIGGER_sensor_3 12
#define ECO_sensor_3  11



// maxima distancia que puede detectar el ultrasonido
#define MAX_DISTANCE 10000000000000

//Declaracion de los sensores ultrasonidos (libreria NewPing.h)
NewPing sensor_1 (TRIGGER_sensor_1, ECO_sensor_1, MAX_DISTANCE);//di
NewPing sensor_2 (TRIGGER_sensor_2, ECO_sensor_2, MAX_DISTANCE);//d
NewPing sensor_3 (TRIGGER_sensor_3, ECO_sensor_3, MAX_DISTANCE); //dd

Servo pro;
int distanciagirovueltacompleta= 20;

int cono1= 0;
int cono2=0;

int vuelta = 0;

int cono11= 0;
int cono12=0;

int cono21= 0;
int cono22=0;

int cono31= 0;
int cono32=0;

int cono41= 0;
int cono42=0;

float gyro=0;
float error=0;
float kp = 1;
int angf = 0;
int cercarec = 10;
int lejosrec =15;
int potenciarectificado = 7;
int i;
int rojo1;
int verde1;
int preocupado = 0;
int total=0;
int rojo=0;
int verde=0;
int azul=0;
int clear=0;
int k = 0;
int j = 0;
int b;
int primera = 0;
int X;
int d = 0; // Distancia ultrasonido izquierdo
int giro = 0 ;
int rec= 140; // Valor del servo para avanzar dececho
int da; // Distancia ultrasonido derecho
int t; // ultrasonido tiempo de rebote izquierdo
int te; // ultrasonido tiempo de rebote derecho

int vel= 150; // velocidad
int velrapida = 150;
int veln = 100;
int gi=vel; // velocidad de giro


int vueltacompleta = 0;

int red = 0;
int green = 0;
int colort = 0;
int ultrat = 0;
int vcono = vel;
int td;
int dd;
int ti;
int di;
int izquierda = rec+35;
int derecha = rec-35;
int linea = 1;
int rectofijo = rec;
int rectofijo2 = rec;
  int x,y,z;
  float geografico, acimut;
  float declinacion = -10.26;		// variables para los 3 ejes y acimut
int direccion = 0;
int angulo1min= 330;
int angulo1max= 360;
int angulo2min= 75;
int angulo2max= 100;
int angulo3min= 165;
int angulo3max=190;
int angulo4min= 245;
int angulo4max= 270;
int maxactual= 0;
int minactual=0;
int cono =0;
int primeravuelta=0;
int a = 0;
int hola = 0;
int carril=0;
float angulo = acimut-10.26;
int adelante = 7;
int atras = 6;
float angulof = 0;
float angulom;
MPU6050 mpu(Wire);
void setup()
{
    byte status = mpu.begin();
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
  pinMode(10, OUTPUT);// Trigger
  pinMode(11, INPUT);  //cho
  pinMode(12, INPUT); //Trigger
  pinMode(13, OUTPUT);  //Echo
  pinMode(22, OUTPUT);
  pinMode(23, INPUT_PULLUP);
  pinMode(24, INPUT);
  pinMode(25, INPUT);
  pinMode(A15, INPUT);
  pinMode(A14, INPUT);
  pinMode(A13, INPUT);
  pinMode(A12, INPUT);
  pinMode(26, OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(29,INPUT);
  pinMode(36, INPUT_PULLUP);
    pinMode(49, INPUT_PULLUP);
    pinMode(51, INPUT);
        pinMode(50, OUTPUT);
  pinMode(53,INPUT);
  pinMode(30,OUTPUT);
  pinMode(40,OUTPUT);
  pinMode(31,INPUT); 
  pinMode(42,OUTPUT);
  pinMode(43,INPUT);
  pinMode(47,OUTPUT);
  pinMode(45,OUTPUT);
  pinMode(49,OUTPUT);
  pinMode(52,OUTPUT); 
  pro.attach(9);  // Pin de control del servo
  pro.write(rec);
  Serial.begin(115200);
  Wire.begin();			// inicializa bus I2C		// inicializa monitor serie a 9600 bps


  
  			// inicializa objeto

  Serial.println(F("Calculating offsets, do not move MPU6050"));
    mpu.calcOffsets(); // gyro and accelero
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");
  angulof = mpu.getAngleZ();

  pro.write(rec);
  while(digitalRead(23)==HIGH){
delay(1);
}
  digitalWrite(atras,0);
  digitalWrite(adelante,1);
  analogWrite(5,vel);
  Serial.println("Iniciado");
 delay(20);
primeravuelta = 0;
}


void loop() {
detectardistancias();
if(primeravuelta==0){
detectarlado();
}

}
void detectarlado(){
  if(d<40&&d>0){
    detectardistancias();
    if(d<40&&d>0){
    Serial.print("detecto d ");
    Serial.println(d);     


  if(di==0&&a==0){
    a=1;
          Serial.print("detecto di 0 di:");
          Serial.println(di);
                    Serial.print("dd");
          Serial.println(dd);               Serial.print(" a ==1 izquierda");   delay(10000);
  

  }
   if(dd==0&&a==0){
          Serial.print("detecto dd 0 dd:");
          Serial.println(dd);
                    Serial.print("di");
          Serial.println(di);       Serial.print(" a ==2 derecha");   delay(10000);

    a=2;
  }
  if(di>dd&&a==0){
          Serial.print("detecto dd:");
          Serial.println(dd);
                    Serial.print("di");
          Serial.println(di);
          Serial.print(" a ==1 izquierda");
                    delay(10000);
    a=1;

  }
   if(dd>di&&a==0){
          Serial.print("detecto  di:");
          Serial.println(di);
                    Serial.print("dd");
          Serial.println(dd);       Serial.print(" a ==2 derecha");
          delay(10000);
    a=2;

  }
  primeravuelta=1;
  }}

}

// reiniciar el contad
  //detectar 3 vueltas y detenerse


void rectificadosolo(int target){
  kp=2;
      mpu.update();
  gyro = mpu.getAngleZ();
 error = target - gyro;
 if (error>180){
  error= error -360;
 } 

 pro.write(rec+error*kp);

}
void rectderecha(int targetult, int target){
  int erroultra;
  int kpultra = -2; 
  kp= 1.5;
  angulof += target;
  mpu.update();
  gyro = mpu.getAngleZ();
 error = angulof - gyro;
 if (error>180){
  error= error -360;
 } 
  dd= sensor_3.ping_cm();
  erroultra = targetult - dd;
    Serial.print("erroultra");
Serial.println(erroultra);
    Serial.print("error");
Serial.println(error);

 pro.write(rec+erroultra*kpultra*-1+error*kp);
}

void rectizquierda(int targetult, int target){
  int erroultra;
  int kpultra = 2; 
  kp=2;
  angulof += target;
  mpu.update();
  gyro = mpu.getAngleZ();
 error = angulof - gyro;
 if (error>180){
  error= error -360;
 } 
  di= sensor_1.ping_cm();
  erroultra = targetult - di;
    Serial.print("erroultra");
Serial.println(erroultra);
    Serial.print("error");
Serial.println(error);
 pro.write(rec+erroultra*kpultra*-1+error*kp);
}

void derechasafe(int targetult, int target, int sensibilidad){
  int erroultra;
  int kpultra = -3; 
  kp=2;
  mpu.update();
  gyro = mpu.getAngleZ();
 error = target - gyro;
 if (error>180){
  error= error -360;
 } 
  dd= sensor_3.ping_cm();
  erroultra = targetult - dd;
    Serial.print("erroultra");
Serial.println(erroultra);
if(erroultra<sensibilidad&&erroultra>-1*sensibilidad){
 pro.write(rec+erroultra*kpultra*-1+error*kp);
 
}
}


void izquierdasafe(int targetult, int target){
  int erroultra;
  int kpultra = 3; 
  kp=2;
  mpu.update();
  gyro = mpu.getAngleZ();
 error = target - gyro;
 if (error>180){
  error= error -360;
 } 
  di= sensor_1.ping_cm();
  erroultra = targetult - di;
    Serial.print("erroultra");
Serial.println(erroultra);
    Serial.print("error");
Serial.println(error);
 pro.write(rec+erroultra*kpultra*-1+error*kp);
}

void detectardistancias(){
  
d= sensor_2.ping_cm();
di= sensor_1.ping_cm();
dd= sensor_3.ping_cm();
  mpu.update();
  gyro = mpu.getAngleZ();
  Serial.print("gyro: ");
    Serial.println(gyro);  
  Serial.print("di: ");
    Serial.println(di);
      Serial.print("d: ");
    Serial.println(d);
      Serial.print("dd: ");
    Serial.println(dd);

}




void giroizq90(){
  int erroultra;
  int kpultra = -3; 
  kp=2;
  angulof +=90;
  mpu.update();
  gyro = mpu.getAngleZ();
  
 while(gyro>angulof+10||gyro<angulof-5){

  mpu.update();
    gyro = mpu.getAngleZ();
 pro.write(izquierda);
       Serial.println("Girando derecha ");
        Serial.println(gyro);
        Serial.println(angulof);
}
      Serial.println("termino derecha");
pro.write(rec);
}

void giroder90(){
  int erroultra;
  int kpultra = -3; 
  kp=2;
  angulof -=90;
  mpu.update();
  gyro = mpu.getAngleZ();
 while(gyro<angulof-5||gyro>angulof+5){
  mpu.update();
    gyro = mpu.getAngleZ();
 pro.write(derecha);
       Serial.println("Girando Izquierda");
        Serial.println(gyro);
        Serial.println(angulof);
     
}
pro.write(rec);
      Serial.println("termino izquierda ");
}