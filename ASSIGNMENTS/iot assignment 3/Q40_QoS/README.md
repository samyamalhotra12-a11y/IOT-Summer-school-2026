# Q40. MQTT Quality of Service (QoS)

## What is QoS in MQTT?

**Quality of Service (QoS)** in MQTT defines the level of guarantee for message delivery between the sender and receiver. MQTT provides three QoS levels based on reliability requirements.

---

## QoS Levels

| QoS Level | Name | Description |
|-----------|------|-------------|
| **QoS 0** | At Most Once | The message is sent only once without acknowledgment. Delivery is not guaranteed, but it has the lowest latency and bandwidth usage. |
| **QoS 1** | At Least Once | The sender waits for an acknowledgment (ACK). If no ACK is received, the message is retransmitted. This guarantees delivery but may result in duplicate messages. |
| **QoS 2** | Exactly Once | The highest level of reliability. A four-step handshake ensures the message is delivered exactly once without duplication. It has the highest latency and communication overhead. |

---

## Comparison Table

| Feature | QoS 0 | QoS 1 | QoS 2 |
|---------|-------|-------|-------|
| Delivery Guarantee | No | Yes | Yes |
| Duplicate Messages | No | Possible | No |
| Acknowledgment Required | No | Yes | Yes (4-step handshake) |
| Latency | Low | Medium | High |
| Network Overhead | Low | Medium | High |

---

## QoS Selection for an IoT Water Level Monitoring System

For an **IoT Water Level Monitoring System**, **QoS 1 (At Least Once)** is the most suitable choice.

### Reasons

- Ensures that important water level readings reach the cloud reliably.
- Occasional duplicate messages can be easily detected and ignored by the application.
- Provides a good balance between reliability, latency, and network bandwidth.
- More efficient than QoS 2 while offering much higher reliability than QoS 0.

---

## Conclusion

**Recommended QoS Level:** **QoS 1 (At Least Once)**

QoS 1 is the best choice for a water level monitoring system because it guarantees message delivery with moderate overhead, making it reliable and efficient for real-time IoT monitoring applications.
