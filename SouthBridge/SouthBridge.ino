/*
- Blue User LED: On GP25, available to user
- RGB WS2812 LED: On GP23
- USR Button : On GP24 (Connected to GND)
*/

#include <Adafruit_NeoPixel.h>
#define RELAY_PIN    25
#define BUTTON_PIN   24  // Builtin USR Button
#define PIXEL_PIN    23  // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT   1  // Number of NeoPixels
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

int wakeup = 22;
int mask8bit[] = {1, 2, 4, 8, 16, 32, 64, 128};
int mask16bit[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

//SouthBridge Controller Details
String supportedSocket[] = {"PGA3152","PGB3152"}; //Pin Grid (Gen) A 31pin by 52pin (26pin DIP)
String cpuSeries = "NewTYPE Ampere"; // NewTYPE (Uses Microcontroller board instead of bare cpu chip) Ampere (Gen 1 Processors) 
String cpuSpeed = "133Mhz"; //CPU Speed
String cpuClass = "A168"; // (A/B/H/Z LOW/Basic/High/Overclock) (168 = 16addr|8data) (+ for 2nd gen)
String cpuArchitecture = "Nightingale"; //Multiplexed Address and Data Lines (E.g. Zen+)

//SouthBridge μP Details
String southBridgeCore = "Arm Cortex M0+"; //Actual Processor
String southBridgeInstructionSet = "Thumb-2"; //Actual Instruction Set


// Core 1 Setup (Secondary Core)
void setup1() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), RGBLED_green, FALLING);
  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.show();  // Initialize all pixels to 'off'
  Serial.begin(9600);
}

// Core 1 Loop (Secondary Core)
void loop1() {
  RGBLED_rainbow(100);
}



// Core 0 Setup (Main Core)
void setup(void) {


   pinMode(BUTTON_PIN, INPUT_PULLUP);
   

   pinMode(RELAY_PIN,OUTPUT);
   digitalWrite(RELAY_PIN,HIGH);
}

// Core 0 Loop (Main Core)
void loop(void) {

      // turn the LED on (HIGH is the voltage level)
  digitalWrite(RELAY_PIN, HIGH);

  // wait for a second
  delay(500);

  // turn the LED off by making the voltage LOW
  digitalWrite(RELAY_PIN, LOW);

   // wait for a second
  delay(500);
}


void RGBLED_green() {
  strip.setPixelColor(0, (strip.gamma32(strip.Color(0,160,0))));  //Pass (Red , Green , Blue) thru gamma32 for better colours
  strip.show(); // Update strip with new contents
  delay(1000);  // Pause for a moment
}

void RGBLED_rainbow(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 3*65536; firstPixelHue += 256) {
    int pixelHue = firstPixelHue + (0 * 65536L / strip.numPixels());
    strip.setPixelColor(0, (strip.gamma32(strip.ColorHSV(pixelHue,160,96)))); //Pass (Hue , Saturation , Brightness) thru gamma32 for better colours
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}

void bios_init(){
  //Get CPU details
  //Setup Accordingly to match CPU used
  // 
  strip.setPixelColor(0, (strip.gamma32(strip.Color(0,0,255))));  //Pass (Red , Green , Blue) thru gamma32 for better colours
  strip.show(); // Update strip with new contents
  delay(1000);  // Pause for a moment
}


