# ⚡ Software-Level Interference & Noise Mitigation

This document describes the firmware-level algorithms and signal conditioning techniques implemented in the VYTRON system to handle electrical noise, mechanical vibration, sensor instability, and communication errors.

---

## 1. I2C Bus Lockup Prevention (`Wire.setWireTimeout`)
## 4. Controlled Motor Acceleration Profiling

**Code location:** `Software/Nano_IDE.ino`, `loop()` and `hareketEkraniHazirla()` functions

```cpp
// Default values
int GUNCEL_HIZ = 3200;
int GUNCEL_IVME = 5000;

// Ball-specific profiles
if (key == '1') { GUNCEL_HIZ = 4200; GUNCEL_IVME = 3500; bilyeEtiketi = "16mm"; }
if (key == '2') { GUNCEL_HIZ = 4200; GUNCEL_IVME = 3000; bilyeEtiketi = "17mm"; }
if (key == '3') { GUNCEL_HIZ = 4000; GUNCEL_IVME = 2400; bilyeEtiketi = "18mm"; }

// Temperature mixing mode (slow, smooth)
stepper.setMaxSpeed(1000);
stepper.setAcceleration(800);
```

**What it does:** Uses the `AccelStepper` library to enforce controlled acceleration and deceleration ramps. Speed and acceleration values are adjusted per ball diameter (16 mm, 17 mm, 18 mm). During temperature mixing mode (`key == 'D'`), speed drops to 1000 and acceleration to 800 for smooth, vibration-free motion.

**Why this was chosen:** Sudden stepper motor starts introduce back-EMF spikes and power rail voltage dips that can couple into sensitive analog sensor lines (MPU-6050, DS18B20). Controlled acceleration reduces inductive noise on the power supply and prevents mechanical shock to the tube assembly.

---

## 5. DS18B20 Sensor Error Detection & SSR Safety Cutoff

**Code location:** `Software/Mega_IDE.ino`, `loop()` function

```cpp
if (guncelSicaklik == -127.0 || guncelSicaklik == 85.0) {
  // Sensor error detected
  digitalWrite(SSR_PIN, LOW);  // Cut heater power
  sensorHata = true;
}
```

**What it does:** Continuously monitors the DS18B20 temperature reading. If the value equals -127.0°C or 85.0°C (DS18B20 error codes for open circuit or short circuit), the SSR heater control pin (`SSR_PIN`, pin 7) is set to LOW, cutting power to the 200W heater.

**Why this was chosen:** A faulty DS18B20 can report erroneous temperatures. Without this check, the system might interpret an error value as a valid low temperature and keep the heater running indefinitely (runaway heating). The dual value check covers both common DS18B20 failure modes.

**Code location:** `Software/Mega_IDE.ino`, `setup()` function

```cpp
Wire.begin();
Wire.setClock(100000);
Wire.setWireTimeout(3000, true);
```

**What it does:** Configures the Arduino Mega's I2C bus to automatically reset and recover after 3000 ms of inactivity or clock stretching.

**Why this was chosen:** Electrical transients from the stepper motor driver and 220V heater SSR can induce missing clock pulses on the I2C bus. Without timeout protection, the standard `Wire.h` library can hang indefinitely waiting for a clock pulse that never arrives. The `setWireTimeout(3000, true)` enables automatic bus recovery, preventing the system from freezing during noise events.

---

## 2. Optical Sensor Glitch Filtering & Interrupt Debouncing

**Code location:** `Software/Mega_IDE.ino`, `sensorTetikInterrupt()` function

```cpp
void sensorTetikInterrupt() {
  // ...
  if (sA == sB) {
    baslangicZamani = micros();  // Start timing when ball passes Sensor A
  }
  if (sA != sB) {
    if (micros() - baslangicZamani > 300000) {  // 300 ms debounce filter
      bitisZamani = micros();  // Stop timing when ball passes Sensor B
    }
  }
}
```

**What it does:** Uses hardware interrupts on pins 2 and 3 (`SENSOR_A`, `SENSOR_B`) with CHANGE mode to detect the falling sphere. A 300-microsecond time threshold (`micros() - baslangicZamani > 300000`) rejects false triggers.

**Why this was chosen:** Optical sensors are susceptible to ambient light spikes and electrical ringing on the signal lines. Without debouncing, a single ball passage could generate multiple false interrupts, corrupting the fall-time measurement. The 300 ms filter ensures only genuine ball crossings are registered as start/stop events.

**Logic conditions:**
- `sA == sB`: Ball has passed Sensor A — measurement starts.
- `sA != sB`: Ball is between sensors or has passed Sensor B — measurement stops (if debounce threshold is met).

---

## 3. Accelerometer Signal Averaging (Moving Average Filter)

**Code location:** `Software/Mega_IDE.ino`, `analizYap()` function

```cpp
void analizYap(float hedefDerece, float katsayi) {
  unsigned long basla = millis();
  float toplam = 0;
  int sayac = 0;
  while (millis() - basla < 5000) {
    toplam += mpuOku();
    sayac++;
    delay(10);
  }
  float ortalama = toplam / sayac;
}
```

**What it does:** Samples MPU-6050 accelerometer data iteratively over a 5-second window (`millis() - basla < 5000`) and calculates a clean average tilt angle.

**Why this was chosen:** Raw MPU-6050 readings contain high-frequency noise from mechanical vibrations (stepper motor, fluid movement, enclosure resonance). A simple single-sample read would be too jittery for precise tube positioning. The 5-second moving average smooths out mechanical jitter while remaining responsive enough for operator calibration.