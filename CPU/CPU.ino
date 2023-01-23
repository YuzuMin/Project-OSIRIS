/*
- Blue User LED: On GP25, available to user
- RGB WS2812 LED: On GP23
- USR Button : On GP24 (Connected to GND)
*/

#include <Adafruit_NeoPixel.h>
#define USER_BTN     24  // Builtin USR Button
#define PIXEL_PIN    23  // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT   1  // Number of NeoPixels

//Mono-Directional Address Pins
#define A0    0
#define A1    1
#define A2    2
#define A3    3
#define A4    4
#define A5    5
#define A6    6
#define A7    7
#define A8    8
#define A9    9
#define A10  10
#define A11  11
#define A12  12
#define A13  13
#define A14  14
#define A15  15

//Bi-Directional Data Pins
#define D0  13
#define D1  12
#define D2  11
#define D3  10
#define D4   9
#define D5   8
#define D6   7
#define D7   6


//Control Pins
#define WAKE_UP  22 //Enable PC BOOT
#define ALE      23 //Address Latch Enable (Active High) (Shared with Pixel Pin)

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

int dataBus[8] = {D0, D1, D2, D3, D4, D5, D6, D7};
int addressBus[16] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15};

int wakeup = 22;
int mask8bit[] = {1, 2, 4, 8, 16, 32, 64, 128};
int mask16bit[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

//CPU Details
String cpuSocket = "PGA3152"; //Pin Grid (Gen) A 31pin by 52pin (26pin DIP)
String cpuSeries = "NewTYPE Ampere"; // NewTYPE (Uses Microcontroller board instead of bare cpu chip) Ampere (Gen 1 Processors)
String cpuSpeed = "133Mhz"; //CPU Speed
String cpuClass = "A168"; // (A/B/H/Z LOW/Basic/High/Overclock) (168 = 16addr|8data) (+ for 2nd gen)
String cpuArchitecture = "Nightingale"; //Multiplexed Address and Data Lines (E.g. Zen+)

//CPU μP Details
String cpuCore = "Arm Cortex M0+"; //Actual Processor
String cpuInstructionSet = "Thumb-2"; //Actual Instruction Set




// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  addressOutput(43690);
}

// the loop function runs over and over again forever
void loop() {
  delay(1000);                      // wait for a second
  //addressOutput(43690);
}

/*
// Core 1 Setup (Secondary Core)
void setup1() {
  pinMode(USER_BTN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(USER_BTN), RGBLED_green, FALLING);
  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.show();  // Initialize all pixels to 'off'
}

// Core 1 Loop (Secondary Core)
void loop1() {
  RGBLED_rainbow(100);
}
*/


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


void addressOutput(int addr){
  pinMode(ALE, OUTPUT);  //Setup Address Latch pin as output
  digitalWrite(ALE, HIGH); //Enable Address Latch

  //Setup AD pins as output 
  for(int i = 0; i<16; i++){
    pinMode(addressBus[i],OUTPUT);
    Serial.println(addressBus[i]);
  }

  //Output Address
  for(int i = 0; i<16; i++){
    Serial.print(addressBus[i]);
    if((addr&mask16bit[i])==mask16bit[i]){
      digitalWrite(addressBus[i], HIGH);
      Serial.print("Mask: ");
      Serial.println(mask16bit[i]);
      Serial.print("Masked: ");
      Serial.println(addr&mask16bit[i]);
      Serial.print("Address: ");
      Serial.println(addr);
      //Serial.print(1);
    }else{
      digitalWrite(addressBus[i], LOW);
      //Serial.print(0);
    }
  }
  Serial.println("");


  digitalWrite(ALE, LOW); //Disable Address Latch
}
