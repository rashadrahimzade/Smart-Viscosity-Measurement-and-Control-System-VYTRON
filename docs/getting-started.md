# 🚀 Getting Started

This guide walks you through assembling, wiring, and running the VYTRON system for the first time.

## 1. Prerequisites

### Software
- [Arduino IDE](https://www.arduino.cc/en/software) 2.x (or PlatformIO)
- Required Arduino libraries (install via Library Manager):
  - `Adafruit_ILI9341` & `Adafruit_GFX`
  - `DallasTemperature` & `OneWire`
  - `AccelStepper`
  - `LiquidCrystal_I2C`
  - `Keypad`

### Hardware
- Assembled VYTRON prototype (see `docs/mechanical/mechanical-design.md` and `docs/electronics/interference-mitigation.md`)
- Arduino Mega 2560
- Arduino Nano
- NEMA 34 stepper motor + JSS-860H driver
- DS18B20 temperature sensor
- MPU-6050 tilt sensor
- ILI9341 TFT LCD (SPI)
- 4×4 matrix keypad × 2
- 20×4 I2C character LCD
- Solid State Relay (SSR)
- 220V / 200W heater (observe safety warnings in `docs/safety.md`)

## 2. Wiring Overview

Connect components according to the schematics in `Electronics/` and the pin definitions in each sketch:

**Arduino Mega (Master):**
| Pin | Function |
|-----|----------|
| 53 | TFT_CS |
| 9 | TFT_DC |
| 8 | TFT_RST |
| 4 | OneWire Bus (DS18B20) |
| 2 | Sensor A (optical, interrupt) |
| 3 | Sensor B (optical, interrupt) |
| 7 | SSR (heater control) |
| 36, 34, 32, 30 | Keypad rows |
| 28, 26, 24, 22 | Keypad cols |
| Serial1 (TX1/RX1) | Communication to Nano |

**Arduino Nano (Motion):**
| Pin | Function |
|-----|----------|
| 3 | Stepper pulse |
| 2 | Stepper direction |
| 4, 5, 6, 7 | Keypad rows |
| 8, 9, 10, 11 | Keypad cols |
| I2C (A4/A5) | 20×4 LCD |
| Serial (TX/RX) | Communication to Mega |

## 3. Upload Firmware

1. Connect the **Arduino Mega** to your PC.
2. Open `Software/Mega_IDE.ino` in Arduino IDE.
3. Select **Board: Arduino Mega or Mega 2560** and the correct COM port.
4. Upload.
5. Connect the **Arduino Nano**.
6. Open `Software/Nano_IDE.ino`.
7. Select **Board: Arduino Nano** (choose the correct bootloader for your clone) and COM port.
8. Upload.

## 4. First Power-Up

1. Wire the system according to the diagrams.
2. Fill the sample tube with the test fluid and seal it with NBR O-rings.
3. Insert the ball (16 mm, 17 mm, or 18 mm).
4. Power on both MCUs.
5. On the Mega TFT, select language (1 = Turkish, 2 = English).
6. Select the ball type.
7. Enter the fluid density.
8. Run MPU calibration, then set target temperature.
9. Start the measurement cycle.

## 5. Verification Checklist

- [ ] TFT shows VYTRON logo, then language selection
- [ ] DS18B20 reads a plausible room temperature (~20–25 °C)
- [ ] MPU-6050 shows stable roll/pitch values
- [ ] Nano LCD shows ball selection screen
- [ ] Stepper responds to Mega serial commands (H / G / S)
- [ ] SSR toggles heater when target temperature is set

## 6. Troubleshooting

| Problem | Possible Cause | Fix |
|---------|----------------|-----|
| TFT remains black | Wiring or power issue | Check TFT_CS/DC/RST pins and 5V supply |
| Temperature reads -127 °C or 85 °C | DS18B20 not connected / short | Check OneWire bus and 4.7K pull-up |
| Stepper does not move | Nano not receiving commands | Check Serial1 wiring (TX1→RX, RX1→TX) |
| Ball fall time not detected | Optical sensors misaligned | Adjust sensor positions; check sensorAktif flag |
| I2C bus hangs | Electrical noise | Ensure `Wire.setWireTimeout(3000, true)` is active |

## 7. Next Steps

After successful first run, proceed to:
- `docs/mechanical/mechanical-design.md` → mechanical assembly details
- `docs/electronics/interference-mitigation.md` → EMI/RFI hardening
- Calibration with reference-viscosity fluids (planned feature)
