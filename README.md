# 🔬 VYTRON: Smart Viscosity Measurement and Control System

![Platform](https://img.shields.io/badge/MCU-Arduino%20Mega%202560%20%2B%20Nano-00979D?logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/Firmware-C%2B%2B%20(.ino)-blue)
![CAD](https://img.shields.io/badge/CAD-SolidWorks-red)
![Project](https://img.shields.io/badge/T%C3%9CB%C4%B0TAK-2209--A-orange)

VYTRON is an automated **falling-ball viscometer** developed as a **TÜBİTAK 2209-A** research project. Based on **Stokes' Law**, it turns the traditional manual falling-ball method into a fully automated, high-precision mechatronic system: the sample tube is rotated by a stepper motor, the ball's fall is timed, the fluid temperature is tracked, and viscosity is calculated and reported in real time.

This repository contains the **firmware, circuit schematics, and mechanical CAD files** of the system.

---

## 📑 Table of Contents

- [How It Works](#-how-it-works)
- [Key Features](#-key-features)
- [System Architecture](#-system-architecture)
- [Hardware](#-hardware)
- [Repository Structure](#-repository-structure)
- [Documentation](#-documentation)
- [Getting Started](#-getting-started)
- [Usage](#-usage)
- [Roadmap](#-roadmap)
- [License](#-license)
- [Acknowledgements](#-acknowledgements)

---

## ⚙️ How It Works

A sphere of known size and density falls through the sample fluid in a sealed tube. The time it takes to travel between two reference points gives its terminal velocity, from which dynamic viscosity is derived with Stokes' Law:

$$
\eta = \frac{2 \cdot (\rho_s - \rho_f) \cdot g \cdot r^2}{9 \cdot v}
$$

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
| **Arduino Mega 2560** (main MCU) | Master control logic, temperature tracking, viscosity calculation, Rotational position via MPU-6050, measurement sequencing |
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

## 📖 Documentation

All detailed guides are centralized under the `docs/` folder:

| Document | Path | Description |
|----------|------|-------------|
| Getting Started | `docs/getting-started.md` | Step-by-step setup, wiring, and first run |
| BOM Index (General Overview) | `docs/bom/bom-index.md` | Material summary and links to sub-sections |
| Electronic Material List | `docs/electronics/electronics-bom.md` | MCU, sensor, motor, driver, screen, power parts |
| Mechanical Material List | `docs/mechanical/mechanical-bom.md` | Glass tube, gaskets, screws, mounting parts |
| Product Pricing | `docs/pricing.md` | BOM cost, commercial comparison and price suggestions |
| Comparison | `docs/comparison.md` | VYTRON vs commercial viscometers |
| Use Cases | `docs/use-cases/` | Food, petrochemical, pharma, automotive, academic laboratory |
| Mechanical Assembly | `docs/assembly-guide.md` | Step-by-step mechanical build and sealing |
| Wiring & Pinout | `docs/wiring-guide.md` | Detailed pin tables and wiring diagrams |
| Calibration Procedure | `docs/calibration.md` | Reference-fluid calibration and validation |
| Safety Warnings | `docs/safety.md` | 220V, heater, and SSR safety precautions |
| Software Architecture & Firmware | `docs/software/software-architecture.md` | Dual-MCU roles, libraries, pin definitions, and flow |
| Mechanical Design & Fluid Dynamics | `docs/mechanical/mechanical-design.md` | CAD, sealing system, Stokes' Law basis |
| CFD & Flow Analysis | `docs/cfd/cfd-analysis.md` | Ansys Fluent simulation setup and findings |
| Interference Mitigation | `docs/electronics/interference-mitigation.md` | EMI/RFI filtering, I2C timeout, glitch filtering |
| TÜBİTAK Result Report | `docs/tubitak/sonuc-raporu.md` | TÜBİTAK 2209-A Result Report info |
| Project Article | `docs/tubitak/makale.md` | Project article info |

Each document can be read directly on GitHub by clicking the links above.

### 🛠️ Project Management (`.github/`)

| Item | Description |
|------|-------------|
| Issue Template: Bug Report | `.github/ISSUE_TEMPLATE/bug_report.md` |
| Issue Template: Feature Request | `.github/ISSUE_TEMPLATE/feature_request.md` |
| CI Workflow (Arduino Build) | `.github/workflows/arduino-ci.yml` |

---

## 📄 License

Full license text: [LICENSE.txt](./LICENSE.txt)

**Copyright © 2026 Rashad Rahimzade. All rights reserved.**

This repository and everything in it (firmware, circuit schematics, mechanical CAD files, documentation and images) may not be copied, modified, distributed, or used in any other project, commercial or non-commercial, without the author's prior written permission.

To request permission, please contact the author by email: **rahimzaderashad1@gmail.com**

---

## 🙏 Acknowledgements & Support

This project was realized with the following support and contributions:

- **TÜBİTAK 2209-A** University Students Research Projects Support Program
- **Prof. Dr. Ertuğrul Durak** (Project Advisor / Support)
- **SDU YETEM** (Suleyman Demirel University Research Center Support)

**Author:** [@rashadrahimzade](https://github.com/rashadrahimzade)

### 📄 TÜBİTAK Documents

| Document | Description | File |
|----------|-------------|------|
| Result Report | TÜBİTAK 2209-A Result Report | [`docs/tubitak/sonuc-raporu.md`](./docs/tubitak/sonuc-raporu.md) |
| Article | Project article (PDF) | [`docs/tubitak/makale.md`](./docs/tubitak/makale.md) |

> PDF files must be placed in the respective folders.
