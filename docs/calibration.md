# 📐 Calibration Guide

Bu rehber, VYTRON sisteminin kalibrasyon prosedürünü açıklar. Ölçüm doğruluğu, referans sıvılar ve kalibrasyon prosedürü ile doğrulanmalıdır.

## 1. Ölçüm Prensibi

Stokes' Yasası ile dinamik viskozite hesaplanır:

$$\eta = \frac{2 \cdot (\rho_s - \rho_f) \cdot g \cdot r^2}{9 \cdot v}$$

Firmware'de bu denklem şu şekilde kodlanmıştır:

```cpp
float dViskozite = sureSaniye * (bilyeYogunluk - siviYog_g_cm3) * bilyeK_Sabiti * fSabiti;
float kViskozite = dViskozite / siviYog_g_cm3;
```

Burada:
- `sureSaniye` : Topun iki optik sensör arasındaki düşme süresi (saniye)
- `bilyeYogunluk` : Seçilen topun yoğunluğu (g/cm³)
- `siviYog_g_cm3` : Kullanıcı tarafından girilen sıvı yoğunluğu (g/cm³)
- `bilyeK_Sabiti` : Top çapına bağlı kalibrasyon katsayısı
- `fSabiti` : Duvar-etkisi (wall-effect) düzeltme katsayısı (şu anda `0.952`)

## 2. Referans Sıvılar (Önerilen)

Kalibrasyon için bilinen viskozite değerine sahip referans sıvılar kullanılmalıdır. Örneğin:

| Sıvı | Sıcaklık | Dinamik Viskozite (cP) | Kinematik Viskozite (cSt) |
|------|----------|------------------------|---------------------------|
| Silikon yağı 10 cSt | 25 °C | ~10 | ~10 |
| Silikon yağı 100 cSt | 25 °C | ~100 | ~100 |
| Glicerin | 25 °C | ~1410 | ~1250 |
| Su | 25 °C | ~0.89 | ~0.89 |

> **Not:** Bu değerler örnektir. Kendi laboratuvarınızdaki referans sıfların sertifikatlı değerlerini kullanın.

## 3. Kalibrasyon Adımları

### Aşama 1: Top ve Sıvı Parametrelerinin Girilmesi
1. Sistemi açın ve dil seçin.
2. Kullanacağınız topu seçin (16 mm, 17 mm veya 18 mm). Sistem otomatik olarak `bilyeYogunluk` ve `bilyeK_Sabiti` değerlerini yükler:
   - 16 mm: Yoğunluk 16.75 g/cm³, K sabiti 0.870
   - 17 mm: Yoğunluk 7.78 g/cm³, K sabiti 1.482
   - 18 mm: Yoğunluk 7.79 g/cm³, K sabiti 0.831
3. Sıvının yoğunluğunu `SIVI_YOGUNLUK_GIRIS` ekranında girin (kg/m³).

### Aşama 2: Pozisyon Kalibrasyonu (MPU-6050)
1. `MPU_HIZALAMA` ekranına gidin.
2. Tüpü başlangıç pozisyonuna getirin.
3. `B` tuşuna basarak `analizYap()` fonksiyonunu çalıştırın. Sistem 5 saniye boyunca MPU verilerinin ortalamasını alır ve step adım sayısını hesaplar.
4. Sonuç ekranda görüntülendiğinde `A` ile onaylayın.

### Aşama 3: Hassas Ayar (Ölçüm Pozisyonu)
1. `HASSAS_AYAR` ekranına gidin.
2. Tüpü ölçüm pozisyonuna (yumuşak eğim, ör. 20°) getirin.
3. `B` ile analiz yapın, `A` ile onaylayın.
4. Roll ve Pitch değerleri ±1.0° içinde yeşil olarak gösterilmelidir.

### Aşama 4: Ölçüm ve Doğrulama
1. `OLCUM_EKRANI`'na gidin.
2. Sıvı hedef sıcaklığa ulaştığında ölçümü başlatın.
3. Topun düşme süresi ekranda gösterilir.
4. Dinamik ve kinematik viskozite değerleri hesaplanıp ekranda görünür.
5. Sonucu referans sıvı değerle karşılaştırın. Fark %5 üzeriyse kalibrasyonu tekrarlayın.

## 4. Duvar-Et Katsayısı (Wall-Effect Factor)

Firmware'de `fSabiti = 0.952` sabit olarak tanımlanmıştır. Bu değer, tüp çapı ve top çapına bağlı olarak değişir.

**Öneri:** Farklı top/tüp kombinasyonları için referans sıvılarla çok noktalı ölçüm yaparak `fSabiti`'yi yeniden hesaplayın ve firmware'de güncelleyin.

## 5. Hata Kaynakları ve Toleranslar

| Hata Kaynağı | Etki | Önlem |
|--------------|------|-------|
| Sıcaklık değişimi (±1 °C) | Viskozide ±2–5% | DS18B20 ile sıcaklık düzeltmesi |
| Top çapı toleransı | Viskozide ±1–3% | Kalibre edilmiş top kullanın |
| Duvar etkisi | Viskozide ±3–8% | `fSabiti` ile düzeltin |
| Optik sensör gürültüsü | Süre hatası | Kesme içi glitch filtresi (300 µs) |
| Sıvı kabarcığı | Titreşim, yanlış sürede bitme | Sıvıyı kabarcıksız doldurun |

## 6. Kalibrasyon Kayıt Formu (Örnek)

| Tarih | Referans Sıvı | Sıcaklık (°C) | Ölçülen (cP) | Referans (cP) | Hata (%) |
|-------|---------------|---------------|--------------|---------------|----------|
| | | | | | |
| | | | | | |

Bu tabloyu `docs/` altında bir Excel veya CSV dosyası olarak da tutabilirsiniz.

## 7. Notlar

- Kalibrasyon sonuçlarını `EEPROM`'a kaydetme özelliği henüz firmware'de yok; her açılışta parametreler yeniden girilmektedir (planlanmış iyileştirme).
- Ölçüm geçmişi (son 5 süre) ekranda saklanır ancak güç kesildiğinde silinir.