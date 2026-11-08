# 🔬 VYTRON: Smart Viscosity Measurement and Control System

![Platform](https://img.shields.io/badge/MCU-Arduino%20Mega%202560%20%2B%20Nano-00979D?logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/Firmware-C%2B%2B%20(.ino)-blue)
![CAD](https://img.shields.io/badge/CAD-SolidWorks-red)
![Project](https://img.shields.io/badge/T%C3%9CB%C4%B0TAK-2209--A-orange)

VYTRON is an automated **falling-ball viscometer** developed as a **TÜBİTAK 2209-A** research project. Based on **Stokes' Law**, it turns the traditional manual falling-ball method into a fully automated, high-precision mechatronic system: the sample tube is rotated by a stepper motor, the ball's fall is timed, the fluid temperature is tracked, and viscosity is calculated and reported in real time.

This repository contains the **firmware, circuit schematics, and mechanical CAD files** of the system.

<img width="675" height="540" alt="Adsız Proje" src="https://github.com/user-attachments/assets/8b889f8e-9948-4315-9d08-34bf66bbcde4" />

---

## 📑 Table of Contents
- [How It Works](#️-how-it-works)
- [Key Features](#-key-features)
- [System Architecture](#-system-architecture)
- [Hardware](#-hardware)
- [Repository Structure](#-repository-structure)
- [Documentation](#-documentation)
- [Getting Started](#-getting-started)
- [Usage](#️-usage)
- [Roadmap](#️-roadmap)
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
| **Arduino Mega 2560** (main MCU) | Master control logic, temperature tracking, viscosity calculation, Rotational position via MPU-6050, mesurement sequencing |
| **Arduino Nano** (motion MCU) | Controls tube position and drives the stepper driver |

```
 ┌──────────────┐                                            ┌──────────────┐
 │ Arduino Mega │ ◄────────────────────────────────────────► │ Arduino Nano │
 │  (Master)    │          serial communication              │  (Motion)    │
 └──────┬───────┘                                            └──────┬───────┘
        │                                                           │
DS18B20 (temp),MPU-6050 (tilt)                             JSS-860H ► NEMA 34
```

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

**Mechanical design:** modeled and assembled in **SolidWorks**, with custom-engineered sealing channels.

---

## 📁 Repository Structure

```
├── Mechanical/     # SolidWorks CAD files (.sldprt, .sldasm), STEP models, technical drawings
├── Software/       # Embedded C++ (.ino) firmware for Arduino Mega 2560 and Arduino Nano
├── Electronics/    # Circuit schematics, wiring diagrams, pinouts
├── docs/           # Centralized documentation (user guides, assembly, calibration, etc.)
├── LICENSE.txt     # License and usage terms (All Rights Reserved)
├── SECURITY.md     # Security policy
├── CONTRIBUTING.md # Contribution guidelines
├── CODE_OF_CONDUCT.md # Community standards
├── CHANGELOG.md    # Version history
├── .github/        # GitHub issue templates & CI workflows
└── README.md       # Project overview and documentation
```

---

## 🚀 Getting Started

### Prerequisites
- [Arduino IDE](https://www.arduino.cc/en/software) 2.x (or PlatformIO)
- Required Arduino libraries (see the `#include` lines at the top of each sketch)
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
5. Power the system and verify the sensor readings on the serial monitor.

---

## 🕹️ Usage

1. Fill the tube with the sample fluid and seal it.
2. Enter the ball and fluid parameters (sphere radius and density, fluid density).
3. Start the measurement cycle.
4. Read the viscosity and temperature values.

---

## 🗺️ Roadmap

- [ ] Calibration with reference-viscosity fluids and accuracy report
- [ ] Data logging (SD card / PC)
- [ ] Temperature-controlled measurement chamber
- [ ] Wiring diagram and photos of the finished prototype

---

## 📖 Documentation

All detailed guides are centralized under the `docs/` folder:

| Document | Path | Description |
|----------|------|-------------|
| Getting Started | `docs/getting-started.md` | Step-by-step setup, wiring, and first run |
| BOM Index (Genel Özet) | `docs/bom/bom-index.md` | Toplam malzeme özeti ve alt bölümlere linkler |
| Elektronik Malzeme Listesi | `docs/electronics/electronics-bom.md` | MCU, sensör, motor, sürücü, ekran, güç parçaları |
| Mekanik Malzeme Listesi | `docs/mechanical/mechanical-bom.md` | Cam tüp, contalar, vida, montaj parçaları |
| Ürün Fiyatlandırması | `docs/pricing.md` | BOM maliyeti, komersiyel karşılaştırma ve fiyat önerileri |
| Karşılaştırma | `docs/comparison.md` | VYTRON vs komersiyel viskozimetreler |
| Kullanım Senaryoları | `docs/use-cases/` | Gıda, petrokimya, ilaç, otomotiv ve akademik laboratuvar |
| Mechanical Assembly | `docs/assembly-guide.md` | Step-by-step mechanical build and sealing |
| Wiring & Pinout | `docs/wiring-guide.md` | Detailed pin tables and wiring diagrams |
| Calibration Procedure | `docs/calibration.md` | Reference-fluid calibration and validation |
| Safety Warnings | `docs/safety.md` | 220V, heater, and SSR safety precautions |
| Software Architecture & Firmware | `docs/software/software-architecture.md` | Dual-MCU roles, libraries, pin definitions, and flow |
| Mechanical Design & Fluid Dynamics | `docs/mechanical/mechanical-design.md` | CAD, sealing system, Stokes' Law basis |
| CFD & Flow Analysis | `docs/cfd/cfd-analysis.md` | Ansys Fluent simulation setup and findings |
| Interference Mitigation | `docs/electronics/interference-mitigation.md` | EMI/RFI filtering, I2C timeout, glitch filtering |

Each document can be read directly on GitHub by clicking the links above.

### 🛠️ Project Management (`.github/`)

| Öge | Açıklama |
|-----|----------|
| Issue Template: Bug Report | `.github/ISSUE_TEMPLATE/bug_report.md` |
| Issue Template: Feature Request | `.github/ISSUE_TEMPLATE/feature_request.md` |
| CI Workflow (Arduino Derleme) | `.github/workflows/arduino-ci.yml` |

---

## 📄 License

Full license text: [LICENSE.txt](./LICENSE.txt)

**Copyright © 2026 Rashad Rahimzade. All rights reserved.**

This repository and everything in it (firmware, circuit schematics, mechanical CAD files, documentation and images) may not be copied, modified, distributed, or used in any other project, commercial or non-commercial, without the author's prior written permission.

To request permission, please contact the author by email: **rahimzaderashad1@gmail.com**

---

## 🙏 Acknowledgements

This project was supported by the **TÜBİTAK 2209-A** University Students Research Projects Support Program.

**Author:** [@rashadrahimzade](https://github.com/rashadrahimzade)
