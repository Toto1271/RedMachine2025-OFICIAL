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
#define TRIGGER_sensor_2  18
#define ECO_sensor_2  19

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
int bloque =0 ;
int ybloque;
int cono11= 0;
int cono12=0;

int cono21= 0;
int cono22=0;

int cono31= 0;
int cono32=0;
int listo2 =0;
int cono41= 0;
int cono42=0;
    int signature;
int prueba;
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
int lastblock;
int vel= 170; // velocidad
int velrapida = 150;
int veln = 100;
int gi=vel; // velocidad de giro


int vueltacompleta = 0;

int listo=0;
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
int pared = 0;
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
    pinMode(LED_BUILTIN, OUTPUT); // Configura el LED como salida
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
pixy.init();

  
  			// inicializa objeto

  Serial.println(F("Calculating offsets, do not move MPU6050"));
    mpu.calcOffsets(); // gyro and accelero

  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down

  Serial.println("Done!\n");
  angulof = mpu.getAngleZ();
 char dato;
 int comenzar=0;
  pro.write(rec);
  while(comenzar!=1){

    detectardistancias(0);
    if(di<30){
        digitalWrite(LED_BUILTIN, HIGH); // Enciende el LED
        pared=1;
        a=2;
    }
        if(di>30){
        digitalWrite(LED_BUILTIN, LOW); // Enciende el LED
        pared=0;

    }

        dato = Serial.read(); // Lee directamente sin verificar disponibilidad
if(digitalRead(23)==LOW){
  comenzar=1;
}
if(dato=='1'){
  comenzar=1;
}
}
  digitalWrite(atras,0);
  digitalWrite(adelante,1);
  analogWrite(5,vel);
  Serial.println("Iniciado");
 delay(20);
primeravuelta = 0;
prueba=0;
}


