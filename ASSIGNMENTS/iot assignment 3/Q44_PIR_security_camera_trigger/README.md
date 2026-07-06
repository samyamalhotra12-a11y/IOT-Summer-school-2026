# PIR-Based Smart Security Alert System using ESP32

##  Overview

The PIR-Based Smart Security Alert System is an IoT project developed using the ESP32 microcontroller and a PIR motion sensor. The system detects human movement and responds with visual and audio alerts using LEDs and a buzzer. It is designed to simulate a basic home or office security system that activates only during a specified time period and prevents repeated alarms using a cooldown mechanism.

---

#  Problem Statement

Unauthorized entry into homes, offices, or restricted areas can lead to security risks. Conventional security systems are often expensive and may require professional installation. There is a need for a simple, low-cost, and programmable motion detection system that can monitor an area and immediately alert users whenever movement is detected.

---

#  Solution Approach

This project uses a PIR (Passive Infrared) sensor to continuously monitor motion in its surroundings. When motion is detected, the ESP32 checks whether the system is currently within the configured active time window.

If the system is active, it performs a three-stage alert sequence:

-  Green LED with a short buzzer beep
-  Yellow LED with a medium buzzer beep
-  Red LED with a long buzzer beep

The buzzer uses ESP32 PWM (LEDC) to generate different sound frequencies, creating an escalating alert effect. After each detection, a cooldown period prevents multiple alarms from being triggered by the same motion event.

All activities are displayed on the Serial Monitor for monitoring and debugging.

---

#  Features

- ✅ Motion detection using PIR sensor
- ✅ Three-level LED alert indication
- ✅ PWM-based buzzer with escalating alarm tones
- ✅ Configurable active time window
- ✅ Cooldown mechanism to avoid repeated alerts
- ✅ Serial Monitor logging
- ✅ Compatible with both Wokwi simulation and real ESP32 hardware

---

#  Hardware Required

- ESP32 Development Board
- PIR Motion Sensor
- Active/Passive Buzzer
- Green LED
- Yellow LED
- Red LED
- 3 × 220Ω Resistors
- Jumper Wires
- Breadboard

---

#  Circuit Connections

| Component | ESP32 Pin |
|-----------|-----------|
| PIR Sensor OUT | GPIO 27 |
| Buzzer | GPIO 25 |
| Green LED | GPIO 18 |
| Yellow LED | GPIO 19 |
| Red LED | GPIO 21 |
| VCC | 3.3V |
| GND | GND |

---

#  Circuit Diagram

```
                 ESP32

            +------------------+
            |                  |
3.3V -------| VCC              |
GND --------| GND              |
            |                  |
GPIO27 -----| PIR Sensor OUT   |
GPIO25 -----| Buzzer           |
GPIO18 -----| Green LED        |
GPIO19 -----| Yellow LED       |
GPIO21 -----| Red LED          |
            |                  |
            +------------------+
```

---

#  Working Principle

1. ESP32 initializes all peripherals.
2. PIR sensor continuously monitors motion.
3. Motion detection triggers the ESP32.
4. System verifies whether it is within the configured active hours.
5. If active:
   - Green LED turns ON with a short beep.
   - Yellow LED turns ON with a medium beep.
   - Red LED turns ON with a long beep.
6. Event details are displayed on the Serial Monitor.
7. A cooldown period of 3 seconds prevents continuous triggering.

---

#  Time Window Configuration

The active monitoring period can be changed using the Serial Monitor.

Command format:

```
SET_HOURS start end
```

Example:

```
SET_HOURS 22 6
```

This configures the system to remain active only between **10:00 PM and 6:00 AM**.

If no time window is configured, the security system remains active throughout the day.

---

#  Alert System

The buzzer is controlled using ESP32 LEDC PWM.

Alert sequence:

-  Low alert → Short beep
-  Medium alert → Medium beep
-  High alert → Long beep

Different frequencies create a realistic security alarm effect.

---

#  Sample Serial Output

```
PIR Security System Ready

Motion Detected
Green Alert Activated
Yellow Alert Activated
Red Alert Activated

Alert Completed
Cooldown Started
```

---

#  Libraries Used

- ESP32 Arduino Core (Built-in)
- LEDC PWM Functions (Built-in)

---

simulation video link: https://drive.google.com/file/d/1HMsBGnlARSKXYa-5pL4YEEsymUf82Xz8/view?usp=sharing

#  Author

**Samya Malhotra**

