# ⚠️ Safety Guide

This guide explains the safe use of the VYTRON system. The system contains 220V AC, high temperature, and moving mechanical parts. Reading and applying this guide is mandatory.

## 1. Electrical Safety

### 220V AC Hazard
- The system contains 220V AC voltage in the 200W heater and power supply.
- **Only qualified and competent personnel may make 220V connections.**
- All 220V cables must be double-insulated and kept in a suitable enclosure.
- Never touch 220V lines during operation.

### Solid State Relay (SSR)
- SSR switches 220V AC current. Incorrect connection or a fault may cause the heater to remain on continuously (runaway heating).
- Ensure the SSR mounting location is ventilated; temperature rise may occur.
- After power is cut, residual charge may remain inside the SSR; wait at least 5 minutes before maintenance.

### Arduino and Logic Circuits
- Arduino Mega and Nano operate at 5V. There is no direct connection to 220V.
- Ensure all logic connections (Serial1, I2C, keypad) share a common GND.

## 2. Heat and Temperature Safety

- The heater is 200W and can heat the liquid to high temperatures.
- The liquid and glass tube surface pose a burn risk. Do not touch the tube or heater with your hand while the heater is operating.
- When setting the target temperature, ensure the liquid does not exceed its boiling point.
- If the SSR locks (remains on continuously), the heater will continue to heat. Cut power from the source in an emergency.

## 3. Mechanical Safety

- The NEMA 34 stepper motor produces high torque. Do not bring your hand or clothing near the motor rotation area.
- Do not open the cover while the tube rotation mechanism is operating.
- The glass tube is fragile; it can break due to impact or dropping. Do not operate the system with a broken tube.

## 4. Chemical and Liquid Safety

- Know the chemical properties of the liquid to be measured; some liquids may not be compatible with NBR O-rings or Viton gaskets.
- Use protective gloves and eye protection when filling liquid.
- Do not approach electrical parts before cleaning spilled liquid.

## 5. Emergency Procedure

If a problem occurs (heater not heating, motor spinning out of control, smoke, etc.):

1. **Immediately cut 220V from the power source.**
2. Disconnect Arduinos from USB.
3. Wait for hot parts to cool down.
4. Restart only after identifying the source of the problem.

## 6. Maintenance and Inspection

- Check cables for damage before each use.
- Inspect O-ring and Viton gasket surfaces; replace if damaged.
- Ensure sensors are clean (especially optical sensors).
- Check all electrical connections are tight once every 12 months.

## 7. Disclaimer

This project is licensed under "All Rights Reserved" terms (`LICENSE.txt`). The author cannot be held responsible for damages arising from incomplete or incorrect application of this guide. All risks arising from system use belong to the user.

## 8. Contact

For safety questions or notifications: **rahimzaderashad1@gmail.com**
