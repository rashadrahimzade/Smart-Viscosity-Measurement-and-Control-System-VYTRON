# ⚠️ Safety Guide

Bu rehber, VYTRON sisteminin güvenli kullanımını açıklar. Sistem 220V AC, yüksek sıcaklık ve hareketli mekanik parçalar içerir. Okunup uygulanması zorunludur.

## 1. Elektrik Güvenliği

### 220V AC Tehlikesi
- Sistemde 220V AC voltajı bulunan 200W ısıtıcısı ve güç kaynağı vardır.
- **Yalnızca yetkili ve yetkin personel 220V bağlantılarını yapabilir.**
- Tüm 220V kabloları çift izolasyonlu olmalı ve uygun bir kutu içinde saklanmalıdır.
- Çalışma esnasında 220V hatlarına asla el atılmamalıdır.

### Solid State Relay (SSR)
- SSR, 220V AC akımını anahtalar. Yanlış bağlanması veya bozuk olması durumunda ısıtıcının sürekli açık kalması (runaway heating) riski vardır.
- SSR montaj parçasının havalandırıldığından emin olun; sıcaklık artışı olabilir.
- Güç kesildiğindeSSR'ın içindeki gerinim kalabilir; bakım öncesi en az 5 dakika bekleyin.

### Arduino ve Lojik Devre
- Arduino Mega ve Nano 5V ile çalışır. 220V ile doğrudan bağlantı yoktur.
- Tüm lojik bağlantıların (Serial1, I2C, keypad) GND ortaklı olduğundan emin olun.

## 2. Isı ve Sıcaklık Güvenliği

- Isıtıcı 200W güçtedir ve sıvıyı yüksek sıcaklıklara ısıtabilir.
- Sıvı ve tüp cam yüzeyi yakma riski oluşturabilir. Isıtıcı çalışırken elinizle tüp veya ısıtıcıya temas etmeyin.
- Hedef sıcaklık ayarlanırken, sıvı kaynama noktasının üzerinde olmamasını sağlayın.
- SSR kilitlenirse (sürekli açık kalırsa) Isıtıcı sürekli ısıtmaya devam edebilir. Acil durumda güç kaynağından kesin.

## 3. Mekanik Güvenlik

- NEMA 34 stepper motoru yüksek tork üretmektedir. Elinizi veya giyimcinizi motor dönüş bölgesine yaklaştırmayın.
- Tüp döndürme mekanizması çalışırken kapağı açmayın.
- Cam tüp hassastır; çarpma veya düşme sonucu kırılabilir. Kırık tüp ile sistemin çalıştırılmaması gerekir.

## 4. Kimyasal ve Sıvı Güvenliği

- Ölçülecek sıvının kimyasal özelliklerini bilin; alguns sıvılar NBR O-ring veya Viton contalarla uyumlu olmayabilir.
- Sıvı doldururken koruyucu eldiven ve göz koruyucu kullanın.
- Dökülen sıvı temizlenmeden elektrikli parçalara yaklaşmayın.

## 5. Acil Durum Prosedürü

Bir sorun oluştuğunda (ısıtıcı sıkmıyor, motor kontrolsüz dönüyor, duman çıkıyor vb.):

1. **Hemen güç kaynağından 220V'yi kesin.**
2. Arduino'ları USB'den çıkarın.
3. Sıcak parçaların soğumasını bekleyin.
4. Sorunun kaynağını belirledikten sonra tekrar çalıştırın.

## 6. Bakım ve Kontrol

- Her kullanım öncesi kabloların bozulup bozulmadığını kontrol edin.
- O-ring ve Viton contaların的にはzirvalarını kontrol edin; bozuksa değiştirin.
- Sensörlerin temiz olduğundan emin olun (özellikle optik sensörler).
- 12 ayda bir tüm elektrik bağlantılarının sıkı olduğundan emin olun.

## 7. Sorumluluk Reddi

Bu proje "tüm hakları saklıdır" şartlarıyla lisanslanmıştır (`LICENSE.txt`). Yazar, bu rehberin eksik veya yanlış uygulanmasından doğacak zararlardan sorumlu tutulamaz. Sistem kullanımından doğacak tüm risk kullanıcıya aittir.

## 8. İletişim

Güvenlikle ilgili sorular veya bildirimler için: **rahimzaderashad1@gmail.com**
