# Smart-Bike-Accident-Detection
Smart Bike Accident Detection and Alert System using ESP32
## Project title
**Smart Bike Accident Detection and Alert System
## 👥 Team Details

**Team Name:** ECO-TECH

### Team Members

- **Vishnu Vardhan A** – Team Leader
- **Sharavana Ajay M**
- **Dharshani R**
- **Suvashika Mai K O**

**College:** Velammal College of Engineering and Technology

**Department:** Electronics and Communication Engineering (ECE)

**Hackathon/Event:** Rush Hour

## 📖 Problem Statement

Road accidents involving two-wheelers often result in delayed emergency assistance, especially when the rider is unconscious or unable to seek help. Many accidents occur in isolated or remote areas where immediate medical support is unavailable, increasing the risk of severe injuries or fatalities.

Most existing solutions rely on manual reporting by the victim or bystanders, which can significantly delay emergency response and reduce the chances of timely medical assistance.

---

## 💡 Proposed Solution

The **Smart Bike Accident Detection and Alert System** is an IoT-based embedded solution that automatically detects motorcycle accidents using the **MPU6050 accelerometer and gyroscope** connected to an **ESP32** microcontroller.

When the system detects a sudden impact followed by an abnormal tilt, it identifies a possible accident. It then activates a **buzzer** and **WS2812 RGB LED** while starting a countdown timer, allowing the rider to cancel the alert using a **push button** if no emergency has occurred.

If the rider does not respond within the specified time, the **Neo-6M GPS** module retrieves the current location, and the **SIM800L GSM** module automatically sends an SMS containing the accident location and a Google Maps link to predefined emergency contacts.

This automated approach minimizes emergency response time, reduces the dependency on manual reporting, and improves rider safety by ensuring that help can be notified even when the rider is unable to communicate.

## ✨ Features

- 🚴 Automatic bike accident detection using the **MPU6050** sensor.
- 📉 Detects bike falls based on sudden impact and abnormal tilt.
- 📍 Real-time GPS location tracking using the **Neo-6M GPS** module.
- 📩 Automatically sends emergency SMS alerts through the **SIM800L GSM** module.
- 🔘 Emergency alert cancellation using a push button to prevent false alarms.
- 💡 WS2812 RGB LED provides visual indication of the system status.
- 🔊 Audible buzzer warning during accident detection.
- 🔋 Rechargeable battery-powered system using an **18650 Li-ion battery**, **TP4056 charging module**, and **MT3608 boost converter**.
- ⚡ Compact, portable, and low-power embedded system design.
- 💰 Cost-effective solution suitable for real-world applications and academic projects.

## 🛠️ Complete Tech Stack

### 💻 Hardware

- **ESP32 Development Board** – Main microcontroller for processing sensor data and controlling all peripherals.
- **MPU6050 Accelerometer & Gyroscope** – Detects sudden impact, acceleration, and bike tilt.
- **Neo-6M GPS Module** – Retrieves the current geographical location (latitude and longitude).
- **SIM800L GSM Module** – Sends emergency SMS alerts to predefined contacts.
- **WS2812 RGB LED** – Provides visual indication of the system status.
- **Push Button** – Allows the rider to cancel false emergency alerts.
- **Buzzer** – Generates an audible warning after accident detection.
- **18650 Li-ion Battery** – Portable rechargeable power source for the system.
- **TP4056 Charging Module** – Safely charges and protects the Li-ion battery.
- **MT3608 Boost Converter** – Boosts the battery voltage to provide a stable power supply to the ESP32 and peripherals.

---

### 💾 Software

- **Arduino IDE** – Development environment for programming and uploading code to the ESP32.
- **Embedded C/C++** – Programming language used for firmware development.
- **ESP32 Arduino Framework** – Enables Arduino-based programming for the ESP32 microcontroller.

---

## 🚀 Installation and Usage Guide

### 📌 Requirements

Before running the project, ensure that the following software and hardware requirements are available.

### 💻 Software Requirements

- **Arduino IDE**
- **ESP32 Board Package**

### 🔌 Hardware Requirements

- **USB Driver** for ESP32 programming
- **SIM Card** for GSM-based SMS alerts
- **GPS Antenna** for accurate location tracking

---

## 📚 Required Libraries

Install the following libraries in Arduino IDE before uploading the code:

- **Wire.h**
- **MPU6050.h**
- **TinyGPSPlus.h**
- **Adafruit_NeoPixel.h**

---

## ⚙️ Setup Steps

Follow these steps to install and run the project:

### 1️⃣ Install Arduino IDE

Download and install Arduino IDE on your computer.

---

### 2️⃣ Install ESP32 Board Package

Add ESP32 board support in Arduino IDE and select the ESP32 development board.

---

### 3️⃣ Install Required Libraries

Install all the required libraries mentioned above using:

```
Arduino IDE → Sketch → Include Library → Manage Libraries
```

---

### 4️⃣ Connect Hardware Components

Connect all hardware components according to the circuit diagram provided in this repository.

Components include:

- ESP32 Development Board
- MPU6050 Accelerometer & Gyroscope
- Neo-6M GPS Module
- SIM800L GSM Module
- WS2812 RGB LED
- Buzzer
- Push Button

---

### 5️⃣ Upload Code to ESP32

1. Connect the ESP32 board to the computer using a USB cable.
2. Open the Arduino code from:

```
src/SmartBikeAccidentDetection.ino
```

3. Select the correct ESP32 board and COM port.
4. Upload the program to the ESP32.

---

### 6️⃣ Power the System

After successful uploading:

- Power the system using the battery supply.
- Ensure the SIM card is inserted into the SIM800L module.
- Place the GPS antenna properly for signal reception.

---

### 7️⃣ Test the System

To test accident detection:

- Keep the bike in normal position.
- Tilt the bike beyond the predefined threshold.
- Verify the following:

✅ Accident detection is triggered.  
✅ Buzzer starts warning.  
✅ RGB LED indicates emergency status.  
✅ GPS location is obtained.  
✅ SMS alert is sent through GSM if not cancelled.

---

## ✅ Usage

The system continuously monitors bike movement. When a fall is detected, it automatically alerts emergency contacts with the rider's location, improving safety and reducing emergency response time.
