# 💰 Product Pricing and Cost Analysis

This document summarizes the estimated BOM cost of the VYTRON system, assembly and calibration expenses, and price advantage compared to industrial competitors. All figures are **2026 averages** and may vary by supplier, region, and quantity.

## 1. BOM Cost Summary

| Category | Description |
|----------|-------------|
| **Electronics** | Arduino Mega 2560, Arduino Nano, NEMA 34, JSS-860H, DS18B20, MPU-6050, ILI9341 TFT, 4×4 Keypad, 20×4 LCD, SSR, 200W Heater, power supplies, cables, ferrites |
| **Mechanical** | Glass tube (inner/outer), NBR O-ring, Viton gasket, aluminum chassis, screws-nuts, motor mount, bearing |
| **Other** | Assembly tools, sealant, test fluids |

> Each BOM table contains its own subtotal; there is no grand total for the entire machine.
> Detailed part-by-part prices:
> - `docs/electronics/electronics-bom.md`
> - `docs/mechanical/mechanical-bom.md`

---

## 2. Additional Cost Items

| Item | Description |
|------|-------------|
| Assembly labor | Mechanical assembly, wiring, first run (hourly basis) |
| Calibration equipment | Reference viscosity fluids (silicone oil, etc.), thermometer, stationery |
| Software development | Firmware, interface, calibration procedures (developer hours) |
| Documentation | User manual, assembly guide, safety documents |

---

## 3. Industrial Comparison

How VYTRON stands against commercial falling-ball viscometers:

| Feature | VYTRON | Commercial Model A | Commercial Model B |
|---------|--------|-------------------|-------------------|
| **Estimated Price** | Low (BOM + labor) | High | Very High |
| **Automation** | Dual MCU, fully automatic | Manual / Semi-automatic | Fully automatic |
| **Real-time ETA** | Yes (with heater) | No | Yes |
| **Bilingual Interface (TR / EN)** | Yes | Foreign language | Foreign language |
| **Open Hardware / Schematic** | Yes (KiCad) | No | No |
| **User Calibration** | User-defined | Factory calibrated | Factory calibrated |
| **Sealing System** | NBR O-ring + Viton | Standard gasket | Special gasket |
| **CFD-Validated Design** | Yes (Ansys Fluent) | Generally no | Yes |

### Value Proposition
- **Cost advantage**: Can reach similar performance at a fraction of commercial device cost.
- **Learning / Research**: Open code and schematics make it ideal for university laboratories.
- **Flexibility**: Ball diameter, liquid type, and measurement range can be changed by the user.

---

## 4. Suggested Selling Price (If Commercialized)

If VYTRON is brought to market as a product, the following multipliers can be applied:

| Pricing Model | Calculation Logic | Suggested Range |
|--------------|-------------------|-----------------|
| **Cost + 20%** | Total BOM + Additional Cost + 20% profit | — TL |
| **40% of Competitor** | Approximately 40% of Commercial Model A | — TL |
| **Academic Discount** | Special discount for university laboratories | — TL |

> These figures are just an example template. Actual pricing should be updated once supplier quotes and labor hours are finalized.

---

## 5. Budget Tracking Form (For TÜBİTAK Projects)

| Item | Planned (TL) | Actual (TL) | Difference (TL) | Approved |
|------|--------------|-------------|-----------------|----------|
| Electronic parts | — | — | — | ? |
| Mechanical parts | — | — | — | ? |
| Assembly and labor | — | — | — | ? |
| Calibration fluids | — | — | — | ? |
| Software development | — | — | — | ? |
| Documentation | — | — | — | ? |
| **Total** | **—** | **—** | **—** | ? |

---

## 6. Cost Optimization Suggestions

1. **Bulk purchasing**: Buying Arduino, sensors, and O-rings in large quantities reduces unit price.
2. **Alternative suppliers**: Same-specification components can be sourced from local manufacturers for power supply and sensors.
3. **PCB integration**: Instead of breadboard, designing a custom PCB reduces cable cost and assembly time.
4. **Local production of CAD parts**: Aluminum chassis and mounting parts can be machined locally.

---

## 7. Related Files

- `docs/bom/bom-index.md` → General BOM summary
- `docs/electronics/electronics-bom.md` → Detailed electronic list
- `docs/mechanical/mechanical-bom.md` → Detailed mechanical list
- `docs/calibration.md` → Reference fluid calibration (additional cost item)
