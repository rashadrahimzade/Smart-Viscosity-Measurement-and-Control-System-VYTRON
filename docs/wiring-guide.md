# 🔌 Wiring Guide

Bu rehber, VYTRON sisteminin elektronik kablolamasını ve pin bağlantılarını açıklar. Tüm şemalar `Electronics/` klasöründe KiCad formatında mevcuttur.

## 1. Arduino Mega 2560 (Master MCU)

| Pin | Bileşen | Açıklama |
|-----|---------|----------|
| 53 | TFT_CS | ILI9341 TFT Chip Select |
| 9 | TFT_DC | ILI9341 TFT Data/Command |
| 8 | TFT_RST | ILI9341 TFT Reset |
| 4 | OneWire Bus | DS18B20 sıcaklık sensörü data hattı |
| 2 | Sensor A | Optik sensör A (donanım kesmesi, CHANGE) |
| 3 | Sensor B | Optik sensör B (donanım kesmesi, CHANGE) |
| 7 | SSR_PIN | Isıtıcı kontrolü (Solid State Relay) |
| 36 | Keypad Row 1 | 4×4 Keypad (Mega tarafı) |
| 34 | Keypad Row 2 | 4×4 Keypad (Mega tarafı) |
| 32 | Keypad Row 3 | 4×4 Keypad (Mega tarafı) |
| 30 | Keypad Row 4 | 4×4 Keypad (Mega tarafı) |
| 28 | Keypad Col 1 | 4×4 Keypad (Mega tarafı) |
| 26 | Keypad Col 2 | 4×4 Keypad (Mega tarafı) |
| 24 | Keypad Col 3 | 4×4 Keypad (Mega tarafı) |
| 22 | Keypad Col 4 | 4×4 Keypad (Mega tarafı) |
| TX1 (Pin 18) | Nano RX | Serial1 üzerinden Nano'ya komut gönderir |
| RX1 (Pin 19) | Nano TX | Serial1 üzerinden Nano'dan veri alır |
| 5V / GND | TFT, Sensörler | Besleme |
| SDA (Pin 20) | MPU-6050, LCD | I2C data |
| SCL (Pin 21) | MPU-6050, LCD | I2C clock |

> **Not:** I2C hattında `Wire.setWireTimeout(3000, true)` kullanılmıştır. MPU-6050 ve 20×4 LCD (Nano üzerinden Mega'ya bağlıysa) aynı I2C hattını paylaşabilir; adres çakışmasına dikkat edin.

## 2. Arduino Nano (Motion MCU)

| Pin | Bileşen | Açıklama |
|-----|---------|----------|
| 3 | Stepper Pulse | JSS-860H sürücüsüne pul gönderir |
| 2 | Stepper Direction | JSS-860H yön sinyali |
| 4 | Keypad Row 1 | 4×4 Keypad (Nano tarafı) |
| 5 | Keypad Row 2 | 4×4 Keypad (Nano tarafı) |
| 6 | Keypad Row 3 | 4×4 Keypad (Nano tarafı) |
| 7 | Keypad Row 4 | 4×4 Keypad (Nano tarafı) |
| 8 | Keypad Col 1 | 4×4 Keypad (Nano tarafı) |
| 9 | Keypad Col 2 | 4×4 Keypad (Nano tarafı) |
| 10 | Keypad Col 3 | 4×4 Keypad (Nano tarafı) |
| 11 | Keypad Col 4 | 4×4 Keypad (Nano tarafı) |
| A4 (SDA) | 20×4 LCD | I2C data |
| A5 (SCL) | 20×4 LCD | I2C clock |
| TX | Mega RX1 | Serial üzerinden Mega'dan komut alır |
| RX | Mega TX1 | Serial üzerinden Mega'ya yanıt/gönderi |
| 5V / GND | LCD, Keypad | Besleme |

## 3. Mega ↔ Nano İletişimi (Serial1)

| Mega Pin | Nano Pin | Açıklama |
|----------|----------|----------|
| TX1 (18) | RX | Mega'dan Nano'ya komut (H, G, S) |
| RX1 (19) | TX | Nano'dan Mega'ya durum/geri bildirim |
| GND | GND | Ortak masa referansı |

**Komutlar (Mega → Nano):**
- `H` : Stepper +400 adım (saat yönünde)
- `G` : Stepper -400 adım (saat yönü tersine)
- `S` : Stepper pozisyon sıfırla (`moveTo(0)`)

## 4. Güç ve 220V Bağlantısı

| Bileşen | Bağlantı | Açıklama |
|---------|----------|----------|
| 48V / 12V Güç Kaynağı | JSS-860H | Stepper motor beslemesi |
| 5V Güç Kaynağı | Arduino'lar, sensörler, LCD | Lojik besleme |
| 220V AC | SSR Giriş | Isıtıcı ana akımı |
| SSR Çıkış | 200W Isıtıcı | Isıtıcı kontrol akımı |
| 4.7K Direnç | OneWire Bus (Pin 4) | DS18B20 pull-up |

> **⚠️ Dikkat:** 220V AC bağlantıları sadece yetkili personel tarafından yapılmalıdır. Tüm 220V hatları izole edilmeli ve kutu içine alınmalıdır.

## 5. Kablolama Notları

- MPU-6050 ve optik sensör kabloları **alüminyum ekranlı (shielded)** kablo ile çekilmelidir.
- Stepper motor kabloları güç kablosu olduğundan, hassas sensör kablolarından en az 5 cm mesafe bırakılmalıdır.
- Tüm ortak GND hatları tek bir noktada birleştirilmeli (star grounding).
- DS18B20 için OneWire hattında 4.7K pull-up direnci zorunludur.

## 6. Kontrol Listesi

- [ ] Mega ve Nano ortak GND'ye bağlı
- [ ] TX1-RX ve RX1-TX çapraz bağlanmış
- [ ] TFT_CS/DC/RST pinleri doğru
- [ ] Sensör A ve B interrupt pinleri (2 ve 3) kullanılmış
- [ ] SSR_PIN (7) çıkış olarak ayarlanmış
- [ ] OneWire pull-up direnci takılmış
- [ ] 220V kabloları izole edilmiş
