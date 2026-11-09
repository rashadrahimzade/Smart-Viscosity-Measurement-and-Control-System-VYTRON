# ⚡ Elektronik Malzeme Listesi (BOM) — Şablon

VYTRON sisteminin elektronik bileşenleri için **şablon** alışveriş listesi. Parça kodları, miktarları ve fiyatları sizin projenize göre doldurmalısınız. Tüm şemalar `Electronics/` klasöründeki KiCad dosyalarında mevcuttur.

## 📁 Excel Dosyası

Gerçek elektronik BOM'nız şu konumda mevcuttur:

- `docs/bom/files/elektronik-bom.xlsx` (kaynak: `BOM_Electronic_VYTRON.xlsx`)

> Dosya Masaüstünden projeye kopyalanmıştır. İçerik güncellemesi gerekiyorsa doğrudan bu dosyada düzenleme yapabilirsiniz.

---

## 1. Mikrokontrolörler (Örnek Şablon)

| Parça | Adet | Parça Kodu (MPN) | Satıcı | Birim Fiyat | Toplam Fiyat | Not |
|-------|------|------------------|--------|-------------|--------------|-----|
| Arduino Mega 2560 | 1 | | | | | Master kontrol |
| Arduino Nano | 1 | | | | | Motion kontrol (bootloader dikkat) |
| USB kablosu (A-Micro / A-Mini) | 2 | | | | | Programlama ve güç |

## 2. Sensörler (Örnek Şablon)

| Parça | Adet | Parça Kodu (MPN) | Satıcı | Birim Fiyat | Toplam Fiyat | Not |
|-------|------|------------------|--------|-------------|--------------|-----|
| DS18B20 sıcaklık sensörü (waterproof) | 1 | | | | | 4.7K pull-up direnci gerekli |
| MPU-6050 (6 eksen IMU) | 1 | | | | | I2C, eğim/pozisyon |
| Optik sensör (düşen top tespiti) | 2 | | | | | SENSOR_A, SENSOR_B |

## 3. Ekranlar ve Giriş (Örnek Şablon)

| Parça | Adet | Parça Kodu (MPN) | Satıcı | Birim Fiyat | Toplam Fiyat | Not |
|-------|------|------------------|--------|-------------|--------------|-----|
| ILI9341 TFT LCD (240×320, SPI) | 1 | | | | | Mega üzerinde ana arayüz |
| 20×4 I2C Karakter LCD | 1 | | | | | Nano üzerinde durum ekranı |
| 4×4 Matris Keypad | 2 | | | | | Bir tane Mega, bir tane Nano |

## 4. Motor ve Güç (Örnek Şablon)

| Parça | Adet | Parça Kodu (MPN) | Satıcı | Birim Fiyat | Toplam Fiyat | Not |
|-------|------|------------------|--------|-------------|--------------|-----|
| NEMA 34 Stepper Motor | 1 | | | | | Yüksek tork, tüp döndürme |
| JSS-860H Stepper Sürücüsü | 1 | | | | | 48V besleme |
| 48V Güç Kaynağı | 1 | | | | | Motor beslemesi |
| 5V Güç Kaynağı | 1 | | | | | MCU ve sensör beslemesi |
| Solid State Relay (SSR) | 1 | | | | | 220V Isıtıcı kontrolü |
| 200W Isıtıcı (220V) | 1 | | | | | Sıvı ısıtma |

## 5. Elektrik Parçaları (Örnek Şablon)

| Parça | Adet | Parça Kodu (MPN) | Satıcı | Birim Fiyat | Toplam Fiyat | Not |
|-------|------|------------------|--------|-------------|--------------|-----|
| 4.7K Ω Direnç | 1 | | | | | DS18B20 OneWire pull-up |
| Ferrit Çekirdek | — | | | | | EMI azaltma |
| Alüminyum Ekranlı Kablo | — | | | | | Sensör ve motor hatları |
| Kondansatör (güç filtresi) | — | | | | | Power rail dips önleme |
| Kablo, konnektor, klemens | — | | | | | 220V ve lojik ayrı |

## 6. Kontrol Listesi

- [ ] Arduino Mega ve Nano doğru bootloader'a sahip mi?
- [ ] TFT_CS/DC/RST pinleri şemaya uygun mu?
- [ ] 220V kabloları izole ve kutu içinde mi?
- [ ] Stepper motor kabloları sensör kablolarından yeterli mesafede mi?

## 📎 İlgili Dosyalar

- KiCad Şema: `Electronics/Smart Viscosity Measurement and Control System.kicad_sch`
- EMI/RFI Rehberi: `docs/electronics/interference-mitigation.md`
- Kablolama Rehberi: `docs/wiring-guide.md`