# ? Electronic Material List (BOM) — Template

This is a **template** shopping list for the electronic components of the VYTRON system. You must fill in part numbers, quantities, and prices according to your project. All schematics are available in KiCad files in the `Electronics/` folder.

## ?? Excel File

Your actual electronic BOM is located here:

- `docs/bom/files/electronics-bom.xlsx` (source: `BOM_Electronic_VYTRON.xlsx`)

> File copied from Desktop to the project. If content update is needed, you can edit this file directly.

---

## 1. Microcontrollers (Example Template)

| Part | Qty | Part Code (MPN) | Supplier | Unit Price | Total Price | Note |
|------|-----|-----------------|----------|------------|-------------|------|
| Arduino Mega 2560 | 1 | | | | | Master control |
| Arduino Nano | 1 | | | | | Motion control (bootloader caution) |
| USB cable (A-Micro / A-Mini) | 2 | | | | | Programming and power |

## 2. Sensors (Example Template)

| Part | Qty | Part Code (MPN) | Supplier | Unit Price | Total Price | Note |
|------|-----|-----------------|----------|------------|-------------|------|
| DS18B20 temperature sensor (waterproof) | 1 | | | | | 4.7K pull-up resistor required |
| MPU-6050 (6-axis IMU) | 1 | | | | | I2C, tilt/position |
| Optical sensor (falling ball detection) | 2 | | | | | SENSOR_A, SENSOR_B |

## 3. Screens and Input (Example Template)

| Part | Qty | Part Code (MPN) | Supplier | Unit Price | Total Price | Note |
|------|-----|-----------------|----------|------------|-------------|------|
| ILI9341 TFT LCD (240×320, SPI) | 1 | | | | | Main interface on Mega |
| 20×4 I2C Character LCD | 1 | | | | | Status screen on Nano |
| 4×4 Matrix Keypad | 2 | | | | | One for Mega, one for Nano |

## 4. Motor and Power (Example Template)

| Part | Qty | Part Code (MPN) | Supplier | Unit Price | Total Price | Note |
|------|-----|-----------------|----------|------------|-------------|------|
| NEMA 34 Stepper Motor | 1 | | | | | High torque, tube rotation |
| JSS-860H Stepper Driver | 1 | | | | | 48V power |
| 48V Power Supply | 1 | | | | | Motor power |
| 5V Power Supply | 1 | | | | | MCU and sensor power |
| Solid State Relay (SSR) | 1 | | | | | 220V Heater control |
| 200W Heater (220V) | 1 | | | | | Liquid heating |

## 5. Electrical Parts (Example Template)

| Part | Qty | Part Code (MPN) | Supplier | Unit Price | Total Price | Note |
|------|-----|-----------------|----------|------------|-------------|------|
| 4.7K O Resistor | 1 | | | | | DS18B20 OneWire pull-up |
| Ferrite Core | — | | | | | EMI reduction |
| Aluminum Shielded Cable | — | | | | | Sensor and motor lines |
| Capacitor (power filter) | — | | | | | Power rail dip prevention |
| Cable, connector, terminal | — | | | | | 220V and logic separation |

## 6. Checklist

- [ ] Do Arduino Mega and Nano have the correct bootloader?
- [ ] Are TFT_CS/DC/RST pins compliant with the schematic?
- [ ] Are 220V cables insulated and inside a box?
- [ ] Are stepper motor cables at a sufficient distance from sensor cables?

## ?? Related Files

- KiCad Schematic: `Electronics/Smart Viscosity Measurement and Control System.kicad_sch`
- EMI/RFI Guide: `docs/electronics/interference-mitigation.md`
- Wiring Guide: `docs/wiring-guide.md`
