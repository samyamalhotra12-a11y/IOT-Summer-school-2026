# Smart Door Lock System with OTP (ESP32 + Keypad + LCD + Servo)



# 📌 Problem Statement

Traditional door locks rely on physical keys or fixed passwords, which can be lost, stolen, duplicated, or shared. To improve security, a two-step authentication system is required that verifies both the user's identity and a time-limited One-Time Password (OTP).

The objective of this project is to design an ESP32-based Smart Door Lock System that generates a unique OTP for every login attempt and grants access only when the correct OTP is entered within the specified time.

---

# 💡 Solution Approach

The ESP32 acts as the central controller of the system.

- User enters a 4-digit User ID using the keypad.
- ESP32 generates a random 6-digit OTP.
- OTP is displayed on the Serial Monitor.
- A 30-second timer starts.
- User enters the OTP using the keypad.
- ESP32 verifies the OTP.
- If the OTP is correct before timeout:
  - LCD displays **ACCESS GRANTED**
  - Servo rotates to **90°** (Door Unlock)
  - After 3 seconds the servo returns to **0°** (Door Lock)
- If the OTP is incorrect or expires:
  - LCD displays **ACCESS DENIED** or **OTP EXPIRED**
  - Door remains locked.
- Every access attempt is logged on the Serial Monitor.

---

# ⚙️ Features

- 🔢 4-digit User ID authentication
- 🔐 Random 6-digit OTP generation
- ⏱️ 30-second OTP validity using `millis()`
- 📺 16×2 I2C LCD for instructions and status
- 🔄 SG90 Servo motor for door locking/unlocking
- 📊 Serial Monitor logging
- 🚫 OTP expiry protection
- 🧠 Two-step authentication
- 🔁 Automatic system reset after every attempt

---

# 🧰 Hardware Required

| Component | Description |
|----------|-------------|
| ESP32 Dev Board | Main microcontroller |
| 4×4 Matrix Keypad | User input |
| 16×2 LCD (I2C) | Display interface |
| SG90 Servo Motor | Door lock simulation |
| Jumper Wires | Connections |
| Wokwi Simulator | Virtual testing platform |

---

# 🔌 Circuit Connections

## 4×4 Keypad → ESP32

| Keypad Pin | ESP32 GPIO |
|------------|------------|
| R1 | GPIO 13 |
| R2 | GPIO 12 |
| R3 | GPIO 14 |
| R4 | GPIO 27 |
| C1 | GPIO 26 |
| C2 | GPIO 25 |
| C3 | GPIO 33 |
| C4 | GPIO 32 |

### Servo Motor → ESP32

| Servo Pin | ESP32 |
|------------|--------|
| Signal | GPIO 18 |
| VCC | 5V |
| GND | GND |

### LCD (I2C) → ESP32

| LCD Pin | ESP32 |
|----------|--------|
| SDA | GPIO 21 |
| SCL | GPIO 22 |
| VCC | 5V |
| GND | GND |

> **Note:** If the LCD does not work, change the I2C address from **0x27** to **0x3F** in the code.

---

# 🧠 Working Principle

1. User enters a 4-digit User ID using the keypad.
2. ESP32 generates a random 6-digit OTP.
3. OTP is displayed on the Serial Monitor.
4. User enters the OTP through the keypad.
5. System checks whether the OTP is entered within 30 seconds.
6. If the OTP is correct:
   - LCD displays **ACCESS GRANTED**
   - Servo rotates to **90°** and unlocks the door.
   - After 3 seconds, servo returns to **0°** and locks the door.
7. If the OTP is incorrect or expired:
   - LCD displays **ACCESS DENIED** or **OTP EXPIRED**.
8. The system resets automatically for the next user.

---

# 🔁 System Flow

```
START
      ↓
Initialize ESP32
      ↓
Enter 4-digit User ID
      ↓
Generate Random OTP
      ↓
Display OTP on Serial Monitor
      ↓
Start 30-Second Timer
      ↓
Enter OTP
      ↓
OTP Correct?
├── YES → Unlock Door (Servo 90°)
│         ↓
│     Lock Door (Servo 0°)
└── NO → Access Denied / OTP Expired
      ↓
Reset System
      ↓
END
```

---



# 📺 Sample Output

```
System Ready

ID Entered: 1234

OTP GENERATED: 582913

Enter OTP:

ACCESS GRANTED

Door Unlocked

----------------------
LOG: SUCCESS ENTRY
```

If the OTP is incorrect:

```
ACCESS DENIED

----------------------
LOG: FAILED ENTRY
```

If the OTP expires:

```
OTP EXPIRED

----------------------
LOG: FAILED ENTRY
```

simulation video link: https://drive.google.com/file/d/1I9NkNrogdxLsRLvuAITnCAAII4b3925u/view?usp=sharing
