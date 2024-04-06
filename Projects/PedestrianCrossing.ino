// Pedestrian Traffic Crossing Control

// Define pin numbers for LEDs and button
const int LEDRED = 13;
const int LEDGREEN = 14;
const int LEDBLUE = 15;
const int BTN = 12;

// Define delay time for light transitions
int delay_time = 100;
int i;

void setup() {
  // Set pin modes for LEDs and button
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDBLUE, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
  pinMode(BTN, INPUT);
}

void loop() {
  // Initially turn on red LED
  digitalWrite(LEDRED, HIGH);
  
  // Check if button is pressed
  if (digitalRead(BTN) == LOW) {
    // Flash red and green LEDs alternately for 5 cycles
    for (i = 0; i <= 5; i++) {
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDGREEN, HIGH);
      delay(200);
      digitalWrite(LEDRED, LOW);
      digitalWrite(LEDGREEN, LOW);
      delay(200);
    }
    
    // Turn on green LED for 10 cycles
    for (i = 0; i <= 10; i++) {
      digitalWrite(LEDGREEN, HIGH);
      delay(200);
    }
    
    // Flash red and green LEDs alternately for 5 cycles
    for (i = 0; i <= 5; i++) {
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDGREEN, HIGH);
      delay(200);
      digitalWrite(LEDRED, LOW);
      digitalWrite(LEDGREEN, LOW);
      delay(200);
    }
  } 
  // If button is not pressed, maintain red LED
  else {
    digitalWrite(LEDRED, HIGH);
    digitalWrite(LEDGREEN, LOW);
    digitalWrite(LEDBLUE, LOW);
    delay(200);
  }
}
