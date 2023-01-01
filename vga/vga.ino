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

//ASCII Char Values
const char NUL = 0x00;
const char SOH = 0x01;
const char STX = 0x02;
const char ETX = 0x03;
const char ENQ = 0x04;


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
  vga.println("ESP32 VGA GPU");
  //initialize serial to get input data
  Serial.begin(921600);
}

void loop()
{
  if(Serial.available()){
    //read serial input
    char input = Serial.read();

    if(input==0x00){
      vga.setCursor(0,0);
      vga.clear(0);
    }else{
      vga.print(input);
    }



    //Code for String inputs (Note: Very slow)
    /*
    String strinput = Serial.readString();
  
    if(strinput == "clear"){
      vga.setCursor(0,0);
      vga.clear(0);
    }
    if(strinput == "\n"){
      vga.println("");
    }

    vga.print(strinput.c_str());
    */
  }
}