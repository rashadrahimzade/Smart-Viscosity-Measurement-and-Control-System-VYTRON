# 💻 Embedded Software Architecture & Firmware

This directory contains the modular C/C++ embedded firmware running on the dual-microcontroller architecture (Arduino Mega 2560 & Arduino Nano) of the VYTRON system.

## 1. System Architecture & Microcontroller Roles

### Master Controller (`Mega_IDE.ino`)
- **Core Responsibilities**: Graphical UI management, sensor data processing, temperature control, and viscosity mathematics.
- **User Interface**: Drives the **ILI9341 TFT LCD** with page-state management (`enum Sayfa`) and dual-language (TR/EN) support (`enum Dil { TR, EN }`).
- **High-Precision Time Measurement**: Uses hardware interrupts (`sensorTetikInterrupt`) on `SENSOR_A` (pin 2) and `SENSOR_B` (pin 3) to calculate ball fall time in microseconds (`micros()`).
- **Thermal Regulation**: Reads fluid temperature via **DS18B20** and controls a Solid State Relay (SSR) on pin 7 with real-time ETA calculation during heating.
- **Kinematics & Calculations**: Analyzes system tilt using the **MPU-6050** orientation sensor (I2C address 0x68) and computes Dynamic (cP) and Kinematic (cSt) Viscosity based on Stokes' Law.
- **Calibration Persistence**: Calibration values (ball density, K coefficient, wall-effect factor, target temperature, fluid density) are stored in and loaded from **EEPROM** via `kalibrasyonYukle()` and `kalibrasyonKaydet()` functions.
- **Interrupt Safety**: Atomic read helpers (`okuOlcumBasladi`, `okuOlcumBitti`, etc.) protect `volatile` variables shared between ISR and `loop()`.

### Motion Controller (`Nano_IDE.ino`)
- **Core Responsibilities**: Stepper motor driver timing, manual user input, and automated mixing sequences.
- **Motion Profiling**: Controls the **NEMA 34** motor via **JSS-860H** driver using `AccelStepper` for acceleration/deceleration curves (pins 2 = direction, 3 = pulse).
- **Inter-MCU Communication**: Listens to UART Serial commands (`H`, `G`, `S`) sent by the Arduino Mega:
  - `H` → +400 steps (clockwise)
  - `G` → -400 steps (counter-clockwise)
  - `S` → Move to position 0
- **Secondary UI & Keypad**: Manages 4×4 Keypad inputs and updates system status on a 20×4 I2C LCD display.
- **Mixing Cycle**: Executes automated 180° back-and-forth oscillation routines during fluid preparation.

## 2. Required Dependencies & Libraries

| Library Name | Version / Core | Usage |
|--------------|----------------|-------|
| `Adafruit_ILI9341` & `Adafruit_GFX` | Latest | TFT Display rendering |
| `DallasTemperature` & `OneWire` | Latest | DS18B20 digital temperature sensing |
| `AccelStepper` | Latest | Stepper motor trajectory planning |
| `LiquidCrystal_I2C` | Latest | 20×4 Character LCD display control |
| `Keypad` | Latest | 4×4 Matrix Keypad scanning |
| `Wire` | Built-in | I2C communication (MPU-6050 & LCD) |
| `EEPROM` | Built-in | Calibration data persistence |

## 3. Key Variables & Constants (Mega)

| Name | Type | Description |
|------|------|-------------|
| `enum Sayfa` | enum | Page states: LOGO, DIL_SECIM, BILYE_SECIM, SIVI_YOGUNLUK_GIRIS, MPU_HIZALAMA, SICAKLIK_AYAR, HASSAS_AYAR, OLCUM_EKRANI, GECMIS_EKRANI |
| `enum Dil` | enum | Language selection: TR, EN |
| `bilyeYogunluk` | float | Selected ball density (g/cm³) |
| `bilyeK_Sabiti` | float | Ball calibration coefficient |
| `fSabiti` | float | Wall-effect correction factor (default `0.952`) |
| `hedefSicaklik` | float | Target temperature (°C) |
| `olcumBasladi`, `olcumBitti` | volatile bool | Measurement start/finish flags (ISR-protected) |
| `baslangicZamani`, `bitisZamani` | volatile unsigned long | Fall start/end time (microseconds) |
