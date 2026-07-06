# Smart Home Air Quality Monitor using ESP32

## Problem Statement

A family in Milan (Europe) is concerned about indoor air quality during winter because they use wood for home heating, which may produce smoke and carbon monoxide (CO). The objective is to design an IoT-based Smart Home Air Quality Monitoring System that continuously monitors indoor air quality using an MQ-2 gas sensor and environmental conditions using a DHT11 sensor. The system should alert residents when smoke or gas levels exceed safe limits and must continue operating even if the internet connection is unavailable.

---

# Solution Approach

The system is built using an ESP32 microcontroller connected to an MQ-2 gas sensor, DHT11 temperature and humidity sensor, RGB LED, buzzer, and Bluetooth communication.

### Working

1. ESP32 continuously reads gas concentration from the MQ-2 sensor.
2. Temperature and humidity are measured using the DHT11 sensor.
3. The gas value is compared with predefined threshold values.
4. Based on the detected air quality:
   - **Green LED** indicates Safe air quality.
   - **Yellow LED** indicates Moderate smoke level.
   - **Red LED** indicates Dangerous air quality.
5. The buzzer generates different alarm tones for each severity level.
6. Sensor readings are printed in CSV format on the Serial Monitor.
7. Alert messages are sent to a mobile phone through Bluetooth.
8. Since all processing is performed locally on the ESP32, the system continues working even when Wi-Fi or the internet is unavailable.

---

# Hardware Required

| Component | Quantity |
|-----------|----------|
| ESP32 DevKit V1 | 1 |
| MQ-2 Gas Sensor | 1 |
| DHT11 Temperature & Humidity Sensor | 1 |
| RGB LED (Common Cathode) | 1 |
| 220Ω Resistors | 3 |
| Active Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |
| USB Cable | 1 |
| Smartphone with Bluetooth | 1 |

---

# Circuit Diagram

## MQ-2 Sensor

| MQ-2 Pin | ESP32 Pin |
|----------|-----------|
| VCC | 5V |
| GND | GND |
| AO | GPIO34 |

---

## DHT11 Sensor

| DHT11 Pin | ESP32 Pin |
|-----------|------------|
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

*(Use a 220Ω resistor with each LED pin.)*

---

## Buzzer

| Buzzer Pin | ESP32 Pin |
|------------|-----------|
| Positive (+) | GPIO14 |
| Negative (-) | GND |

---

## System Connection Overview

```
              +-----------------------+
              |        ESP32          |
              |                       |
MQ-2 AO ------| GPIO34                |
DHT11 DATA ---| GPIO4                 |
Red LED ------| GPIO25                |
Green LED ----| GPIO26                |
Blue LED -----| GPIO27                |
Buzzer -------| GPIO14                |
              |                       |
5V ---------- MQ-2 VCC                |
3.3V -------- DHT11 VCC               |
GND -------- All GND Connections      |
              +-----------------------+
```

---

# Air Quality Thresholds

| MQ-2 Value | Status | LED | Buzzer |
|------------|--------|-----|---------|
| 0 – 300 | SAFE | Green | Short Beep |
| 301 – 600 | MODERATE | Yellow | Medium Tone |
| Above 600 | DANGER | Red | Continuous High Tone |

---

# Serial Monitor Output (CSV)

```
Timestamp,MQ-2 Value,DHT11 Temp,DHT11 Humidity,Severity Level
00:01,220,23.4,49,SAFE
00:02,280,23.5,50,SAFE
00:03,420,23.6,49,MODERATE
00:04,710,23.8,48,DANGER
```

---

# Bluetooth Alert Examples

### SAFE

```
SAFE
Gas:210
Temp:22.8°C
Humidity:51%
```

### MODERATE

```
WARNING
Moderate Smoke Detected
Gas=430
Check Fireplace
```

### DANGER

```
DANGER!!
Smoke Level Critical
Gas=765
Open Windows
Leave Room if Necessary.
```

---

# Features

- Continuous air quality monitoring
- MQ-2 gas sensor threshold comparison
- DHT11 temperature and humidity monitoring
- RGB LED status indication
- Three-level buzzer alarm
- Bluetooth alerts to smartphone
- CSV data logging through Serial Monitor
- Fully functional without internet connectivity

---

# Applications

- Smart homes
- Indoor air quality monitoring
- Fireplace safety monitoring
- Smoke detection
- Home automation
- Winter indoor pollution monitoring

---

# Author

**Samya Malhotra**  
