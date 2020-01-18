/*********************************************************
BSM313 Nesnelerin İnterneti ve Uygulamaları Dersi
Doç. Dr. Cüneyt BAYILMIŞ
ESP8266 WiFiManager Uygulaması
*********************************************************/
/* Kütüphane Dosyaları */
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
void setup() {
Serial.begin (115200); // Serihaberleşme 115200 baud hızında başlatılıyor
WiFiManager wifiManager; // WiFiManager kütüphanesinin nesnesini tanimlama
wifiManager.autoConnect ("AutoConnectAPG"); // WiFiManager kütüphanesinin erisim nokta açma fonksiyonu
Serial.print ("Kablosuz Aga Baglaniyor");
// WiFi bağlantı durum kontrolü
while (WiFi.status() != WL_CONNECTED) {
Serial.print (".");
delay (500);
}
Serial.println ();
Serial.println (WiFi.SSID());
Serial.println ("Kablosuz Aga Baglandi");
Serial.println ("IP adresi: "); Serial.println (WiFi.localIP() );
}
/* Ana (çalışan) fonksiyon */
void loop() {
// WiFi bağlantısından sonra çalışacak uygulamaya özgü ana kod
}
