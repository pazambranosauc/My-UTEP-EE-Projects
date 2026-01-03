# Project 4: Temperature and Humidity Monitor with Screen 

## Description
This project uses the Temperature readings to then display them on the Serial Monitor and in the LCD Screen.
When the temperature goes past 50 degrees Celsius, the red LED will light up, otherwise green LED will light up.


## Components
- Arduino UNO
- USB cable (Make readings and display text on the LCD screen)
- Breadboard
- DHT11 (temperature sensor)
- LCD Screen
- Red LED (pin 13)
- Green LED (pin 12)
- 4 Male-to-Female jumper wires (for LCD connection)
- 8 Jumper wires 
- USBasp (to upload code with programmer)
- 1 220 Ohm Resistor
- 1 1k Ohms Resistor (for green LED, and make it less bright)

## Component Wiring
-  DHT11:
          S or Data → pin 2
          + → V source or 5v
          - → Ground
-  LCD screen:
          GND → Ground
          VCC → V source or 5v
          SDA → A4
          SCL → A5

## What I Learned
- How to wire and setup the code for the Temperature sensor
- How to wire and setup the code for the LCD screen
- Using the Serial.print(); function
- Using the lcd.setCursor(x,y); and lcd.print(); functions

## Struggles 
- I confused the - and + in my portoboard, which caused my DHT11 sensor to die, so I got a new one.

## Date
January 2026
