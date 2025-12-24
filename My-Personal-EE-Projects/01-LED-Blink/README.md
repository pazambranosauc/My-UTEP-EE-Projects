# Project 1: LED Blink

## Description
My first Arduino project! Made the built-in LED blink in different patterns.

## Components
- Arduino UNO
- USB cable (Usually)
- Breadboard
- Built-in LED (pin 13)
- 2 Jumper caples
- USBasp (in my case needed)
- 1 220 Ohm Resistor

## What I Learned
- How to upload code to Arduino
- Digital output control
- Using delay() function
- Modifying example code
- Drivers
- VID/PID
- USB stacks

## Struggles 
- Arduino boootloader not working
  - I've had experience with arduino beafore and uploading my code was never a problem, but this time it gave a weird error.
  I started lookign up online, and I found my bootloader wasn't working, so I needed a USBasp programmer to burn the bootloader.
  The bootloader didn't work either, apparently the USBasp didn't had the right or any program at all. In order make the programmer
  work I needed to download the the driver libusbk into the programmer, for this I used zadig. Even after all this the arduino
  wasn't able to receive any code, so I decided uploading my code using the USBasp programmer each time. It might not look pretty
  but it's functional.

## Date
December 2025
