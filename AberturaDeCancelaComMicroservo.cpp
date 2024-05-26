#include <Servo.h>

// C++ code
//
#define bot1 1
#define bot2 2
#define ledVermelho 13
#define ledVerde 12
Servo servo;

void setup()
{
  pinMode(ledVermelho,OUTPUT); // definição de PinMode
  pinMode(ledVermelho,OUTPUT);
  servo.attach(3); // 
  servo.write(0); //Definindo início como angulação 0.
}

void loop()
{
  int lerbot1 = digitalRead(bot1); // Lendo o estado do botão
  int lerbot2 = digitalRead(bot2);
  
  if (lerbot1 == 1) {
    digitalWrite(ledVerde, HIGH);
    servo.write(90); //Muda o estado do Servo motor para 0 graus
} else if (lerbot2 == 1) {
    digitalWrite(ledVerde, LOW);
}
 
  // Checando estado do botao um para fechar catraca
  if(lerbot2 == 1){
    digitalWrite(ledVermelho, HIGH);
    servo.write(0); //Muda o estado do Servo motor para 0 graus
  } else if (lerbot1 == 1) {
    digitalWrite(ledVermelho, LOW);
  }
}
//link: https://www.tinkercad.com/things/lBrlspkweTi-larissa-ferreira-servo-motor-cancela
