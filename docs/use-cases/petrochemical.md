# ⛽ Use Case: Petrochemical Industry

Viscosity plays a critical role in processability and quality control of petrochemical products (oils, additives, polymer solutions).

## 1. Application Areas

| Product | Viscosity Range | Importance |
|---------|----------------|------------|
| Motor oil | ~50–200 cP (40 °C'de) | Classification and performance |
| Hydraulic fluid | ~30–100 cP | System efficiency |
| Polymer solution | ~100–5000 cP | Processability and quality |
| Additive | ~10–500 cP | Dosage in recipe |

## 2. VYTRON Advantages

- **Wide temperature range**: DS18B20 and SSR allow measurement independent of temperature.
- **Aluminum shielded cable and ferrites**: Protection against electromagnetic noise in industrial environment (`docs/electronics/interference-mitigation.md`).
- **CFD-validated design**: Flow analysis performed for different liquid types (`docs/cfd/cfd-analysis.md`).
- **User-defined calibration**: Wall-effect factor (`fSabiti`) can be changed for different polymer or oil types.

## 3. Limitations

- Chemical resistance of gaskets (NBR, Viton) against liquids must be tested.
- Flammable liquids may require explosion-proof safety measures.

## 4. Related Files

- `docs/calibration.md` — Reference fluid calibration
- `docs/electronics/interference-mitigation.md` — EMI/RFI mitigation
- `docs/cfd/cfd-analysis.md` — Flow analysis
