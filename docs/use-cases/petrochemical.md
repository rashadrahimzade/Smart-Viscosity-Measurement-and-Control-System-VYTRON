# ⛽ Kullanım Senaryosu: Petrokimya Endüstrisi

Petrokimya ürünlerinde (yağlar, süreyiciler, polymer çözeltileri) viskozite, işlenebilirlik ve kalite kontrolünde kritik rol oynar.

## 1. Uygulama Alanları

| Ürün | Viskozite Aralığı | Önem |
|------|------------------|------|
| Motor yağı | ~50–200 cP (40 °C'de) | Sınıflandırma ve performans |
| Hidrolik sıvısı | ~30–100 cP | Sistem verimliliği |
| Polymer çözeltisi | ~100–5000 cP | İşlenebilirlik ve kalite |
| Süreyici | ~10–500 cP | Reçetede dozaj |

## 2. VYTRON'daki Avantajlar

- **Geniş sıcaklık aralığı**: DS18B20 ve SSR ile sıcaklıktan bağımsız ölçüm imkanı.
- **Alüminyum ekranlı kablo ve ferritler**: Endüstriyel ortamdaki elektromanyetik gürültüye karşı koruma (`docs/electronics/interference-mitigation.md`).
- **CFD doğrulamalı tasarım**: Farklı sıvı türleri için akış analizi yapılmış (`docs/cfd/cfd-analysis.md`).
- **Kullanıcı tanımlı kalibrasyon**: Farklı polymer ya da yağ türleri için `fSabiti` (duvar-et katsayısı) değiştirilebilir.

## 3. Kısıtlamalar

- Kimyasal sıvıların contalara (NBR, Viton) karşı direnci testi yapılmalıdır.
- Ateşli sıvılar için exter güvenlik önlemleri (gazlı ortam uyumluluğu) gerekli olabilir.

## 4. İlgili Dosyalar

- `docs/calibration.md` — Referans sıvı kalibrasyonu
- `docs/electronics/interference-mitigation.md` — EMI/RFI azaltma
- `docs/cfd/cfd-analysis.md` — Akış analizi