/*****************************************************
   Flame-Throwing Pumpkin

   By John M. Wargo
   Created October 25, 2019
   https://johnwargo.com

   This is the Adafruit Feather code for a remote controlled
   flame-throwing pumpkin project.

   Remote Control Buttons:

   1. Lights flash RED
   2. Scream
   3. Lights and Scream

  Note: The code expects that the media player SD
  card has only `.mp3` files on it. If you want to
  put other files on the card, then you must adjust
  the print directory function to only count /mp3
  files.
 *****************************************************/

// NeoPixel shield pin
#define NEOPIXELPIN        11
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 32

#define TESTING false
#define VOL 10
#define FADE_COLOR ORANGE
#define NUM_INPUT_PINS 3

//=======================================
// Adafruit NeoPixel setup
//=======================================
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
//=======================================

//===============================================================
// Adafruit Music Maker FeatherWing
// https://www.adafruit.com/product/3357
// https://learn.adafruit.com/adafruit-music-maker-featherwing/
//===============================================================
// include SPI, MP3 and SD libraries
#include <SPI.h>
#include <SD.h>
#include <Adafruit_VS1053.h>

// These are the pins used
#define VS1053_RESET   -1     // VS1053 reset pin (not used!)

// Feather ESP8266
#if defined(ESP8266)
#define VS1053_CS      16     // VS1053 chip select pin (output)
#define VS1053_DCS     15     // VS1053 Data/command select pin (output)
#define CARDCS          2     // Card chip select pin
#define VS1053_DREQ     0     // VS1053 Data request, ideally an Interrupt pin

// Feather ESP32
#elif defined(ESP32)
#define VS1053_CS      32     // VS1053 chip select pin (output)
#define VS1053_DCS     33     // VS1053 Data/command select pin (output)
#define CARDCS         14     // Card chip select pin
#define VS1053_DREQ    15     // VS1053 Data request, ideally an Interrupt pin

// Feather Teensy3
#elif defined(TEENSYDUINO)
#define VS1053_CS       3     // VS1053 chip select pin (output)
#define VS1053_DCS     10     // VS1053 Data/command select pin (output)
#define CARDCS          8     // Card chip select pin
#define VS1053_DREQ     4     // VS1053 Data request, ideally an Interrupt pin

// WICED feather
#elif defined(ARDUINO_STM32_FEATHER)
#define VS1053_CS       PC7     // VS1053 chip select pin (output)
#define VS1053_DCS      PB4     // VS1053 Data/command select pin (output)
#define CARDCS          PC5     // Card chip select pin
#define VS1053_DREQ     PA15    // VS1053 Data request, ideally an Interrupt pin

#elif defined(ARDUINO_NRF52832_FEATHER )
#define VS1053_CS       30     // VS1053 chip select pin (output)
#define VS1053_DCS      11     // VS1053 Data/command select pin (output)
#define CARDCS          27     // Card chip select pin
#define VS1053_DREQ     31     // VS1053 Data request, ideally an Interrupt pin

// Feather M4, M0, 328, nRF52840 or 32u4
#else
#define VS1053_CS       6     // VS1053 chip select pin (output)
#define VS1053_DCS     10     // VS1053 Data/command select pin (output)
#define CARDCS          5     // Card chip select pin
// DREQ should be an Int pin *if possible* (not possible on 32u4)
#define VS1053_DREQ     9     // VS1053 Data request, ideally an Interrupt pin

#endif
//=======================================

// use double the pixel count to manage fading the background color
const int FADE_LIMIT = (NUMPIXELS * 2);
// variables to hold Analog input pins
int myPins[] = {A1, A2, A4};
int fadeVal = 0;
int numAudioFiles = 0;

//=======================================
// NeoPixel initialization
//=======================================
// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXELPIN, NEO_GRB + NEO_KHZ800);

// colors
const uint32_t GOLD = pixels.Color(255, 215, 0);
const uint32_t ORANGE = pixels.Color(255, 105, 0);
const uint32_t PURPLE = pixels.Color(148, 0, 211);
const uint32_t RED = pixels.Color(255, 0, 0);

//=======================================

//=======================================
// music player initialization
//=======================================
Adafruit_VS1053_FilePlayer musicPlayer =
  Adafruit_VS1053_FilePlayer(VS1053_RESET, VS1053_CS, VS1053_DCS, VS1053_DREQ, CARDCS);

