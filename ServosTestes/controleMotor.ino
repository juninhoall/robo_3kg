#include <Servo.h>
Servo ST1, ST2;
int portaMotorE = 2;
int portaMotorD = 3;
int potenciaD = 0;
// Deve-ser colocado no setup da aplicação
void iniciar() {
  ST1.attach(portaMotorE);
  ST2.attach(portaMotorD);
}

// pulso deve ser de 40 maximo 90 minimo
void frente(int potencia) {
  ST1.write(potencia);
  ST2.write(potencia);
  //delay(2000);

}
void acelerarFrente(int potenciaIni) {
  if (potenciaIni < 40 || potenciaIni > 90) {
    potenciaIni = 90;
  }
  do {
    ST1.write(potenciaIni);
    ST2.write(potenciaIni);
    potenciaIni - 5;
  }
  while (potenciaIni > 40);
}

// pulso deve ser de 94 maximo 144 minimo
void  tras(int potencia) {
  ST1.write(potencia);
  ST2.write(potencia);
  potenciaD = potencia;
  potenciaD;
}
void acelerarTras(int potenciaIni) {
  if (potenciaIni > 94 || potenciaIni < 144) {
    potenciaIni = 144;
  }
  do {
    ST1.write(potenciaIni);
    ST2.write(potenciaIni);
    potenciaIni - 5;
  }
  while (potenciaIni > 94);
}

// girar no proprio eixo
void direita() {
  ST1.write(90);
  ST2.write(95);
}

void esquerda() {
  ST1.write(92);
  ST2.write(potenciaD);

}

// método para fazer parar
void parar() {
  ST1.write(92);
  ST2.write(92);

}



/*
   Regras de pulso, para não estorar.
*/
void controlaPotenciaMaxima(int potencia) {

}

void controlaPotenciaMinima(int potencia) {

}


