# 🔬 VYTRON: Akıllı Viskozite Ölçüm ve Kontrol Sistemi

![Platform](https://img.shields.io/badge/MCU-Arduino%20Mega%202560%20%2B%20Nano-00979D?logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/Firmware-C%2B%2B%20(.ino)-blue)
![CAD](https://img.shields.io/badge/CAD-SolidWorks-red)
![CI](https://img.shields.io/badge/GitHub%20Actions-Arduino%20CI-blueviolet)
![Project](https://img.shields.io/badge/T%C3%9CB%C4%B0TAK-2209--A-orange)
![License](https://img.shields.io/badge/License-All%20Rights%20Reserved-red)

VYTRON, **TÜBİTAK 2209-A** üniversite öğrencileri araştırma projeleri destek programı kapsamında geliştirilen, otomatize bir **dışarıya düşen küre viskozimetresidir**. **Stokes Yasası**'na dayanan bu sistem, geleneksel el ile yapılan dışarıya düşen küre yöntemini tam otomatize, yüksek hassasiyetli bir mekatronik sisteme dönüştürür: örnek borusu stepper motor ile döndürülür, kürenin düşüş süresi zamanlanır, sıvı sıcaklığı izlenir ve viskozite hesaplayıp gerçek zamanlı raporlanır.

Bu depoda sistemin **yazılımı (firmware), devre şemaları ve mekanik CAD dosyaları** bulunmaktadır.

<img width="675" height="540" alt="VYTRON Prototip" src="https://github.com/user-attachments/assets/8b889f8e-9948-4315-9d08-34bf66bbcde4" />

---

## 📑 İçerik

- [Nasıl Çalışır](#️-nasıl-çalışır)
- [Özellikler](#-özellikler)
- [Sistem Mimarisi](#-sistem-mimarisi)
- [Donanım](#-donanım)
- [Depo Yapısı](#-depo-yapısı)
- [Başlangıç](#-başlangıç)
- [Kullanım](#️-kullanım)
- [Geliştirici Rehberi](#-geliştirici-rehberi)
- [Güvenlik](#-güvenlik)
- [Harita (Roadmap)](#-harita-roadmap)
- [Lisans](#-lisans)
- [Teşekkürler](#-teşekkürler)

---

## ⚙️ Nasıl Çalışır

Bilinmiş büyüklük ve yoğunluktaki bir küre, muhr edilmiş bir boru içindeki örnek sıvı üzerinden düşer. Küre, iki referans nokta arasında giderken harcadığı süre terminal hızı verir ve bu hız Stokes Yasası yardımıyla dinamik viskoziteye dönüştürülür:

```
η = 2 · (ρs − ρf) · g · r² / (9 · v)
```

| Sembol | Anlamı |
|--------|--------|
| η | Dinamik viskozite (Pa·s) |
| ρs, ρf | Küre / sıvı yoğunluğu (kg/m³) |
| g | Yerçekimi ivmesi (m/s²) |
| r | Küre yarıçapı (m) |
| v | Terminal hız (m/s) |

Küre sınırlı bir boru içinden dolayı, sonuca **duvar-etkisi düzeltme katsayısı** çarpılarak boru sınır etkisi gidereceğine çalışılır.

**Ölçüm döngüsü**
1. Boru başlangıç pozisyonuna döndürülür ve eğim MPU-6050 ile doğrulanır.
2. Sıvı sıcaklığı DS18B20 ile okunur.
3. Boru stepper motor ile çevrilir ve kürenin düşüş süresi optik sensörlerle ölçülür.
4. Viskozite duvar-etkisi düzeltmesiyle hesaplanıp raporlanır.

---

## 📌 Özellikler

- **Otomatize viskozite hesaplama** – Stokes Yasası ve duvar-etkisi düzeltmesiyle.
- **İkili mikrobirim mimarisi** – Senkronize Arduino Mega ↔ Arduino Nano iletişimi.
- **Gerçek zamanlı sensör işleme** – Sıcaklık ve eğim/oryantasyon takibi.
- **EMI'ye dayanıklı elektronik tasarımı** – Stepper sürücü ve sensör hatlarında filtreleme.
- **Kalıp kapalı boru pozisyonlama** – MPU-6050 eğim geri bildirimiyle.
- **Kimyasal direncli, sızdırmaz mekanik yapı** – NBR O-ring ve Viton (FKM) kontaşlarla.
- **İkili dil arayüzü (Türkçe / İngilizce)** – ILI9341 TFT LCD üzerinde.
- **4×4 matris tuş takımı** – Mega ve Nano tarafında ayrı ayrı.
- **20×4 I2C LCD** – Nano tarafında hareket durumu için.
- **SSR ısıtıcı kontrolü** – Hedef sıcaklığa ETA (kalan süre) gösterimiyle.
- **Son 5 ölçüm kaydı** – Ekran üzerinde geçmiş görüntüleme.
- **EEPROM kalibrasyon kalıcılığı** – Küre yoğunluğu, K katsayısı, duvar faktörü ve hedef sıcaklık saklama.
- **Optik küre algılama sensörleri** – Donanım kesmesi ile mikrosaniye hassasiyetinde zamanlama.
- **AccelStepper profilleme** – Yumuşak motor ivmelenme ve yavaşlama.
- **Yazılım seviyesinde gürültü azaltma** – I2C zaman aşımlı, kesme debouncing, hareketli ortalama filtresi.

---

## 🧠 Sistem Mimarisi

| Denetleyici | Rol |
|-------------|-----|
| **Arduino Mega 2560** (Ana MCU) | Kontrol mantığı, sıcaklık takibi, viskozite hesaplama, MPU-6050 ile pozisyon, ölçüm sıralaması, TFT arayüz |
| **Arduino Nano** (Hareket MCU) | Boru pozisyon kontrolü, stepper sürücü yönetimi, ikincil arayüz |

```
 ┌──────────────┐                                            ┌──────────────┐
 │ Arduino Mega │ ◄────────────────────────────────────────► │ Arduino Nano │
 │  (Master)    │          Serial1 iletişimi                  │  (Motion)    │
 └──────┬───────┘                                            └──────┬───────┘
        │                                                           │
 DS18B20 (sıcaklık), MPU-6050 (eğim), ILI9341 TFT, tuş takımı     JSS-860H ► NEMA 34
        │                                                           │
   Optik Sensör A & B (küre algılama)                          20×4 I2C LCD
```

**Mega ↔ Nano komutları (Serial1):**
- `H` : Stepper +400 adım (saat yönünde)
- `G` : Stepper -400 adım (saat yönünün tersi)
- `S` : Stepper pozisyonu sıfırla (`moveTo(0)`)

---

## 🔩 Donanım

| Bileşen | Amacı |
|---------|-------|
| Arduino Mega 2560 | Ana denetleyici |
| Arduino Nano | Hareket denetleyici |
| DS18B20 | Dijital sıcaklık sensörü |
| MPU-6050 | 6 eksenli jiro/akselerometre (eğim ve pozisyon takibi) |
| NEMA 34 stepper motor | Yüksek torklu boru döndürme |
| JSS-860H sürücü | Stepper motor sürücüsü |
| ILI9341 TFT LCD | Ana arayüz (SPI, TR/EN) |
| 20×4 I2C LCD | Nano hareket durumu ekranı |
| 4×4 matris tuş takımı × 2 | Kullanıcı girişi (Mega ve Nano) |
| SSR (Solid State Relay) | 200W ısıtıcı kontrolü |
| 220V / 200W ısıtıcı | Sıvı ısıtma |
| NBR O-ring, Viton (FKM) kontaş | Sızdırmazlık ve kimyasal direnci |
| 48V / 12V güç kaynağı | Stepper ve mantık besleme |

**Mekanik tasarım:** SolidWorks ile modellenmiş ve montaj edilmiş, özel mühendislik sızdırmazlık kanallarıyla.

**Elektronik:** KiCad şeması `Electronics/` klasöründe; EMI önlemi olarak alüminyum pantalla kablolar, ferrit çekirdekler ve kondansatör filtreleme kullanılmıştır.

---

## 📁 Depo Yapısı

```
Smart-Viscosity-Measurement-and-Control-System-VYTRON/
├── .github/
│   ├── ISSUE_TEMPLATE/     # Hata ve özellik bildirim şablonları
│   ├── PULL_REQUEST_TEMPLATE.md
│   └── workflows/
│       └── arduino-ci.yml  # GitHub Actions Arduino derleme CI
├── Software/
│   ├── Mega_IDE.ino        # Arduino Mega 2560 (ana MCU) firmware
│   └── Nano_IDE.ino        # Arduino Nano (hareket MCU) firmware
├── Electronics/
│   ├── Smart Viscosity Measurement and Control System.kicad_sch   # KiCad devre şeması
│   ├── Dual-microcontroller control panel and power architecture..jpg
│   ├── Detail_of_Parts/                 # Bileşen ve prototip fotoğrafları
│   └── Interference_Mitigation/         # EMI/RFI gürültü önleme fotoğrafları ve notları
├── Mechanical/
│   ├── 3D Model/                # SolidWorks CAD dosyaları (.sldprt, .sldasm) ve STEP
│   ├── CFD_Analysis/            # Ansys Fluent CFD simülasyon dosyaları
│   ├── Mechanical Calculations/ # Mekanik hesaplama dosyaları
│   └── Techincal_Drawing/       # Teknik çizimler (PDF)
├── docs/
│   ├── getting-started.md       # Kurulum ve ilk çalıştırma kılavuzu
│   ├── wiring-guide.md          # Detaylı pin bağlantı kılavuzu
│   ├── assembly-guide.md        # Mekanik montaj kılavuzu
│   ├── calibration.md           # Kalibrasyon prosedürü (HD-46VG, 40 °C / 46 cSt)
│   ├── cfd-analysis.md          # Ansys Fluent CFD akış analizi
│   ├── comparison.md            # VYTRON vs laboratorio viskozimetre karşılaştırması
│   ├── safety.md                # Güvenlik kılavuzu (220V, ısı, mekanik)
│   ├── pricing.md               # Üretim maliyeti analizi
│   ├── software-architecture.md # Yazılım mimarisi ve algoritmalar
│   ├── mechanical-design.md     # Mekanik tasarım ve akışkan dinamikleri
│   ├── electronics/interference-mitigation.md
│   ├── bom/
│   │   ├── bom-index.md         # Malzeme listesi (BOM) genel özet
│   │   ├── electronics-bom.md   # Elektronik BOM
│   │   ├── mechanical-bom.md    # Mekanik BOM
│   │   └── files/               # BOM_Electronic_VYTRON.xlsx, BOM_Mechanic_VYTRON.xlsx
│   ├── tubitak/                 # TÜBİTAK 2209-A raporu ve makale
│   └── use-cases/               # Akademik, otomotiv, gıda, petrokimya, ilaç kullanım senaryoları
├── .gitignore
├── CHANGELOG.md                 # Sürüm geçmişi
├── CODE_OF_CONDUCT.md           # Davranış kuralları
├── CONTRIBUTING.md              # Katkıda bulunma kılavuzu
├── LICENSE.txt                  # Tüm Hakları Saklıdır lisansı
├── SECURITY.md                  # Güvenlik politikası
└── README.md                    # Projeye genel bakış (bu dosya)
```

---

## 🚀 Başlangıç

### Önkoşullar

**Yazılım:**
- [Arduino IDE](https://www.arduino.cc/en/software) 2.x (veya PlatformIO)
- Arduino Kütüphanesi Yöneticisi üzerinden kurulan kütüphaneler:
  - `Adafruit_ILI9341` & `Adafruit_GFX`
  - `DallasTemperature` & `OneWire`
  - `AccelStepper`
  - `LiquidCrystal_I2C`
  - `Keypad`

**Donanım:**
- Montaj edilmiş VYTRON prototipi (`docs/assembly-guide.md` ve `docs/wiring-guide.md` bkz.)
- Arduino Mega 2560, Arduino Nano
- NEMA 34 stepper motor + JSS-860H sürücü
- DS18B20 sıcaklık sensörü, MPU-6050 eğim sensörü
- ILI9341 TFT LCD (SPI), 2× 4×4 tuş takımı, 20×4 I2C LCD
- Solid State Relay (SSR), 220V / 200W ısıtıcı
- NBR O-ring ve Viton (FKM) contaları

### Kurulum ve Yükleme

1. Depoyu klonlayın:
   ```bash
   git clone https://github.com/rashadrahimzade/Smart-Viscosity-Measurement-and-Control-System-VYTRON.git
   cd Smart-Viscosity-Measurement-and-Control-System-VYTRON
   ```
2. Sistemi `Electronics/` şemalarına göre kablolayın.
3. **Arduino Mega** için:
   - `Software/Mega_IDE.ino` dosyasını Arduino IDE'de açın.
   - Board: **Arduino Mega or Mega 2560** seçin, doğru COM portunu belirleyin ve yükleyin.
4. **Arduino Nano** için:
   - `Software/Nano_IDE.ino` dosyasını açın.
   - Board: **Arduino Nano** (klonunuza göre doğru bootloader'ı seçin) ve COM portunu belirleyin ve yükleyin.
5. Sistemi güçlendirin ve seri monitörden sensör okumalarını doğrulayın.

### İlk Çalıştırma Kontrol Listesi

- [ ] TFT ekran VYTRON logosunu gösterir, ardından dil seçimi çıkar
- [ ] DS18B20 mantık sıcaklığını okur (~20–25 °C)
- [ ] MPU-6050 stabil roll/pitch değerleri gösterir
- [ ] Nano LCD küre seçimi ekranını gösterir
- [ ] Stepper motor Mega'dan gelen seri komutlara (H / G / S) tepki verir
- [ ] SSR hedef sıcaklık ayarlandığında ısıtıcıyı kontrol eder
- [ ] Optik sensörler küre geçişini algılar (sensorAktif bayrağı kontrol edin)

---

## 🕹️ Kullanım

1. Boruyu örnek sıvıyla doldurun ve NBR O-ringleriyle muhrleyin.
2. Küreyi (16 mm, 17 mm veya 18 mm) ekleyin.
3. TFT ekrandan dil (1 = Türkçe, 2 = İngilizce) seçin.
4. Küre tipini seçin; sistem `bilyeYogunluk` ve `bilyeK_Sabiti` değerlerini otomatik yükler.
5. Sıvı yoğunluğunu girin.
6. MPU-6050 kalibrasyonu yapın ve hedef sıcaklığı ayarlayın.
7. Sıcaklık hedefe ulaştığında ölçüm döngüsünü başlatın.
8. Dinamik ve kinematik viskozite değerlerini ekran üzerinde okuyun.

**Küre seçenekleri:**
| Küre | Yoğunluk (g/cm³) | K Katsayısı | Açıklama |
|------|------------------|-------------|----------|
| 16 mm | 16.75 | 0.870 | Hafif küre; yüksek döndürme hızı gerektirmez |
| 17 mm | 7.78 | 1.482 | Orta küre; standart döndürme hızı |
| 18 mm | 7.79 | 0.831 | Ağır küre; standart döndürme hızı |

**Duvar-etkisi faktörü:** `fSabiti = 0.952` (Ladenburg yöntemiyle hesaplanmış, HD-46VG referans sıvı ile kalibre edilmiştir).

---

## 👨‍💻 Geliştirici Rehberi

### Kod Standartları (Arduino / Yerleşik)

- Tutarlı girinti kullanın (2 veya 4 boşluk).
- Performans kritik kesme (ISR) veya döngü kodunda `String` sınıfından kaçının (bellek parçalanmasını önlemek için).
- Kesme hizmet rutinlerini (ISR) kısa tutun; içinde `delay()` veya `Serial.print()` çağrısı yapmayın.
- ISR ve `loop()` arasında paylaşılan değişkenler için `volatile` kullanın.
- Pin tanımlarını sketch'in en üstünde `#define` ile belirtin.
- Türkçe ve İngilizce arayüz etiketlerini tutarlı tutun.

### Katkıda Bulunma

Daha fazla bilgi için [`CONTRIBUTING.md`](./CONTRIBUTING.md) dosyasına bakın. Özetle:

1. Depoyu fork'layın ve `main` dalından yeni bir dal oluşturun.
2. Değişikliklerinizi odaklanmış bir commit'te yapın.
3. Değişiklik kullanım, kablolama veya montajı etkiliyorsa `docs/` içindeki belgeleri güncelleyin.
4. Mümkünse gerçek donanımla test edin.
5. Neyi değiştirdiğinizi ve nedenini açıklayan bir pull request açın.

### Hata ve Özellik Bildirimleri

Hata veya özellik önerisi için [.github/ISSUE_TEMPLATE/](./.github/ISSUE_TEMPLATE/) şablonlarını kullanın. Şunları eklemeyi unutmayın:

- Net bir başlık ve açıklama
- Yeniden üretme adımları (varsa)
- Donanım sürümü (Mega 2560, Nano, JSS-860H vb.)
- Firmware sürümü / commit hash'i
- Fotoğraf veya ekran görüntüsü (varsa)
- Beklenen ve gerçek davranış

### Sürekli Entegrasyon (CI)

Depoda GitHub Actions ile Arduino CI kurulumu vardır (`.github/workflows/arduino-ci.yml`). Her `main` branch'e push veya pull request'te:

- Arduino CLI ile ortam kurulumu
- Gerekli kütüphanelerin yüklenmesi
- `Mega_IDE.ino` (Arduino Mega 2560) ve `Nano_IDE.ino` (Arduino Nano) derleme denetimi

---

## ⚠️ Güvenlik

Sistem **220V AC**, yüksek sıcaklık ve hareketli mekanik parçalar içerir. Kullanmadan önce [`docs/safety.md`](./docs/safety.md) kılavuzunu mutlaka okuyun.

**Önemli uyarılar:**
- 220V AC bağlantıları yalnızca yetkili ve yetkin personel tarafından yapılmalıdır.
- Tüm 220V kabloları çift yalıtılmış ve uygun bir kutu içinde tutulmalıdır.
- 200W ısıtıcı ve cam boru yanma riski taşır; ısıtıcı çalışırken elinizi buna temas ettirmeyin.
- NEMA 34 stepper motor yüksek tork üretir; dönüş bölgesine el veya giysinizi yaklaştırmayın.
- Cam boru kırılgandır; impact veya düşme sonucu kırılabilir.

Acil durumda: **220V'yi güç kaynağından kesin**, ardından motor acil anahtarını kullanın ve Arduinoları USB'den ayırın.

---

## 🗺️ Harita (Roadmap)

- [ ] Referans viskozite sıvılarıyla kalibrasyon ve doğruluk raporu
- [ ] Veri kaydı (SD kart / PC)
- [ ] Sıcaklık kontrollü ölçüm odası
- [ ] Kablolama şeması ve bitmiş prototip fotoğrafları
- [ ] SD kart veya PC üzerinden otomatik veri günlüğü

---

## 📄 Lisans

Tam lisans metni: [LICENSE.txt](./LICENSE.txt)

**Copyright © 2026 Rashad Rahimzade. Tüm hakları saklıdır.**

Bu depodaki her şey (yazılım, devre şemaları, mekanik CAD dosyaları, belgeler ve görseller), yazarın önceden yazılı izni olmadan kopyalanamaz, değiştirilemez, dağıtılmaz veya ticari ve não-ticari başka bir projede kullanılamaz.

İzin talep etmek için yazarla iletişime geçin: **rahimzaderashad1@gmail.com**

---

## 🙏 Teşekkürler

Bu proje **TÜBİTAK 2209-A** Üniversite Öğrencileri Araştırma Projeleri Destek Programı ile desteklenmiştir.

**Yazar:** [@rashadrahimzade](https://github.com/rashadrahimzade)

---

### İlgili Belgeler

| Belge | Açıklama |
|-------|----------|
| [`docs/getting-started.md`](./docs/getting-started.md) | İlk kurulum ve çalıştırma kılavuzu |
| [`docs/wiring-guide.md`](./docs/wiring-guide.md) | Detaylı pin bağlantı tablosu |
| [`docs/assembly-guide.md`](./docs/assembly-guide.md) | Mekanik montaj kılavuzu |
| [`docs/calibration.md`](./docs/calibration.md) | Kalibrasyon prosedürü |
| [`docs/safety.md`](./docs/safety.md) | Güvenlik kılavuzu |
| [`docs/pricing.md`](./docs/pricing.md) | Üretim maliyeti analizi |
| [`docs/cfd-analysis.md`](./docs/cfd-analysis.md) | Ansys Fluent CFD analizi |
| [`docs/comparison.md`](./docs/comparison.md) | Laboratuvar viskozimetre karşılaştırması |
| [`docs/bom/bom-index.md`](./docs/bom/bom-index.md) | Malzeme listesi (BOM) |
| [`CHANGELOG.md`](./CHANGELOG.md) | Sürüm geçmişi |
| [`CONTRIBUTING.md`](./CONTRIBUTING.md) | Katkıda bulunma kılavuzu |
| [`CODE_OF_CONDUCT.md`](./CODE_OF_CONDUCT.md) | Davranış kuralları |
| [`SECURITY.md`](./SECURITY.md) | Güvenlik politikası |









