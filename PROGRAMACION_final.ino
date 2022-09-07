//Basado y modificado en: (Stunning Leelo-Blad - control de temperatura - Blad-William Andrés Granada Campos - Colegio Agustiniano Norte - 29/04/2022)
//
int Temperatura;// Definimos variables y pines a usar en el proyecto
int Temp=A0;

int Humedad;
int Hum=A1;

int IN3=2;//Bomba de agua
int ENB=10;
int IN1=3;//Ventilador
int ENA=8;
int ledr=7;
int ledv=5;


void setup()
{
  pinMode(IN1, OUTPUT);//Definos las salidas en los pines digitales
  pinMode(IN3, OUTPUT);
  pinMode(ENA, OUTPUT);//Definos las salidas en los pines digitales
  pinMode(ENB, OUTPUT);
  pinMode(ledr, OUTPUT);
  pinMode(ledv, OUTPUT);
  pinMode(Humedad, INPUT);
  pinMode(Temperatura, INPUT);
  pinMode(Hum, INPUT);
  pinMode(Temp, INPUT);
  Serial.begin(9600);//abrir monitor en serie para que queden registrados los datos obtenidos por los sensores
  
}

void loop()
{
  Serial.print("La temperatura es ");//imprima la palabra en comillas en el monitor
Serial.println(Temp);//imprima datos en el monitor, recogidos por el sensor
Temperatura=analogRead(Temp);// Función matematica para que los datos en el monitor tengan varianza y no sean el mismo
  Serial.print("La humedad es ");
Serial.println(Humedad);
  Humedad=map(analogRead(Hum),0,1023,0,100);

  
 if ((Humedad>= 45)&&(Temp>30))//Condicion para que se active el ventilador y la bomba de agua simultaneamente
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(ENA,HIGH);
    digitalWrite(ledv,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(ENB,HIGH);
    delay (6000);
    digitalWrite(ledv,LOW);
    digitalWrite(IN1,LOW);
    digitalWrite(ENA,LOW);
    digitalWrite(IN3,LOW);
     digitalWrite(ENB,LOW);
    digitalWrite(ledr,HIGH);
    delay (3000);
    digitalWrite(ledr,LOW);
    
  }
 else if(Humedad>=45)//Condicion para que se active la bomba de agua
 {
    digitalWrite(IN3,HIGH);
     digitalWrite(ENB,HIGH);
    digitalWrite(ledv,HIGH);
    delay (6000);
    digitalWrite(ledv,LOW);
    digitalWrite(IN3,LOW);
     digitalWrite(ENB,LOW);
    digitalWrite(ledr,HIGH);
    delay (3000);
    digitalWrite(ledr,LOW);
    
 }
  else if(Temp>30)//Condicion para que se active solo el ventilador
 {
    digitalWrite(IN1,HIGH);
     digitalWrite(ENA,HIGH);
    digitalWrite(ledv,HIGH);
    delay (5000);
    digitalWrite(ledv,LOW);
    digitalWrite(IN1,LOW);
    digitalWrite(ENA,LOW);
    digitalWrite(ledr,HIGH);
    delay (3000);
    digitalWrite(ledr,LOW);
   
 }
 else
  {
   digitalWrite(IN1,LOW);
   digitalWrite(IN3,LOW);
   digitalWrite(ENA,LOW);
   digitalWrite(ENB,LOW);
   digitalWrite(ledr,LOW);
   digitalWrite(ledv,LOW);
 }
}
