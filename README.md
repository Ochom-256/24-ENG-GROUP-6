# 24-ENG-GROUP 6

## Project Overview

24-ENG-GROUP 6 is a prototype of a solar-powered battery monitoring and charging system designed to support future battery swapping infrastructure for electric motorcycles (boda bodas). The system integrates renewable energy with intelligent battery monitoring to improve battery safety, charging efficiency, and reliability.

---

## Problem & Solution

### Problem

The expansion of electric motorcycles in Uganda is limited by battery charging infrastructure that is largely dependent on grid electricity and concentrated in urban areas. This limits deployment in peri-urban and underserved regions where electricity supply is unreliable or unavailable. Additionally, inadequate battery monitoring can reduce battery lifespan and compromise safety.

### Solution

Engineering Group 6 built a prototype of a solar-powered smart battery swapping cabinet that:

- Charges lithium-ion batteries using solar energy through a Battery Management System (BMS).
- Monitors battery voltage, current, and temperature in real time.
- Displays battery status on an LCD screen.
- Activates a buzzer when the battery reaches the full-charge threshold.
- Automatically controls a cooling fan through a relay when battery temperature exceeds the preset threshold.

The prototype demonstrates the feasibility of integrating renewable energy with intelligent battery monitoring for future battery swapping stations.

---

## Features

- Solar-powered battery charging
- Battery voltage monitoring
- Battery current monitoring
- Battery temperature monitoring
- LCD status display
- Automatic cooling fan control
- Battery full-charge buzzer alert
- Battery protection using a BMS

---

## Hardware Components

- Arduino Uno
- Solar Panel
- Buck Converter
- Battery Management System (BMS)
- Lithium-ion Battery
- Current Sensor
- Voltage Sensor
- Temperature Sensor
- 16×2 LCD Display
- Relay Module
- DC Cooling Fan
- Buzzer
- Power Adapter

---

## Software

- Arduino IDE
- C/C++
- Proteus (Circuit Design & Simulation)

---

## Setup Instructions

### Hardware Setup

1. Assemble all components according to the circuit diagram.
2. Connect the solar panel and adapter through the buck converter and BMS.
3. Connect the voltage, current, and temperature sensors to the Arduino.
4. Connect the LCD, relay module, buzzer, and fan to the Arduino.
5. Verify all wiring before powering the system.

### Software Setup

1. Install the Arduino IDE.
2. Clone this repository:

```bash
git clone https://github.com/Ochom-256/24-ENG-GROUP-6.git
```

3. Open the Arduino source code (.ino file).
4. Install any required Arduino libraries.
5. Select the correct Arduino board and COM port.
6. Upload the program to the Arduino Uno.

### Running the System

1. Power the system using the solar panel or DC adapter.
2. The Arduino initializes all sensors.
3. Battery voltage, current, and temperature are displayed on the LCD.
4. The buzzer sounds when the battery reaches the preset charging threshold.
5. The relay automatically switches on the cooling fan when the battery temperature exceeds the set threshold.

---

## Future Improvements

- Multi-battery charging capability
- IoT-based remote monitoring
- Mobile application integration
- Automated battery swapping mechanism
- Larger solar charging capacity
- Commercial-scale battery swapping cabinet

---

## Team

- Ochom Kenneth 
- Nakato Dennise
- Jovia Patience
- Nuwahereza Ronald
- Ludoru Emmanuel Gale
- Kamusiime Isaac

---

## License

This project was developed as a Final Year Diploma Project at the Uganda Institute of Information and Communications Technology (UICT).
