# 🛠️ Mechanical Assembly Guide

Bu rehber, VYTRON düşen-toplık viskozimetresinin mekanik montajını adım adım açıklar. Tüm 3D CAD modelleri `Mechanical/3D Model/` klasöründe, teknik çizimler ise `Mechanical/Techincal_Drawing/` klasöründe bulunmaktadır.

## 1. Gerekli Araçlar ve Malzemeler

- Inbus anahtar seti (M3, M4, M5)
- Tornavida seti (Philips ve シングル düzgün)
- Kalibreli anahtar (10 mm, 13 mm)
- Silikon conta veya uygun sızdırmazlık macunu (isteğe bağlı)
- NBR O-ring ve Viton (FKM) contalar (depo ile birlikte)
- Temizleyici (isopropol alkol)
- Eldiven ve göz koruyucu

## 2. Montaj Sırası

### Adım 1: Alt Gövde ve Tüp Sabitleme
1. Alt kapak parçasını düz ve stabil bir yüzeye yerleştirin.
2. Cam tüp (iç ve dış) yerleşim kanalına dikkatlice oturtun.
3. Tüp borusu üzerindeki NBR O-ring kanalını temizleyin ve O-ring'i yerine oturtun.
4. Üst kapak parçasını tüp üzerine yerleştirin. Viton (FKM) contayı uygun kanalın içine yerleştirin.
5. Kapakları birbirine civatalayın. Aşırı sıkınmaktan kaçının; cam tüp kırılabilir.

### Adım 2: Stepper Motor ve Tüp Döndürme Mekanizması
1. NEMA 34 stepper motorunu motor montaj parasına sabitleyin (4 adet M5 civata).
2. Motorun şaftındaki kemer veya bağlayıcıyı tüp döndürme mekanizmasıyla bağlantılı hale getirin.
3. Motor montaj paranasını ana çatıya sabitleyin.
4. Motorun hareketi sırasında tüpün titreşmediğinden emin olun; gerekirse damper veya yalıtım materiaisini ekleyin.

### Adım 3: Sensör Montajı
**MPU-6050 (Eğim/pozisyon):**
- Tüp gövdesinin tarafına sabitleyin. Sensör düz yüzeyde ve sağlam şekilde monte edilmelidir.
- Kablo yolunu alüminyum ekranlı kablo ile koruyun (EMI'ye karşı).

**Optik Sensörler (SENSOR_A ve SENSOR_B):**
- Tüpün düşme yolunun iki farklı noktasına monte edin.
- Topun optik alana girdiği ve çıktığı noktalar tam olarak hizalanmalıdır.
- Sensörlerin ışık kaynağı ve alıcısı karşı karşıya olmalı, engel olmamalıdır.

**DS18B20 (Sıcaklık):**
- Sondunu sıvının içine girecek şekilde tüp gevşeme veya sızdırmazlık kanalı üzerinden geçirin.
- Sondunun sıvı ile temas ettiğinden ve hava kesildiğinden emin olun.

### Adım 4: Isıtıcı ve Güvenlik
1. 220V 200W ısıtıcıyı tasarlanan yere monte edin.
2. Isıtıcının cam tüple doğrudan temas etmediğinden (veya tasarım gereği temas ediyorsa uygun yalıtım olduğundan) emin olun.
3. SSR (Solid State Relay) montaj parçasını havalandırılabilir bir yere sabitleyin.
4. Tüm 220V bağlantıları izole edilmeli ve kutu içine alınmalıdır.

### Adım 5: Kullanıcı Arayüzü Montajı
1. ILI9341 TFT LCD'yi Mega kontrol panelinde sabitleyin.
2. 4×4 keypad'leri Mega ve Nano panellerine monte edin.
3. Nano üzerindeki 20×4 I2C LCD'yi hareket kontrol panelinde yerleştirin.

## 3. Sızdırmazlık Kontrolü

Tüm montaj tamamlandıktan sonra:
- Tübe su doldurun ve birkaç saat bekleyin.
- Kapak kenarları, O-ring kanalları ve boru giriş çıkış noktalarından sızdırmazlık olup olmadığını kontrol edin.
- Sızdırmazlık varsa montajı tekrar yapın ve contaları kontrol edin.

## 4. Kontrol Listesi

- [ ] Cam tüp kırık veya hasarlı değil
- [ ] NBR O-ring ve Viton kontalar yerinde ve bozuk değil
- [ ] Tüp sıkı ve titreşimsiz monte edilmiş
- [ ] MPU-6050 düz yüzeyde sabit
- [ ] Optik sensörler paralel ve hizalı
- [ ] DS18B20 sıvı ile temas ediyor
- [ ] 220V bağlantıları izole ve kutu içinde
- [ ] Tüm civatalar sıkı (aşırı sıkılmamış)

## 5. Notlar

- Tüm cad dosyaları SolidWorks'te hazırlanmıştır; STEP formatında da mevcuttur.
- Montaj sırasında herhangi bir parçayı zorlamayın; cam parçalar özellikle hassastır.
- Montajdan sonra ilk çalıştırmada `docs/getting-started.md` rehberini takip edin.