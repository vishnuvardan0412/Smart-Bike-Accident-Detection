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

# Smart-Bike-Accident-Detection

Smart Bike Accident Detection and Alert System using ESP32.

## Project Title

**Smart Bike Accident Detection and Alert System**

## 🧪 Testing and Performance

The Smart Bike Accident Detection and Alert System was thoroughly tested to ensure reliable operation under different conditions. Each hardware component, including the ESP32, MPU6050, Neo-6M GPS module, SIM800L GSM module, buzzer, WS2812 RGB LED, and push button, was individually tested before integrating the complete system. The MPU6050 accurately detected sudden impacts and abnormal tilt angles, enabling reliable bike fall detection while minimizing false alarms through threshold-based verification. The GPS module successfully acquired the bike's location in open environments, and the SIM800L module transmitted emergency SMS alerts containing the accident location to predefined contacts. The buzzer and RGB LED functioned as intended by providing immediate audio and visual alerts, while the push button effectively cancelled false emergency notifications during the countdown period. The system operated reliably using the 18650 Li-ion battery, TP4056 charging module, and MT3608 boost converter, providing stable power to all components. Overall, the integrated system demonstrated consistent performance, fast accident detection, accurate location tracking, and dependable emergency alert transmission, making it suitable for real-time bike safety applications.


## ⚠️ Challenges Faced

During the development of the Smart Bike Accident Detection and Alert System, several technical challenges were encountered and resolved:

- **Reliable Power Supply for SIM800L GSM Module**  
  The SIM800L requires a stable power supply with high current capability during SMS transmission. Proper voltage regulation and power management were required to ensure reliable GSM communication.

- **GPS Signal Delay**  
  The Neo-6M GPS module requires sufficient satellite visibility to obtain accurate location data. Signal acquisition time was reduced by testing the system in open environments with proper antenna placement.

- **Selecting Appropriate Fall Detection Threshold**  
  Choosing the correct acceleration and tilt thresholds was challenging because normal riding conditions can also produce sudden movements. Multiple tests were performed to differentiate actual accidents from normal vibrations.

- **Reducing False Accident Detection**  
  False alarms caused by potholes, speed breakers, or sudden braking were minimized by combining impact detection with tilt angle verification.

- **UART Communication Conflicts**  
  ESP32 has limited hardware UART interfaces, so proper GPIO pin selection and serial communication configuration were required to avoid conflicts between GPS and GSM modules.

- **Battery Voltage Management**  
  Managing different voltage requirements of ESP32, SIM800L, and other peripherals required proper power distribution using the TP4056 charging module and MT3608 boost converter.

  ## 🚀 Future Scope

The Smart Bike Accident Detection and Alert System can be further enhanced with advanced technologies to improve safety, reliability, and user experience.

Future improvements include:

- 📱 **Mobile Application Integration**  
  Develop a dedicated mobile application to monitor bike status, receive accident alerts, and view real-time location updates.

- ☁️ **Cloud-Based Monitoring**  
  Store accident data, location history, and system status on cloud platforms for remote access and analysis.

- 📍 **Real-Time Live Tracking**  
  Enable continuous GPS tracking to monitor the bike's location in real time.

- 📞 **Automatic Emergency Calling**  
  Add an automatic voice call feature to emergency contacts along with SMS alerts.

- 📊 **Crash Severity Analysis**  
  Implement advanced algorithms to analyze accident impact level and classify crash severity.

- 🌐 **IoT Dashboard Integration**  
  Develop a web-based dashboard for monitoring multiple bikes and visualizing accident-related data.

- 🤖 **AI-Based Accident Prediction**  
  Use machine learning techniques to analyze riding patterns and predict potential accident risks.

- 🪖 **Smart Helmet Integration**  
  Integrate the system with smart helmets to improve rider safety through additional sensors and communication features.

- 💾 **Cloud Data Logging**  
  Store sensor readings, accident history, and performance data for future analysis.

- 🗣️ **Voice Assistant Support**  
  Integrate voice-based assistance for hands-free emergency communication and system interaction.
## 📚 References

The following resources were referred to during the development of this project:

1. **ESP32 Documentation**  
   - ESP32 technical documentation and hardware specifications.

2. **MPU6050 Datasheet**  
   - Reference for accelerometer and gyroscope functionality, sensor communication, and configuration.

3. **Neo-6M GPS Datasheet**  
   - Reference for GPS module specifications, UART communication, and location data processing.

4. **SIM800L AT Command Manual**  
   - Reference for GSM communication, SMS commands, and module configuration.

5. **Arduino Documentation**  
   - Reference for Arduino IDE, programming environment, and embedded development.

6. **TinyGPSPlus Library Documentation**  
   - Reference for GPS data parsing and location extraction.

7. **Adafruit NeoPixel Documentation**  
   - Reference for WS2812 RGB LED control and programming.
