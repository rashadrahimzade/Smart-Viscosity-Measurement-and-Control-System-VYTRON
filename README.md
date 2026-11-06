# 🔬 VYTRON: Smart Viscosity Measurement and Control System

![Platform](https://img.shields.io/badge/MCU-Arduino%20Mega%202560%20%2B%20Nano-00979D?logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/Firmware-C%2B%2B%20(.ino)-blue)
![CAD](https://img.shields.io/badge/CAD-SolidWorks-red)
![Project](https://img.shields.io/badge/T%C3%9CB%C4%B0TAK-2209--A-orange)

VYTRON is an automated **falling-ball viscometer** developed as a **TÜBİTAK 2209-A** research project. Based on **Stokes' Law**, it turns the traditional manual falling-ball method into a fully automated, high-precision mechatronic system: the sample tube is rotated by a stepper motor, the ball's fall is timed, the fluid temperature is tracked, and viscosity is calculated and reported in real time.

This repository contains the **firmware, circuit schematics, and mechanical CAD files** of the system.

![VYTRON system overview](https://private-user-images.githubusercontent.com/279043277/687437779-b8ce3b4c-5375-4893-8aae-2aef60468832.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3OTM3NDI4OTUsIm5iZiI6MTc5Mzc0MjU5NSwicGF0aCI6Ii8yNzkwNDMyNzcvNjg3NDM3Nzc5LWI4Y2UzYjRjLTUzNzUtNDg5My04YWFlLTJhZWY2MDQ2ODgzMi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjYxMTAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI2MTEwM1QyMTQ5NTVaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1hNGUzZTgyOWE2OTcwMTc4OThiNzAxNjg1ODUxOWNjMDMyOWMwYTg0Y2Q1NzFiNDAzMGNlZjM3ZTAzN2ZiMDZmJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZyZXNwb25zZS1jb250ZW50LXR5cGU9aW1hZ2UlMkZwbmcifQ.1ZBXepN4l9fp3UlGgZs8z45JOH0CcJugwZiCVexgLRI)

> 💡 **Tip:** Upload the image into the repo (e.g. `docs/overview.png`) and reference it with a relative path. Signed `private-user-images` links can expire.

---

## 📑 Table of Contents
- [How It Works](#-how-it-works)
- [Key Features](#-key-features)
- [System Architecture](#-system-architecture)
- [Hardware](#-hardware)
- [Repository Structure](#-repository-structure)
- [Getting Started](#-getting-started)
- [Usage](#-usage)
- [Roadmap](#-roadmap)
- [License](#-license)
- [Acknowledgements](#-acknowledgements)

---

## ⚙️ How It Works

A sphere of known size and density falls through the sample fluid in a sealed tube. The time it takes to travel between two reference points gives its terminal velocity, from which dynamic viscosity is derived with Stokes' Law:

```
η = 2 · (ρs − ρf) · g · r² / (9 · v)
```

| Symbol | Meaning |
|--------|---------|
| η | Dynamic viscosity (Pa·s) |
| ρs, ρf | Density of the sphere / the fluid (kg/m³) |
| g | Gravitational acceleration (m/s²) |
| r | Sphere radius (m) |
| v | Terminal velocity (m/s) |

Because the ball falls in a bounded tube, the result is multiplied by a **wall-effect correction factor** to account for the tube boundary.

**Measurement cycle**
1. The tube is rotated to the start position and its tilt is verified (MPU-6050).
2. The fluid temperature is read (DS18B20).
3. The tube is flipped by the stepper motor and the ball's fall time is measured.
4. Viscosity is computed with the wall-effect correction and reported.

<!-- TODO: Adjust the steps above to match the actual firmware flow (e.g. how fall time is detected, how many repetitions are averaged). -->

---

## 📌 Key Features

- **Automated viscosity calculation** with Stokes' Law and wall-effect correction.
- **Dual-microcontroller architecture** with synchronized Mega ↔ Nano communication.
- **Real-time sensor processing** for temperature and tilt/orientation.
- **EMI-aware electronics design**: filtering for the stepper driver and sensor lines to keep measurements stable.
- **Closed-loop tube positioning** using MPU-6050 tilt feedback.
- **Chemically resistant, leak-free mechanics** with NBR O-rings and Viton (FKM) seals.

---

## 🧠 System Architecture

| Controller | Role |
|------------|------|
| **Arduino Mega 2560** (main MCU) | Master control logic, temperature tracking, viscosity calculation, measurement sequencing |
| **Arduino Nano** (motion MCU) | Reads the MPU-6050, controls tube position and drives the stepper driver |

```
 ┌──────────────┐   <!-- TODO: protocol, e.g. UART/I2C -->   ┌──────────────┐
 │ Arduino Mega │ ◄────────────────────────────────────────► │ Arduino Nano │
 │  (Master)    │                                            │  (Motion)    │
 └──────┬───────┘                                            └──────┬───────┘
        │                                                           │
   DS18B20 (temp)                                  MPU-6050 (tilt) + JSS-860H ► NEMA 34
```

<!-- TODO: Describe the Mega↔Nano message format and synchronization method. -->

---

## 🔩 Hardware

| Component | Purpose |
|-----------|---------|
| Arduino Mega 2560 | Main controller |
| Arduino Nano | Motion controller |
| DS18B20 | Digital temperature sensor |
| MPU-6050 | 6-axis gyro/accelerometer for tilt and position tracking |
| NEMA 34 stepper motor | High-torque tube rotation |
| JSS-860H driver | Stepper motor driver |
| NBR O-rings, Viton (FKM) seals | Sealing and chemical resistance |

<!-- TODO: Add power supply, display/UI, and any EMI filter components (ferrite beads, RC snubbers, shielded cables, etc.). -->

**Mechanical design:** modeled and assembled in **SolidWorks**, with custom-engineered sealing channels.

---

## 📁 Repository Structure

```
├── Mechanical/     # SolidWorks CAD files (.sldprt, .sldasm), STEP models, technical drawings
├── Software/       # Embedded C++ (.ino) firmware for Arduino Mega 2560 and Arduino Nano
├── Electronics/    # Circuit schematics, wiring diagrams, pinouts
├── SECURITY.md     # Security policy
└── README.md       # Project overview and documentation
```

---

## 🚀 Getting Started

### Prerequisites
- [Arduino IDE](https://www.arduino.cc/en/software) 2.x (or PlatformIO)
- Arduino libraries: <!-- TODO: list the exact ones, e.g. OneWire, DallasTemperature, MPU6050, AccelStepper -->
- Assembled hardware following the schematics in `Electronics/`

### Build & Upload
1. Clone the repository:
   ```bash
   git clone https://github.com/rashadrahimzade/Smart-Viscosity-Measurement-and-Control-System-VYTRON.git
   cd Smart-Viscosity-Measurement-and-Control-System-VYTRON
   ```
2. Wire the system according to the diagrams in `Electronics/`.
3. Open the Mega sketch from `Software/`, select **Arduino Mega or Mega 2560**, and upload.
4. Open the Nano sketch from `Software/`, select **Arduino Nano** (check the bootloader option), and upload.
5. Power the system and verify the sensor readings on the serial monitor (<!-- TODO: baud rate -->).

---

## 🕹️ Usage

<!-- TODO: Explain how to start a measurement, what the output looks like (serial/display), and required inputs such as sphere radius/density and fluid density. -->

1. Fill the tube with the sample fluid and seal it.
2. Enter the ball and fluid parameters.
3. Start the measurement cycle.
4. Read the viscosity and temperature values.

---

## 🗺️ Roadmap
<!-- TODO: Edit freely. -->
- [ ] Calibration with reference-viscosity fluids and accuracy report
- [ ] Data logging (SD card / PC)
- [ ] Temperature-controlled measurement chamber
- [ ] Wiring diagram and photos of the finished prototype

---

## 📄 License

<!-- TODO: Add a LICENSE file (e.g. MIT for firmware, CC BY for hardware/CAD) and update this line. -->
No license has been specified yet. Please contact the author before reuse.

---

## 🙏 Acknowledgements

This project was supported by the **TÜBİTAK 2209-A** University Students Research Projects Support Program.

**Author:** [@rashadrahimzade](https://github.com/rashadrahimzade)
