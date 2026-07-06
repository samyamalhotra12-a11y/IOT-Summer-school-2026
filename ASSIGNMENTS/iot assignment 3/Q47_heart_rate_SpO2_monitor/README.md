# Heart Rate & SpO₂ Monitoring System using ESP32 (Simulation)

## Problem Statement

Continuous monitoring of vital health parameters such as Heart Rate (HR) and Blood Oxygen Saturation (SpO₂) plays an important role in identifying abnormal health conditions at an early stage. Medical-grade sensors are often expensive and may not be readily available for educational purposes. Therefore, this project presents a simulation-based IoT health monitoring system using an ESP32 and an LDR sensor to mimic heart rate and SpO₂ readings. The objective is to demonstrate real-time physiological monitoring, alert generation, and data logging in a low-cost simulation environment.

---

## Solution Approach

The project uses an ESP32 microcontroller along with an LDR (Light Dependent Resistor) to simulate sensor readings. The analog value obtained from the LDR is processed using a rolling average filter to minimize fluctuations caused by rapid changes in light intensity.

The filtered value is then mapped into simulated Heart Rate (bpm) and Blood Oxygen Saturation (SpO₂ %) values. The ESP32 continuously checks whether these values fall within the normal operating range.

If any abnormal condition is detected, such as low or high heart rate or low SpO₂ level, a red LED is activated as an alert indicator. The generated values are displayed on the Serial Monitor in CSV format, making them suitable for data logging and further analysis.

---

## Hardware Required

- ESP32 Development Board
- LDR (Light Dependent Resistor)
- 10kΩ Resistor
- Red LED
- 220Ω Resistor
- Breadboard
- Jumper Wires
- USB Cable

---

## Circuit Connections

| Component | ESP32 Pin |
|-----------|-----------|
| LDR Analog Output | GPIO 34 |
| Red LED | GPIO 14 |
| LDR VCC | 3.3V |
| LDR GND | Through 10kΩ Resistor |
| ESP32 GND | GND |

---

## Circuit Diagram

```
                 +----------------------+
                 |        ESP32         |
                 |                      |
LDR Output ----->| GPIO 34             |
Red LED -------->| GPIO 14             |
3.3V ----------->| 3.3V                |
GND ------------>| GND                 |
                 +----------------------+

              LDR Circuit

          3.3V
            |
           LDR
            |
         GPIO34
            |
         10kΩ
            |
           GND


      Alert LED Circuit

GPIO14 ----220Ω---->|----GND
                    Red LED
```

---

## Features

- Simulated Heart Rate Monitoring
- Simulated Blood Oxygen (SpO₂) Monitoring
- Real-Time Sensor Updates
- 5-Sample Rolling Average Filter
- Automatic Health Alert Detection
- Red LED Alert Indicator
- CSV Format Serial Output
- Suitable for Wokwi Simulation
- Lightweight and Easy to Implement

---

## Working Principle

1. The LDR measures the surrounding light intensity.
2. The ESP32 reads the analog value from GPIO 34.
3. A rolling average filter smooths the sensor readings.
4. The filtered value is converted into simulated Heart Rate and SpO₂ values.
5. The controller compares the values against predefined thresholds.
6. If abnormal conditions are detected, the red LED turns ON.
7. All readings are displayed on the Serial Monitor in CSV format for logging.

---

## Alert Conditions

| Condition | Alert |
|-----------|-------|
| Heart Rate < 50 bpm | 🔴 Red LED ON |
| Heart Rate > 120 bpm | 🔴 Red LED ON |
| SpO₂ < 94% | 🔴 Red LED ON |
| Normal Values | ✅ LED OFF |

---

## Sample Serial Monitor Output

```
Time,HeartRate,SpO2

2,78,98
4,110,96
6,130,92
8,82,99
```

---

## Data Logging

The Serial Monitor output can be saved as a CSV file for further analysis.

Example:

```
Time,HeartRate,SpO2

2,78,98
4,110,96
6,130,92
```

---

## Wokwi Simulation

### Steps

1. Create a new ESP32 project in Wokwi.
2. Add an LDR, resistors, and a Red LED.
3. Connect the components according to the circuit diagram.
4. Upload the Arduino code.
5. Start the simulation.
6. Adjust the LDR slider to observe changes in Heart Rate and SpO₂ values.

---

## Testing Scenarios

| LDR Condition | System Response |
|--------------|-----------------|
| Medium Light | Normal Heart Rate and SpO₂ (LED OFF) |
| Low Light | Low Heart Rate / Low SpO₂ (LED ON) |
| High Light | High Heart Rate (LED ON) |

---

wokwi simulation link:https://drive.google.com/file/d/1VXDFjyKWwiif8Vo2WedcPApHSe0RMwyP/view?usp=sharing

## Author

**Samya Malhotra**
