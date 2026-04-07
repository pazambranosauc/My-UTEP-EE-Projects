# Project 8: ESP-32 Game Console

## Description
This project recreates a basic game console environment on an ESP-32 using low-level graphics rendering and real-time input handling. This project has 
a multi-screen menu architecture displayed on a SSD1306 OLED display, controlled with a joystick, 
facilitating the game scroll, and gameplay for fure games. This project was developed using the ESP-IDF framework and leverages FreeRTOS for task scheduling.
Different from my previous project which were all in Arduino IDE with the basic libraries. I decided to this to start using the ESPRESSIF-IDE in order to fully
understand the ESP=32 and take advantage of its full potential, which the Arduino IDE would limitate me to do. I implemented a rendering pipeline for drawing
text, shapes, and sprites directly to the display, facilitating dynamic screen uptdates and simple animations. 
I'm looking forward to keep implementing Flappy bird, Tetris, the snake game, and make them functional. 

This project was mainly meant for me to learn about the usage of ESP, and its softwasre, ESPRESSIF-IDE. I knew it was more powerfull and its WI-FI and Bloothoth
feature. I expexted to be complex, and it really was. While Arduino is easy and accesible, this one requires more skill with not just coding, but data and folder managment,
VS Code and terminal usage, and more complex set of library usage. This project is teaching me a lot. 

From this project I'm also seeking to learn about control an OLED display, draw graphics and text using pixels, handle user input with a joystick, organize code using multiple screens and states.
This project is also meant to help me improve my EE-Calculator project adding more features and formulas. And it will be fundamental knowledge for more complex future projects.

## Components
- ESP-32 (WROOM-32 DevKitC v4)
- USB cable
- Breadboard
- SSD1306 OLED display
- 12 Jumper wires
- KY-023 joystick

## Component Wiring
| Signal | ESP32 GPIO |
|--------|-----------|
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 | 
| OLED VCC | 3.3 V |
| OLED GND | GND |
| Joystick VRX | GPIO 34 |
| Joystick VRY | GPIO 35 |
| Joystick SW | GPIO 32 | 
| Joystick VCC | 3.3 V |
| Joystick GND | GND |

## What I Learned 


## Problems 

## Videos of the project

## Date
April 2026
