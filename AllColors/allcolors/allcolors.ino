// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        7 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 150 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.show();   // Send the updated pixel colors to the hardware.

  Serial.begin(9600);
}

int r=128;
int g=2;
int b=10;

int dr = 1;
int dg = 2;
int db = 10;

void loop() {
  if ((r < abs(dr)) || (r > 255-dr))
  {
    dr=-dr;
  }
  if ((g < abs(dg)) || (g > 255-dg))
  {
    dg=-dg;
  }
  if ((b < abs(db)) || (b > 255-db))
  {
    db=-db;
  }

  r += dr;
  g += dg;
  b += db;

  pixels.fill(Adafruit_NeoPixel::Color(r,g,b), 0,NUMPIXELS);
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(100);

}
