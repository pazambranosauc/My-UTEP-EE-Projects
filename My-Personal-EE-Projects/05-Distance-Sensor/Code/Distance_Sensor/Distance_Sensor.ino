#include <LiquidCrystal_I2C.h>

const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 11;
const int redLEDPin = 13;

LiquidCrystal_I2C lcd(0x27, 16, 2);

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.init();
  lcd.clear();
  lcd.backlight(); 
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send 10 microsecond pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance (cm)
  distance = duration * 343 / 20000;
  
  // Display
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.setCursor(1,0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  
  // Proximity alert (closer than 15cm)
  if (distance < 15 && distance > 0) {
    digitalWrite(redLEDPin, HIGH);
    tone(buzzerPin, 1000);  // Play tone
    Serial.println("OBJECT TOO CLOSE!");
    lcd.setCursor(2, 1);
    lcd.print("TOO CLOSE!");
  } else {
    digitalWrite(redLEDPin, LOW);
    noTone(buzzerPin);
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }
  
  delay(100);
}