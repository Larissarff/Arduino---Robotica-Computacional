#define echo 3
#define trig 4
#define LedR 8
#define LedO 9
#define LedY 10
#define LedG 11
#define piezzo 13

//float armazem = 0;
float distancia;

void setup()
{ 
  //Definindo pinModes
  pinMode(LedR,OUTPUT);
  pinMode(LedO,OUTPUT);
  pinMode(LedY,OUTPUT);
  pinMode(LedG,OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig,OUTPUT);
  pinMode(piezzo,OUTPUT);
  
  //Iniciando o serial
  Serial.begin(9600);
}
 void Pulso(){
  //Definindo inicio.
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
 
}
  // Mapeia a distância para um intervalo específico
void loop()
{
  Pulso();
 
  float tempo = pulseIn(echo, HIGH);// Mede a duração do pulso de echo
  distancia =(tempo * 0.017);
  //armazem = tempo;
   
  Serial.print("distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if(distancia >= 230){
    noTone(piezzo);
    digitalWrite(LedG,HIGH);
    digitalWrite(LedY,LOW);
    digitalWrite(LedO,LOW);
    digitalWrite(LedR,LOW);
  }
 else if(distancia >= 180){
    tone(piezzo,400,1000);
    digitalWrite(LedG,LOW);
    digitalWrite(LedY,HIGH);
    digitalWrite(LedO,LOW);
    digitalWrite(LedR,LOW);
 } else if(distancia >= 110){
    tone(piezzo,700,1000);
    digitalWrite(LedG,LOW);
    digitalWrite(LedY,LOW);
    digitalWrite(LedO,HIGH);
    digitalWrite(LedR,LOW);
 } else {
    tone(piezzo,1200,1000);
    digitalWrite(LedG,LOW);
    digitalWrite(LedY,LOW);
    digitalWrite(LedO,LOW);
    digitalWrite(LedR,HIGH);
 }
}
  
