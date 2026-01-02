#include <SPI.h>

#define CS_PIN 25
#define RESET_PIN 24
#define MBUSY_PIN 0

void setup() {
  pinMode(CS_PIN, OUTPUT);
  pinMode(RESET_PIN, OUTPUT);
  pinMode(MBUSY_PIN, INPUT);

  SPI.begin();
  digitalWrite(CS_PIN, HIGH);
  // Hardware reset
  digitalWrite(RESET_PIN, LOW);
  delay(5);
  digitalWrite(RESET_PIN, HIGH);
  // delay(50);

  // Wait for display ready
  while (digitalRead(MBUSY_PIN) == HIGH) {}
  delay(5);
  // /CS pulse
  digitalWrite(CS_PIN, LOW);
  // Send data write prefix
  SPI.transfer(0x44);
  // Initialize
  SPI.transfer(0x1B);
  SPI.transfer(0x40);
  delay(50);
  digitalWrite(CS_PIN, HIGH);


  while (digitalRead(MBUSY_PIN) == HIGH) {}
  delay(5);
  // /CS pulse
  digitalWrite(CS_PIN, LOW);
  // Send data write prefix
  SPI.transfer(0x44);
  // 
  SPI.transfer(0x1F);
  SPI.transfer(0x40);
  delay(50);
  digitalWrite(CS_PIN, HIGH);


}

void loop() {}
