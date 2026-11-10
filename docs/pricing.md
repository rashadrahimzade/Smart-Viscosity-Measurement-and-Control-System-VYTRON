# 💰 Production Cost Analysis

This document summarizes the estimated production cost of the VYTRON system based on the Bill of Materials (BOM). **This system is NOT for sale.** The figures below represent the estimated cost to build the prototype, not a retail price.

## 1. Estimated Production Cost

| Item | Estimated Cost (TL) | Notes |
|------|---------------------|-------|
| Electronic parts | 12,492 TL | See `docs/electronics/electronics-bom.md` |
| Mechanical parts | 8,580 TL | See `docs/mechanical/mechanical-bom.md` |
| **Total Production Cost** | **21,072 TL** | **KDV dahil, Mayıs 2026** |

> **Note:** Detailed part-by-part prices are in the Excel BOM files under `docs/bom/files/`:
> - `BOM_Electronic_VYTRON.xlsx`
> - `BOM_Mechanic_VYTRON.xlsx`

---

## 2. Important Notice

**VYTRON is not a commercial product.** It is a research prototype developed under the TÜBİTAK 2209-A University Students Research Projects Support Program. There is **no sales price**, **no retail distribution**, and **no commercial warranty**.

---

## 3. Comparison with Laboratory Viscometers

| Feature | VYTRON | Conventional Laboratory Viscometer (Höppler-type) |
|---------|--------|--------------------------------------------------|
| **Type** | Dual-MCU automated falling-ball viscometer | Typically manual or semi-automatic |
| **Fully Automated** | Yes | Rare / Limited |
| **Production Cost** | ~21,072 TL (estimated) | Generally higher |
| **Open Hardware** | Yes (KiCad, SolidWorks) | Generally closed / proprietary |
| **Open Firmware** | Yes (Arduino `.ino`) | Generally closed |
| **User Calibration** | User-defined | Usually factory-calibrated |
| **Bilingual Interface (TR/EN)** | Yes | Usually single language |
| **Temperature Control** | Integrated heater + DS18B20 + SSR | Usually external heating / manual control |
| **Tilt Measurement** | Integrated MPU-6050 | Usually not integrated |
| **Ball Detection** | Optical sensors with hardware interrupt | Usually manual timing / photo-optical |
| **Data Logging** | Not yet available (planned) | Usually not available |
| **Assembly** | User-assemblable from open CAD/schematics | Factory-assembled |

## 4. Advantages of VYTRON

- **Lower production cost**: Estimated 21,072 TL, significantly lower than comparable commercial automated systems.
- **Open design**: All CAD files, schematics, and firmware are open for modification and local manufacturing.
- **Bilingual interface**: Turkish and English support.
- **Integrated temperature and tilt control**: Built-in heater, DS18B20 temperature sensor, MPU-6050 tilt sensor, and real-time ETA calculation.
- **Precise timing**: Optical sensors with hardware interrupt provide microsecond-precision fall-time measurement.

## 5. Limitations Compared to Commercial Units

- **Data logging**: Automatic SD card / PC data logging is not yet available (planned feature).
- **Service warranty**: No factory warranty or service network; maintenance is performed by the user.
- **Industrial certification**: May not yet have ISO, CE, or similar industrial quality certificates.

## 6. Related Files

- `docs/bom/bom-index.md` — Material list and cost summary
- `docs/electronics/electronics-bom.md` — Detailed electronic BOM (Excel)
- `docs/mechanical/mechanical-bom.md` — Detailed mechanical BOM (Excel)
- `docs/calibration.md` — Calibration procedure (HD-46VG reference fluid, 40 °C / 46 cSt)
- `docs/cfd-analysis.md` — CFD validation (Ansys Fluent)
