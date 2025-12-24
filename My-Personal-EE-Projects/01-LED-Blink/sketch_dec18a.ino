int green_LED = 13;

void setup()
{
  pinMode(green_LED, OUTPUT);
}

void loop()
{
  digitalWrite(green_LED, HIGH);
  delay(1000); 
  digitalWrite(green_LED, LOW);
  delay(1000);

}