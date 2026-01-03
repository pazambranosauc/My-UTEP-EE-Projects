#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Temperature and Humidity Monitor");
  dht.begin();
}

void loop() {
  delay(2000);  // Wait 2 seconds between readings
  
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
}