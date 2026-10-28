#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Keypad.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// --- PIN TANIMLARI ---
#define TFT_CS 53
#define TFT_DC 9
#define TFT_RST 8
#define MPU_ADDR 0x68
#define SSR_PIN 7   
#define ONE_WIRE_BUS 4 
#define SENSOR_A 2  
#define SENSOR_B 3  

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

enum Dil { TR, EN };
Dil seciliDil = TR;

enum Sayfa { LOGO, DIL_SECIM, BILYE_SECIM, SIVI_YOGUNLUK_GIRIS, MPU_HIZALAMA, SICAKLIK_AYAR, HASSAS_AYAR, OLCUM_EKRANI, GECMIS_EKRANI };
Sayfa suankiSayfa = LOGO;

// KALİBRASYON VE HESAPLAMA DEĞİŞKENLERİ
float bilyeYaricap = 0, bilyeYogunluk = 0, bilyeK_Sabiti = 0; 
volatile unsigned long baslangicZamani = 0, bitisZamani = 0;
volatile bool olcumBasladi = false, olcumBitti = false;
bool sensorAktif = false; 

float sonYatay = 0, sonDikey = 0, guncelSicaklik = 0, hedefSicaklik = 0;
String girilenYogunluk = "", girilenHedefSicaklik = "";
long sonHesaplananStep = 0;
bool analizBitti = false, hedefSicaklikKaydedildi = false; 
unsigned long mpuZamani = 0, ekranZamani = 0, sicaklikZamani = 0;

// ETA (Kalan Süre) ve Ölçüm Hafızası Değişkenleri
float isitmaBaslangicSicaklik = 0;
unsigned long isitmaBaslangicZamani = 0;
float gecmisSureler[5] = {0, 0, 0, 0, 0}; 
bool sureKaydedildi = false;
bool olcumEkraniIlkCizim = true;

const byte ROWS = 4, COLS = 4;
char keys[ROWS][COLS] = {{'1','2','3','A'}, {'4','5','6','B'}, {'7','8','9','C'}, {'*','0','#','D'}};
byte rowPins[ROWS] = {36, 34, 32, 30}; 
byte colPins[COLS] = {28, 26, 24, 22}; 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void sensorTetikInterrupt() {
  if (!sensorAktif) return;
  bool sA = digitalRead(SENSOR_A);
  bool sB = digitalRead(SENSOR_B);
  
  if (!olcumBasladi && !olcumBitti) {
    if (sA == sB) {
      baslangicZamani = micros();
      olcumBasladi = true;
    }
  } 
  else if (olcumBasladi && !olcumBitti) {
    if (sA != sB) {
      if (micros() - baslangicZamani > 300000) { 
        bitisZamani = micros();
        olcumBasladi = false;
        olcumBitti = true;
      }
    }
  }
}

void setup() {
  pinMode(SSR_PIN, OUTPUT); digitalWrite(SSR_PIN, LOW); 
  pinMode(SENSOR_A, INPUT_PULLUP); pinMode(SENSOR_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SENSOR_A), sensorTetikInterrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(SENSOR_B), sensorTetikInterrupt, CHANGE);
  Serial1.begin(9600); 
  pinMode(TFT_RST, OUTPUT); digitalWrite(TFT_RST, LOW); delay(100); digitalWrite(TFT_RST, HIGH); delay(100);
  tft.begin(2000000); tft.setRotation(3); tft.fillScreen(ILI9341_BLACK); tft.setTextWrap(false);
  
  Wire.begin(); Wire.setClock(100000); Wire.setWireTimeout(3000, true); 
  sensors.begin();
  Wire.beginTransmission(MPU_ADDR); Wire.write(0x6B); Wire.write(0); Wire.endTransmission();
  vytronLogoAnimasyon(); delay(500); sayfaDegistir(DIL_SECIM); 
}

