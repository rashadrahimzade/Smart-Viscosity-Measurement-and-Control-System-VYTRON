# 📐 Calibration Guide

This guide explains the calibration procedure for the VYTRON falling-ball viscometer system. Measurement accuracy is validated using reference fluids and the calibration procedure.

## 1. Measurement Principle

Dynamic viscosity is calculated using Stokes' Law:

$$\eta = \frac{2 \cdot (\rho_s - \rho_f) \cdot g \cdot r^2}{9 \cdot v}$$

In the firmware, this equation is coded as follows:

```cpp
float dViskozite = sureSaniye * (bilyeYogunluk - siviYog_g_cm3) * bilyeK_Sabiti * fSabiti;
float kViskozite = dViskozite / siviYog_g_cm3;
```

Where:
- `sureSaniye` : Fall time of the ball between the two optical sensors (seconds)
- `bilyeYogunluk` : Density of the selected ball (g/cm³)
- `siviYog_g_cm3` : Liquid density entered by the user (g/cm³)
- `bilyeK_Sabiti` : Calibration coefficient based on ball diameter
- `fSabiti` : Wall-effect correction factor (currently `0.952`)

The measurement principle diagram is shown in **Figure 3** of the project documentation.

## 2. Calibration Reference Fluid

The VYTRON system has been calibrated using **HD-46VG hydraulic press oil**.

| Parameter | Value |
|-----------|-------|
| Reference Fluid | HD-46VG Hydraulic Oil |
| Calibration Temperature | 40 °C |
| Reference Viscosity | 46 cSt (46 Ps) |
| Wall-Effect Factor (`fSabiti`) | Calculated via Ladenburg method for this fluid |

### Comparative Viscosity-Temperature Curve

The prototype measurement curve compared with ISO VG 46 reference oil is shown in the project documentation (Figure 1: "Comparative Viscosity-Temperature Curve of the Prototype Device using ISO VG 46 Reference Oil").

The market reference curve for Shell Tellus S2 MX oil is shown in Figure 2 of the documentation.

## 3. Ball Selection

Ball selection is performed before measurement because each ball diameter has different speed and acceleration curves. Based on extensive testing, optimal curves have been determined:

- **16 mm ball**: Light ball; does not require very high rotation speed. Excessive speed causes the ball to move away from center, creating turbulence effects at the beginning.
- **17 mm ball**: Medium ball; standard rotation speed.
- **18 mm ball**: Heavy ball; standard rotation speed.

The user selects the ball type on the system screen, and the corresponding `bilyeYogunluk` and `bilyeK_Sabiti` values are automatically loaded:
- 16 mm: Density 16.75 g/cm³, K coefficient 0.870
- 17 mm: Density 7.78 g/cm³, K coefficient 1.482
- 18 mm: Density 7.79 g/cm³, K coefficient 0.831

## 4. Calibration Steps

### Step 1: Ball and Fluid Parameter Entry
1. Turn on the system and select the language.
2. Select the ball you will use (16 mm, 17 mm, or 18 mm). The system automatically loads the `bilyeYogunluk` and `bilyeK_Sabiti` values.
3. Enter the liquid density on the `SIVI_YOGUNLUK_GIRIS` screen (kg/m³).

### Step 2: Position Calibration (MPU-6050)
1. Go to the `MPU_HIZALAMA` screen.
2. Move the tube to the starting position.
3. Press the `B` key to run the `analizYap()` function. The system averages MPU data for 5 seconds and calculates the step count.
4. When the result is displayed on the screen, confirm with `A`.

**MPU-6050 Specifications:**
- Sensitivity: 0.1°
- Tolerance range: ±1°
- Example: If target is 20°, values between 19° and 21° are accepted. 18.9° is rejected and the system does not proceed to the next step.

### Step 3: Fine Adjustment (Measurement Position)
1. Go to the `HASSAS_AYAR` screen.
2. Move the tube to the measurement position (slight tilt, e.g., 20°).
3. Run analysis with `B`, confirm with `A`.
4. Roll and Pitch values should be shown in green within ±1.0°.

### Step 4: Temperature Measurement
Temperature is measured with 0.1 °C sensitivity using the DS18B20 sensor. The liquid must reach the target temperature before measurement starts.

### Step 5: Measurement and Validation
1. Go to `OLCUM_EKRANI`.
2. Start measurement when the liquid reaches the target temperature.
3. The ball's fall time is displayed on the screen.
4. Dynamic and kinematic viscosity values are calculated and shown on screen.
5. Compare the result with the reference fluid value (46 cSt at 40 °C for HD-46VG). If the difference is over 5%, repeat calibration.

## 5. Wall-Effect Factor (Ladenburg)

The firmware defines `fSabiti = 0.952` as a constant. This value was calculated using the **Ladenburg Wall-Effect Factor (Ball Factor)** method based on HD-46VG hydraulic oil calibration.

**Formula:**

$$F = 1 + 2.4 \left(\frac{d}{D}\right)$$

Where:
- `F`: Ball Factor
- `d`: Ball diameter (m)
- `D`: Tube diameter (m)

**Recommendation:** For different ball/tube combinations, recalculate `fSabiti` using multi-point measurement with reference fluids and update the firmware.

## 6. Sensor Noise and Filtering

Sensor noise has been minimized using the following methods:
- Sensor reading speed optimization
- Screen refresh rate optimization
- Parasitic/anti-noise filtering applications

## 7. Measurement History

- The system stores the **last 5 measurement records**.
- These records are visible on the last measurement screen (`OLCUM_EKRANI`).
- Measurement history is deleted when power is cut.

## 8. Error Sources and Tolerances

| Error Source | Effect | Precaution |
|--------------|--------|------------|
| Temperature change (±1 °C) | ±2–5% in viscosity | DS18B20 temperature correction |
| Ball diameter tolerance | ±1–3% in viscosity | Use calibrated ball |
| Wall effect | ±3–8% in viscosity | Correct with `fSabiti` |
| Optical sensor noise | Time error | Interrupt glitch filter (300 µs) |
| Liquid bubbles | Vibration, premature end of fall | Fill liquid without bubbles |
| MPU-6050 tilt tolerance | ±1° outside range rejected | System blocks next step if out of range |

## 9. Calibration Record Form (Example)

| Date | Reference Fluid | Temperature (°C) | Measured (cP) | Reference (cP) | Error (%) |
|------|-----------------|------------------|---------------|----------------|-----------|
| | HD-46VG | 40.0 | | 46.0 | |

You can keep this table as an Excel or CSV file under `docs/`.

## 10. Notes

- EEPROM storage of calibration results is not yet available in the firmware; parameters are re-entered on every power-up (planned improvement).
- Measurement history (last 5 times) is stored on screen but deleted when power is cut.
- The system blocks progression to the next step if MPU-6050 tilt is outside ±1° tolerance.
- Ball selection affects measurement accuracy; always use the ball matched to the fluid viscosity range.
