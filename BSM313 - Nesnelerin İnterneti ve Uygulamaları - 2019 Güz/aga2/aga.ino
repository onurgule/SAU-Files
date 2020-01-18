#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
 
#define PIN D1
#define NUM_LEDS 8
 
const char* ssid = "baglanirsan_ekime";
const char* password = "nevereyimabime";
 
FirebaseData firebaseData;
 
void setup() {
  Serial.begin(9600);
  connectWifi();
  Firebase.begin("https://havadurumu-13212.firebaseio.com/", "v5sZYsWMCcs9wgeVOkLmY53At592JJsjhrDEOGY3");
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
}
 
void loop() {
  String path = "/Test";
 if (Firebase.setDouble(firebaseData, path + "/Sakarya/Sicaklik", 7.1))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
      Serial.println("ETag: " + firebaseData.ETag());
      Serial.print("VALUE: ");
      //printResult(firebaseData);
      Serial.println("------------------------------------");
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
  // Let us connect to WiFi
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println(".......");
  Serial.println("WiFi Connected....IP Address:");
  Serial.println(WiFi.localIP());
 
}
 
