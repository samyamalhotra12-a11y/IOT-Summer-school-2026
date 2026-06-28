Ultrasonic Parking Sensor
Using HC-SR04, build a parking distance alert system:
Distance > 50cm: No alert, Serial prints SAFE
Distance 20–50cm: Yellow LED ON, buzzer beeps every 500ms
Distance 10–20cm: Red LED ON, buzzer beeps every 200ms
Distance < 10cm: All LEDs flash rapidly, buzzer continuous
Calculate and display distance in cm using the formula: distance = (duration * 0.034) / 2
Advanced: Use millis() for non-blocking timing (no delay()). +1 bonus mark.

