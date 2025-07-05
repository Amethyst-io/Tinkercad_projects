#define NOP()  asm("nop")

volatile long V = 0;

const unsigned char DIGS[11] = {
  // 0     1     2     3     4
  0x3F, 0x06, 0x5B, 0x4F, 0x66,
  // 5     6     7     8     9     -
  0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x40
};

unsigned char DISP[3] = {0, 0, 0};
volatile boolean flag = false;
volatile unsigned char period = 0;

void setup() {
  // Crystal oscillator division factor: 1
  CLKPR = (1 << CLKPCE);
  CLKPR = 0x00;

  // Port B initialization: bits 0-4 as output, bit 5 input
  DDRB = 0x1F;
  PORTB = 0x1C;  // Initial PORTB state

  // Timer/Counter0 initialization
  TCCR0A = (1 << WGM01);  // CTC mode
  TCCR0B = (1 << CS02);   // Prescaler 256
  TCNT0 = 0x00;
  OCR0A = 0x95;           // Compare value for ~4ms interrupt
  OCR0B = 0x00;

  // Timer/Counter0 interrupt enable
  TIMSK = (1 << OCIE0A);

  // ADC initialization
  DIDR0 = (1 << ADC0D);   // Disable digital input buffer on ADC0
  ADMUX = 0x00;           // ADC0, AVcc reference
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC, prescaler 128

  sei(); // Enable global interrupts
}

void loop() {
  if (!flag)
    return;

  V = adcRead0();

  if (V == 1023) {
    DISP[2] = DISP[1] = DISP[0] = 10; // Display '-'
  } else {
    V = (V * 160L) / 1023L;  // Scale ADC reading to 0-160
    DISP[2] = V / 100;
    DISP[1] = (V / 10) % 10;
    DISP[0] = V % 10;
  }

  flag = false;
}

void softDelay(unsigned char d1) {
  for (; d1 > 0; d1--) {
    NOP();
  }
}

void transmitByte(unsigned char bt) {
  for (unsigned char j = 0; j < 8; j++) {
    if (bt & 0x80)
      PORTB |= (1 << 0);
    else
      PORTB &= ~(1 << 0);

    NOP();

    PORTB |= (1 << 1);
    NOP();
    PORTB &= ~(1 << 1);

    bt <<= 1;
  }
  NOP();
  PORTB &= ~(1 << 0);
  NOP();
  PORTB |= (1 << 0);
}

// Timer0 Compare Match A Interrupt Service Routine
ISR(TIMER0_COMPA_vect) {
  static unsigned char p = 0;
  unsigned char s;

  PORTB |= 0x1C; // Set bits 2,3,4 high

  s = DIGS[DISP[p]] | ((p == 1) ? 0x80 : 0x00); // Add decimal point on digit 1
  transmitByte(s);

  PORTB &= ~(1 << (p)); // Turn off current digit
  p++;
  if (p == 3)
    p = 0;

  period++;
  if (period == 25) {
    period = 0;
    flag = true;
  }
}

// Read the ADC conversion result from ADC0
int adcRead0(void) {
  ADMUX = 0x00; // Select ADC0, AVcc reference
  softDelay(10); // Delay for voltage stabilization

  ADCSRA |= (1 << ADSC); // Start conversion

  while ((ADCSRA & (1 << ADIF)) == 0)
    ; // Wait for conversion to complete

  ADCSRA |= (1 << ADIF); // Clear interrupt flag

  // Read ADC result (must read ADCL first)
  int result = ADCL;
  result |= (ADCH << 8);

  return result;
}