# Q37. Wi-Fi Security for IoT

## Introduction

Wi-Fi connectivity enables IoT devices such as the ESP32 to communicate with cloud platforms and other devices. However, insecure Wi-Fi networks expose IoT devices to cyberattacks that may compromise data, privacy, and system availability. Implementing strong security practices is essential for building secure IoT applications.

---

## Common Wi-Fi Attack Vectors on IoT Devices

One common attack against Wi-Fi networks is the exploitation of **WPA2 vulnerabilities**. Weak or easily guessed passwords can allow attackers to perform offline dictionary or brute-force attacks after capturing the WPA2 handshake. Another major threat is the **Evil Twin Attack**, where an attacker creates a fake Wi-Fi access point with the same SSID as the legitimate network. IoT devices or users may unknowingly connect to the rogue access point, allowing attackers to intercept data or steal credentials.

---

## Best Practices for Securing ESP32 Wi-Fi Connections

ESP32 devices should use **WPA3** whenever supported because it offers stronger protection than WPA2 through Simultaneous Authentication of Equals (SAE), making offline password-guessing attacks significantly more difficult. Developers should also enable **TLS encryption** for all cloud communication and use **certificate pinning** to verify the server's identity, preventing man-in-the-middle attacks. Additional best practices include using strong and unique Wi-Fi passwords, regularly updating firmware, enabling Protected Management Frames (PMF), and disabling unnecessary network services.

---

## Why Hardcoding Passwords is Dangerous

Hardcoding Wi-Fi credentials directly into the source code is a poor security practice. If the source code is uploaded to a public repository or extracted from the device, attackers can easily obtain the Wi-Fi password and gain unauthorized access to the network. Hardcoded credentials are also difficult to update and often result in the same password being reused across multiple devices. Instead, credentials should be stored securely using encrypted storage, secure provisioning methods, or configuration files that are excluded from version control (such as `config.h` or environment variables).

---

## Conclusion

Securing Wi-Fi communication is a critical requirement for IoT systems. Using modern security standards such as WPA3, TLS with certificate pinning, secure credential storage, and regular firmware updates significantly reduces the risk of attacks and improves the overall security of ESP32-based IoT deployments.

---

## References

1. Espressif Systems. *ESP-IDF Wi-Fi Security Guide*. https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/wifi-security.html
2. Wi-Fi Alliance. *Wi-Fi CERTIFIED WPA3™ Security*. https://www.wi-fi.org/discover-wi-fi/security
