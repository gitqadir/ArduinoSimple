#include <Ticker.h> // Include the Ticker library for timer functionality

// Define variables to store LED states and pin numbers
int LED_STATE = LOW;  // Variable to store the state of the first LED
int LED_STATE2 = LOW; // Variable to store the state of the second LED
int LEDRED = 0;       // Pin number for the first LED (Assuming it's connected to pin 0)
int LEDBLUE = 2;      // Pin number for the second LED (Assuming it's connected to pin 2)

Ticker myTimer;   // Declare a Ticker object for the first LED
Ticker myTimer2;  // Declare a Ticker object for the second LED

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDRED, OUTPUT);  // Set the first LED pin as an output
  pinMode(LEDBLUE, OUTPUT); // Set the second LED pin as an output
  
  // Attach timers to the flip functions with specified intervals
  myTimer.attach(.55, flip);  // Attach the first timer to the flip function with an interval of 0.55 seconds
  myTimer2.attach(.85, flip2); // Attach the second timer to the flip2 function with an interval of 0.85 seconds
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(3000); // Delay for 3 seconds (3000 milliseconds)
}

void flip() {
  // This function toggles the state of the first LED
  LED_STATE = !LED_STATE; // Toggle the LED state
  digitalWrite(LEDRED, LED_STATE); // Write the new LED state to the first LED pin
}

void flip2() {
  // This function toggles the state of the second LED
  LED_STATE2 = !LED_STATE2; // Toggle the LED state
  digitalWrite
