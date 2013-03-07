// was 8 MHZ is now 16 MHZ – Scope check

#include <avr/io.h>
#include <util/delay.h>

#define CTL_PIN (1<<5)
#define CTL_HI (!(ACSR & (1<<ACO)))

void main()
{

  CLKPR = 0x80;
  CLKPR = 0x0;
  ADCSRB &= ~(1<< ACME);
  ACSR |= ( 1<< ACBG);
  TCCR0A = 0x03;
  TCCR0B = 0x09;
  OCR0B = 7;
  DDRC = CTL_PIN;
  
  while(1){
    PORTC = 0;  
    while (!CTL_HI);
    _delay_ms(4.1);
    PORTC |= CTL_PIN;
    _delay_ms(4.2);
    
    // 280khz burst
    TCCR0A = 0x23;
    TCNT0 = 0x0;
    OCR0A = 27;
    DDRD |= 1<<5;
    _delay_ms(1.5);
    
    // 245khz burst
    OCR0A = 33;
    TCNT0 = 0x0;
    _delay_ms(4.6);
    
    // burst off
    TCCR0A = 0x03;
    DDRD &= ~(1<<5);
    
    // wait for ack pulse
    while (CTL_HI);
    // kill init pulldown
    PORTC &= ~CTL_PIN;
    
    // Just hang around and 
    // wait for loss-of-signal
    while (1) {
      while (CTL_HI);
      _delay_ms(100);
      if (!CTL_HI)
        break;
    }
  }
}