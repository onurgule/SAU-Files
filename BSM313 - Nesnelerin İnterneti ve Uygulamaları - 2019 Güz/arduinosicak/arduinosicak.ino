/*********************************************************
                            BSM313 Nesnelerin İnterneti ve  Uygulamaları  Dersi
                                                                        Doç.  Dr. Cüneyt  BAYILMIŞ
                                                                            ThingSpeak Genel  Uygulama
*********************************************************/
/*  Kütüphane Dosyaları */
#include  <ESP8266WiFi.h>
#include  "ThingSpeak.h"
/*  Kablosuz  Bağlantı  Bilgileri */
#define WLAN_SSID   "Orion23"       
#define WLAN_PASSWORD   "piedraaa"         
/*  ThingSpeak  Kurulumu */
unsigned long channelID = 900085;
const char* thingSpeakHost = "api.thingspeak.com";
unsigned  int field_no=1;
const char* writeAPIKey = "BEQQ3M94RR0SX5R5";     //  Thingspeak  write API Key
const char* readAPIKey  = "OEKCKCXN463ABPAJ";     //  Thingspeak  read  API Key
/*    Pin Tanımları */
int sicaklikSensor=A0;      //  LM35  Data  ucu A0  pinine  bağlanacak
float sicaklikDegeri;     //  Analog  değeri  dönüştüreceğimiz  sıcaklık  değeri
float olculenDeger;        // Ölçeceğimiz analog  değer
WiFiClient  client;
/*  ESP8266 WiFi  Kurulum Fonksiyonu  */
void  wifiSetup (){
    delay (10);
    Serial.println(); Serial.println(WLAN_SSID);
        Serial.println(F("Kablosuz  Agina Baglaniyor"));
    WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
    //  WiFi  durum kontrolü
    while (WiFi.status()  !=  WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
Serial.println();
Serial.print(WLAN_SSID);  Serial.println("Kablosuz  Aga Baglandi");
    Serial.println("IP  adresi: "); Serial.println(WiFi.localIP());
}
void  setup() {
     Serial.begin(9600);      //  Serihaberleşme  9600  baud  hızında başlatılıyor
      wifiSetup();                    //  Kablosuz  ağ  kurulum fonksiyonu
      ThingSpeak.begin(client);                 //  ThingSpeak client sınıfı  başlatılıyor
    pinMode (A0,  INPUT);                // A0  ucu sensör  okumak  için  giriş modunda
Serial.println(F("Kurulum Hazır"));
}
/*  Ana (çalışan) fonksiyon */
void  loop()  {
      delay(500);
sicaklik();                                 //  Sicaklik  grafik  fonksiyonu
}
void  sicaklik (){
      /*  LM35  sensöründen sıcaklık  değeri  okuma işlemi  */
        olculenDeger  = analogRead  (sicaklikSensor);   //  A0  analog  ucundan değer oku
        olculenDeger  = (olculenDeger/1024)*5000;         //  mv'a  dönüşüm işlemi
        sicaklikDegeri  = olculenDeger  /12,0;                 // mV'u  sıcaklığa dönüştür
        sicaklikDegeri  = sicaklikDegeri-10;
      
        Serial.print("ThingSpeak  Gonderilen  Sicaklik  Değeri: "); Serial.println(sicaklikDegeri);
        
      /*  ThingSpeak  Field Yazma İşlemi */
        ThingSpeak.writeField (channelID, field_no, sicaklikDegeri, writeAPIKey);             //  sıcaklık  değerini  gönder
//        ThingSpeak.setField (1, sicaklikDegeri);              //  1 nolu  field ı kur
//        ThingSpeak.writeFields(channelID, writeAPIKey);             //  kurulu  field lere  yaz (çoklu  yazma)
    Serial.println("\n");
      delay(20000);
      /*  ThingSpeak  Field Okuma İşlemi */
float oku = ThingSpeak.readFloatField (channelID, field_no);              //  ilgili  kanalın belirtilen  field oku
//      float oku = ThingSpeak.readFloatField(channelID,  field_no, readAPIKey);              //  private kanallar  için  readAPIKey
        Serial.print("ThingSpeak’ten  Okunan  Sicaklik  Değeri: "); Serial.println(oku);
}