void loop() {
  char key = keypad.getKey();
  
  if (millis() - mpuZamani > 50) { mpuOku(); mpuZamani = millis(); }
  
  if (millis() - sicaklikZamani > 1000) {
    sensors.requestTemperatures();
    guncelSicaklik = sensors.getTempCByIndex(0);
    if (suankiSayfa == SICAKLIK_AYAR && hedefSicaklikKaydedildi) {
      if (guncelSicaklik < hedefSicaklik) digitalWrite(SSR_PIN, HIGH); else digitalWrite(SSR_PIN, LOW);
    } else { digitalWrite(SSR_PIN, LOW); }
    if (suankiSayfa == SICAKLIK_AYAR) guncelSicaklikGoster();
    sicaklikZamani = millis();
  }
  
  if (key) {
    if (key == 'D' && suankiSayfa != DIL_SECIM && suankiSayfa != OLCUM_EKRANI && suankiSayfa != GECMIS_EKRANI) sayfaAtla(); 
    
    if (suankiSayfa == DIL_SECIM) { 
        if (key == '1') { seciliDil = TR; sayfaDegistir(BILYE_SECIM); } 
        else if (key == '2') { seciliDil = EN; sayfaDegistir(BILYE_SECIM); } 
    }
    else if (suankiSayfa == BILYE_SECIM) { 
        // BİLYE SEÇİMİ VE GÜNCELLENMİŞ KALİBRASYON SABİTLERİ (K)
        // Sabitlerin virgülü bir sağa kaydırıldı (x10 yapıldı). Türbülans yanılgısı giderildi.
        if (key == '1') { bilyeYogunluk = 16.75; bilyeK_Sabiti = 0.870; sayfaDegistir(SIVI_YOGUNLUK_GIRIS); } 
        else if (key == '2') { bilyeYogunluk = 7.78; bilyeK_Sabiti = 1.482; sayfaDegistir(SIVI_YOGUNLUK_GIRIS); } 
        else if (key == '3') { bilyeYogunluk = 7.79; bilyeK_Sabiti = 0.831; sayfaDegistir(SIVI_YOGUNLUK_GIRIS); } 
    }
    else if (suankiSayfa == SIVI_YOGUNLUK_GIRIS) { 
        if ((key >= '0' && key <= '9') || key == '*') { if (key == '*') girilenYogunluk += "."; else girilenYogunluk += key; yogunlukGuncelle(); } 
        else if (key == '#') { girilenYogunluk = ""; yogunlukGuncelle(); } 
        else if (key == 'A' && girilenYogunluk.length() > 0) sayfaDegistir(MPU_HIZALAMA); 
    }
    else if (suankiSayfa == MPU_HIZALAMA) { 
        if (key == 'B') analizYap(-90.0, 2.2222); 
        if (key == 'A' && analizBitti) sayfaDegistir(SICAKLIK_AYAR); 
    }
    else if (suankiSayfa == SICAKLIK_AYAR) { 
        if (key >= '0' && key <= '9') { girilenHedefSicaklik += key; hedefSicaklikGuncelle(); } 
        else if (key == '#') { girilenHedefSicaklik = ""; hedefSicaklikKaydedildi = false; digitalWrite(SSR_PIN, LOW); hedefSicaklikGuncelle(); tft.fillRect(160, 50, 160, 45, ILI9341_BLACK); tft.fillRect(0, 180, 320, 20, ILI9341_BLACK); } 
        else if (key == 'B') { if (girilenHedefSicaklik.length() > 0) { hedefSicaklik = girilenHedefSicaklik.toFloat(); hedefSicaklikKaydedildi = true; isitmaBaslangicSicaklik = guncelSicaklik; isitmaBaslangicZamani = millis(); } }
        else if (key == 'A') { sayfaDegistir(HASSAS_AYAR); } 
    }
    else if (suankiSayfa == HASSAS_AYAR) { 
        if (key == 'B') analizYap(20.0, 2.28); 
        if (key == 'A' && analizBitti) { if(abs(sonYatay - 20.0) <= 1.0 && abs(sonDikey) <= 1.0) sayfaDegistir(OLCUM_EKRANI); } 
    }
    else if (suankiSayfa == OLCUM_EKRANI) { 
        // YENİ MENÜ SİSTEMİ: A (Sıfırla), B (Geçmiş), C (Ana Menü)
        if (key == 'A') { olcumBasladi = false; olcumBitti = false; baslangicZamani = 0; bitisZamani = 0; sureKaydedildi = false; sayfaDegistir(OLCUM_EKRANI); } 
        else if (key == 'B') { sayfaDegistir(GECMIS_EKRANI); } 
        else if (key == 'C') { olcumBasladi = false; olcumBitti = false; sayfaDegistir(DIL_SECIM); } 
    }
    else if (suankiSayfa == GECMIS_EKRANI) { sayfaDegistir(OLCUM_EKRANI); }
  }
  
  if (millis() - ekranZamani > 300) { 
    if (suankiSayfa == MPU_HIZALAMA || suankiSayfa == HASSAS_AYAR) veriGoster(); 
    if (suankiSayfa == OLCUM_EKRANI) olcumEkraniGuncelle(); 
    ekranZamani = millis(); 
  }
}

