# Q39. IoT Gateway

## What is an IoT Gateway?

An **IoT Gateway** is an intermediate device that connects IoT sensor nodes to the cloud. It collects data from multiple sensors, performs data filtering or processing (edge computing), converts communication protocols if required, and securely forwards the data to cloud services. The gateway also receives commands from the cloud and sends them back to the IoT devices.

---

## Simple Architecture Diagram

```text
+----------------+      +----------------+      +----------------+      +----------------------+
| IoT Sensor     | ---> |  IoT Gateway   | ---> |     Cloud      | ---> |  User Application    |
| Nodes          |      |                |      |                |      | (Web/Mobile Dashboard)|
+----------------+      +----------------+      +----------------+      +----------------------+

     Sensor Data          Data Aggregation        Data Storage &           Monitoring,
     Collection           & Protocol Conversion   Analytics                Alerts & Control
```

---

## Protocols Used at Each Layer

| Layer | Common Protocols |
|--------|------------------|
| **IoT Sensor Nodes → Gateway** | LoRa, Zigbee, BLE, Wi-Fi, Z-Wave |
| **Gateway → Cloud** | MQTT, HTTP/HTTPS, CoAP |
| **Cloud → User Application** | HTTPS (REST API), WebSocket, MQTT |

---

## Conclusion

The IoT gateway acts as a bridge between sensor devices and the cloud. It improves security, reduces network traffic through local processing, performs protocol conversion, and enables reliable communication between IoT devices and cloud applications.
