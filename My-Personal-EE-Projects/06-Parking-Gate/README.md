# Project 6: Parking Gate Project

## Description
This project is meant to simulate a parking gate with a simple functioning, the car approaches, light changes from red on to green on,
then the gate opens for couple seconds. I added a car counting feature, which tells you the amount of spaces left. I 3D designed and 
printed the gate stick using Fusion 360 and an Ender 3, but it can replaced with a wooden stick or something alike. I wanted to use
IR sensors for it to work entering and leaving the parking lot, but since I don't have any I will improve it once I get some.
This project was mainly educative for me. I wanted to implent servos to learn about their wiring and coding to later implement them in 
more complex future projects.

## Components
- Arduino UNO
- USB cable (Make readings and display text on the LCD screen)
- Breadboard
- HC-SR04 (Ultrasonic Sensor)
- LCD Screen
- Red LED (pin ??)
- 8 Male-to-Female jumper wires (for LCD connection and sen)
- 7 Jumper wires (I used 2 wires just to hold the Arduino microcontroller)
- USBasp (to upload code with programmer)
- 1 220 Ohm Resistor
- 1 1k Ohm Resistor
- 1 micro servo (I used an SG90)

## Component Wiring
-  Distance sensor:
  - VCC → 5V
  - Trig → pin 9
  - Echo → pin 10
  - GND → Ground
-  LCD screen:
  - GND → Ground
  - VCC → 5V
  - SDA → A4
  - SLC → A5
- Micro Servo:
  - GND → GND
  - VCC → 5v
  - Data → pin 8
- LEDs:
  - GND → Red LED → 220Ω resistor → 5V
  - GND → Green LED → 1kΩ resistor → 5V

## What I Learned
  - How to correctly setup and wire a servo.
  - Combine mutiple sensors to make something manage data.
## Problems
I struggle with the 3D printing precision. I have 3D printed before but didn't need milimeter precision.
That was really educative, since 3D printing usually makes a desing thicker or taller and sometimes curved.
This just means I have to keep practicing and trying new things to take those erros into account beforehand.

## Videos of the project
Parking Gate prject progress: https://www.youtube.com/watch?v=zLpb_QMXn3A
Parking Gate Final Result: https://www.youtube.com/watch?v=Quojk_kl2gg

## Date
March 2026
