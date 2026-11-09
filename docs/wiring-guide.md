# 🔌 Wiring Guide

This guide explains the electronic wiring and pin connections of the VYTRON system. All schematics are available in KiCad format in the `Electronics/` folder.

## 1. Arduino Mega 2560 (Master MCU)

| Pin | Component | Description |
|-----|-----------|-------------|
| 53 | TFT_CS | ILI9341 TFT Chip Select |
| 9 | TFT_DC | ILI9341 TFT Data/Command |
| 8 | TFT_RST | ILI9341 TFT Reset |
| 4 | OneWire Bus | DS18B20 temperature sensor data line |
| 2 | Sensor A | Optical sensor A (hardware interrupt, CHANGE) |
| 3 | Sensor B | Optical sensor B (hardware interrupt, CHANGE) |
| 7 | SSR_PIN | Heater control (Solid State Relay) |
| 36 | Keypad Row 1 | 4×4 Keypad (Mega side) |
| 34 | Keypad Row 2 | 4×4 Keypad (Mega side) |
| 32 | Keypad Row 3 | 4×4 Keypad (Mega side) |
| 30 | Keypad Row 4 | 4×4 Keypad (Mega side) |
| 28 | Keypad Col 1 | 4×4 Keypad (Mega side) |
| 26 | Keypad Col 2 | 4×4 Keypad (Mega side) |
| 24 | Keypad Col 3 | 4×4 Keypad (Mega side) |
| 22 | Keypad Col 4 | 4×4 Keypad (Mega side) |
| TX1 (Pin 18) | Nano RX | Sends commands to Nano via Serial1 |
| RX1 (Pin 19) | Nano TX | Receives data from Nano via Serial1 |
| 5V / GND | TFT, Sensors | Power |
| SDA (Pin 20) | MPU-6050, LCD | I2C data |
| SCL (Pin 21) | MPU-6050, LCD | I2C clock |

> **Note:** `Wire.setWireTimeout(3000, true)` is used on the I2C bus. MPU-6050 and 20×4 LCD (if connected to Mega via Nano) can share the same I2C bus; watch out for address conflicts.

## 2. Arduino Nano (Motion MCU)

| Pin | Component | Description |
|-----|-----------|-------------|
| 3 | Stepper Pulse | Sends pulses to JSS-860H driver |
| 2 | Stepper Direction | JSS-860H direction signal |
| 4 | Keypad Row 1 | 4×4 Keypad (Nano side) |
| 5 | Keypad Row 2 | 4×4 Keypad (Nano side) |
| 6 | Keypad Row 3 | 4×4 Keypad (Nano side) |
| 7 | Keypad Row 4 | 4×4 Keypad (Nano side) |
| 8 | Keypad Col 1 | 4×4 Keypad (Nano side) |
| 9 | Keypad Col 2 | 4×4 Keypad (Nano side) |
| 10 | Keypad Col 3 | 4×4 Keypad (Nano side) |
| 11 | Keypad Col 4 | 4×4 Keypad (Nano side) |
| A4 (SDA) | 20×4 LCD | I2C data |
| A5 (SCL) | 20×4 LCD | I2C clock |
| TX | Mega RX1 | Receives commands from Mega via Serial |
| RX | Mega TX1 | Sends response/data to Mega via Serial |
| 5V / GND | LCD, Keypad | Power |

## 3. Mega ↔ Nano Communication (Serial1)

| Mega Pin | Nano Pin | Description |
|----------|----------|-------------|
| TX1 (18) | RX | Commands from Mega to Nano (H, G, S) |
| RX1 (19) | TX | Status/feedback from Nano to Mega |
| GND | GND | Common ground reference |

**Commands (Mega → Nano):**
- `H` : Stepper +400 steps (clockwise)
- `G` : Stepper -400 steps (counter-clockwise)
- `S` : Stepper position zero (`moveTo(0)`)

## 4. Power and 220V Connection

| Component | Connection | Description |
|-----------|------------|-------------|
| 48V / 12V Power Supply | JSS-860H | Stepper motor power |
| 5V Power Supply | Arduinos, sensors, LCD | Logic power |
| 220V AC | SSR Input | Heater main current |
| SSR Output | 200W Heater | Heater control current |
| 4.7K Resistor | OneWire Bus (Pin 4) | DS18B20 pull-up |

> **⚠️ Warning:** 220V AC connections must only be made by qualified personnel. All 220V lines must be insulated and enclosed in a box.

## 5. Wiring Notes

- MPU-6050 and optical sensor cables should be pulled with **aluminum shielded (shielded)** cable.
- Stepper motor cables are power cables, so keep them at least 5 cm away from sensitive sensor cables.
- All common GND lines should be joined at a single point (star grounding).
- DS18B20 requires a 4.7K pull-up resistor on the OneWire bus.

## 6. Checklist

- [ ] Mega and Nano connected to common GND
- [ ] TX1-RX and RX1-TX cross-connected
- [ ] TFT_CS/DC/RST pins correct
- [ ] Sensor A and B using interrupt pins (2 and 3)
- [ ] SSR_PIN (7) set as output
- [ ] OneWire pull-up resistor installed
- [ ] 220V cables insulated
