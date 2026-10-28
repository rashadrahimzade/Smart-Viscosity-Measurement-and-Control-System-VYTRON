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