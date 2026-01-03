#include "DHT.h"
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
int alertLED = 13;
int greenLED = 12;
const float TEMP_THRESHOLD = 50.0;


void setup() {
  Serial.begin(9600);
  pinMode(alertLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  Serial.println("Temperature and Humidity Monitor");
  dht.begin();
  lcd.init();
  lcd.clear();
  lcd.backlight(); 
}

void loop() {
  delay(5000);  // Wait 5 seconds between readings
  
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();  // Celsius
  float temperatureF = dht.readTemperature(true);  // Fahrenheit
  
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from sensor!");
    return;
  }
  
  Serial.print("Humidity: ");
  Serial.print(humidity);

  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.print("°C / ");
  Serial.print(temperatureF);
  Serial.println("°F");


  lcd.setCursor(2, 0);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(2, 1);
  lcd.print("Temperature: ");
  lcd.print(temperature);
  lcd.print("C");

  if (temperature > TEMP_THRESHOLD) {
    digitalWrite(alertLED, HIGH);
    digitalWrite(greenLED, LOW);
  } else {
    digitalWrite(alertLED, LOW);
    digitalWrite(greenLED, HIGH);
  }

}