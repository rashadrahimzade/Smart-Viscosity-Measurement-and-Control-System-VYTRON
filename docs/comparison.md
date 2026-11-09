# ⚖️ Comparison: VYTRON vs Commercial Falling-Ball Viscometers

This document compares the VYTRON system with industrial and laboratory-level commercial falling-ball viscometers. All values are approximate and for reference purposes.

## 1. Feature Comparison Table

| Feature | VYTRON | Commercial Model A | Commercial Model B |
|---------|--------|-------------------|-------------------|
| **Price** | Low (BOM + labor) | High | Very High |
| **Automation** | Dual MCU, fully automated | Manual / Semi-automatic | Fully automatic |
| **Real-time ETA** | Yes (with heater) | No | Yes |
| **Bilingual Interface (TR/EN)** | Yes | Foreign language | Foreign language |
| **Open Hardware / Schematic** | Yes (KiCad) | No | No |
| **Open Source Firmware** | Yes (Arduino .ino) | No | No |
| **User Calibration** | User-defined | Factory calibrated | Factory calibrated |
| **Sealing System** | NBR O-ring + Viton (FKM) | Standard gasket | Special gasket |
| **CFD-Validated Design** | Yes (Ansys Fluent) | Generally no | Yes |
| **Data Logging** | No (planned) | Yes | Yes |
| **220V Heater Control** | SSR + PID planned | Yes | Yes |
| **MPU-6050 Tilt Measurement** | Yes | No | Yes |
| **Optical Ball Detection** | Microsecond with hardware interrupt | Photo optical | Photo optical |
| **Assembly Ease** | User-assemblable | Factory assembled | Factory assembled |

## 2. Advantages and Disadvantages

### ✅ Advantages of VYTRON
- **Cost**: Approximately 20–40% of commercial device cost.
- **Transparency**: All CAD files, schematics, and firmware are open; users can modify and improve them.
- **Learning / Research**: Ideal for university laboratories and student experiments as a TÜBİTAK 2209-A project.
- **Flexibility**: Ball diameter, liquid type, measurement range, and calibration parameters can be changed by the user.
- **Local Production Potential**: Mechanical parts can be manufactured locally; electronics can be sourced from local suppliers.

### ❌ Disadvantages of VYTRON
- **Data Logging**: Automatic data logging with SD card or PC connection is not yet available (on the roadmap).
- **Service Warranty**: Commercial devices have factory warranty and service network; VYTRON maintenance is done by the user.
- **Quality Certificate**: Industrial quality certificate (ISO, CE, etc.) may not yet be obtained.

## 3. When to Choose Which?

| Scenario | Recommended Solution |
|----------|---------------------|
| University laboratory, student project | **VYTRON** (low cost, open source, learning-focused) |
| Industrial production line, precision guarantee | Commercial Model A / B |
| R&D center, customized measurement | **VYTRON** (firmware and CAD can be modified) |
| Calibrated certificate required | Commercial (factory calibration) |

## 4. Related Files

- `docs/bom/bom-index.md` → BOM summary
- `docs/pricing.md` → Cost and pricing analysis
- `docs/calibration.md` → Calibration procedure