void sayfaDegistir(Sayfa yeni) {
  suankiSayfa = yeni; analizBitti = false; digitalWrite(SSR_PIN, LOW); hedefSicaklikKaydedildi = false; 
  if (yeni == OLCUM_EKRANI) { sensorAktif = true; olcumEkraniIlkCizim = true; } else { sensorAktif = false; }
  tft.fillScreen(ILI9341_BLACK); tft.setTextColor(ILI9341_WHITE);
  
  if (yeni == DIL_SECIM) { 
      tft.fillRect(0, 0, 320, 50, ILI9341_BLUE); tft.setTextSize(2); tft.setCursor(25, 8); tft.print("AKILLI VISKOZITE OLCUM"); tft.setCursor(55, 28); tft.print("VE KONTROL SISTEMI"); 
      tft.setCursor(40, 90); tft.print("1. TURKCE"); tft.setCursor(40, 140); tft.print("2. ENGLISH"); altBilgiGoster("SECIN / SELECT"); 
  } else {
      tft.fillRect(0, 0, 320, 35, ILI9341_BLUE); tft.setCursor(10, 10); 
      if (yeni == BILYE_SECIM) { 
          tft.setTextSize(2); tft.print(seciliDil == TR ? "BILYE SECIMI" : "BALL SELECTION"); tft.setCursor(10, 60); tft.print("1. 16mm (16.75 g/cm3)"); tft.setCursor(10, 100); tft.print("2. 17mm  (7.78 g/cm3)"); tft.setCursor(10, 140); tft.print("3. 18mm  (7.79 g/cm3)"); altBilgiGoster(seciliDil == TR ? "SECIN VEYA D:ATLA" : "SELECT OR D:SKIP"); 
      }
      else if (yeni == SIVI_YOGUNLUK_GIRIS) { 
          tft.setTextSize(2); tft.print(seciliDil == TR ? "SIVININ YOGUNLUGU" : "LIQUID DENSITY"); tft.setCursor(225, 105); tft.print("kg/m3"); tft.drawRect(20, 88, 200, 54, ILI9341_WHITE); altBilgiGoster(seciliDil == TR ? "A:ONAY *:. #:SIL D:ATLA" : "A:OK *:. #:CLR D:SKIP"); 
      }
      else if (yeni == SICAKLIK_AYAR) { 
          tft.setTextSize(2); tft.print(seciliDil == TR ? "SICAKLIK" : "TEMPERATURE"); tft.drawRect(98, 108, 124, 54, ILI9341_WHITE); tft.setCursor(230, 125); tft.print("C"); altBilgiGoster(seciliDil == TR ? "A:GEC B:BASLAT #:SIL D:AT" : "A:NEXT B:START #:CLR D:SK"); 
      }
      else if (yeni == MPU_HIZALAMA) { 
          tft.setTextSize(2); tft.print(seciliDil == TR ? "SICAKLIK POZISYONU" : "TEMP POSITION"); altBilgiGoster(seciliDil == TR ? "A:ONAY B:HESAP D:ATLA" : "A:OK B:CALC D:SKIP"); 
      }
      else if (yeni == HASSAS_AYAR) { 
          tft.setTextSize(2); tft.print(seciliDil == TR ? "OLCUM POZISYONU" : "MEASURE POSITION"); 
      }
      else if (yeni == OLCUM_EKRANI) { 
          tft.setTextSize(2); tft.print(seciliDil == TR ? "OLCUM EKRANI" : "MEASUREMENT"); 
          altBilgiGoster(seciliDil == TR ? "A:YENI B:GECMIS C:MENU" : "A:NEW B:HISTORY C:HOME"); 
      }
      else if (yeni == GECMIS_EKRANI) {
          tft.setTextSize(2); tft.print(seciliDil == TR ? "SON 5 OLCUM" : "LAST 5 HISTORY"); 
          for(int i = 0; i < 5; i++) {
              tft.setCursor(20, 55 + (i * 28)); tft.print(i + 1); tft.print(". ");
              if (gecmisSureler[i] > 0) { tft.setTextColor(ILI9341_GREEN); tft.print(gecmisSureler[i], 4); tft.print(" s"); } else { tft.setTextColor(ILI9341_DARKGREY); tft.print("-"); }
              tft.setTextColor(ILI9341_WHITE);
          }
          altBilgiGoster(seciliDil == TR ? "GERI ICIN TUSA BASIN" : "PRESS KEY TO BACK"); 
      }
  }
}

