#include <Wire.h>

void setup() {
  Serial.begin(9600);  
  Wire.begin();        
  Serial.println("\nI2C Scanner");
}

void loop() {
  byte error, address;
  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address: 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
      delay(1000); 
    }
  }
}
