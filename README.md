# Smart_Parking_system
Arduino-based smart parking system that uses HC-SR04 ultrasonic sensors to detect vehicle presence in parking slots and automatically indicates availability using green LEDs and occupancy using red LEDs. A low-cost IoT prototype designed for simple and efficient parking monitoring.
# 🚗 Smart Parking System

A low-cost Arduino-based Smart Parking System that automatically detects whether parking slots are **free or occupied** using HC-SR04 ultrasonic sensors.

The system provides a simple visual indication for each parking slot:

* 🟢 **Green LED** → Parking slot is FREE
* 🔴 **Red LED** → Parking slot is OCCUPIED

This project is designed as a **budget-friendly prototype** that can be expanded into a complete IoT-based parking management system.

---

## 📌 Project Overview

Finding available parking spaces can be time-consuming, especially in crowded areas. This project demonstrates a simple automated solution using ultrasonic distance measurement.

An **Arduino UNO** continuously reads the distance from HC-SR04 ultrasonic sensors. When a vehicle is detected within a predefined distance, the corresponding parking slot is marked as occupied and the red LED turns ON.

When no vehicle is detected, the green LED remains ON to indicate that the slot is available.

---

## ✨ Features

* Real-time parking slot detection
* HC-SR04 ultrasonic distance sensing
* Individual status indication for each slot
* Green LED for available slots
* Red LED for occupied slots
* Low-cost hardware
* Simple Arduino-based implementation
* Easy to expand with additional parking slots
* Suitable for physical prototypes and academic demonstrations

---

## 🛠️ Hardware Requirements

| Component                 |    Quantity |
| ------------------------- | ----------: |
| Arduino UNO               |           1 |
| HC-SR04 Ultrasonic Sensor |           2 |
| Green LED                 |           2 |
| Red LED                   |           2 |
| 220Ω Resistor             |           4 |
| Breadboard                |           1 |
| Jumper Wires              | As required |
| USB Cable                 |           1 |
| Cardboard/Foam Board      |    Optional |

---

## 🔌 Pin Connections

### Parking Slot 1

| Component    | Arduino UNO Pin |
| ------------ | --------------- |
| HC-SR04 TRIG | D2              |
| HC-SR04 ECHO | D3              |
| Green LED    | D4              |
| Red LED      | D5              |

### Parking Slot 2

| Component    | Arduino UNO Pin |
| ------------ | --------------- |
| HC-SR04 TRIG | D6              |
| HC-SR04 ECHO | D7              |
| Green LED    | D8              |
| Red LED      | D9              |

### Power Connections

* HC-SR04 VCC → Arduino **5V**
* HC-SR04 GND → Arduino **GND**
* LED cathodes → **GND**
* Each LED anode is connected to its Arduino digital pin through a **220Ω resistor**

---

## ⚙️ How It Works

```text
        HC-SR04 Sensor
               ↓
        Measure Distance
               ↓
        Arduino UNO
               ↓
       ┌───────┴───────┐
       ↓               ↓
   Car Detected     No Car
       ↓               ↓
    🔴 RED          🟢 GREEN
   OCCUPIED           FREE
```

The ultrasonic sensor sends an ultrasonic pulse and measures the time taken for the echo to return.

The Arduino calculates the distance and compares it with the configured detection threshold.

### Default Detection

```text
Distance ≤ 15 cm
       ↓
   OCCUPIED
       ↓
    🔴 RED
```

```text
Distance > 15 cm
       ↓
      FREE
       ↓
   🟢 GREEN
```

The detection distance can be modified in the Arduino code:

```cpp
const int occupiedDistance = 15;
```

---

## 💻 Software

* Arduino IDE
* Arduino C/C++
* HC-SR04 Ultrasonic Sensor Library-free implementation

No external libraries are required for the current version.

---

## 📂 Project Structure

```text
Smart-Parking-System/
│
├── smartparkingsystem.ino
└── README.md
```

---

## 🚀 Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/yourusername/Smart-Parking-System.git
```

### 2. Open the Arduino sketch

Open:

```text
smartparkingsystem.ino
```

using the Arduino IDE.

### 3. Connect the hardware

Connect the Arduino UNO, ultrasonic sensors and LEDs according to the pin connection table.

### 4. Upload the code

Select:

```text
Board: Arduino Uno
```

Select the correct COM port and upload the sketch.

### 5. Test the system

Open the Serial Monitor at:

```text
9600 baud
```

The measured distance for each parking slot will be displayed.

---

## 🧪 Example Output

When both slots are empty:

```text
Slot 1: 35 cm     Slot 2: 32 cm

🟢 SLOT 1 - FREE
🟢 SLOT 2 - FREE
```

When a vehicle enters Slot 1:

```text
Slot 1: 8 cm      Slot 2: 32 cm

🔴 SLOT 1 - OCCUPIED
🟢 SLOT 2 - FREE
```

When both slots contain vehicles:

```text
Slot 1: 8 cm      Slot 2: 10 cm

🔴 SLOT 1 - OCCUPIED
🔴 SLOT 2 - OCCUPIED
```

---

## 💰 Budget-Friendly Design

This project intentionally uses inexpensive and easily available components.

Instead of expensive cameras, RFID systems or specialized parking sensors, the prototype uses:

**Arduino UNO + HC-SR04 + LEDs**

This makes it suitable for students and low-budget IoT project development.

---

## 🔮 Future Improvements

The current project is a basic prototype and can be expanded with:

* 📱 Mobile application
* 🌐 IoT web dashboard
* ☁️ Cloud data storage
* 📊 Parking usage statistics
* 🚘 Automatic entry/exit detection
* 🚧 Servo-based automatic gate
* 🖥️ LCD/OLED availability display
* 📡 ESP8266/ESP32 connectivity
* 🕐 Parking duration tracking
* 📈 Parking history and analytics

---

## 🎯 Project Objective

The main objective of this project is to demonstrate how **ultrasonic sensing and microcontrollers can be used to automate parking slot detection** in a simple, affordable and scalable way.

---

## 👨‍💻 Author

**Lokesh M**

Developed as a low-cost IoT prototype using Arduino UNO.

---

## 📄 License

This project is open-source and available for educational and personal use.
Submitted By: Medishetty Lokesh
Intern ID: CITS8871
