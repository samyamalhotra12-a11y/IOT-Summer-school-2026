Bluetooth LED Controller (HC-05 + Arduino)

Project Description

This project controls three LEDs using Bluetooth communication between an Arduino Uno and an HC-05 Bluetooth module. Commands sent from an Android phone through a Bluetooth terminal application are received by the Arduino to control the LEDs.

Hardware Required

Arduino Uno

HC-05 Bluetooth Module

Red LED

Green LED

Blue LED

3 × 220 Ω Resistors

Jumper Wires

Breadboard

Android Phone with a Bluetooth Terminal App

Circuit Connections

HC-05 Bluetooth Module

HC-05 Pin	Arduino Uno

VCC	5V

GND	GND

TXD	D2 (SoftwareSerial RX)

RXD	D3 (SoftwareSerial TX)

LEDs

Component	Arduino Pin

Red LED	D8

Green LED	D9

Blue LED	D10

Each LED should be connected in series with a 220 Ω resistor, with the cathode connected to GND.



Pairing Instructions

Upload the Arduino program to the Arduino Uno.

Connect the HC-05 module as shown in the circuit diagram.

Power the Arduino.

Enable Bluetooth on the Android phone.

Search for HC-05 in the Bluetooth settings.

Pair using the default PIN:

1234

or 0000

Open a Bluetooth Terminal application (such as Serial Bluetooth Terminal).

Connect to the HC-05 device.

Send the commands listed below.

Bluetooth Commands

Command	Function

R	Turn Red LED ON

G	Turn Green LED ON

B	Turn Blue LED ON

X	Turn OFF all LEDs

F	Flash all LEDs 5 times

Expected Output

Sending R turns on the Red LED.

Sending G turns on the Green LED.

Sending B turns on the Blue LED.

Sending X switches off all LEDs.

Sending F flashes all three LEDs five times.

Software Used

Arduino IDE

SoftwareSerial Library

Simulation Note

The HC-05 Bluetooth module is not available in Tinkercad Circuits or Wokwi, so this project cannot be fully simulated. The repository contains the complete Arduino source code and documentation. Bluetooth pairing and communication require a physical HC-05 module and an Android phone running a Bluetooth terminal application.

Author
Name: Samya Malhotra

Repository: week4/bt_led_control/