float mpuOku() {
  Wire.beginTransmission(MPU_ADDR); Wire.write(0x3B); Wire.endTransmission(false); Wire.requestFrom(MPU_ADDR, 6, true);
  if (Wire.available() >= 6) {
    int16_t ax = Wire.read()<<8|Wire.read(), ay = Wire.read()<<8|Wire.read(), az = Wire.read()<<8|Wire.read();
    float r = (atan2((float)ay, (float)az) * 180.0 / PI); if (r > 0) r -= 180.0; else r += 180.0; 
    sonYatay = -r; sonDikey = (atan2((float)-ax, sqrt((float)ay*ay + (float)az*az)) * 180.0 / PI);
  } return sonYatay;
}

void analizYap(float hedefDerece, float katsayi) {
  digitalWrite(SSR_PIN, LOW); tft.fillRect(5, 140, 310, 60, ILI9341_BLACK); tft.setCursor(15, 160); tft.setTextSize(2); tft.setTextColor(ILI9341_YELLOW); tft.print(seciliDil == TR ? "HESAPLANIYOR..." : "CALCULATING...");
  float toplam = 0; int sayac = 0; unsigned long basla = millis();
  while (millis() - basla < 5000) { toplam += mpuOku(); sayac++; delay(10); }
  float temizOrtalama = (sayac > 0) ? (toplam / sayac) : sonYatay; sonHesaplananStep = round(abs((hedefDerece - temizOrtalama) * katsayi));
  Serial1.print(sonHesaplananStep); 
  tft.fillRect(5, 140, 310, 60, ILI9341_DARKGREEN); tft.setCursor(20, 170); tft.setTextColor(ILI9341_WHITE); tft.print("STEP: "); tft.print(sonHesaplananStep); analizBitti = true;
}

