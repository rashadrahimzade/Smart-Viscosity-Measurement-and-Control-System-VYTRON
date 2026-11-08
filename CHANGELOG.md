# Changelog

All notable changes to the VYTRON project are documented in this file.

## [v1.0.0] — 2026-05-04

### Added
- Initial release of VYTRON Smart Viscosity Measurement and Control System
- Dual-microcontroller firmware:
  - `Mega_IDE.ino` (Arduino Mega 2560) — master control, UI, temperature, viscosity calculation
  - `Nano_IDE.ino` (Arduino Nano) — motion control, stepper driver, secondary UI
- Sensors: DS18B20 temperature, MPU-6050 tilt, optical ball-detection sensors
- ILI9341 TFT LCD with dual-language (TR/EN) support and page-state navigation
- 4×4 keypad input on both Mega and Nano
- 20×4 I2C LCD on Nano for motion status
- NEMA 34 stepper motor control via JSS-860H driver with AccelStepper profiling
- Solid State Relay (SSR) heater control with ETA display
- Last 5 measurement history on screen
- Software-level noise mitigation (I2C timeout, interrupt debouncing, moving average filter)

### Hardware
- SolidWorks CAD models and STEP files (`Mechanical/`)
- KiCad schematic (`Electronics/`)
- NBR O-ring and Viton (FKM) sealing channels
- Technical drawings (PDF)

### Documentation
- `README.md` — project overview
- `LICENSE.txt` — All Rights Reserved
- `SECURITY.md` — security policy
- Centralized docs under `docs/` (software, mechanical, CFD, electronics)