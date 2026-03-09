# Manhole Monitoring System using Arduino

## Overview

The **Manhole Monitoring System** is an Arduino-based embedded project designed to improve urban safety by continuously monitoring the condition of underground manholes. The system detects open manhole covers, harmful gas presence, and rising water levels using multiple sensors. When a hazardous condition is detected, the system immediately triggers a buzzer alert and displays real-time information on an LCD screen.

This project helps reduce manual inspection efforts and enables faster response to potential dangers such as toxic gases, flooding, or uncovered manholes.

---

## Features

* Detects **open or closed manhole covers** using an IR sensor
* Monitors **harmful gas levels** (CO₂ / methane) using an MQ gas sensor
* Tracks **water level** inside the manhole to detect flooding or blockage
* Displays **real-time sensor data** on an I2C LCD display
* Activates a **buzzer alert system** during dangerous conditions
* Reduces dependency on manual inspections

---

## Hardware Components

* Arduino Uno
* MQ Gas Sensor
* Water Level Sensor
* IR Sensor
* DHT11 Humidity Sensor (optional environmental monitoring)
* I2C LCD Display (16x2)
* Buzzer
* Jumper Wires
* Breadboard
* Power Supply

---

## Pin Connections

| Component          | Arduino Pin |
| ------------------ | ----------- |
| MQ Gas Sensor      | A0          |
| Water Level Sensor | A1          |
| IR Sensor          | D7          |
| DHT11 Sensor       | D4          |
| Buzzer             | D8          |
| LCD SDA            | A4          |
| LCD SCL            | A5          |

---

## Software Requirements

* Arduino IDE or VS Code with Arduino Extension
* Required Libraries:

  * LiquidCrystal_I2C
  * DHT Sensor Library
  * Adafruit Unified Sensor

Install libraries through the Arduino **Library Manager**.

---

## How It Works

1. Sensors continuously collect environmental data from the manhole.
2. The Arduino processes the sensor values.
3. The LCD displays gas level, water level, humidity, and cover status.
4. If gas concentration or water level exceeds the threshold, or the cover is open:

   * The system triggers a **buzzer alert**.
   * A warning message is displayed on the LCD.

---

## Project Structure

```
ManholeMonitoringSystem
│
├── ManholeMonitoring.ino
├── README.md
└── images (optional circuit diagrams or project photos)
```

---

## Applications

* Smart city infrastructure monitoring
* Sewer safety systems
* Hazard detection in underground maintenance areas
* Municipal drainage monitoring

---

## Future Improvements

* IoT integration for remote monitoring
* GSM module for SMS alerts
* Cloud data logging using platforms like ThingSpeak or Blynk
* Mobile application dashboard

---

## Author

Project developed as part of an academic embedded systems project using Arduino.
