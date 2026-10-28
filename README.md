## 🔬 VYTRON: Smart Viscosity Measurement and Control System

VYTRON is an automated falling-ball viscometer system developed as a TÜBİTAK 2209-A research project. Based on **Stokes' Law**, it transforms traditional viscosity measurement methods into a fully automated, high-precision mechatronic system.

---

### 📌 Key Features & Technical Highlights

* **Automated Viscosity Calculation:** Real-time viscosity processing with Stokes' Law algorithms and boundary wall-effect correction factors.
* **Dual Microcontroller Architecture:**
  * **Arduino Mega 2560 (Main MCU):** Handles master control logic, temperature tracking, and calculations.
  * **Arduino Nano (Motion Control MCU):** Processes **MPU-6050** tilt/orientation data and controls tube position.
* **Sensors & Actuators:**
  * **DS18B20:** Digital temperature sensor for tracking fluid thermal properties.
  * **MPU-6050:** 6-axis gyro/accelerometer for precise tilt and position tracking.
  * **NEMA 34 Stepper Motor & JSS-860H Driver:** High-torque motor setup for smooth tube rotation cycles.
* **Custom Mechanical Design:**
  * 3D modeled and assembled in **SolidWorks**.
  * Custom-engineered sealing channels using **NBR O-Rings** and **Viton (FKM)** seals for chemical resistance and zero-leakage operation.
<img width="675" height="540" alt="Adsız Proje" src="https://github.com/user-attachments/assets/b8ce3b4c-5375-4893-8aae-2aef60468832" />

---

### 📁 Repository Structure

```text
├── Mechanical/     # SolidWorks 3D CAD files (.sldprt, .sldasm), STEP models & technical drawings
├── Software/       # Embedded C++ code (.ino) for Arduino Mega 2560 and Arduino Nano
├── Electronics/    # Circuit schematics, wiring diagrams, and pinouts
└── README.md       # Project overview and documentation
