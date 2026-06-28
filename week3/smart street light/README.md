 Smart Street Light (LDR + PIR)
Implement an intelligent street light controller:
LDR below threshold (dark): Enable motion detection mode
PIR detects motion at night: Turn LED on at full brightness for 30 seconds
No motion after 30 sec: Dim LED to 20% using PWM
LDR above threshold (daylight): Turn LED completely OFF
Log every event to Serial: [HH:MM:SS] EVENT: description
