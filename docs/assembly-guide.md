# 🛠️ Mechanical Assembly Guide

This guide explains step by step the mechanical assembly of the VYTRON falling-ball viscometer. All 3D CAD models are in the `Mechanical/3D Model/` folder, and technical drawings are in `Mechanical/Techincal_Drawing/`.

## 1. Required Tools and Materials

- Allen key set (M3, M4, M5)
- Screwdriver set (Phillips and flathead)
- Calibrated wrench (10 mm, 13 mm)
- Silicone gasket or suitable sealant (optional)
- NBR O-ring and Viton (FKM) gaskets (included with the system)
- Cleaner (isopropyl alcohol)
- Gloves and eye protection

## 2. Assembly Order

### Step 1: Base Housing and Tube Fixing
1. Place the lower cover part on a flat and stable surface.
2. Carefully insert the glass tube (inner and outer) into the seat channel.
3. Clean the NBR O-ring channel on the tube and place the O-ring in position.
4. Place the upper cover part over the tube. Insert the Viton (FKM) gasket into the appropriate channel.
5. Fasten the covers together with screws. Do not overtighten; the glass tube can break.

### Step 2: Stepper Motor and Tube Rotation Mechanism
1. Mount the NEMA 34 stepper motor to the motor mounting plate (4 × M5 screws).
2. Connect the belt or coupling on the motor shaft to the tube rotation mechanism.
3. Secure the motor mounting plate to the main chassis.
4. Ensure the tube does not vibrate during motor movement; add a damper or insulation material if necessary.

### Step 3: Sensor Assembly
**MPU-6050 (Tilt/Position):**
- Mount on the side of the tube body. The sensor must be on a flat surface and securely mounted.
- Protect the cable path with aluminum shielded cable (against EMI).

**Optical Sensors (SENSOR_A and SENSOR_B):**
- Mount at two different points along the tube's falling path.
- The points where the ball enters and exits the optical area must be precisely aligned.
- The sensor's light source and receiver must face each other without obstruction.

**DS18B20 (Temperature):**
- Pass the probe through the tube's loosening or sealing channel so it enters the liquid.
- Ensure the probe contacts the liquid and air is excluded.

### Step 4: Heater and Safety
1. Mount the 220V 200W heater to the designated location.
2. Ensure the heater does not come into direct contact with the glass tube (or that proper insulation is in place if contact is required by design).
3. Mount the SSR (Solid State Relay) assembly in a ventilated location.
4. All 220V connections must be insulated and enclosed in a box.

### Step 5: User Interface Assembly
1. Mount the ILI9341 TFT LCD to the Mega control panel.
2. Mount the 4×4 keypads to the Mega and Nano panels.
3. Place the 20×4 I2C LCD on the Nano in the motion control panel.

## 3. Sealing Leak Test

After full assembly:
- Fill the tube with water and wait a few hours.
- Check for leaks at cover edges, O-ring channels, and tube entry/exit points.
- If there is a leak, repeat the assembly and check the gaskets.

## 4. Checklist

- [ ] Glass tube is not cracked or damaged
- [ ] NBR O-ring and Viton gaskets are in place and undamaged
- [ ] Tube is tightly and vibration-free mounted
- [ ] MPU-6050 is fixed on a flat surface
- [ ] Optical sensors are parallel and aligned
- [ ] DS18B20 contacts the liquid
- [ ] 220V connections are insulated and boxed
- [ ] All screws are tight (not overtightened)

## 5. Notes

- All CAD files were prepared in SolidWorks; STEP format is also available.
- Do not force any parts during assembly; glass components are especially sensitive.
- After assembly, follow the `docs/getting-started.md` guide for the first run.
