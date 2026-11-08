# 💰 Ürün Fiyatlandırması ve Maliyet Analizi

Bu dosya, VYTRON sisteminin tahmini BOM maliyetini, montaj ve kalibrasyon giderlerini ve endüstriyel rakiplere göre fiyat avantajını özetlemektedir. Tüm rakamlar **2026 ortalamaları**dır ve satıcıya, bölgeye ve miktara göre değişebilir.

## 1. BOM Maliyet Özeti

| Kategori | Açıklama | Tahmini Maliyet (TL) |
|----------|----------|---------------------|
| **Elektronik** | Arduino Mega 2560, Arduino Nano, NEMA 34, JSS-860H, DS18B20, MPU-6050, ILI9341 TFT, 2×4×4 Keypad, 20×4 LCD, SSR, 200W Isıtıcı, güç kaynakları, kablolar, ferritler | — |
| **Mekanik** | Cam tüp (iç/dış), NBR O-ring, Viton conta, alüminyum çatı, vida-somun, motor montaj, yatak | — |
| **Diğer** | Montaj araçları, sızdırmazlık macunu, test sıvıları | — |
| **Toplam BOM** | — | **—** |

> Detaylı parça bazlı fiyatlar için:  
> - `docs/electronics/electronics-bom.md`  
> - `docs/mechanical/mechanical-bom.md`

---

## 2. Ek Maliyet Kalemleri

| Kalem | Açıklama | Tahmini Maliyet (TL) |
|-------|----------|---------------------|
| Montaj işçiliği | Mekanik montaj, kablolama, ilk çalıştırma (saat bazlı) | — |
| Kalibrasyon ekipmanı | Referans viskozite sıvıları (silikon yağı vb.), termometre, stasyoner | — |
| Yazılım geliştirme | Firmware, arayüz, kalibrasyon prosedürleri (geliştirici saati) | — |
| Dokümantasyon | Kullanım kılavuzu, montaj rehberi, güvenlik dosyası | — |
| **Toplam Ek Maliyet** | — | **—** |

---

## 3. Endüstriyel Karşılaştırma

VYTRON'un komersiyel düşen-toplık viskozimetreler karşılaştırmada hangi konuda önde olduğu:

| Özellik | VYTRON | Komersiyel Model A | Komersiyel Model B |
|---------|--------|-------------------|-------------------|
| **Tahmini Fiyat** | Düşük (BOM + işçilik) | Yüksek | Çok Yüksek |
| **Otomatikasyon** | Dual MCU, tam otomatik | Manuel / Yarı otomatik | Tam otomatik |
| **Gerçek Zamanlı ETA** | Var (Isıtıcı ile) | Yok | Var |
| **Çift Dil Arayüzü** | TR / EN | Yabancı dil | Yabancı dil |
| **Açık Donanım / Şema** | Evet (KiCad) | Hayır | Hayır |
| **Kullanıcı Kalibrasyonu** | Kullanıcı tanımlı | Fabrika kalibre | Fabrika kalibre |
| **Sızdırmazlık** | NBR O-ring + Viton | Standart conta | Özel conta |
| **CFD Doğrulanmış Tasarım** | Evet (Ansys Fluent) | Genelde yok | Evet |

### Değer Teklifi
- **Maliyet avantajı**: Komersiyel cihazların bir fraksiyonu maliyetle benzer.performansa ulaşabilir.
- **Öğrenme / Araştırma**: Açık kod ve şema sayesinde üniversite laboratuvarları için ideal.
- **Esneklik**: Top çapı, sıvı türü ve ölçüm aralığı kullanıcı tarafından değiştirilebilir.

---

## 4. Önerilen Satış Fiyatı (Komersiyelleştirme Durumunda)

Eğer VYTRON bir ürün olarak piyasaya sürülürse, aşağıdaki çarpanlar uygulanabilir:

| Fiyat Modeli | Hesaplama Mantığı | Önerilen Aralık |
|--------------|-------------------|-----------------|
| **Maliyet + %20** | Toplam BOM + Ek Maliyet + %20 kâr | — TL |
| **Rakiplerin %40'u** | Komersiyel Model A'nın yaklaşık %40'ı | — TL |
| **Akademik İndirimli** | Üniversite laboratuvarlarına özel indirim | — TL |

> Bu rakamlar sadece örnek bir şablondur. Gerçek fiyatlandırma, satıcı teklifleri ve işçilik saatleri netleşince güncellenmelidir.

---

## 5. Bütçe Takip Formu (TÜBİTAK Projesi İçin)

| Kalem | Planlanan (TL) | Gerçekleşen (TL) | Fark (TL) | Onay |
|-------|----------------|------------------|-----------|------|
| Elektronik parçalar | — | — | — | □ |
| Mekanik parçalar | — | — | — | □ |
| Montaj ve işçilik | — | — | — | □ |
| Kalibrasyon sıvıları | — | — | — | □ |
| Yazılım geliştirme | — | — | — | □ |
| Dokümantasyon | — | — | — | □ |
| **Toplam** | **—** | **—** | **—** | □ |

---

## 6. Maliyet İyileştirme Önerileri

1. **Toplu satın alma**: Arduino, sensör ve O-ring parçalarını büyük miktarda almak birim fiyatı düşürür.
2. **Alternatif satıcılar**: Aynı spesifikasyondaki yerli üreticilerden besleme ve sensör temin edilebilir.
3. **PCB entegrasyonu**: Breadboard üzerinden devreye geçiş yerine özel bir PCB tasarlanarak kablo maliyeti ve montaj süresi azaltılabilir.
4. **CAD parçalarının yerli üretilmesi**: Alüminyum çatı ve montaj parçaları yerli işlenebilir.

---

## 7. İlgili Dosyalar

- `docs/bom/bom-index.md` — Genel BOM özeti
- `docs/electronics/electronics-bom.md` — Elektronik detaylı liste
- `docs/mechanical/mechanical-bom.md` — Mekanik detaylı liste
- `docs/calibration.md` — Referans sıvı kalibrasyonu (ek maliyet kalemi için)