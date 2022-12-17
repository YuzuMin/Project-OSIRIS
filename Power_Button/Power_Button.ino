#define BUTTON_PIN 3
#define RELAY_PIN 2

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
