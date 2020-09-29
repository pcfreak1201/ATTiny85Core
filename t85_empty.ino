// Source: http://www.technoblogy.com/show?TWD

#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

int led = 2; // In port B

void setup() {                
 DDRB = DDRB | 1<<led;         // Define PB5 as an output
}

volatile long Counter;

void delay (long n) {          // Delay by n milliseconds
 Counter = 469 * n;
  do Counter--; while (Counter != 0);
}

// The loop routine runs over and over again forever:
void loop() {
  PORTB = PORTB | 1<<led;      // Take PB5 high
  delay(100);                 // Wait for a second
  PORTB = PORTB & ~(1<<led);   // Take PB5 low
  delay(100);                 // Wait for a second
}

int main() {
  sei();
  setup();
  for(;;)
    loop();
}
