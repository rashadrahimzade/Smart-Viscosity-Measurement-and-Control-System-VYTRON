# 🧮 Software-Level Noise Mitigation & Signal Conditioning

This directory documents the firmware algorithms, interrupt debouncing strategies, and signal filtering techniques implemented in software to handle sensor noise and communication instability.

---

### 🛡️ Firmware Noise Mitigation Techniques

* **I2C Bus Lockup Prevention (`Wire.setWireTimeout`):**
  * Electrical transients can cause missing clock pulses on the I2C bus, freezing traditional `Wire.h` implementations.
  * Configured `Wire.setWireTimeout(3000, true)` on Arduino Mega to automatically reset and recover the I2C bus in case of noise-induced bus hang-ups.

* **Optical Sensor Glitch Filtering & Interrupt Debouncing:**
  * High-precision optical sensors (`SENSOR_A` & `SENSOR_B`) use hardware interrupts for sphere detection.
  * Implemented a software time-threshold check (`micros() - baslangicZamani > 300000`) inside the ISR (`sensorTetikInterrupt`) to reject false optical triggers caused by ambient light spikes or electrical ringing.

* **Accelerometer Signal Averaging (Moving Average Filter):**
  * Raw MPU-6050 readings suffer from physical system vibrations and sensor noise.
  * The `analizYap()` function samples accelerometer data iteratively over a 5-second interval to calculate a clean average tilt angle (`temizOrtalama`), eliminating high-frequency mechanical jitter.

* **Controlled Motor Acceleration Profiling:**
  * Sudden stepper motor starts introduce back-EMF spikes and power rail voltage dips.
  * Utilized the `AccelStepper` library to enforce controlled acceleration and deceleration ramps, reducing inductive noise spikes on the power supply.

# 🧮 Software-Level Noise Mitigation & Signal Conditioning

This directory documents the firmware routines, interrupt debouncing strategies, and signal conditioning algorithms implemented across the VYTRON embedded software architecture to eliminate noise and ensure system stability.

---

### 1. I2C Bus Lockup Protection (`Wire.setWireTimeout`)

Transient electrical noise on signal lines can corrupt clock pulses on the I2C bus, causing standard microcontrollers to freeze indefinitely. To prevent system lockups, a 3-millisecond hardware timeout with auto-reset capability is configured on the Arduino Mega:

```cpp
// Configures I2C bus timeout to automatically reset communication during transient noise
Wire.begin(); 
Wire.setClock(100000); 
Wire.setWireTimeout(3000, true);

---

void sensorTetikInterrupt() {
  if (!sensorAktif) return;
  bool sA = digitalRead(SENSOR_A);
  bool sB = digitalRead(SENSOR_B);
  
  if (!olcumBasladi && !olcumBitti) {
    if (sA == sB) {
      baslangicZamani = micros();
      olcumBasladi = true;
    }
  } 
  else if (olcumBasladi && !olcumBitti) {
    if (sA != sB) {
      // Glitch Filter: Ignores spurious noise spikes occurring within 300ms
      if (micros() - baslangicZamani > 300000) { 
        bitisZamani = micros();
        olcumBasladi = false;
        olcumBitti = true;
      }
    }
  }
}

---

void analizYap(float hedefDerece, float katsayi) {
  float toplam = 0; 
  int sayac = 0; 
  unsigned long basla = millis();

  // Continuously collects accelerometer samples for 5 seconds to eliminate mechanical jitter
  while (millis() - basla < 5000) { 
    toplam += mpuOku(); 
    sayac++; 
    delay(10); 
  }

  float temizOrtalama = (sayac > 0) ? (toplam / sayac) : sonYatay; 
  sonHesaplananStep = round(abs((hedefDerece - temizOrtalama) * katsayi));
}

---

// Enforces controlled acceleration ramps to prevent sudden current draws and power rail dips
stepper.setMaxSpeed(GUNCEL_HIZ);
stepper.setAcceleration(GUNCEL_IVME);
