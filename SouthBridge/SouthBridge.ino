/*
- Blue User LED: On GP25, available to user
- RGB WS2812 LED: On GP23
- USR Button : On GP24 (Connected to GND)
*/

#include <Adafruit_NeoPixel.h>
#define BUTTON_PIN 24
#define RELAY_PIN 25

#define BUTTON_PIN   24  // Builtin USR Button
#define PIXEL_PIN    23  // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT   1  // Number of NeoPixels
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

int wakeup = 22;
int mask8bit[] = {1, 2, 4, 8, 16, 32, 64, 128};
int mask16bit[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

//SouthBridge Controller Details
String supportedSocket[] = {"PGA3152","PGB3152"}; //Pin Grid (Gen) A 31pin by 52pin (26pin DIP)
String cpuSeries = "NewTYPE Ampere"; // NewTYPE (Due to complexities and bad planning) Ampere (Gen 1 Pilot) 
String cpuSpeed = "133Mhz"; //
String cpuClass = "A168"; // (A/B/H/Z LOW/Basic/High/Overclock) (168 = 16addr|8data) (+ for 2nd gen)
String cpuArchitecture = "Nightingale"; //Multiplexed Address and Data Lines (E.g. Zen+)

//SouthBridge μP Details
String southBridgeCore = "Arm Cortex M0+"; //Actual Processor
String southBridgeInstructionSet = "Thumb-2"; //Actual Instruction Set



void setup1() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.show();  // Initialize all pixels to 'off'
  Serial.begin(9600);
}
void loop1() {
  RGBLED_rainbow(100);
}




void setup(void) {

   pinMode(BUTTON_PIN, INPUT_PULLUP);
   pinMode(RELAY_PIN,OUTPUT);
   digitalWrite(RELAY_PIN,HIGH);
}

void loop(void) {
static byte toggle_sw_memmory=1;

   // Check for keypress
   if ( !digitalRead(BUTTON_PIN) ) {          // Pulled up so zero = pushed.

      delay(100);

      if ( !digitalRead(BUTTON_PIN) ) {       // if it is still pushed after a delay.
         toggle_sw_memmory = !toggle_sw_memmory;

         if (toggle_sw_memmory)
            digitalWrite(RELAY_PIN,HIGH);
         else
            digitalWrite(RELAY_PIN,LOW);
      }
      while(!digitalRead(BUTTON_PIN)); // wait for low
   }

}



void RGBLED_rainbow(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 3*65536; firstPixelHue += 256) {
    int pixelHue = firstPixelHue + (0 * 65536L / strip.numPixels());
    strip.setPixelColor(0, (strip.gamma32(strip.ColorHSV(pixelHue,160,96))));
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}




