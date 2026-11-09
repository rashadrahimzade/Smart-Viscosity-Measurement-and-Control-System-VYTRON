# 🛠️ Mechanical Assembly Guide

This guide explains step by step the mechanical assembly of the VYTRON falling-ball viscometer. All 3D CAD models are in the `Mechanical/3D Model/` folder, and technical drawings are in `Mechanical/Technical_Drawing/`.

## 1. Required Tools and Materials

- Allen key set (M3, M4, M5, M6, M8)
- Screwdriver set (Phillips and flathead)
- Calibrated wrench (10 mm, 13 mm)
- Silicone sealant (high-temperature resistant)
- NBR O-rings and Viton (FKM) gaskets (included with the system)
- Compressed Fiber Gasket
- Cleaner (isopropyl alcohol)
- Gloves and eye protection

## 2. Assembly Order

### Step 1: Sigma Profile Base Mounting
1. Start with the sigma profile.
2. Mount the first surface using **DIN 7991 M8x20 Phosphate** screws.
3. Use **40×40 Flat Corner Bracket** and **T-head M8** for corner connections.
4. Mount two sigma profiles (210 mm each) for the bearings. **Ensure both profiles are at the same height level.** This is critical for proper bearing alignment.

### Step 2: Bearing Mounting
1. Mount **2 × UCP-201** bearings onto the sigma profiles.
2. Ensure the bearings are properly aligned and secured.

### Step 3: Upper Cover Assembly
1. Take the **Üst Kapak** part.
2. Mount the **threaded heater** into its channel.
3. Use **Compressed Fiber Gasket** and high-temperature resistant **silicone** for sealing.
4. Insert the **temperature sensor** into its hole and mount it with silicone.

### Step 4: Lower Cover Assembly
1. Take the **Alt Kapak** part.
2. Mount the heater in the same way as the Upper Cover.
3. Install the **Threaded Bushing (Drain Port)** into the other channel.
4. Use **NBR flat washer** and silicone for sealing.

### Step 5: Glass Tube and Clamp Assembly
1. Take the **Glass Tube Borosilicate 3.3** (100 × 212 mm).
2. Pass the **Kelepçe** part through the glass from the inside.
3. Place the glass into the channels of the **Alt Kapak** and **Üst Kapak** (ABS covers).
4. Insert **4 × M8 Threaded Rod** (260 mm) through the assembly.
5. Use **M8 washers** and **M8 nuts** on both ends.
6. Place the **Boş çubuklar** (empty rods) between the **Kelepçe** and the covers, then pass the Threaded Rod through them.
7. Tighten the nuts. **Critical detail:** Tighten until the empty rods stop rotating between the **Kelepçe** and covers.
   - **Too tight:** Risk of cracking the glass.
   - **Too loose:** Risk of leakage.
   - **Correct:** Tighten until the empty rods cannot rotate freely.

### Step 6: Shaft Support Assembly
1. Mount **SHF 12 Shaft Supports** into the slots on the **Kelepçe** part.
2. Secure them with **M6 nuts and bolts**.

### Step 7: Calculation System Assembly
1. Place the **calculation system** between the **UCP-201** bearings.
2. Pass the **aluminum miller** through the calculation system.
3. Tighten the bolts on the **UCP-201** bearings.
4. Tighten the bolts on the **SHF** supports mounted on the calculation system.
5. The system is now mechanically stable.

### Step 8: Sealing and Final Steps
1. Place **O-rings** into the O-ring channels on the covers.
2. Insert the **small tube** through the center hole. It must be **flush with the surface level**.
3. Take the **Kapak Sensor** part and mount the **proximity sensors** on it.

### Step 9: Sensor Cover Mounting
1. Mount **4 × M5 Threaded Rod** (40 mm), **4 × M5 nuts**, and **4 × DIN 315 Nut** on the **Kapak Sensor** parts (these will remain on the top part).
2. Securely mount the **Kapak Sensor** parts to the housing.
3. Carefully route the cables through the edges of the **Boş çubuklar** (empty rods) to align the **aluminum miller** correctly.

### Step 10: Wooden Box and Motor Assembly
1. Mount the **wooden box** in place.
2. Mount the **stepper motor bracket** to this box.
3. Connect the motor to the calculation system shaft using **GS19 Coupling - HRJ C40**.
4. Mount the motor using **4 × DIN 912 M6x30 bolts** and nuts.

### Step 11: Electrical System Assembly
1. Place the **control panel cover**.
2. Install **Arduino Nano** and **Arduino Mega** in their positions.
3. Mount the **large and medium breadboards** onto the surface.
4. Mount **MPU-6050** onto the center of the **Kelepçe** using a small breadboard. **Ensure it is exactly centered.**
5. **IMU sensor cables:** Not regular jumper cables — these are aluminum foil wrapped and fiber insulated protected cables.
6. Route the **IMU cable separately** to the panel, not together with other heater and sensor cables.
7. On the inside of the **wooden box**:
   - Mount the **SMPS power supply** vertically on the far left side.
   - Mount **SSR-25** to the ceiling with double-sided adhesive.
   - Mount **TFT LCD** and **4×4** on the slanted outside of the box. Route their cables from the inside of the box to the control panel.
   - The **TFT LCD cable** must be protected like the sensor cables.
   - Connect the 220V power cable to the appropriate **terminal port** inside the box.
   - Mount **Schneider FUSE 10C** to the wall and perform necessary wiring.
   - Connect the **12V Adaptor** to the required terminal port.