void setup() {

  Serial.begin(115200);
  if (TESTING) {
    // Wait for serial port to be opened, remove this line for 'standalone' operation
    while (!Serial) {
      delay(1);
    }
    delay(500);
  } else {
    delay(1000);
  }

  Serial.println("\nFlame-throwing Pumpkin");
  Serial.println("By John M. Wargo\n");

  // Set input mode for each of the pins we're using
  for (int x = 0; x < NUM_INPUT_PINS; x++) {
    pinMode(myPins[x], INPUT_PULLUP);
  }

  // NeoPixel setup
  // Use the following to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  // initialize the NeoPixel strip object
  pixels.begin();
  if (TESTING) {
    pixels.setBrightness(10);
  } else {
    // CRANK THIS UP FOR PRODUCTION USE
    pixels.setBrightness(200);
  }
  // Set all pixel colors to off
  pixels.clear();

  // Music player setup
  if (! musicPlayer.begin()) { // initialise the music player
    Serial.println(F("Couldn't find the VS1053"));
    while (1);
  }
  Serial.println(F("VS1053 found"));

  // Make a tone to indicate VS1053 is working
  musicPlayer.sineTest(0x44, 500);
  doFlash(PURPLE, 2, 500);

  //  Look for the SD card
  if (!SD.begin(CARDCS)) {
    Serial.println(F("SD failed, or not present"));
    while (1);  // don't do anything more
  }
  Serial.println("SD card OK!");

  // list files
  printDirectory(SD.open("/"), 0);

  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(VOL, VOL);

  //#if defined(__AVR_ATmega32U4__)
  //  // Timer interrupts are not suggested, better to use DREQ interrupt!
  //  // but we don't have them on the 32u4 feather...
  //  musicPlayer.useInterrupt(VS1053_FILEPLAYER_TIMER0_INT); // timer int
  //#else
  //  // If DREQ is on an interrupt pin we can do background
  //  // audio playing
  //  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  // DREQ int
  //#endif
}

void loop() {
  fadeBackground(FADE_COLOR);
  // Loop through the pin array
  for (int x = 0; x < NUM_INPUT_PINS; x++) {
    if (digitalRead(myPins[x]) == LOW) {
      switch (x) {
        case 0:
          flashLights(myPins[x]);
          break;
        case 1:
          scream(false);
          break;
        case 2:
          scream(true);
          break;
      }
    }
    delay(10);
  }
}

void doFlash(uint32_t theColor, int theCount, int theDelay) {
  for (int i = 0; i < theCount; i++) {
    pixels.fill(theColor);
    pixels.show();
    delay(theDelay);
    pixels.clear();
    pixels.show();
    delay(theDelay);
  }
}

void fadeBackground(uint32_t theColor) {
  // Runs continually in the loop, fading up and down orange
  int numLEDs;
  // called every time the device loops
  // fades up/down the base color in the pumpkin
  // increment our counter
  fadeVal ++;
  // Are we at the end of the run?
  if (fadeVal > FADE_LIMIT) {
    // then reset this to zero
    fadeVal = 0;
  }
  // Shut off all pixels
  pixels.clear();
  // then set the number of pixels we want set
  numLEDs = abs(32 - fadeVal);
  if (numLEDs > 0) {
    pixels.fill(theColor, 0, numLEDs);
    pixels.show();
    delay(10);
  }
}

void flashLights(int pin) {
  // Flash the lights RED as long as the button is pressed
  Serial.println("\nFlashing LEDs");
  pixels.fill(RED);
  pixels.show();
  // Repeat until the button is released
  while (digitalRead(pin) == LOW) {
    delay(250);
  }
  // turn off all pixels
  pixels.clear();
  // Reset the background light to the beginning
  fadeVal = NUMPIXELS;
}

void scream(bool doLights) {
  // Play a scream sound (with or without RED Lights)
  Serial.println("\nScreaming ");

  // Character array holding the root file name
  char fileName[] = "/track00#.mp3";
  // used to store the character that replaces the
  // # in the above string.
  char aChar;

  //Do the lights thing?
  if (doLights) {
    // Then go all red
    pixels.fill(RED);
  } else {
    // Otherwise go loud with orange
    pixels.fill(FADE_COLOR);
  }
  // Show the pixels (all of them)
  pixels.show();

  // select a random file number
  // build the file name (using the file number)
  // assumes we have less than 10 files
  aChar = char(48 + random(1, numAudioFiles));
  // Replace the last digit in the file name
  fileName[8] = aChar;
  // Print this to the console
  Serial.println(fileName);

  // play the sound, then wait until it's done
  musicPlayer.playFullFile(fileName);
  // NOTE: execution is blocked until the file stops playing

  // when it finished, turn off the red LEDs
  if (doLights) {
    // Turn off all the LEDs
    pixels.clear();
    // Reset the background light to the beginning
    fadeVal = NUMPIXELS;
  }
}

/// File listing helper
void printDirectory(File dir, int numTabs) {
  while (true) {
    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      //Serial.println("**nomorefiles**");
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // increment the number of audio files counter
      numAudioFiles ++;
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}
