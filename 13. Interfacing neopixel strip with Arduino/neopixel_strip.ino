#include <Adafruit_NeoPixel.h>

// Corrected macro definitions: remove '=' sign
#define PIN 6
#define N_LEDS 4

// Corrected object initialization: use defined constants without '=' and proper spacing
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 0, 255)); // Blue
}

// Removed 'static' keyword (not needed here) and fixed parameter name
void chase(uint32_t c)
{
  // Loop extended to strip.numPixels() + 4 to create trailing effect
  for(uint16_t i = 0; i < strip.numPixels() + 4; i++)
  {
    if (i < strip.numPixels()) {
      strip.setPixelColor(i, c); // Turn on current pixel
    }
    if (i >= 4) {
      strip.setPixelColor(i - 4, 0); // Turn off pixel 4 steps behind
    }
    strip.show();
    delay(25);
  }
}