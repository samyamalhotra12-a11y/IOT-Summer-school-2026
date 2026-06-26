ESP32 Serial Communication Protocols

1. UART: Universal Serial (Asynchronous)
Point-to-Point: Connects exactly two devices together.
Asynchronous: No clock line; requires matched Baud Rates (e.g., 115200).
ESP32 Hardware: Features 3 hardware UART controllers.
Practical Application:NEO-6M GPS — Ideal for streaming positioning data strings.


 2. I2C: Master-Slave Bus (Synchronous)
Multi-Device: Up to 127 devices on 2 wires (SDA / SCL).
Synchronous: Shared clock signal driven by ESP32.
Pull-Up Resistors: Essential for active logic HIGH states on the bus lines.
Practical Application:BME280 Sensor — Tracks Temperature, Humidity, and Pressure.


 3. SPI: High-Speed Serial (Synchronous)
Full Duplex: Simultaneous 2-way data flow.
CS Line: Individual "Chip Select" wire for each peripheral to enable communication.
High Speed: Handles MB/s throughput; ideal for high-bandwidth modules like SD cards.
VSPI Default Pins on ESP32:
MOSI
MISO:
CS:
SCK:
