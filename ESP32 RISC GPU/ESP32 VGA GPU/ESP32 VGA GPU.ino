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
const char NUL = 0x00;  //null
const char SOH = 0x01;  //start of header
const char STX = 0x02;  //start of text
const char ETX = 0x03;  //end of text
const char EOT = 0x04;  //end of transmission
const char ENQ = 0x05;  //enquiry
const char ACK = 0x06;  //acknowledge
const char BEL = 0x07; 	//bell (ring)
const char BS  = 0x08; 	//backspace
const char HT  = 0x09; 	//horizontal tab
const char LF  = 0x0A;  //line feed
const char VT  = 0x0B;	//vertical tab
const char FF  = 0x0C; 	//form feed
const char CR  = 0x0D; 	//carriage return
const char SO  = 0x0E; 	//shift out
const char SI  = 0x0F; 	//shift in
const char DLE = 0x10;  //data link escape
const char DC1 = 0x11;	//device control 1
const char DC2 = 0x12;	//device control 2
const char DC3 = 0x13;	//device control 3
const char DC4 = 0x14;	//device control 4
const char NAK = 0x15;	//negative acknowledge
const char SYN = 0x16;	//synchronize
const char ETB = 0x17;	//end transmission block
const char CAN = 0x18;	//cancel
const char EM  = 0x19;	//end of medium
const char SUB = 0x1A;	//substitute
const char ESC = 0x1B;	//escape
const char FS  = 0x1C;	//file separator
const char GS  = 0x1D;	//group separator
const char RS  = 0x1E;	//record separator
const char US  = 0x1F;	//unit separator
const char DEL = 0x7F;	//delete (rubout)

//Custom Char Values
const char RSFH = 0x80;	//Refresh
const char GFX  = 0x81; //Graphics

const char BUF0 = 0x82; //Buffer 0
const char BUF1 = 0x83; //Buffer 1
const char BUF2 = 0x84; //Buffer 2






//VGA Device
VGA3Bit vga;

void setup()
{
  //vga.setFrameBufferCount(2);   //Double buffering for performance
	
  //initializing vga at the specified pins
	vga.init(vga.MODE320x240, redPin, greenPin, bluePin, hsyncPin, vsyncPin);
	//selecting the font
	vga.setFont(Font6x8);
	//displaying the text
	vga.println("Monitor Check");
  vga.println("ESP32 VGA GPU");
  vga.println("ESP32 VGA GPU");
  vga.println("ESP32 VGA GPU");
  vga.println("ESP32 VGA GPU");
  vga.println("ESP32 VGA GPU");
  vga.println("ESP32 VGA GPU");
  vga.println("ESP32 VGA GPU");
  //initialize serial to get input data
  Serial.begin(921600);
}

void loop()
{
  if(Serial.available()){
    //read serial input
    char input = Serial.read();


    switch (input) {
      case RSFH:
        vga.clear(0);       //Clears Screen
        vga.setCursor(0,0); //Re Position Cursor to top left
        break;
      case NUL:
        vga.print("Null");
        break;
      case SOH:
        vga.print("Start of Heading");
        break;
      case LF:
        vga.println("");  //Next Line
        break;
      default:
        vga.print(input);
        break;
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