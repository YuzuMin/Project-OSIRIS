
void setup() {
  // initialize serial:
  Serial.begin(921600);
}

void loop() {
  delay(5000);
  Serial.write(0x00);
  delay(1000);
  Serial.write("Hello World");
  delay(5000);
  Serial.write(0x00);
  Serial.write(0x01);
  delay(1000);
  Serial.write(0x10);
  Serial.write("Hello World");
}
