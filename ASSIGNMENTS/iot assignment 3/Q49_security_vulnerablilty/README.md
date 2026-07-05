# Q49. Security Vulnerability Analysis

## Problem Statement

An ESP8266-based IoT application has the following security issues:
- Hardcoded Wi-Fi SSID and password
- Uses unencrypted HTTP instead of HTTPS
- Publishes data to a public MQTT broker without authentication
- Never validates incoming commands

Identify at least **5 security vulnerabilities**, explain the risk of each, and provide corrected code for at least **2 vulnerabilities**.

---

# Security Vulnerabilities

| Vulnerability | Risk | Recommended Solution |
|--------------|------|----------------------|
| **1. Hardcoded Wi-Fi Credentials** | Anyone with access to the source code can obtain the Wi-Fi SSID and password, leading to unauthorized network access. | Store credentials in a separate configuration file, secure storage, or use Wi-Fi provisioning. |
| **2. Using HTTP Instead of HTTPS** | Data is transmitted in plain text and can be intercepted or modified through Man-in-the-Middle (MITM) attacks. | Use HTTPS with TLS/SSL encryption and verify the server certificate. |
| **3. Public MQTT Broker Without Authentication** | Anyone can publish or subscribe to topics, allowing attackers to inject fake data or steal sensor information. | Use MQTT authentication (username/password) and TLS encryption with a private broker. |
| **4. No Validation of Incoming Commands** | Attackers can send malicious commands to control the IoT device, causing unauthorized operations or damage. | Validate commands, check message format, and allow only authorized commands. |
| **5. No Certificate Verification** | The device cannot verify the identity of the server, making it vulnerable to fake servers and MITM attacks. | Enable certificate validation or certificate pinning when using HTTPS or MQTT over TLS. |

---

# Corrected Code Example 1 – Secure Wi-Fi Credentials

### ❌ Insecure Code

```cpp
const char* ssid = "PublicWiFi";
const char* password = "12345678";
```

### ✅ Improved Code

```cpp
#include "config.h"

// config.h (not uploaded to GitHub)

#define WIFI_SSID "YourWiFi"
#define WIFI_PASSWORD "YourStrongPassword"

WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
```

---

# Corrected Code Example 2 – HTTPS Instead of HTTP

### ❌ Insecure Code

```cpp
HTTPClient http;
http.begin("http://example.com/data");
```

### ✅ Secure Code

```cpp
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

WiFiClientSecure client;
client.setInsecure();   // For testing only

HTTPClient https;
https.begin(client, "https://example.com/data");
```

> **Note:** In production, use certificate validation or certificate pinning instead of `setInsecure()`.

---

# Additional Security Recommendations

- Use **HTTPS** for all web communication.
- Use **MQTT over TLS (port 8883)** instead of an unsecured MQTT connection.
- Enable **username/password authentication** on the MQTT broker.
- Validate every incoming MQTT command before executing it.
- Keep firmware updated to patch known vulnerabilities.
- Store sensitive credentials securely instead of exposing them in the source code.

---

# Conclusion

The original IoT implementation contains several serious security weaknesses that can expose the device and network to unauthorized access, data theft, and remote attacks. By securing Wi-Fi credentials, using HTTPS/TLS, authenticating MQTT communication, validating commands, and verifying server certificates, the ESP8266 application becomes significantly more secure and reliable.
