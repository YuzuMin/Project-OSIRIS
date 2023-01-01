//This example shows a simple "Hello world!" on a VGA screen.
//You need to connect a VGA screen cable to the pins specified below.
//cc by-sa 4.0 license
//bitluni

#include <ESP32Lib.h>
#include <Ressources/Font6x8.h>

//pin configuration
const int redPin = 27;
const int greenPin = 14;
const int bluePin = 12;
const int hsyncPin = 32;
const int vsyncPin = 33;

//VGA Device
VGA3Bit vga;

void setup()
{

	//initializing vga at the specified pins
	vga.init(vga.MODE320x240, redPin, greenPin, bluePin, hsyncPin, vsyncPin);
	//selecting the font
	vga.setFont(Font6x8);
	//displaying the text
	vga.println("Hello World!");
  Serial.begin(921600);
}

void loop()
{
  if(Serial.available()){
    char input = Serial.read();
    vga.print(input);

    
    if(input==' '){
      Serial.println("space");
      vga.setCursor(0,0);
      vga.clear(0);
    }
    }
}