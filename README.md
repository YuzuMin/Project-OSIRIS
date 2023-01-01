# Project OSIRIS
 A New Beginning with a series of small microcontroller projects

# ESP32 RISC GPU
The ESP32 GPU receives data via UART and outputs it to a VGA Display via i2c 

### Documentation
<b> NOTE : This code only supports ESP32 </b>

Custom Commands
~~~cpp
//ASCII Char Values
const char NUL = 0x00; //Clears the monitor and returns cursor to 0,0
const char  LF = 0x10; //Newline
~~~

UART Input Wiring
~~~cpp
const int RX = 1;
const int TX = 3;
~~~


3-Bit VGA Output Wiring
~~~cpp
const int redPin = 27;
const int greenPin = 14;
const int bluePin = 12;
const int hsyncPin = 32;
const int vsyncPin = 33;
~~~
### Acknowledgements
This project heavily relies on Bitluni's <a href="https://github.com/bitluni/ESP32Lib"> ESP32lib</a>.

### License
YuzuMin 2023
Creative Commons Attribution ShareAlike 4.0
https://creativecommons.org/licenses/by-sa/4.0/
