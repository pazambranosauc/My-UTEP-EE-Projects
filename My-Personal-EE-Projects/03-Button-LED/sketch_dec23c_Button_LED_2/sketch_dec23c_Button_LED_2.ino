const int buttonPin = 2;
const int ledPin = 13;

int buttonState = 0;
int lastButtonState = 0;
int ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  // Check if button state changed from HIGH to LOW (pressed)
  if (buttonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;  // Toggle LED state
    digitalWrite(ledPin, ledState);
    Serial.println(ledState ? "LED ON" : "LED OFF");
    delay(50);  // Debounce delay
  }
  
  lastButtonState = buttonState;
}