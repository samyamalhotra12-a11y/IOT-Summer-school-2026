# River Water Level Alert System (Flood Detection using ESP32)

## Problem Statement

Floods caused by rising river water levels can result in severe damage to life, property, and agriculture if timely warnings are not provided. Traditional monitoring methods often require manual observation, which may not be reliable during emergencies. The objective of this project is to develop an IoT-based River Water Level Alert System that continuously monitors water level using an ultrasonic sensor and generates early warning alerts. The collected data is also uploaded to the cloud for real-time monitoring and analysis.

---

## Solution Approach

The system is built around the ESP32 microcontroller and an HC-SR04 ultrasonic sensor. The ultrasonic sensor continuously measures the distance between itself and the water surface. As the water level rises, the measured distance decreases.

The ESP32 processes these readings and calculates a rolling average to reduce fluctuations caused by sensor noise. Based on predefined threshold values, the controller classifies the water level into three stages:

- **Normal** – Safe water level
- **Warning** – Water level increasing
- **Critical** – High risk of flooding

Visual and audible alerts are generated using LEDs and a buzzer. The measured distance and alert status are transmitted to ThingSpeak using HTTP requests, allowing remote monitoring through cloud dashboards.

---

## Hardware Required

- ESP32 Development Board
- HC-SR04 Ultrasonic Sensor
- Active Buzzer
- Green LED
- Yellow LED
- Red LED
- 220Ω Resistors
- Breadboard
- Jumper Wires
- USB Cable

---

## Circuit Connections

| Component | ESP32 Pin |
|-----------|-----------|
| HC-SR04 TRIG | GPIO 5 |
| HC-SR04 ECHO | GPIO 18 |
| Buzzer | GPIO 4 |
| Green LED | GPIO 12 |
| Yellow LED | GPIO 13 |
| Red LED | GPIO 14 |

---

## Circuit Diagram

```
                   +----------------------+
                   |        ESP32         |
                   |                      |
 TRIG -----------> | GPIO 5              |
 ECHO -----------> | GPIO 18             |
 Buzzer ---------> | GPIO 4              |
 Green LED ------> | GPIO 12             |
 Yellow LED -----> | GPIO 13             |
 Red LED --------> | GPIO 14             |
                   +----------------------+

            HC-SR04 Ultrasonic Sensor
         +------------------------------+
         | VCC  -> 5V                   |
         | GND  -> GND                  |
         | TRIG -> GPIO 5               |
         | ECHO -> GPIO 18              |
         +------------------------------+

 Green LED  (GPIO12) ----220Ω---->|----GND
 Yellow LED (GPIO13) ----220Ω---->|----GND
 Red LED    (GPIO14) ----220Ω---->|----GND

 Buzzer (+) -------- GPIO4
 Buzzer (-) -------- GND
```

---

## Features

- Continuous Water Level Monitoring
- HC-SR04 Ultrasonic Distance Measurement
- Rolling Average for Stable Readings
- Three-Level Flood Alert System
- Green, Yellow and Red LED Indicators
- Audible Alarm using Buzzer
- Real-Time ThingSpeak Cloud Updates
- Serial Monitor Debug Information
- HTTP-Based Data Transmission
- Easy Integration with IoT Dashboards

---

## Working Principle

1. The HC-SR04 sensor measures the distance between the sensor and the water surface.
2. The ESP32 calculates both the current distance and a rolling average.
3. The measured value is compared with predefined thresholds.
4. According to the water level, the system activates the appropriate LED and buzzer alert.
5. Distance values and alert levels are uploaded to ThingSpeak for remote monitoring.
6. The Serial Monitor displays live readings and server response.

---

## Alert Levels

| Status | Distance |
|---------|----------|
| 🟢 Normal | Greater than 30 cm |
| 🟡 Warning | 15 – 30 cm |
| 🔴 Critical | Less than 15 cm |

---

## Cloud Integration (ThingSpeak)

Create a ThingSpeak channel and configure the following fields:

```
Field 1 : Distance
Field 2 : Alert Level
```

Replace your Write API Key in the Arduino code:

```cpp
String apiKey = "YOUR_API_KEY";
```

---

## Sample Serial Monitor Output

```
Water Distance : 14 cm
Average Distance : 16 cm

Flood Status : CRITICAL

Uploading Data...
HTTP Response Code : 200
```

---

## Security Note

- Store API keys in a separate `secrets.h` file.
- Add the file to `.gitignore`.
- Never upload confidential API keys to public GitHub repositories.

---


---

## Author

**Samya Malhotra**

