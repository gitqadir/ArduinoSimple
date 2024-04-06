// Analog to Digital converter with LDR as sensor

// Define pin numbers for LEDs
const int LEDRED = 13;
const int LEDGREEN = 14;
const int LEDBLUE = 15;

// Variable for loop iteration
int i;

void setup() {
  // Set pin modes for LEDs
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDBLUE, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read analog value from pin 17 (LDR sensor)
  int sensorValue = analogRead(17);
  
  // Map sensor value to brightness level (0-255)
  int brightness = map(sensorValue, 120, 1023, 0, 255);  // Calibrating the sensor, in a dark room LDR values were in the 100's
  Serial.println(brightness);  // Print brightness value to serial monitor
  
  // Control LEDs based on brightness levels
  if (brightness < 50) {
    // Low brightness, turn on red LED, turn off green LED
    digitalWrite(LEDRED, HIGH);
    digitalWrite(LEDGREEN, LOW);
  } 
  else if (brightness > 50 && brightness < 200) {
    // Medium brightness, flash both red and green LEDs for 10 cycles
    for (i = 0; i <= 10; i++) {
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDGREEN, HIGH);
    }
  } 
  else if (brightness > 200) {
    // High brightness, turn on green LED, turn off red LED
    digitalWrite(LEDGREEN, HIGH);
    digitalWrite(LEDRED, LOW);
  }
}