void olcumEkraniGuncelle() {
  static bool oncekiBasladi = false;
  static bool oncekiBitti = false;

  if (olcumEkraniIlkCizim || oncekiBasladi != olcumBasladi || oncekiBitti != olcumBitti) {
      oncekiBasladi = olcumBasladi;
      oncekiBitti = olcumBitti;
      olcumEkraniIlkCizim = false;

      tft.setTextSize(2);
      
      // DURUM BAŞLIĞI
      tft.fillRect(10, 45, 300, 40, ILI9341_BLACK);
      tft.setCursor(10, 45); tft.setTextColor(ILI9341_CYAN); tft.print("DURUM / STATUS:");
      tft.setCursor(10, 70);
      
      if (!olcumBasladi && !olcumBitti) { tft.setTextColor(ILI9341_GREEN); tft.print(seciliDil == TR ? "Yuvada (Hazir)" : "Ready in tube"); } 
      else if (olcumBasladi && !olcumBitti) { tft.setTextColor(ILI9341_YELLOW); tft.print(seciliDil == TR ? "Ayrildi, Dusuyor..." : "Falling..."); } 
      else if (olcumBitti) { tft.setTextColor(ILI9341_GREEN); tft.print(seciliDil == TR ? "Hedefe Vardi" : "Target Reached"); }

      // DEĞERLER (SÜRE VE VİSKOZİTE HESAPLAMA)
      tft.fillRect(0, 95, 320, 105, ILI9341_BLACK); // Ekranın alt kısmını temizle
      
      if (olcumBitti) {
         float sureSaniye = (bitisZamani - baslangicZamani) / 1000000.0;
         
         // Viskozite Matematiği
         float siviYog_g_cm3 = girilenYogunluk.toFloat() / 1000.0; // kg/m3'ü g/cm3'e çevir
         if (siviYog_g_cm3 <= 0) siviYog_g_cm3 = 1.0; // Sıfıra bölünme hatasını önle
         
         float fSabiti = 0.952;
         float dViskozite = sureSaniye * (bilyeYogunluk - siviYog_g_cm3) * bilyeK_Sabiti * fSabiti;
         float kViskozite = dViskozite / siviYog_g_cm3;

         // Süre Yazdırma
         tft.setCursor(10, 105); tft.setTextSize(3); tft.setTextColor(ILI9341_GREEN);
         tft.print(sureSaniye, 4); tft.print(" s");

         // Dinamik ve Kinematik Viskozite Yazdırma
         tft.setCursor(10, 145); tft.setTextSize(2); tft.setTextColor(ILI9341_YELLOW);
         tft.print(seciliDil == TR ? "D.Viskozite: " : "D.Viscosity: "); tft.print(dViskozite, 2); tft.print(" cP");
         
         tft.setCursor(10, 175); tft.setTextColor(ILI9341_ORANGE);
         tft.print(seciliDil == TR ? "K.Viskozite: " : "K.Viscosity: "); tft.print(kViskozite, 2); tft.print(" cSt");

         if (!sureKaydedildi) {
             for(int i = 4; i > 0; i--) gecmisSureler[i] = gecmisSureler[i-1];
             gecmisSureler[0] = sureSaniye; sureKaydedildi = true;
         }
      } 
      else if (!olcumBasladi && !olcumBitti) {
         tft.setCursor(10, 105); tft.setTextSize(3); tft.setTextColor(ILI9341_WHITE); tft.print("0.0000 s");
      } 
      else if (olcumBasladi && !olcumBitti) {
         tft.setCursor(10, 105); tft.setTextSize(3); tft.setTextColor(ILI9341_YELLOW); tft.print(seciliDil == TR ? "OLCULUYOR.." : "MEASURING..");
      }
  }
}

void guncelSicaklikGoster() {
  tft.fillRect(10, 50, 140, 35, ILI9341_BLACK); 
  if (hedefSicaklikKaydedildi) { 
      tft.fillRect(160, 50, 160, 45, ILI9341_BLACK); tft.setCursor(160, 55); tft.setTextSize(2); tft.setTextColor(ILI9341_WHITE); tft.print(seciliDil == TR ? "Kalan Zaman:" : "ETA:"); 
      if (guncelSicaklik < hedefSicaklik) { 
          tft.fillRect(0, 180, 320, 20, ILI9341_BLACK); tft.setTextColor(ILI9341_RED); tft.setCursor(150, 182); tft.setTextSize(2); tft.print(seciliDil == TR ? "ISITILIYOR..." : "HEATING..."); 
          long elapsed = (millis() - isitmaBaslangicZamani) / 1000; float dTemp = abs(guncelSicaklik - isitmaBaslangicSicaklik); tft.setCursor(160, 75); 
          if (dTemp >= 0.1 && elapsed > 0) { float hiz = dTemp / (float)elapsed; long kalanSaniye = abs(hedefSicaklik - guncelSicaklik) / hiz; if (kalanSaniye < 0) kalanSaniye = 0; if (kalanSaniye > 5999) kalanSaniye = 5999; int dak = kalanSaniye / 60; int san = kalanSaniye % 60; tft.setTextColor(ILI9341_WHITE); if (dak < 10) tft.print("0"); tft.print(dak); tft.print(":"); if (san < 10) tft.print("0"); tft.print(san); } else { tft.setTextColor(ILI9341_WHITE); tft.print(seciliDil == TR ? "Bilgi yok" : "No Info"); }
      } else { tft.fillRect(0, 180, 320, 20, ILI9341_BLACK); tft.setTextColor(ILI9341_GREEN); tft.setCursor(120, 182); tft.setTextSize(2); tft.print(seciliDil == TR ? "HEDEF SICAKLIKTA" : "TARGET REACHED"); tft.setCursor(160, 75); tft.setTextColor(ILI9341_WHITE); tft.print("00:00"); } 
  } else { tft.setTextColor(ILI9341_CYAN); }
  tft.setCursor(20, 55); tft.setTextSize(3); tft.print(guncelSicaklik, 1); tft.print(" C");
}

