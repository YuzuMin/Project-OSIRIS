# Project OSIRIS
 A New Beginning with a series of small microcontroller projects

# ESP32 RISC GPU
The ESP32 GPU receives data via UART and outputs VGA over I²S.

### Installation

This library only supports the ESP32.
To install the ESP32 features in the board manager you need to add an additional Boards Manager URL in the Preferences (File -> Preferences)
```
https://dl.espressif.com/dl/package_esp32_index.json
```
The ESP32Lib can be found in the Library Manager (Sketch -> Include Library -> Manage Libaries)
To be able to use the library featues the main header needs to included in the sketch
```cpp
#include <ESP32Lib.h>
```

### Documentation

Custom Commands
~~~cpp
//ASCII Char Values
const char NUL = 0x80; //Clears the monitor and returns cursor to 0,0
const char  LF = 0x10; //Newline
~~~

UART Pin Configuration
~~~cpp
const int RX = 1;
const int TX = 3;
~~~


3-Bit VGA Pin Configuration
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
