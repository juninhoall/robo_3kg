
int sensorPin = A0;    // select the input pin for the potentiometer
//int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

static unsigned long ult_tempo = 0;

long seg = 0,
     minu = 0,
     hor = 0,
     mil = 0;

void setup() {
  delay(500);
  // declare the ledPin as an OUTPUT:
  // pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  long tempo = millis();
  mil = tempo % 1000;
  // read the value from the sensor:

  sensorValue = analogRead(sensorPin);
  // delay(2222);
  if (sensorValue > 50) {

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


}
