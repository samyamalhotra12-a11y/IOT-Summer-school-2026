# ESP32 REST API Weather Data Fetcher 🌦️

## Problem Statement

Weather information obtained from online services may differ from the actual environmental conditions at a specific location. This project aims to compare real-time weather data obtained from the OpenWeatherMap REST API with local temperature and humidity measured by a DHT11 sensor using an ESP32.

---

## Objective

- Connect the ESP32 to a Wi-Fi network.
- Fetch real-time weather data from the OpenWeatherMap REST API.
- Read local temperature and humidity using the DHT11 sensor.
- Compare API data with local sensor readings.
- Display the results on the Serial Monitor.
- Securely store Wi-Fi credentials and API key using a separate configuration file.

---

## Hardware Required

- ESP32 Development Board
- DHT11 Temperature & Humidity Sensor
- Breadboard
- Jumper Wires
- USB Cable
- Computer with Arduino IDE
- Wi-Fi Internet Connection

---

## Circuit Connections

| DHT11 Pin | ESP32 Pin |
|------------|------------|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO 4 |

> **Note:** If your DHT11 module does not have a built-in pull-up resistor, connect a **10kΩ resistor** between the DATA pin and 3.3V.

---

## Libraries Used

- WiFi.h
- HTTPClient.h
- ArduinoJson
- DHT Sensor Library

Install the following libraries from the Arduino IDE Library Manager:
- DHT Sensor Library by Adafruit
- ArduinoJson by Benoit Blanchon

---

## Project Structure

```
WeatherFetcher/
├── WeatherFetcher.ino
├── config.h
├── .gitignore
└── README.md
```

---

## Setup

### 1. Clone the Repository




### 2. Install Required Libraries

Install:
- DHT Sensor Library
- ArduinoJson

### 3. Create `config.h`

```cpp
#ifndef CONFIG_H
#define CONFIG_H

const char* WIFI_SSID = "Your_WiFi_Name";
const char* WIFI_PASSWORD = "Your_WiFi_Password";

const char* API_KEY = "YOUR_API_KEY";

const char* CITY = "Jammu";
const char* COUNTRY = "IN";

#endif
```

### 4. Add `.gitignore`

```
config.h
```

### 5. Upload the Code

- Select **ESP32 Dev Module**.
- Select the correct COM Port.
- Upload the sketch.
- Open the Serial Monitor at **115200 baud**.

---

## Sample Output (Jammu)

```
WiFi Connected

--------------------------------
City: Jammu
Weather: clear sky

API Temperature: 31.8 °C
Local DHT11 Temperature: 30.9 °C
Temperature Difference: 0.9 °C

API Humidity: 64%
Local Humidity: 67%
Humidity Difference: -3%

--------------------------------
```

---

## Security Features

- Wi-Fi credentials are stored in a separate `config.h` file.
- OpenWeatherMap API key is not included in the main source code.
- `config.h` is added to `.gitignore` to prevent accidental upload to GitHub.
- Sensitive information remains private when sharing the repository.

---

## Author

**Samya Malhotra**

