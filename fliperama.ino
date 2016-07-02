
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorPin2 = A1;
int sensorValue = 0;  // variable to store the value coming from the sensor
int  sensorValue2 = 0;
static unsigned long ult_tempo = 0;
boolean start = false;

long seg = 0,
     minu = 0,
     hor = 0,
     mil = 0;

void setup() {
  delay(500);
  Serial.begin(9600);

}

void loop() {
  start = false;
  sensorValue = analogRead(sensorPin);
Serial.println(sensorValue);
  if (sensorValue > 30) {
    start = true;

  }
  while (start) {
    comecar();
    sensorValue2 = analogRead(sensorPin2);
    Serial.println(sensorValue2);
   // delay(1000);
    if (sensorValue2 > 30) {
      start = false;
      Serial.end();
    }

  }
}
void comecar() {
  //sensorValue = analogRead(sensorPin);
  cronometro();
}

void cronometro() {
  long tempo = millis();

  mil = tempo % 1000;
  if (tempo - ult_tempo >= 1000 ) {
    ult_tempo = tempo;
    seg++;

  }

  if (seg >= 60) {
    seg = 0;
    minu++;
  }
  if (minu >= 60) {
    minu = 0;
    hor++;
  }
  if (hor >= 24) {
    hor = 0;
    minu = 0;
  }
  Serial.print(hor);
  Serial.print(":");
  Serial.print(minu);
  Serial.print(":");
  Serial.print(seg);
  Serial.print(":");
  Serial.println(mil);
}
