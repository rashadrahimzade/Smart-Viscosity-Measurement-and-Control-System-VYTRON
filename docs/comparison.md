# ⚖️ Karşılaştırma: VYTRON vs Komersiyel Düşen-Topluk Viskozimetreler

Bu belge, VYTRON sisteminin endüstriyel ve laboratuvar seviyesindeki komersiyel düşen-topluk viskozimetrelerle karşılaştırılmasını içerir. Tüm değerler yaklaşık ve referans amaçlıdır.

## 1. Özellik Karşılaştırma Tablosu

| Özellik | VYTRON | Komersiyel Model A | Komersiyel Model B |
|---------|--------|-------------------|-------------------|
| **Fiyat** | Düşük (BOM + işçilik) | Yüksek | Çok Yüksek |
| **Otomatikasyon** | Dual MCU, tam otomatik | Manuel / Yarı otomatik | Tam otomatik |
| **Gerçek Zamanlı ETA** | Var (ısıtıcıyla) | Yok | Var |
| **Çift Dil Arayüzü (TR/EN)** | Var | Yabancı dil | Yabancı dil |
| **Açık Donanım / Şema** | Evet (KiCad) | Hayır | Hayır |
| **Açık Kaynak Firmware** | Evet (Arduino .ino) | Hayır | Hayır |
| **Kullanıcı Kalibrasyonu** | Kullanıcı tanımlı | Fabrika kalibre | Fabrika kalibre |
| **Sızdırmazlık Sistemi** | NBR O-ring + Viton (FKM) | Standart conta | Özel conta |
| **CFD Doğrulanmış Tasarım** | Evet (Ansys Fluent) | Genelde yok | Evet |
| **Veri Kaydı** | Yok (planlı) | Var | Var |
| **220V Isıtıcı Kontrolü** | SSR + PID planlı | Var | Var |
| **MPU-6050 Eğim İzleme** | Var | Yok | Var |
| **Optik Top Tespiti** | Donanım kesmesi ile mikro-saniye | Foto optik | Foto optik |
| **Montaj Kolaylığı** | Kullanıcı monte edilebilir | Fabrika monte | Fabrika monte |

## 2. Avantajlar ve Dezavantajlar

### ✅ VYTRON'un Avantajları
- **Maliyet**: Komersiyel cihazların yaklaşık %20–%40'ı civarında tahmini maliyet.
- **Şeffaflık**: Tüm CAD dosyaları, şemalar ve firmware açık; kullanıcı değiştirebilir, iyileştirebilir.
- **Öğrenme / Araştırma**: TÜBİTAK 2209-A projesi olarak üniversite laboratuvarları ve öğrenci deneyleri için ideal.
- **Esneklik**: Top çapı, sıvı türü, 측정 aralığı ve kalibrasyon parametreleri kullanıcı tarafından değiştirilebilir.
- **Yerli Üretim Potansiyeli**: Mekanik parçalar yerli işlenebilir, elektronik yerli satıcılardan temin edilebilir.

### ❌ VYTRON'un Dezavantajları
- **Veri Kaydı**: SD kart veya PC bağlantısıyla otomatik veri kaydı henüz yok (roadmap'te var).
- **Servis Garantisi**: Komersiyel cihazlarda fabrika garanti ve servis ağrı mevcut; VYTRON'da kullanıcı kendisi bakım yapar.
- **Kalite Sertifikası**: Endüstriyel kalite sertifikası (ISO, CE vb.) henüz alınmamış olabilir.

## 3. Ne Zaman Hangisi Seçilmeli?

| Senaryo | Önerilen Çözüm |
|---------|---------------|
| Üniversite laboratuvarı, öğrenci projesi | **VYTRON** (düşük maliyet, açık kaynak, öğrenme odaklı) |
| Endüstriyel üretim hattı, kesinlik garanti | Komersiyel Model A / B |
| Ar-Ge merkezi, özelleştirilmiş ölçüm | **VYTRON** (firmware ve CAD'de değişiklik yapılabilir) |
| Kalibre sertifikalı rapor gerekiyor | Komersiyel (fabrika kalibrasyonu) |

## 4. İlgili Dosyalar

- `docs/bom/bom-index.md` — Malzeme listesi
- `docs/pricing.md` — Maliyet ve fiyatlandırma analizi
- `docs/calibration.md` — Kalibrasyon prosedürü