# Smart Home Air Quality Monitor using ESP32

## Problem Statement

A family in Milan (Europe) uses a wood-burning fireplace during winter, which can increase indoor smoke and carbon monoxide (CO) levels. The objective of this project is to design an IoT-based Smart Home Air Quality Monitoring System that continuously monitors indoor air quality using an MQ-2 gas sensor along with temperature and humidity using a DHT22 sensor. The system provides visual and audible alerts based on air quality and continues working even without an internet connection.

---

# Solution Approach

This project uses an ESP32 microcontroller to continuously monitor indoor environmental conditions.

- The **MQ-2 sensor** measures smoke/gas concentration.
- During startup, the ESP32 performs **automatic calibration** by taking 30 readings after a 10-second warm-up period to calculate a baseline value.
- The current gas value is compared with the baseline to determine the air quality.
- A **DHT22 sensor** measures temperature and humidity.
- Depending on the detected gas level:
  - Green LED indicates **Safe** condition.
  - Yellow LED indicates **Moderate** smoke.
  - Red LED indicates **Dangerous** smoke level.
- The buzzer generates different alarms according to the severity.
- Sensor readings are logged in **CSV format** on the Serial Monitor for easy analysis.
- Since all processing is performed locally on the ESP32, the system operates normally even if Wi-Fi or the internet is unavailable.

---

# Hardware Required

| Component | Quantity |
|-----------|----------|
| ESP32 DevKit V1 | 1 |
| MQ-2 Gas Sensor | 1 |
| DHT22 Temperature & Humidity Sensor | 1 |
| RGB LED (Common Cathode) | 1 |
| 220Ω Resistors | 3 |
| Active Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |
| USB Cable | 1 |

---

# Circuit Diagram

## MQ-2 Gas Sensor

| MQ-2 Pin | ESP32 Pin |
|----------|-----------|
| VCC | 5V |
| GND | GND |
| AO | GPIO34 |

---

## DHT22 Sensor

| DHT22 Pin | ESP32 Pin |
|-----------|-----------|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO4 |

---

## RGB LED

| RGB LED Pin | ESP32 Pin |
|-------------|-----------|
| Red | GPIO25 |
| Green | GPIO26 |
| Blue | GPIO27 |
| Common Cathode | GND |

*(Connect a 220Ω resistor in series with each LED pin.)*

---

## Buzzer

| Buzzer Pin | ESP32 Pin |
|------------|-----------|
| Positive (+) | GPIO14 |
| Negative (-) | GND |

---

## Circuit Connection Overview

```
                   +----------------------+
                   |        ESP32         |
                   |                      |
MQ-2 Analog ------>| GPIO34              |
DHT22 Data ------->| GPIO4               |
Red LED ---------->| GPIO25              |
Green LED -------->| GPIO26              |
Blue LED --------->| GPIO27              |
Buzzer ----------->| GPIO14              |
                   |                      |
5V --------------->| MQ-2 VCC            |
3.3V ------------->| DHT22 VCC           |
GND--------------->| All GND Connected   |
                   +----------------------+
```

---

# Working Logic

### Calibration

- ESP32 waits for **10 seconds** to stabilize the MQ-2 sensor.
- It then takes **30 analog readings**.
- The average of these readings is stored as the **baseline** gas value.

### Air Quality Thresholds

| Difference from Baseline | Status | LED | Buzzer |
|--------------------------|--------|-----|---------|
| Less than 100 | SAFE | Green | OFF |
| 101 – 299 | MODERATE | Yellow | 1000 Hz short beep |
| 300 or above | DANGER | Red | Continuous 2000 Hz alarm |

---

# Serial Monitor Output

The readings are printed in CSV format.

```
Timestamp, MQ-2 Value, DHT11 Temp, DHT11 Humidity, Severity Level

00:02, 315 ppm, 24.3°C, 46.5%, SAFE
00:04, 402 ppm, 24.4°C, 47.0%, MODERATE
00:06, 690 ppm, 24.6°C, 46.8%, DANGER
```

---

# Features

- Automatic MQ-2 sensor calibration
- Real-time smoke/gas monitoring
- Temperature and humidity monitoring
- RGB LED air quality indication
- Three-level alert system
- Buzzer warning according to severity
- CSV logging through Serial Monitor
- Fully offline operation (No Wi-Fi required)

---

# Future Improvements

- Bluetooth notification to smartphone
- OLED/LCD display for live readings
- Cloud data logging
- Mobile application
- Email/SMS emergency alerts
- CO sensor integration for higher accuracy

---

# Author

**Samya Malhotra**  
Electronics and Communication Engineering (ECE)
