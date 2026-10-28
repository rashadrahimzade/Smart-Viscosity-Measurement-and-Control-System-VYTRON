#include <AccelStepper.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

#define pulsePin 3
#define dirPin 2

// Motor Ayarları
int GUNCEL_HIZ = 3200;
int GUNCEL_IVME = 5000;
String bilyeEtiketi = "";

// Sıcaklık (Karıştırma) Modu Değişkenleri
bool sicaklikModuAktif = false;
int sicaklikAsama = 0;

LiquidCrystal_I2C lcd(0x27, 20, 4); 

const byte ROWS = 4, COLS = 4; 
char keys[ROWS][COLS] = {
  {'1','2','3','A'}, {'4','5','6','B'}, {'7','8','9','C'}, {'*','0','#','D'}
};
byte rowPins[ROWS] = {4, 5, 6, 7}; 
byte colPins[COLS] = {8, 9, 10, 11};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

AccelStepper stepper(AccelStepper::DRIVER, pulsePin, dirPin);

enum Mod { SECIM, HAREKET };
Mod suankiMod = SECIM;

String girilenDeger = "";
bool ileriYon = true; 

void setup() {
  Serial.begin(9600);
  lcd.init(); lcd.backlight();
  acilisEkrani();
}

void acilisEkrani() {
  suankiMod = SECIM;
  sicaklikModuAktif = false;
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("--- BILYE SECIN ---");
  lcd.setCursor(0, 1); lcd.print("1: 16mm");
  lcd.setCursor(0, 2); lcd.print("2: 17mm");
  lcd.setCursor(0, 3); lcd.print("3: 18mm");
}

void hareketEkraniHazirla() {
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("BILYE: "); lcd.print(bilyeEtiketi);
  lcd.setCursor(0, 1); lcd.print("ADIM : ");
  lcd.setCursor(0, 2); lcd.print("YON  : "); 
  lcd.print(ileriYon ? "SAAT YONU  " : "SAAT TERS-G");
  lcd.setCursor(0, 3); lcd.print("DURUM: BEKLEMEDE");
  stepper.setMaxSpeed(GUNCEL_HIZ);
  stepper.setAcceleration(GUNCEL_IVME);
}

void loop() {
  char key = keypad.getKey();

  // Bilye Seçim Modu
  if (suankiMod == SECIM) {
    if (key == '1') {
      GUNCEL_HIZ = 4200; GUNCEL_IVME = 3500;
      bilyeEtiketi = "16mm";
      suankiMod = HAREKET; hareketEkraniHazirla();
    } else if (key == '2') {
      GUNCEL_HIZ = 4200; GUNCEL_IVME = 3000; 
      bilyeEtiketi = "17mm";
      suankiMod = HAREKET; hareketEkraniHazirla();
    } else if (key == '3') {
      GUNCEL_HIZ = 4000; GUNCEL_IVME = 2400;
      bilyeEtiketi = "18mm";
      suankiMod = HAREKET; hareketEkraniHazirla();
    }
    return; 
  }

  // Seri Port Komutları (Mega'dan gelenler)
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    sicaklikModuAktif = false; 
    stepper.setMaxSpeed(GUNCEL_HIZ); stepper.setAcceleration(GUNCEL_IVME);
    
    if (cmd == 'H') { stepper.move(400); }      
    else if (cmd == 'G') { stepper.move(-400); } 
    else if (cmd == 'S') { stepper.moveTo(0); }   
  }

  // Tuş Takımı Kontrolleri
  if (key) {
    if (sicaklikModuAktif && key != 'D') {
      sicaklikModuAktif = false;
      stepper.setMaxSpeed(GUNCEL_HIZ); stepper.setAcceleration(GUNCEL_IVME);
    }

    if (key == '*') {
      acilisEkrani();
      girilenDeger = "";
      return;
    }
    else if (key >= '0' && key <= '9') {
      if (girilenDeger.length() < 8) {
        girilenDeger += key;
        lcd.setCursor(7, 1); lcd.print(girilenDeger); 
      }
    } 
    else if (key == 'C') { 
      // TEK TUŞLA YÖN DEĞİŞTİRME (TOGGLE)
      ileriYon = !ileriYon; 
      lcd.setCursor(7, 2); 
      if(ileriYon) lcd.print("SAAT YONU  ");
      else         lcd.print("SAAT TERS-G");
    }
    else if (key == 'D') {
      // SICAKLIK / KARIŞTIRMA MODU (Yavaş 180 derece Git-Gel)
      sicaklikModuAktif = true;
      sicaklikAsama = 1;
      
      stepper.setMaxSpeed(1000);     // Yavaş hız
      stepper.setAcceleration(800);  // Düşük ivme (sarsıntısız)
      stepper.move(400);             // ÖNCE SAAT YÖNÜNDE (+400)
      
      lcd.setCursor(7, 3); lcd.print("KARISTIRMA   ");
    }
    else if (key == 'B') { 
      lcd.setCursor(7, 3); lcd.print("DENGE 180'   ");
      if (ileriYon) stepper.move(400); else stepper.move(-400);
    }
    else if (key == 'A') {
      long h = girilenDeger.toInt();
      if (h != 0) {
        if (ileriYon) stepper.move(h); else stepper.move(-h);
        lcd.setCursor(7, 3); lcd.print("HAREKETLI    ");
        girilenDeger = ""; 
        lcd.setCursor(7, 1); lcd.print("            "); 
      }
    }
    else if (key == '#') { 
      girilenDeger = "";
      lcd.setCursor(7, 1); lcd.print("            ");
    }
  }

  stepper.run(); 

  // Motor durduğunda yapılacak işlemler
  if (stepper.distanceToGo() == 0) {
      if (sicaklikModuAktif) {
        // 1. aşama bittiyse (saat yönüne gittiyse), 2. aşamaya geç (saat yönü tersi)
        if (sicaklikAsama == 1) {
          sicaklikAsama = 2;
          stepper.move(-400); // SAAT YÖNÜNÜN TERSİNE DÖN (-400)
        } 
        else if (sicaklikAsama == 2) {
          sicaklikModuAktif = false;
          sicaklikAsama = 0;
          stepper.setMaxSpeed(GUNCEL_HIZ);
          stepper.setAcceleration(GUNCEL_IVME);
          lcd.setCursor(7, 3); lcd.print("BEKLEMEDE    ");
        }
      } else {
        static unsigned long sonEkran = 0;
        if(millis() - sonEkran > 500){
          lcd.setCursor(7, 3); lcd.print("BEKLEMEDE    ");
          sonEkran = millis();
        }
      }
  }
}
