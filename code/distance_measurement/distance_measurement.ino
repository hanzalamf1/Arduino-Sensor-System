#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  

const int trigPin = 7;  // Trig pin
const int echoPin = 6;  // Echo pin
const int buzzerPin = 8; // Buzzer pin
const int ledPin = 13;   // LED pin

void setup() {
  lcd.init();      
  lcd.backlight();  

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  pinMode(buzzerPin, OUTPUT); 
  pinMode(ledPin, OUTPUT);  

  lcd.setCursor(0, 0); 
  lcd.print("Calculate Dist:");
  delay(2000);
}

void alertSystem(int delayTime) {
  if (delayTime == -1) {
    tone(buzzerPin, 1000); 
    digitalWrite(ledPin, HIGH);
  } else if (delayTime > 0) {
    tone(buzzerPin, 1000);
    digitalWrite(ledPin, HIGH);
    delay(delayTime);
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    delay(delayTime);
  } else {
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
  }
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration * 0.0343) / 2; 

  lcd.setCursor(0, 1);
  lcd.print("Distance:   ");
  lcd.setCursor(10, 1);
  lcd.print(distance);
  lcd.print(" cm");

 if (distance <= 3) { 
    alertSystem(-1); 
  } else if (distance < 5) {
    alertSystem(50);
  } else if (distance < 10) {
    alertSystem(100);
  } else if (distance < 15) {
    alertSystem(150);
  } else if (distance < 20) {
    alertSystem(200);
  } else if (distance < 25) {
    alertSystem(250);
  } else if (distance < 30) {
    alertSystem(300);
  } else if (distance < 40) {
    alertSystem(350);
  } else if (distance < 50) {
    alertSystem(400);
  } else {
    alertSystem(0);
  }

  delay(200);

}
