# 💻 Embedded Software Architecture & Firmware

This directory contains the modular C/C++ embedded firmware running on the dual-microcontroller architecture (Arduino Mega 2560 & Arduino Nano) of the VYTRON system.

## 1. System Architecture & Microcontroller Roles

### Master Controller (`Mega_IDE.ino`)
- **Core Responsibilities**: Graphical UI management, sensor data processing, temperature control, and viscosity mathematics.
- **User Interface**: Drives the **ILI9341 TFT LCD** with page-state management (`enum Sayfa`) and dual-language (TR/EN) support.
- **High-Precision Time Measurement**: Uses hardware interrupts (`sensorTetikInterrupt`) on `SENSOR_A` and `SENSOR_B` to calculate ball fall time in microseconds (`micros()`).
- **Thermal Regulation**: Reads fluid temperature via **DS18B20** and controls a Solid State Relay (SSR) with real-time ETA calculation during heating.
- **Kinematics & Calculations**: Analyzes system tilt using the **MPU-6050** orientation sensor and computes Dynamic (cP) and Kinematic (cSt) Viscosity based on Stokes' Law.

### Motion Controller (`Nano_IDE.ino`)
- **Core Responsibilities**: Stepper motor driver timing, manual user input, and automated mixing sequences.
- **Motion Profiling**: Controls the **NEMA 34** motor via **JSS-860H** driver using `AccelStepper` for acceleration/deceleration curves.
- **Inter-MCU Communication**: Listens to UART Serial commands (`H`, `G`, `S`) sent by the Arduino Mega.
- **Secondary UI & Keypad**: Manages 4x4 Keypad inputs and updates system status on a 20x4 I2C LCD display.
- **Mixing Cycle**: Executes automated 180° back-and-forth oscillation routines during fluid preparation.

## 2. Required Dependencies & Libraries

| Library Name | Version / Core | Usage |
|--------------|----------------|-------|
| `Adafruit_ILI9341` & `Adafruit_GFX` | Latest | TFT Display rendering |
| `DallasTemperature` & `OneWire` | Latest | DS18B20 digital temperature sensing |
| `AccelStepper` | Latest | Stepper motor trajectory planning |
| `LiquidCrystal_I2C` | Latest | 20x4 Character LCD display control |
| `Keypad` | Latest | 4x4 Matrix Keypad scanning |
| `Wire` | Built-in | I2C communication (MPU-6050 & LCD) |
