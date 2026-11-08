# 🚗 Kullanım Senaryosu: Otomotiv Endüstrisi

Motor yağı, fren sıvısı, transmission yağı gibi otomotiv sıvılarının viskozite kontrolünde kullanılır.

## 1. Uygulama Alanları

| Sıvı | Viskozite Aralığı | Önem |
|------|------------------|------|
| Motor yağı (5W30, 10W40 vb.) | ~50–200 cP | Motor Koruması ve sınıflandırma |
| Fren sıvısı (DOT 3, 4, 5.1) | ~10–30 cP | Fren sistemi performansı |
| Transmission yağı | ~100–500 cP | Vites sistemi çalışması |
| Soğutma sıvısı | ~1–5 cP | Soğutma verimliliği |

## 2. VYTRON'daki Avantajlar

- **NEMA 34 stepper motoru**: Yüksek torklu, kesin konumlama ile tüp döndürme ve ölçüm pozisyonu ayarı.
- **MPU-6050 eğim sensörü**: Tüpün ölçüm pozisyonunda doğru açıda tutulmasını sağlar.
- **Isıtıcı ve ETA**: Sıcaklığa bağlı viskozite değişimi ölçümünde ETA (kalan süre) gösterimi.
- **Optik sensörler**: Mikro-saniye hassasiyetle topun düşme süresi ölçülür.

## 3. Kısıtlamalar

- Otomotiv standartları (ISO, SAE vb.) ile uyumluluk için ek sertifikasyon gerekebilir.
- Yağ ve fren sıvıları için kimyasal direnci test edilmelidir.

## 4. İlgili Dosyalar

- `docs/calibration.md` — Referans sıvı kalibrasyonu
- `docs/mechanical/mechanical-design.md` — Mekanik CAD ve tasarım
- `docs/safety.md` — 220V ve ısıtıcı güvenliği