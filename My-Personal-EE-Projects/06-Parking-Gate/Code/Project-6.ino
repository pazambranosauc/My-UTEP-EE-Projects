#include <LiquidCrystal_I2C.h>  
#include <Servo.h>              


const int servoPin = 8;
const int trigPin = 9;
const int echoPin = 10;     
const int RedLed = 12;
const int GreenLed = 13;

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Create Servo object to control the gate
Servo myServo;

// Variables used for ultrasonic sensor
long duration;  // Time it takes for sound to travel to object and back
int distance;   // Calculated distance in centimeters

int ParkingSpace = 5;  // Maximum number of parking spaces available

// Timing variables to avoid counting the same car multiple times
unsigned long lastDetection = 0;  // Stores last time a car was detected
const int cooldown = 3000;       // Wait time (3 seconds) before detecting again

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  myServo.attach(servoPin); // Connect servo object to its pin
  myServo.write(0); // Set servo to 0 degrees (gate closed at start)

  updateDisplay(); // Show initial parking spaces on LCD
}

void loop() {

  // The trigger pin sends a short pulse to start measurement
  digitalWrite(trigPin, LOW);   // Ensure trigger is LOW
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);  // Send HIGH pulse (start signal)
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);   // Stop pulse

  duration = pulseIn(echoPin, HIGH);    // pulseIn() measures how long the echo pin stays HIGH. This represents the time taken for sound to return
  distance = duration * 0.034 / 2;    // Speed of sound = 0.034 cm per microsecond. Divide by 2 because signal travels to object AND back

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If something is detected within 10 cm, assume it's a car
  if (distance > 0 && distance < 10) {

    // Check cooldown so we don't count the same car multiple times
    if (millis() - lastDetection > cooldown) {

      // If there is at least 1 parking space available
      if (ParkingSpace > 0) {

        ParkingSpace--;

        openGate();
        updateDisplay();

      } else {
        // If no space left, show full alert
        parkingFullAlert();
      }

      // Save current time as last detection
      lastDetection = millis();
    }
  }
}

// Function to control gate using servo
void openGate() {

  digitalWrite(GreenLed, HIGH);
  digitalWrite(RedLed, LOW);

  myServo.write(90); // Rotate servo to 90 degrees (gate open)
  delay(2000);

  myServo.write(0);  // Return servo to 0 degrees (gate closed)
  delay(500);

  digitalWrite(GreenLed, LOW);
}

// Function to update LCD display
void updateDisplay() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Spaces Left:");

  lcd.setCursor(0, 1);
  lcd.print(ParkingSpace);

  // If no spaces left, override message
  if (ParkingSpace == 0) {
    lcd.setCursor(0, 1);
    lcd.print("Parking Full");

    digitalWrite(RedLed, HIGH);
    digitalWrite(GreenLed, LOW);
  }
}

// Function when parking is full
void parkingFullAlert() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Spaces Left: 0");

  lcd.setCursor(0, 1);
  lcd.print("Parking Full");

  digitalWrite(RedLed, HIGH);
  digitalWrite(GreenLed, LOW);
}