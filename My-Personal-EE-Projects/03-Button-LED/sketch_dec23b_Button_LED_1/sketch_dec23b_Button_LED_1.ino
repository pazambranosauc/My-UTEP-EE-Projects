const int buttonPin = 2;
const int ledPin = 13;

int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Using internal pull-up
  Serial.begin(9600);  // Start serial communication
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {  
    digitalWrite(ledPin, HIGH);
    Serial.println("Button pressed - LED ON");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Button released - LED OFF");
  }
  
  delay(50);  // Small delay for stability
}