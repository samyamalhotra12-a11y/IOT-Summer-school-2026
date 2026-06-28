BLE Sensor Dashboard

Board

ESP32

Sensor

DHT11 (DHT22 used for Wokwi simulation)

Update Interval

3 seconds

BLE Service UUID

12345678-1234-1234-1234-1234567890AB

Characteristics

Characteristic	UUID

Temperature	12345678-1234-1234-1234-1234567890AC

Humidity	12345678-1234-1234-1234-1234567890AD

Timestamp	12345678-1234-1234-1234-1234567890AE

BLE Scanner Apps

nRF Connect

LightBlue

Simulation Note: This project was developed using Wokwi with an ESP32 and a DHT22 sensor (used in place of DHT11 for simulation). Bluetooth Low Energy (BLE) advertising and GATT services cannot be fully simulated in Wokwi. The code is intended to run on a physical ESP32, where it can be tested using BLE scanner applications such as nRF Connect or LightBlue.
