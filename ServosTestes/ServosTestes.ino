/*
   Material de Apoio http://blog.filipeflop.com/motores-e-servos/controle-motor-dc-arduino-motor-shield.html
   Angulo
   44 -141
   Pulso deve ser de 90 minimo 94 minimo inverso
   Pulso deve ser de 44 maximo 141 maximo inverso

   Para parar, usa-se o angulo valor 92
   Controle de Motor
   http://www.superdroidrobots.com/shop/custom.aspx/motor-controllers/60/

   Documentação do Drive Sabertooth 2x25
   http://www.dimensionengineering.com/datasheets/Sabertooth2x25.pdf

*/
#include <Servo.h>

void setup() {
  Serial.begin(9600);
  iniciar();
}

void loop() {

  delay(500);
  direita();
  delay(5000);
}