void loop() {
detectardistancias(0);
detectarladocorto();
girosegundoreto();
detectarpixyY();
if(a!=0){
esquivarconos();
}
if(a==0){
primercono();
}
//rojo ==1 verde =2



}
void detectarlado(){
  if(d<30&&d>0){
    detectardistancias(1);
    if(d<30&&d>0){
    Serial.print("detecto d ");
    Serial.println(d);     


  if(di==0&&a==0){
    a=1;
          Serial.print("detecto di 0 di:");
          Serial.println(di);
                    Serial.print("dd");
          Serial.println(dd);               Serial.print(" a ==1 izquierda");   
  

  }
   if(dd==0&&a==0){
          Serial.print("detecto dd 0 dd:");
          Serial.println(dd);
                    Serial.print("di");
          Serial.println(di);       Serial.print(" a ==2 derecha");   

    a=2;
  }
  if(di>dd&&a==0){
          Serial.print("detecto dd:");
          Serial.println(dd);
                    Serial.print("di");
          Serial.println(di);
          Serial.print(" a ==1 izquierda");
                    
    a=1;

  }
   if(dd>di&&a==0){
          Serial.print("detecto  di:");
          Serial.println(di);
                    Serial.print("dd");
          Serial.println(dd);       Serial.print(" a ==2 derecha");
          
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
  detectardistancias(0);
  int erroultra;
  int kpultra = -2; 
  kp= 0.5;
  angulof += target;
  mpu.update();
  gyro = mpu.getAngleZ();
 error = angulof - gyro;
 if (error>180){
  error= error -360;
 } 
  dd= sensor_3.ping_cm();
  erroultra = targetult - dd;


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
 Serial.print("Angulof");
 Serial.println(angulof);
 Serial.println("Error");
 Serial.println(error);
  di= sensor_1.ping_cm();
  erroultra = targetult - di;

 pro.write(rec+erroultra*kpultra*-1+error*kp);

}



void detectardistancias(int serial){
  
d= sensor_2.ping_cm();
di= sensor_1.ping_cm();
dd= sensor_3.ping_cm();
  mpu.update();
  gyro = mpu.getAngleZ();
  if(serial==1){
  Serial.print("gyro: ");
    Serial.println(gyro);  
  Serial.print("di: ");
    Serial.println(di);
      Serial.print("d: ");
    Serial.println(d);
      Serial.print("dd: ");
    Serial.println(dd);

}}




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
      Serial.println("termino izquierda ");
}
void giroizq90n(){
  int erroultra;
  int kpultra = -3; 
  kp=2;
    mpu.update();
  gyro = mpu.getAngleZ();
  angulof =gyro + 90;
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

void giroder90n(){
  int erroultra;
  int kpultra = -3; 
  kp=2;
    mpu.update();
  gyro = mpu.getAngleZ();
  angulof = gyro -90;
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
      Serial.println("termino izquierda ");
}

void detectarpixyY(){
  ybloque = 0;
  bloque=0;
   pixy.ccc.getBlocks(); // Obtener bloques de color detectados

  if (pixy.ccc.numBlocks) {

    Serial.println(pixy.ccc.numBlocks);

    for (int i = 0; i < pixy.ccc.numBlocks; i++) {

      int signature = pixy.ccc.blocks[i].m_signature; // Identificador de color
      int x = pixy.ccc.blocks[i].m_x; // Coordenada X
      int y = pixy.ccc.blocks[i].m_y; // Coordenada Y

    
      if(y>ybloque){
        bloque = signature;
        ybloque = y;
      }

    }

      if (bloque%2 == 1) {
              Serial.print("Rojo: ");
            Serial.println(ybloque);
  }

    
      if (bloque%2 == 0) {
            Serial.print("Verde: ");
            Serial.println(ybloque);

      }
    }


}

void detectarladocorto(){
  if(d<10&&d>0){
    detectardistancias(1);
    if(d<10&&d>0){
    Serial.print("detecto d ");
    Serial.println(d);     
  if(di==0&&a==0){
    a=1;
          Serial.print("detecto di 0 di:");
          Serial.println(di);
                    Serial.print("dd");
          Serial.println(dd);               Serial.print(" a ==1 izquierda");   
  

  }
   if(dd==0&&a==0){
          Serial.print("detecto dd 0 dd:");
          Serial.println(dd);
                    Serial.print("di");
          Serial.println(di);       Serial.print(" a ==2 derecha");   

    a=2;
  }
  if(di>dd&&a==0){
          Serial.print("detecto dd:");
          Serial.println(dd);
                    Serial.print("di");
          Serial.println(di);
          Serial.print(" a ==1 izquierda");
                    
    a=1;

  }
   if(dd>di&&a==0){
          Serial.print("detecto  di:");
          Serial.println(di);
                    Serial.print("dd");
          Serial.println(dd);       Serial.print(" a ==2 derecha");
          
    a=2;

  }
  primeravuelta=1;
  }}

}



void giroizq90nc(){
  int erroultra;
  int kpultra = -3; 
  kp=2;
    mpu.update();
  gyro = mpu.getAngleZ();
  angulof =gyro + 90;
  mpu.update();
  gyro = mpu.getAngleZ();
  
 while(gyro>angulof+10||gyro<angulof-5){

  mpu.update();
    gyro = mpu.getAngleZ();
 pro.write(derecha);
       Serial.println("Girando derecha ");
        Serial.println(gyro);
        Serial.println(angulof);
}
      Serial.println("termino derecha");
pro.write(rec);
}

void giroder90nc(){
  int erroultra;
  int kpultra = -3; 
  kp=2;
    mpu.update();
  gyro = mpu.getAngleZ();
  angulof = gyro -90;
  mpu.update();
  gyro = mpu.getAngleZ();
 while(gyro<angulof-5||gyro>angulof+5){
  mpu.update();
    gyro = mpu.getAngleZ();
 pro.write(izquierda);
       Serial.println("Girando Izquierda");
        Serial.println(gyro);
        Serial.println(angulof);
     
}
pro.write(rec);
      Serial.println("termino izquierda ");
}





void girosegundoreto(){

if(a==2){
if(d<10&&d>0&&carril%2==1){
  if(d<10&&d>0){
    prueba=1;
    pro.write(rec);
    delay(500);
digitalWrite(adelante,0);
digitalWrite(atras,1);
delay(700);
giroizq(-90);
pro.write(rec);
retroceder();
delay(2500);
avanzar();
digitalWrite(adelante,1);
digitalWrite(atras,0);
  vuelta++;
  reiniciarvariables();
  detectardistancias(0);
}}
if(d<10&&d>0&&carril%2==0){
  if(d<10&&d>0){
    prueba=1;
    delay(500);
   retroceder();
   retroceder();
delay(2300);
   detener();
   avanzar();
   giroder(90);
   retroceder();
   delay(2500);
   pro.write(rec);
   avanzar();
   pro.write(rec);
  vuelta++;
  reiniciarvariables();
  detectardistancias(0);
}}}





if(a==1){
if(d<10&&d>0&&carril%2==0&&carril!=0){
  if(d<10&&d>0){
  prueba=1;
  pro.write(rec);
  delay(500);
digitalWrite(adelante,0);
digitalWrite(atras,1);
delay(700);
giroder(-90);
pro.write(rec);
retroceder();
delay(2500);
avanzar();
digitalWrite(adelante,1);
digitalWrite(atras,0);
  vuelta++;
  reiniciarvariables();
  detectardistancias(0);
}}
if(d<10&&d>0&&carril%2==1&&carril!=0){
  if(d<10&&d>0){
    prueba=1;
    delay(500);
   retroceder();
   retroceder();
delay(1800);
   detener();
   avanzar();
   giroizq(90);
   retroceder();
   delay(2500);
   pro.write(rec);
   avanzar();
   pro.write(rec);
  vuelta++;
  reiniciarvariables();
  detectardistancias(0);
}}
if(d<10&&d>0&&carril==0){
  if(d<10&&d>0){
    prueba=1;
    delay(500);
   retroceder();
   retrocedercondistancias(55);
   detener();
   avanzar();
   giroizq(90);
   retroceder();
   delay(2500);
   pro.write(rec);
   avanzar();
   pro.write(rec);
  vuelta++;
  reiniciarvariables();
  detectardistancias(0);
}}
}}


void detener(){
  digitalWrite(adelante,0);
  digitalWrite(atras,0);
}
void avanzar(){
  digitalWrite(adelante,1);
  digitalWrite(atras,0);
}
void retroceder(){
  digitalWrite(adelante,0);
  digitalWrite(atras,1);
}


void giroizq(int cantidad){
  int erroultra;
  int kpultra = -3; 
  kp=2;
    mpu.update();
  gyro = mpu.getAngleZ();
  angulof =gyro + cantidad;
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

void giroder(int cantidad){
  int erroultra;
  int kpultra = -3; 
  kp=2;
    mpu.update();
  gyro = mpu.getAngleZ();
  angulof = gyro -cantidad;
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
      Serial.println("termino derecha ");
}



void derechasafe(int targetult, int target, int sensibilidad){
  int erroultra;
  int kpultra = -2; 
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
if(erroultra>0&&erroultra<sensibilidad){
 pro.write(rec+erroultra*kpultra*-1+error*kp);
}
else{
  pro.write(rec);
}
if(erroultra<0&&erroultra>sensibilidad){
 pro.write(rec+erroultra*kpultra*-1+error*kp);
}
else{
  pro.write(rec);
}
}


void izquierdasafe(int targetult, int target, int sensibilidad){

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
 Serial.print("Angulof");
 Serial.println(angulof);
 Serial.println("Error");
 Serial.println(error);
  di= sensor_1.ping_cm();
  erroultra = targetult - di;
if(erroultra>0&&erroultra<sensibilidad){
 pro.write(rec+erroultra*kpultra*-1+error*kp);
}
else{
  pro.write(rec);
}
if(erroultra<0&&erroultra>sensibilidad){
 pro.write(rec+erroultra*kpultra*-1+error*kp);
}
else{
  pro.write(rec);
}

}
void delayx(int cantidad){
  int i =0;
  while(i< cantidad){
    detectardistancias(0);
    i++;
  }
}
void retrocedercondistancias(int distancia){
  while(d<distancia||d==0){
  
     while(d<distancia||d==0){
    detectardistancias(0);
  }
    detectardistancias(0);
}}

void avanzarhasta(int distancia){

  detectardistancias(0);
  while(d>distancia&&d!=0){
    detectardistancias(0);

  }
}
void reiniciarvariables(){
listo =0;
carril=0;

bloque=0;
lastblock=0;
}
void primercono(){
if(pared==1){
  if(bloque==1&&carril==0){
if(listo==0){
giroderf(45);
pro.write(rec);
delay(200);
giroizqf(45);
listo=1;
}
carril=1;
}
}
if(pared==0){
  if(bloque==1&&carril==0){
if(listo==0){
giroderf(25);
pro.write(rec);
delay(200);
giroizqf(25);
listo=1;
}
carril=0;
}
}

if(bloque==2&&carril==0){
if(listo==0){
giroizqf(45);
pro.write(rec);
delay(700);
giroderf(45);
listo=1;
}

Serial.println("Izquierda");
carril=2;
}


if(carril%2==0&&carril!=0){
if(di>25&&d>100){
rectderecha(70,0);
}
else{
  pro.write(rec);
}
if(di<25&&d>100||di<60&&d==0){
rectizquierda(13,0);
}
else{
  pro.write(rec);
}


if(carril%2==1){
if(dd>60){
rectizquierda(65,0);
}
if(dd<60&&d>110||dd<60&&d==0){
rectderecha(13,0);
}
Serial.println("Izquierda");
}



}}
void esquivarconos(){


  if(bloque==2&&carril==2){
carril=4;
}
if(bloque==1&&carril==1){
carril=3;
}

if(a==2){
if(bloque==1&&carril==0){
if(listo==0){
giroderf(45);
pro.write(rec);
delay(200);
giroizqf(45);
listo=1;
}
carril=1;
}

if(bloque==1&&carril==2){
giroderf(80);
pro.write(rec);
avanzarhasta(35);
giroizqf(80);
carril=3;
}



if(carril%2==1){
if(dd>60){
rectizquierda(65,0);
}
if(dd<60&&d>110||dd<60&&d==0){
rectderecha(13,0);
}
Serial.println("Izquierda");
}

if(carril%2==0){
rectizquierda(14,0);
Serial.println("Izquierda");
}

if(carril==0){
rectizquierda(40,0);
Serial.println("Izquierda");
}

if(bloque==2&&carril==0){
if(listo==0){
giroizqf(45);
pro.write(rec);
delay(700);
giroderf(45);
listo=1;
}
rectizquierda(14,0);
Serial.println("Izquierda");
carril=2;
}
if(bloque==2&&carril==1){
giroizqf(80);
pro.write(rec);

avanzarhasta(35);
giroderf(80);

listo=1;
carril=4;
}
}
if(a==1){





if(bloque==2&&carril==2){
carril=4;
}
if(bloque==1&&carril==1){
carril=3;
}

  if(bloque==1&&carril==0){
giroderf(45);
pro.write(rec);
delay(500);
giroizqf(45);
carril=1;
}





//rojo
  if(bloque==1&&carril==2){
giroderf(80);
pro.write(rec);
detectardistancias(0);
avanzarhasta(30);
giroizqf(70);
carril=3;
}


if(carril%2==0&&carril!=0){
if(di>25&&d>100){
rectderecha(70,0);
}
else{
  pro.write(rec);
}
if(di<25&&d>100||di<60&&d==0){
rectizquierda(13,0);
}
else{
  pro.write(rec);
}

Serial.println("Izquierda");
}

if(carril%2==1){
rectderecha(13,0);
Serial.println("Izquierda");
}

if(carril==0){
rectderecha(40,0);
Serial.println("Izquierda");
}


//verde
if(bloque==2&&carril==0){
if(listo==0){
giroizqf(45);
pro.write(rec);
delay(600);
giroderf(45);
listo=1;
}

Serial.println("Izquierda");
carril=2;
}

if(bloque==2&&carril==1){
giroizqf(80);
pro.write(rec);
avanzarhasta(35);
giroderf(80);

listo=1;
carril=4;
}
}
  bloque=0;
  lastblock=0;
}

void giroizqf(int cantidad){
  int erroultra;
  int kpultra = -3; 
  kp=2;
    mpu.update();
  gyro = mpu.getAngleZ();
  angulof =angulof + cantidad;
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

void giroderf(int cantidad){
  int erroultra;
  int kpultra = -3; 
  kp=2;
    mpu.update();
  gyro = mpu.getAngleZ();
  angulof = angulof -cantidad;
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
      Serial.println("termino derecha ");
}