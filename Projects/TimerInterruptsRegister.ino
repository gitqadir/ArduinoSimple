void setup() {
  DDRB |= (1 << DDB5);      // Set pin 13 as an output (Arduino Uno's built-in LED)
  DDRD &= ~(1 << DDD2);     // Set pin 2 as an input
  PORTB &= ~(1 << PORTB5);  // Turn off the LED initially
  Serial.begin(9600);       // Initialize serial communication at 9600 baud rate
  
  // Configure Timer1 for generating interrupts
  TCCR1A = 0;               // Clear Timer1 Control Register A
  TCCR1B = 0;               // Clear Timer1 Control Register B
  TCNT1 = 0;                // Reset Timer1 counter
  TCCR1B |= (1 << CS12);    // Set prescaler to 256
  OCR1A = 15625;            // Set the output compare register to generate interrupt every 0.25 seconds (31250 clock cycles is 0.5 second)
  TIMSK1 |= (1 << OCIE1A);  // Enable output compare interrupt for Timer1
}

ISR(TIMER1_COMPA_vect)  // Interrupt service routine for Timer1 compare match
{
  TCNT1 = 0;               // Reset Timer1 counter
  PORTB ^= (1 << PORTB5);  // Toggle LED on pin 13
}

// Explanation of digitalRead alternative for reading specific bits
// This is NOT equal to: int value = digitalRead(5);
// Why? Because value = an 8-bit value. For only 1 bit, you need to shift registers
// int value = PIND & B00100000;

// This is equal to int value2 = digitalRead(5);
// Since we read the fifth bit, we need to shift 5 times to the right
// int value2 = (PIND >> 5 & B00100000 >> 5);
void loop() {
  if (PIND >> 2 == 1) {    // Check if the input on pin 2 is HIGH
    OCR1A = 15625;         // Set the output compare register to generate interrupt every 0.25 seconds
    Serial.println(PIND >> 2);  // Print the value read from pin 2 shifted 2 times to the right
  } else {
    OCR1A = 31250;         // Set the output compare register to generate interrupt every 0.5 seconds
    Serial.println(PIND >> 2);  // Print the value read from pin 2 shifted 2 times to the right
  }
}