8. Mount **JSS-860H** under the control panel. At this time, mount the switch box on the upper part.
9. Connect motor cables to the required ports. Motor cables must be protected.
10. Wire all necessary cables according to the **KiCAD files**.
11. Mount **4×20 LCD** and **4×4 keypad** on the control panel covers.
12. Connect cables from the **calculation system** and screens to their required locations.
13. Finally, power the Arduinos using a **power bank** with power supply cables.

---

## 3. Critical Warnings

| Warning | Detail |
|---------|--------|
| Glass tightening | Do not overtighten the M8 nuts; the glass tube can crack. |
| Glass looseness | Do not leave nuts too loose; the system can leak. |
| Alignment | Both 210 mm sigma profiles must be at the same height. |
| Small tube | Must be level with the surface (flush). |
| IMU cable | Route separately from other heater and sensor cables; use protected (aluminum foil + fiber insulated) cables only. |
| MPU-6050 | Must be exactly centered on the Kelepçe part. |

---

## 4. Checklist

- [ ] Sigma profiles mounted with DIN 7991 M8x20 Phosphate
- [ ] 40×40 Flat Corner Bracket and T-head M8 installed
- [ ] Two 210 mm sigma profiles at same height level
- [ ] Two UCP-201 bearings mounted
- [ ] Upper Cover with heater, Compressed Fiber Gasket, and silicone
- [ ] Temperature sensor mounted with silicone
- [ ] Lower Cover with heater, Threaded Bushing, NBR washer, and silicone
- [ ] Glass Tube Borosilicate 3.3 (100 × 212 mm) installed
- [ ] Kelepçe part passed through glass from inside
- [ ] 4 × M8 Threaded Rod (260 mm) installed with washers and nuts
- [ ] Boş çubuklar between Kelepçe and covers, Threaded Rod passed through
- [ ] Nuts tightened until Boş çubuklar stop rotating
- [ ] SHF 12 Shaft Supports mounted with M6 nuts and bolts
- [ ] Calculation system placed between UCP-201s
- [ ] Aluminum miller passed through calculation system
- [ ] UCP bolts tightened
- [ ] SHF bolts tightened
- [ ] O-rings placed in cover channels
- [ ] Small tube inserted flush with surface level
- [ ] Kapak Sensor part mounted with proximity sensors
- [ ] 4 × M5 Threaded Rod (40 mm), 4 × M5 nuts, 4 × DIN 315 Nut mounted on Kapak Sensor
- [ ] Kapak Sensor parts securely mounted to housing
- [ ] Cables routed through Boş çubuklar edges to align aluminum miller
- [ ] Wooden box mounted in place
- [ ] Step motor bracket mounted to box
- [ ] GS19 Coupling - HRJ C40 connecting motor to calculation system shaft
- [ ] Motor mounted with 4 × DIN 912 M6x30 bolts and nuts
- [ ] Control panel cover placed
- [ ] Arduino Nano and Mega installed
- [ ] Large and medium breadboards mounted on surface
- [ ] MPU-6050 mounted exactly centered on Kelepçe via small breadboard
- [ ] IMU cables protected (aluminum foil + fiber insulated), routed separately to panel
- [ ] SMPS mounted vertically on far left of wooden box
- [ ] SSR-25 mounted to ceiling with double-sided adhesive
- [ ] TFT LCD and 4×4 mounted on slanted outside of box, cables routed to panel
- [ ] TFT LCD cable protected like sensor cables
- [ ] 220V power cable connected to terminal port inside box
- [ ] Schneider FUSE 10C mounted to wall, wiring completed
- [ ] 12V Adaptor connected to terminal port
- [ ] JSS-860H mounted under control panel, switch box mounted on upper part
- [ ] Motor cables connected to required ports, protected
[ ] All cables wired according to KiCAD files
- [ ] 4×20 LCD and 4×4 keypad mounted on control panel covers
- [ ] Cables from calculation system and screens connected to required locations
- [ ] Arduinos powered via power bank with power supply cables

---

## 5. Notes

- All CAD files were prepared in SolidWorks; STEP format is also available.
- Do not force any parts during assembly; glass components are especially sensitive.
- After assembly, follow the `docs/getting-started.md` guide for the first run.
- CAD file names such as **Kelepçe**, **Üst Kapak**, **Alt Kapak**, **Kapak Sensor**, **Boş çubuklar** remain in Turkish as they appear in the CAD files.
