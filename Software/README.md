# 💻 Embedded Software Architecture

This directory contains the embedded C++ source code (.ino) for the dual-microcontroller architecture of the VYTRON system.

---

### 🎛️ Microcontroller Responsibilities

* **`VYTRON_Mega_Main.ino` (Arduino Mega 2560 - Main MCU):**
  * Drives the ILI9341 TFT Graphical User Interface (GUI).
  * Reads temperature from the DS18B20 sensor and controls heating via SSR.
  * Measures inclination angles using the MPU-6050 accelerometer.
  * Handles high-precision optical sensor interrupts to measure ball fall duration.
  * Calculates Dynamic and Kinematic Viscosity using Stokes' Law with wall-effect correction factors.

* **`VYTRON_Nano_Motion.ino` (Arduino Nano - Motion Controller):**
  * Controls the NEMA 34 stepper motor using the `AccelStepper` library.
  * Manages motor speed, acceleration curves, and automated mixing/rotation cycles.
  * Interfaces with a 4x4 Keypad and a 20x4 I2C LCD display.