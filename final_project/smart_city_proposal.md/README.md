# IoT System Proposal: Jammu Smart City Project

**Abstract**
As part of the Jammu Smart City initiative, this proposal outlines an Internet of Things (IoT) architecture to modernize urban infrastructure. To improve resource management, citizen safety, and environmental health, we propose deploying three specialized IoT subsystems: Smart Waste Management, Smart Street Lighting, and Air Quality Monitoring.

---

## 1. Smart Waste Management (Bin Fill Level Monitoring)
Overflowing waste bins pose hygiene and aesthetic issues. This system alerts the municipal corporation when bins reach capacity, optimizing collection routes.

*   **Sensors Needed:** Waterproof Ultrasonic Sensor (JSN-SR04T) to measure the distance from the top of the bin to the garbage level.
*   **Microcontroller / Connectivity:** Heltec LoRa 32 (ESP32 + LoRaWAN module). LoRaWAN is ideal due to its low power consumption and long-range capabilities, perfect for dispersed city bins.
*   **Data Flow:**
    *   **Sensor:** Measures fill percentage.
    *   **Protocol:** LoRaWAN protocol transmits data to a local gateway.
    *   **Cloud:** The Things Network (TTN) receives the packets and forwards them via Webhook/MQTT to a cloud server (e.g., AWS or Ubidots).
    *   **Dashboard:** A Grafana or Ubidots dashboard displays bin status on a city map, alerting drivers via a mobile app.
*   **Estimated Cost Per Node:** 
    *   Sensor: ₹400
    *   Heltec LoRa 32: ₹1,500
    *   Battery & Enclosure: ₹600
    *   **Total:** ~₹2,500 INR

---

## 2. Smart Street Lighting
Streetlights consume massive amounts of municipal energy. An adaptive lighting system will dim lights when no one is around and brighten them upon detecting motion.

*   **Sensors Needed:** 
    *   LDR (Light Dependent Resistor) to detect ambient daylight (turning lights off during the day).
    *   PIR Motion Sensor (HC-SR501) to detect pedestrians or vehicles.
*   **Microcontroller / Connectivity:** ESP32 with NB-IoT (Narrowband IoT). NB-IoT piggybacks on existing cellular towers (Jio/Airtel), requiring no new gateway infrastructure.
*   **Data Flow:**
    *   **Sensor:** LDR checks ambient light; PIR checks motion.
    *   **Protocol:** CoAP or MQTT over NB-IoT cellular network.
    *   **Cloud:** AWS IoT Core processes the telemetry data.
    *   **Dashboard:** A custom web dashboard for municipal engineers to monitor energy consumption, track dead bulbs, and manually override lights.
*   **Estimated Cost Per Node:**
    *   ESP32 + NB-IoT Module (SIM7020): ₹1,200
    *   Sensors (LDR + PIR) & Relay: ₹250
    *   **Total:** ~₹1,450 INR

---

## 3. Air Quality Monitoring
Jammu’s varying climate and increasing traffic require localized air quality data to inform public health advisories.

*   **Sensors Needed:**
    *   PMS5003 (Laser dust sensor for PM2.5 and PM10).
    *   MQ-135 (Gas sensor for CO2, NOx, and Benzene).
*   **Microcontroller / Connectivity:** NodeMCU (ESP8266) or ESP32 utilizing city-wide public Wi-Fi or 4G LTE modules for continuous data streaming.
*   **Data Flow:**
    *   **Sensor:** Reads particulate matter via UART and gas levels via Analog pins.
    *   **Protocol:** HTTP POST or MQTT over Wi-Fi/LTE.
    *   **Cloud:** ThingSpeak or custom InfluxDB time-series database.
    *   **Dashboard:** A public-facing web dashboard and digital billboards across Jammu displaying the real-time Air Quality Index (AQI).
*  *Estimated Cost Per Node:*
    *   PMS5003 Sensor: ₹1,500
    *   MQ-135 Sensor: ₹150
    *   ESP32 & Power Supply: ₹600
    *   *Total:* ~₹2,250 INR
