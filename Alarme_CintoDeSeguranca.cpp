// C++ code
//

#define PORT_CINTO 2
#define PORT_IGNICAO 3

#define PORT_LED_VERMELHO 12
#define PORT_LED_VERDE 13



void setup()
{
  Serial.begin(9600);
  pinMode(PORT_CINTO, INPUT);
  pinMode(PORT_IGNICAO, INPUT);
  
  pinMode(PORT_LED_VERMELHO, OUTPUT);
  pinMode(PORT_LED_VERDE, OUTPUT);
}

void loop()
{
  Serial.println(digitalRead(PORT_IGNICAO));
  
  if(digitalRead(PORT_IGNICAO) == 0){
  	digitalWrite(PORT_LED_VERDE, LOW);
    digitalWrite(PORT_LED_VERMELHO, LOW);
  } else if(digitalRead(PORT_CINTO) == 1 && digitalRead(PORT_IGNICAO) == 1){
  	digitalWrite(PORT_LED_VERDE, LOW);
    digitalWrite(PORT_LED_VERMELHO, HIGH);
    tone(7, 523, 1000);
  } else{
    noTone(0);
    digitalWrite(PORT_LED_VERMELHO, LOW);
  	digitalWrite(PORT_LED_VERDE, HIGH);
  }  
}

// link: https://www.tinkercad.com/things/dPScjeHkAC4-copy-of-alarme-de-cinto-de-seguraca?sharecode=t9MU8lXcuWhJ58DxvJO7sZq8oH9PwgUdVcWEeIRKwUo
