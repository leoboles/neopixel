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

int x = 0;

void loop() {
  float passo = 255.0 / NUMPIXELS * 3.0;
  
  for (int c = 0; c <= NUMPIXELS / 3; c++){
    int r = 255 - (c * passo);
    int g = 0 + (c * passo);

    int pixel = c + x + ((NUMPIXELS / 3) * 0);
    if (pixel > NUMPIXELS)
      pixel -= NUMPIXELS;
    pixels.setPixelColor(pixel, r, g, 0);
  }
  for (int c = 0; c <= NUMPIXELS / 3; c++){
    int g = 255 - (c * passo);
    int b = 0 + (c * passo);
    int pixel = c + x + ((NUMPIXELS / 3) * 1);
    if (pixel > NUMPIXELS)
      pixel -= NUMPIXELS;
    pixels.setPixelColor(pixel, 0, g, b);
  }
  for (int c = 0; c <= NUMPIXELS / 3; c++){
    int b = 255 - (c * passo);
    int r = 0 + (c * passo);
    
    int pixel = c + x + ((NUMPIXELS / 3) * 2);
    if (pixel > NUMPIXELS)
      pixel -= NUMPIXELS;
      
    pixels.setPixelColor(pixel, r, 0, b);
  }
  pixels.show();   // Send the updated pixel colors to the hardware.
  
  x++;
  if (x > NUMPIXELS)
  {
    x = 0;
  } 
  //delay(50);
}
