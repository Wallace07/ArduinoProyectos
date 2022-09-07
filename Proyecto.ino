// C++ code
//
//Cables Morados: Alimentaciòn
//Cables negros: Tierra
//Cables Amarillos: Outputs
//cables naranjas: Inputs

#include <Servo.h>

Servo servo;
int trig1=11; //Sensor inferior
int echo1=10; 
int trig2=13; //Sensor superior
int echo2=12; 
int RED=6;
int BLUE=5;
int GREEN=3;

void setup()
{
  servo.attach(9);
  Serial.begin(9600);
  pinMode (trig1,OUTPUT);
  pinMode (echo1,INPUT);
  pinMode (trig2,OUTPUT);
  pinMode (echo2,INPUT);
  digitalWrite (trig1,LOW);
  digitalWrite (trig2,LOW);
  pinMode (RED,OUTPUT);
  pinMode (BLUE,OUTPUT);
  pinMode (GREEN,OUTPUT);
}

void loop()
{
  // Funcion tapa
 long t;
  long d;

  digitalWrite(trig1, HIGH);
  digitalWrite(trig1, LOW);
  
  t = pulseIn(echo1, HIGH);
  d = t/60;
  
  Serial.print("Distancia Inferior: ");
  Serial.print(d);     
  Serial.print("cm");
  delay(100);
  
  if (d<8){
    servo.write(180);
  analogWrite(RED,255);
  analogWrite(GREEN,25);
  analogWrite(BLUE,25);
  delay(10000);
  }
  
  else {
    servo.write(0);
  }
  
  // Funcion seguimiento
  
  digitalWrite(trig2, HIGH);
  digitalWrite(trig2, LOW);
  
  t = pulseIn(echo2, HIGH);
  d = t/60;
  
  Serial.print("Distancia Supeior: ");
  Serial.print(d);     
  Serial.print("cm");
  
  if (d>30&&d<40) { // Morado
  analogWrite(RED,255);
  analogWrite(GREEN,000);
  analogWrite(BLUE,130);}
  
  if (d>20&&d<30) { // Verde
  analogWrite(RED,000);
  analogWrite(GREEN,255);
  analogWrite(BLUE,000);}
  
  if (d>10&&d<20) { // Amarillo
  analogWrite(RED,255);
  analogWrite(GREEN,20);
  analogWrite(BLUE,000);}
  
  if (d<10) { // Rojo
  analogWrite(RED,255);
  analogWrite(GREEN,000);
  analogWrite(BLUE,000);}
  }

//Info tomada 
//Sensor ultrasonico: https://naylampmechatronics.com/blog/10_tutorial-de-arduino-y-sensor-ultrasonico-hc-sr04.html
//Servomotor: https://programarfacil.com/blog/arduino-blog/servomotor-con-arduino/
//Condicionales: https://programarfacil.com/blog/arduino-blog/if-else-arduino/
