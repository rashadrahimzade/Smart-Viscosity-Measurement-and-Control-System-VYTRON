# ⚖️ Comparison: VYTRON vs Höppler-Type Laboratory Viscometers

This document compares the VYTRON falling-ball viscometer with conventional laboratory viscometers (typically Höppler-type manual viscometers). Fully automated commercial models are rare; most laboratory viscometers are manual or semi-automatic.

## 1. Overview

| Aspect | VYTRON | Conventional Laboratory Viscometer (Höppler-type) |
|--------|--------|--------------------------------------------------|
| **Type** | Dual-MCU automated falling-ball viscometer | Typically manual or semi-automatic falling-ball viscometer |
| **Fully Automated** | Yes | Rare / Limited |
| **Estimated Production Cost** | ~25,000 TL (BOM + labor, not retail price) | Varies by supplier; generally higher than VYTRON production cost |
| **Open Hardware** | Yes (KiCad schematics, SolidWorks CAD) | Generally closed / proprietary |
| **Open Firmware** | Yes (Arduino `.ino`) | Generally closed |
| **User Calibration** | User-defined and repeatable | Usually factory-calibrated |
| **Bilingual Interface (TR/EN)** | Yes | Usually single language |
| **Temperature Control** | Integrated heater + DS18B20 + SSR with ETA | Usually external heating / manual control |
| **Tilt Measurement** | Integrated MPU-6050 | Usually not integrated |
| **Ball Detection** | Optical sensors with hardware interrupt (microsecond precision) | Usually manual timing / photo-optical |
| **Data Logging** | Not yet available (planned) | Usually not available or limited |
| **Assembly** | User-assemblable from open CAD/schematics | Factory-assembled |

## 2. Advantages of VYTRON

- **Cost-effective production**: Estimated production cost around 25,000 TL (BOM + labor), significantly lower than comparable commercial automated systems.
- **Open design**: All CAD files, schematics, and firmware are open; users can modify, improve, and manufacture locally.
- **Bilingual interface**: Turkish and English support, suitable for local laboratories and international collaboration.
- **Integrated temperature and tilt control**: Built-in heater, DS18B20 temperature sensor, MPU-6050 tilt sensor, and real-time ETA calculation.
- **Precise timing**: Optical sensors with hardware interrupt provide microsecond-precision fall-time measurement.
- **Educational value**: Ideal for university laboratories and student projects (TÜBİTAK 2209-A supported).

## 3. Limitations Compared to Commercial Units

- **Data logging**: Automatic SD card / PC data logging is not yet available (planned feature).
- **Service warranty**: No factory warranty or service network; maintenance is performed by the user.
- **Industrial certification**: May not yet have ISO, CE, or similar industrial quality certificates.

## 4. When to Choose Which?

| Scenario | Recommended Solution |
|----------|---------------------|
| University laboratory, student project, TÜBİTAK-supported research | **VYTRON** (open source, low cost, bilingual) |
| Industrial production line requiring factory calibration certificate | Commercial laboratory viscometer |
| R&D center needing customized firmware or CAD changes | **VYTRON** (fully modifiable) |
| Immediate turnkey solution with warranty | Commercial viscometer |

## 5. Related Files

- `docs/bom/bom-index.md` — Material list and cost summary
- `docs/pricing.md` — Cost analysis and pricing notes
- `docs/calibration.md` — Calibration procedure (HD-46VG reference fluid, 40 °C / 46 cSt)
- `docs/cfd-analysis.md` — CFD validation (Ansys Fluent)
- `docs/getting-started.md` — Assembly and first-run guide
