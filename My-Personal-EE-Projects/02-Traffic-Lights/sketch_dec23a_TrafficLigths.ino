int red_LED = 13;
int yellow_LED = 12;
int green_LED = 11;

void setup()
{
  pinMode(red_LED, OUTPUT);
  pinMode(yellow_LED, OUTPUT);
  pinMode(green_LED, OUTPUT);
}

void loop()
{
  digitalWrite(green_LED, HIGH);
  delay(5000); 
  digitalWrite(green_LED, LOW);
  digitalWrite(yellow_LED, HIGH);
  delay(500); 
  digitalWrite(yellow_LED, LOW);
  delay(500);
  digitalWrite(yellow_LED, HIGH);
  delay(500); 
  digitalWrite(yellow_LED, LOW);
  delay(500);
  digitalWrite(yellow_LED, HIGH);
  delay(500); 
  digitalWrite(yellow_LED, LOW);
  delay(500);
  digitalWrite(red_LED, HIGH);
  delay(5000);
  digitalWrite(red_LED, LOW);
}