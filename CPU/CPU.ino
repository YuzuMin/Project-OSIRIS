int wakeup = 22;
int addressLatchEn = 23; //Active High
int mask8bit[] = {1, 2, 4, 8, 16, 32, 64, 128};
int mask16bit[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};
String  cpuClass = "Moby Dick / VIVY / UNICORN / NewTYPE Itanium" 

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, LOW);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  addressOutput(170);
  delay(1000);                      // wait for a second
}


void addressOutput(int addr){
  pinMode(addressLatchEn, OUTPUT);  //Setup Address Latch pin as output

  //Setup AD pins as output 
  /*for(int i = 15; i>=0; i--){
    pinMode(i,OUTPUT);
  }*/

  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(0,OUTPUT);



  digitalWrite(addressLatchEn, HIGH); //Enable Address Latch

  //Output Address
  /*
  for(int i = 15; i>=0; i--){
    if((addr&mask16bit[i])==mask16bit[i]){
      digitalWrite(i, HIGH);
    }else{
      digitalWrite(i, LOW);
    }
  }
  */
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);

  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);


}
