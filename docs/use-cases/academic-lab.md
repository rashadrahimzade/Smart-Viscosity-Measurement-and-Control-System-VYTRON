# 🎓 Kullanım Senaryosu: Akademik Laboratuvarlar

Üniversite ve Ar-Ge laboratuvarlarında araştırma, öğrenci deneyleri ve tez çalışmaları için kullanılır.

## 1. Uygulama Alanları

| Kullanım Amacı | Açıklama |
|---------------|----------|
| Stokes' Yasası deneyi | Düşen-topluk viskozimetre prensibinin gösterimi |
| Viskozite-sıcaklık ilişkisi | Farklı sıcaklıklarda sıvı viskozite değişimi araştırması |
| Kalibrasyon çalışması | Referans sıvılarla sistem doğrulanması |
| Öğrenci projesi | Mekatronik, endüstri Mühendisliği, kimya mühendisliği deneyleri |

## 2. VYTRON'daki Avantajlar

- **Açık kod ve açık donanım**: Tüm firmware, CAD ve şema dosyaları değiştirilebilir ve öğrenilebilir.
- **Dual-MCU mimarisi**: Arduino Mega ve Nano arasındaki iletişim, öğrencilere embedded sistem öğretmek için idealdir.
- **TÜBİTAK 2209-A desteği**: Akademik projeler için uygun bir referans sistem.
- **Çift dil (TR/EN)**: Türkçe ve İngilizce arayüz, uluslararası ortamlarda kullanılabilir.
- **Düşük maliyet**: Üniversite bütçelerine uygun.

## 3. Kısıtlamalar

- Veri kaydı (SD kart / PC bağlantısı) henüz yok; manuel not alma gerekebilir.
- Fabrika kalibrasyon sertifikası yok; kullanıcı kendi kalibrasyonunu yapmalıdır.

## 4. İlgili Dosyalar

- `docs/getting-started.md` — İlk kurulum ve çalıştırma
- `docs/assembly-guide.md` — Mekanik montaj
- `docs/software/software-architecture.md` — Yazılım mimarisi
- `docs/cfd/cfd-analysis.md` — Akış analizi (araştırma için referans)