void yogunlukGuncelle() { tft.fillRect(25, 90, 190, 50, ILI9341_BLACK); tft.setCursor(35, 100); tft.setTextSize(4); tft.setTextColor(ILI9341_YELLOW); tft.print(girilenYogunluk); }
void altBilgiGoster(String m) { tft.fillRect(0, 205, 320, 35, ILI9341_DARKGREY); tft.drawRect(0, 205, 320, 35, ILI9341_WHITE); tft.setCursor(10, 215); tft.setTextSize(2); tft.setTextColor(ILI9341_WHITE); tft.print(m); }
void vytronLogoAnimasyon() { tft.fillScreen(ILI9341_BLACK); tft.setCursor(85, 100); tft.setTextSize(4); tft.setTextColor(ILI9341_BLUE); tft.print("VYTRON"); delay(2000); }
void hedefSicaklikGuncelle() { tft.fillRect(100, 110, 120, 50, ILI9341_BLACK); tft.setCursor(115, 120); tft.setTextSize(4); tft.setTextColor(ILI9341_YELLOW); tft.print(girilenHedefSicaklik); }
void sayfaAtla() { if (suankiSayfa < OLCUM_EKRANI) sayfaDegistir((Sayfa)(suankiSayfa + 1)); }

void veriGoster() { 
  tft.fillRect(10, 45, 300, 90, ILI9341_BLACK); tft.setTextSize(2); tft.setCursor(10, 60); tft.setTextColor(ILI9341_WHITE); tft.print(seciliDil == TR ? "Yatay egim: " : "Roll: "); 
  bool rollTamam = false; if (suankiSayfa == HASSAS_AYAR) { if (abs(sonYatay - 20.0) <= 1.0) { tft.setTextColor(ILI9341_GREEN); rollTamam = true; } else { tft.setTextColor(ILI9341_RED); } } else { tft.setTextColor(ILI9341_GREEN); } tft.print(sonYatay, 1); 
  tft.setCursor(10, 100); tft.setTextColor(ILI9341_WHITE); tft.print(seciliDil == TR ? "Dusey egim: " : "Pitch: "); 
  bool pitchTamam = false; if (suankiSayfa == HASSAS_AYAR) { if (abs(sonDikey) <= 1.0) { tft.setTextColor(ILI9341_GREEN); pitchTamam = true; } else { tft.setTextColor(ILI9341_RED); } } else { tft.setTextColor(ILI9341_GREEN); } tft.print(sonDikey, 1); 
  if (suankiSayfa == HASSAS_AYAR) { bool ikisiDeTamam = (rollTamam && pitchTamam); tft.fillRect(0, 205, 320, 35, ikisiDeTamam ? ILI9341_DARKGREEN : ILI9341_RED); tft.drawRect(0, 205, 320, 35, ILI9341_WHITE); tft.setCursor(10, 215); tft.setTextColor(ILI9341_WHITE); tft.print(seciliDil == TR ? "A:ONAY B:HESAP D:ATLA" : "A:OK B:CALC D:SKIP"); }
}
