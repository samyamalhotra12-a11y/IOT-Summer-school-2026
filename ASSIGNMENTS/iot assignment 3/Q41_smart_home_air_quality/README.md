# Smart Home Air Quality Monitor 

## Problem Statement

Indoor air pollution caused by smoke, LPG leakage, and combustible gases can affect human health and safety. The objective of this project is to design an ESP32-based Smart Home Air Quality Monitoring System that continuously monitors indoor gas concentration using an MQ-2 gas sensor along with temperature and humidity using a DHT22 sensor. The system provides visual and audible alerts according to the detected air quality and operates completely offline without requiring an internet connection.

---

# Solution Approach

This project uses an ESP32 microcontroller to continuously monitor indoor environmental conditions.

- The MQ-2 gas sensor detects smoke and combustible gases.
- The analog sensor value is converted into an estimated gas concentration (pseudo PPM).
- A DHT22 sensor measures temperature and humidity.
- The ESP32 compares the gas concentration with predefined threshold values.
- Depending on the detected air quality:
  - Green LED indicates **SAFE** condition.
  - Yellow LED indicates **MODERATE** condition.
  - Red LED indicates **DANGER** condition.
- A buzzer generates different warning sounds according to the severity level.
- Sensor readings are displayed in CSV format on the Serial Monitor.
- The entire system works locally on the ESP32 without requiring Wi-Fi or cloud connectivity.

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

# Circuit Connection Overview

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

### Air Quality Thresholds

| Gas Concentration (PPM) | Status | LED | Buzzer |
|-------------------------|--------|-----|---------|
| Less than 1500 | SAFE | Green | OFF |
| 1500 – 2999 | MODERATE | Yellow | Short 1000 Hz Beep |
| 3000 and Above | DANGER | Red | Continuous 2000 Hz Alarm |

---



# Features

- Real-time gas monitoring
- Temperature monitoring
- Humidity monitoring
- RGB LED air quality indication
- Three-level alert system
- Buzzer warning according to severity
- CSV logging through Serial Monitor
- Offline operation (No Wi-Fi required)

---

# Future Improvements

- OLED/LCD display
- Bluetooth notifications
- Mobile application
- Cloud data logging
- Firebase integration
- Email/SMS emergency alerts
- Additional gas sensors for AQI calculation

---

# wokwi link: https://wokwi.com/projects/new/esp32

# Author

**Samya Malhotra**
