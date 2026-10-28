# 💻 Embedded Software Architecture & Firmware

This directory contains the modular C/C++ embedded firmware running on the dual-microcontroller architecture (Arduino Mega 2560 & Arduino Nano) of the VYTRON system.

---

### 🧱 System Architecture & Microcontroller Roles

#### 1. Master Controller (`VYTRON_Mega_Main.ino`)
* **Core Responsibilities:** Graphical UI management, sensor data processing, temperature control, and viscosity mathematics[cite: 3].
* **User Interface:** Drives the **ILI9341 TFT LCD** with page-state management (`enum Sayfa`) and dual-language (TR/EN) support[cite: 3].
* **High-Precision Time Measurement:** Uses hardware interrupts (`sensorTetikInterrupt`) on `SENSOR_A` and `SENSOR_B` to calculate ball fall time in microseconds (`micros()`)[cite: 3].
* **Thermal Regulation:** Reads fluid temperature via **DS18B20** and controls a Solid State Relay (SSR) with real-time ETA calculation during heating[cite: 3].
* **Kinematics & Calculations:** Analyzes system tilt using the **MPU-6050** orientation sensor and computes Dynamic ($\text{cP}$) and Kinematic ($\text{cSt}$) Viscosity based on Stokes' Law[cite: 3].

#### 2. Motion Controller (`VYTRON_Nano_Motion.ino`)
* **Core Responsibilities:** Stepper motor driver timing, manual user input, and automated mixing sequences[cite: 4].
* **Motion Profiling:** Controls the **NEMA 34** motor via **JSS-860H** driver using `AccelStepper` for acceleration/deceleration curves[cite: 4].
* **Inter-MCU Communication:** Listens to UART Serial commands (`H`, `G`, `S`) sent by the Arduino Mega[cite: 4].
* **Secondary UI & Keypad:** Manages 4x4 Keypad inputs and updates system status on a 20x4 I2C LCD[cite: 4].
* **Mixing Cycle:** Executes automated 180° back-and-forth oscillation routines during fluid preparation[cite: 4].

---

### 📦 Required Dependencies & Libraries

To compile and upload the project files, install the following libraries via the **Arduino Library Manager**:

| Library Name | Version / Core | Usage |
| :--- | :--- | :--- |
| `Adafruit_ILI9341` & `Adafruit_GFX` | Latest | TFT Display rendering[cite: 3] |
| `DallasTemperature` & `OneWire` | Latest | DS18B20 digital temperature sensing[cite: 3] |
| `AccelStepper` | Latest | Stepper motor trajectory planning[cite: 4] |
| `LiquidCrystal_I2C` | Latest | 20x4 Character LCD display control[cite: 4] |
| `Keypad` | Latest | 4x4 Matrix Keypad scanning[cite: 3, 4] |
| `Wire` | Built-in | I2C communication (MPU-6050 & LCD)[cite: 3, 4] |