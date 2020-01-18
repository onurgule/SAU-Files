#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <WifiLocation.h>
#define PIN D1
#define NUM_LEDS 8
 
const char* ssid = "baglanirsan_ekime";
const char* password = "nevereyimabime";
int  sicaklikSensor=A0;      //  LM35  Data  ucu A0  pinine  bağlanacak
double sicaklikDegeri;     //  Analog  değeri  dönüştüreceğimiz  sıcaklık  değeri
double olculenDeger;        // Ölçeceğimiz analog  değer
//const char server[] = "api.openweathermap.org";
//String nameOfCity = "ISTANBUL,TR"; 
//String apiKey = "51a199c3f6738edfb74cfca15c01061f"; 
double latitude    = 40.7422638;
double longitude   = 30.3256708;

unsigned long lastConnectionTime = 10 * 60 * 1000;     // last time you connected to the server, in milliseconds
const unsigned long postInterval = 10 * 60 * 1000;
//WifiLocation location(googleApiKey);
 
FirebaseData firebaseData;
FirebaseJson sicaklikJson;
 
void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  connectWifi();
  Firebase.begin("https://havadurumu-13212.firebaseio.com/", "v5sZYsWMCcs9wgeVOkLmY53At592JJsjhrDEOGY3");
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");  
}
double sicaklik (){
      /*  LM35  sensöründen sıcaklık  değeri  okuma işlemi  */
        olculenDeger  = analogRead(sicaklikSensor);   //  A0  analog  ucundan değer oku
        olculenDeger  = (olculenDeger/1024)*5000;         //  mv'a  dönüşüm işlemi
        sicaklikDegeri  = olculenDeger  /12,0;                 // mV'u  sıcaklığa dönüştür
        sicaklikDegeri  = sicaklikDegeri-10;
      
        Serial.print("Firebase'e  Gonderilen  Sicaklik  Değeri: "); Serial.println(sicaklikDegeri);
        return sicaklikDegeri;
        
}
void loop() {
  String path = "/Olcumler";
    delay(15000);
    sicaklikJson.clear().add("sicaklik",sicaklik());
    sicaklikJson.add("lat",latitude);
    sicaklikJson.add("lon",longitude);
    
 if (Firebase.pushJSON(firebaseData, path + "/", sicaklikJson))
    {
      Firebase.setTimestamp(firebaseData, firebaseData.dataPath() + firebaseData.pushName() + "/timestamp");
      Serial.print("Firebase'e yazıldı.");
      Serial.println();
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
}
 
void connectWifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());
}
 
