# 🚗 Use Case: Automotive Industry

Used for viscosity control of automotive fluids such as engine oil, brake fluid, transmission oil.

## 1. Application Areas

| Fluid | Viscosity Range | Importance |
|-------|----------------|------------|
| Engine oil (5W30, 10W40, etc.) | ~50–200 cP | Engine protection and classification |
| Brake fluid (DOT 3, 4, 5.1) | ~10–30 cP | Brake system performance |
| Transmission oil | ~100–500 cP | Gear system operation |
| Coolant | ~1–5 cP | Cooling efficiency |

## 2. VYTRON Advantages

- **NEMA 34 stepper motor**: High torque, precise positioning for tube rotation and measurement position adjustment.
- **MPU-6050 tilt sensor**: Ensures tube is kept at correct angle in measurement position.
- **Heater and ETA**: ETA (remaining time) display in viscosity measurement dependent on temperature.
- **Optical sensors**: Ball fall time measured with microsecond precision.

## 3. Limitations

- Compliance with automotive standards (ISO, SAE, etc.) may require additional certification.
- Chemical resistance must be tested for oil and brake fluids.

## 4. Related Files

- `docs/calibration.md` — Reference fluid calibration
- `docs/mechanical/mechanical-design.md` — Mechanical CAD and design
- `docs/safety.md` — 220V and heater safety
