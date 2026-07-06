# Smart Greenhouse Controller

## Problem Statement

Maintaining the ideal environmental conditions inside a greenhouse is essential for healthy flower cultivation, especially for plants such as tulips and roses. Manual monitoring of temperature, humidity, and light intensity is time-consuming and may lead to inconsistent growing conditions. The objective of this project is to develop an IoT-based Smart Greenhouse Automation System that continuously monitors these environmental parameters and automatically controls heating, ventilation, and artificial lighting to provide an optimal growing environment. The system also enables remote monitoring through MQTT, allowing users to observe greenhouse conditions from anywhere.

---

## Solution Approach

The Smart Greenhouse Automation System uses an ESP32 microcontroller as the main controller. A DHT11 sensor measures temperature and humidity, while an LDR continuously monitors light intensity. The ESP32 processes these sensor values and compares them with predefined threshold values.

Based on the readings:

- The Heater is activated when the temperature falls below the desired range.
- The Fan is switched ON when the temperature or humidity exceeds the safe limit.
- The Grow Light automatically turns ON whenever natural light is insufficient.

To improve stability, the LDR values are averaged over multiple readings, and a hysteresis-based control method is used to prevent rapid switching of devices.

The measured data and device status are displayed locally on a 16×2 I2C LCD and also published to an MQTT broker, enabling real-time remote monitoring through any MQTT dashboard.

---

## Hardware Required

- ESP32 Development Board
- DHT11 Temperature & Humidity Sensor
- LDR (Light Dependent Resistor)
- 10kΩ Resistor
- 16×2 I2C LCD Display
- 3 LEDs (Heater, Fan, Grow Light Indicators)
- Breadboard
- Jumper Wires
- USB Cable

---

## Circuit Connections

| Component | ESP32 Pin |
|-----------|-----------|
| DHT11 Data | GPIO 4 |
| LDR Output | GPIO 34 |
| Heater LED | GPIO 25 |
| Fan LED | GPIO 26 |
| Grow Light LED | GPIO 27 |
| LCD SDA | GPIO 21 |
| LCD SCL | GPIO 22 |
| LCD VCC | VIN (5V) |
| LCD GND | GND |

---

## Circuit Diagram

```
                 +----------------------+
                 |        ESP32         |
                 |                      |
        DHT11 -->| GPIO 4              |
          LDR -->| GPIO 34             |
 Heater LED ---> | GPIO 25             |
    Fan LED ---> | GPIO 26             |
 Grow Light ---> | GPIO 27             |
      LCD SDA -->| GPIO 21             |
      LCD SCL -->| GPIO 22             |
      LCD VCC -->| VIN (5V)            |
      LCD GND -->| GND                 |
                 +----------------------+

            DHT11
        +---------------+
        | VCC -> 3.3V   |
        | GND -> GND    |
        | DATA -> GPIO4 |
        +---------------+

              LDR
       3.3V
         |
        LDR
         |
 GPIO34--+----10kΩ----GND

 Heater LED (GPIO25) ----220Ω---->|----GND
 Fan LED    (GPIO26) ----220Ω---->|----GND
 Grow LED   (GPIO27) ----220Ω---->|----GND

         16x2 I2C LCD
      -------------------
      VCC -> VIN (5V)
      GND -> GND
      SDA -> GPIO21
      SCL -> GPIO22
```

---

## Features

- Real-time Temperature Monitoring
- Humidity Monitoring
- Light Intensity Monitoring
- Automatic Heater Control
- Automatic Fan Control
- Automatic Grow Light Control
- Running Average Light Calculation
- Bang-Bang Control with Hysteresis
- LCD Status Display
- Serial Monitor Output
- MQTT Cloud Monitoring
- Stable and Efficient Automation

---

## Working Principle

1. The DHT11 sensor measures temperature and humidity.
2. The LDR continuously measures ambient light intensity.
3. The ESP32 processes the sensor readings.
4. Based on threshold values, the controller automatically operates the Heater, Fan, and Grow Light.
5. Sensor values and system status are displayed on the LCD.
6. The same information is transmitted over MQTT for remote monitoring.

---



## Sample Serial Monitor Output

```
------ GREENHOUSE STATUS ------

Temperature : 21.0 °C
Humidity    : 65.0 %
Light Level : 1320

Heater      : OFF
Fan         : OFF
Grow Light  : ON
```

---



## Author

**Samya Malhotra**

