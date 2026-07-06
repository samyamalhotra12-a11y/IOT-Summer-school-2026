# Smart Plant Watering System using ESP32 🌱

## ⚠️ Problem Statement
Maintaining optimal soil moisture for plants is often challenging due to manual monitoring and inconsistent watering schedules. Traditional automated systems simply water plants based on timers or basic soil sensors, which leads to **water wastage** during rainy days or overwatering when the soil is already adequately moist. There is a need for an intelligent system that not only checks the ground reality but also anticipates weather conditions before triggering the irrigation mechanism.

---

## 💡 Solution Approach
This project proposes an IoT-driven smart irrigation prototype that makes logical watering decisions based on a combination of local sensor data and cloud-based weather forecasts. 

**The core logic follows these steps:**
1. **Continuous Monitoring:** The ESP32 reads real-time data from the soil moisture sensor and ambient light levels via an LDR every 30 seconds.
2. **Weather Verification:** Before turning on the water pump, the system queries the OpenWeatherMap API via Wi-Fi to check for any current or forecasted rain in the specified location.
3. **Smart Actuation:** 
   * If the soil is dry and the weather is clear, the relay activates the water pump.
   * If the soil is dry but rain is detected (locally via LDR or via API), watering is skipped to save water.
4. **Cloud Telemetry & Logging:** Every decision and sensor reading is logged directly into a Google Sheet using Google Apps Script for future analysis.
5. **Manual Override:** A physical tactile button with software debouncing allows users to manually bypass the system and water the plant if necessary.
6. **Local Display:** A 16x2 I2C LCD screen provides real-time system status to the user.

---

## 🛠️ Hardware Components
To build this prototype, the following components are required:
* **Microcontroller:** ESP32 Development Board
* **Sensors:** 
  * Analog Soil Moisture Sensor
  * LDR (Light Dependent Resistor) + 10kΩ Resistor (configured as a voltage divider to simulate rain/cloud cover)
* **Actuator:** 5V Relay Module & Water Pump (Represented by an LED in the Wokwi simulation)
* **User Interface:** 
  * 16x2 LCD Display with I2C Module
  * Tactile Push Button
* **Miscellaneous:** Breadboard and connecting Jumper Wires

---


### ESP32 Pin Connections
| Component | Pin / Terminal | ESP32 GPIO Pin |
| :--- | :--- | :--- |
| **Soil Moisture Sensor** | Analog Out (A0) | `GPIO 34` |
| **LDR (Voltage Divider)** | Analog Out | `GPIO 35` |
| **Manual Override Button** | Terminal 1 | `GPIO 18` *(Uses internal pull-up)* |
| **Relay Module / Pump** | Signal / IN | `GPIO 19` |
| **I2C LCD Display** | SDA | `GPIO 21` |
| **I2C LCD Display** | SCL | `GPIO 22` |

**Important Hardware Notes:**
* Ensure the LDR is correctly wired with the 10kΩ resistor to form a proper voltage divider, otherwise, the analog readings will float.
* The push button relies on the ESP32's `INPUT_PULLUP` mode, so no external resistor is needed for it.
* If using a real water pump, always use a Relay or a suitable Transistor (like TIP120) to isolate the ESP32 from high-current draw.
*
