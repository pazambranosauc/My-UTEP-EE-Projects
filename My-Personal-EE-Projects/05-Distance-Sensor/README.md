# Project 5: Distance sensor with Praking sensor project

## Description
This project uses a distance sensor to then display the distance in an LCD screen.
It also triggers an LED and a buzzer to activate at a certain distance (15 centemeters).
The distance is measured from the reading of the echo of the distance sensor, with pulseIn(echoPin, HIGH);
It is then saved in the variable duration. 
Then it is multiplied by the speed of sound 343m/s or .0343 cm per µs, because it uses an ultrasonic sensor to find duration.
It also finally divides by 20000, or 2 * 10000. It divide by 2 for the sound to go and come back, and by 10000
to display distance in  centimeter. This is save in the varaible distance like this distance = duration * 343 / 20000;
There is a second part of the project wich simulates a parking sensor increasing the speed of the beep and LED blink the 
closer the car is.

## Components
- Arduino UNO
- USB cable (Make readings and display text on the LCD screen)
- Breadboard
- HC-SR04 (Distance sensor)
- LCD Screen
- Buzzer (make the beep noise)
- Red LED (pin 13)
- 4 Male-to-Female jumper wires (for LCD connection)
- 10 Jumper wires 
- USBasp (to upload code with programmer)
- 1 220 Ohm Resistor

## Component Wiring
-  Distance sensor:
          VCC → V source or 5v
          Trigger → pin 9
          Echo → pin 10
          GND → Ground
-  Buzzer:
          + → pin 11
          - → Ground
-  LCD screen:
          GND → Ground
          VCC → V source or 5v
          SDA → A4
          SCL → A5

## What I Learned
- How ultrasonic sensors work.
- How to wire and setup the code for the Distance sensor.
- How to wire the buzzer.
- Using the tone(pin, 1000); function
-Implemeting math calculations to display distance in different units. 

## Date
January 2026
