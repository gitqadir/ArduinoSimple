//Analog to Digital conversion

const int LEDRED = 13;
const int LEDGREEN = 14;
const int LEDBLUE = 15;
int i;

void setup() {
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDBLUE, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int sensorValue = analogRead(17);
  int brightness = map(sensorValue, 120, 1023, 0, 255);  //Calibrating the sensor, In a dark room LDR values were in 100's //
  Serial.println(brightness);
  if (brightness < 50) {
    digitalWrite(LEDRED, HIGH);
    digitalWrite(LEDGREEN, LOW);
  } else if (brightness > 50 && brightness < 200) {
    for (i = 0; i <= 10; i++) {
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDGREEN, HIGH);
      }
  } else if (brightness > 200) {
    digitalWrite(LEDGREEN, HIGH);
    digitalWrite(LEDRED, LOW);
  }
}
