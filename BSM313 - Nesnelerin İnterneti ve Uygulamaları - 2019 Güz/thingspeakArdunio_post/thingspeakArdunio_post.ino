
/************************************************
 BSM 313 Nesnelerin İnterneti ve Uygulaması Dersi
              Doç. Dr. Cüneyt BAYILMIŞ
       ThingSpeak Uygulaması (ESP8266 WiFi)
 *************************************************/
/*** ESP8266 WiFi Kütüphane Dosyası ***/
#include <ESP8266WiFi.h>

/*** Kablosuz Ağ Bilgileri ***/
const char*  WLAN_SSID  =   "Orion23";   //   
const char*   WLAN_PASSWORD = "11223344" ;  //   

/************************* ThingSpeak Kurulumu *********************************/
const char* thingSpeakHost = "api.thingspeak.com";  //184.106.153.149 
String  writeAPIKey = "BEQQ3M94RR0SX5R5";   // 

/*** Değişken ve Pin Tanımlamaları ***/
int sicaklikSensor= A0;
float sicaklikdegeri;   //Analog değeri dönüştüreceğimiz sıcaklık değeri 
float olculendeger;   //Ölçeceğimiz analog değer

WiFiClient client;

/*** ESP8266 WiFi Kurulum Fonksiyonu ***/
void WiFi_Setup(){
 delay(10);
 Serial.println(); Serial.print(WLAN_SSID);
 Serial.print("Kablosuz Agina Baglaniyor");
 WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
 // WiFi durum kontrolü
 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();Serial.print(WLAN_SSID);
  Serial.println("Kablosuz Agina Baglandi");
  Serial.println("IP adresi: "); 
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);  // Seri port baud rate ayarı
  WiFi_Setup();          //Kablosuz ağ bağlantı fonksiyonu
  
  pinMode(A0,INPUT);
 
}

void loop() {

// LM35 sıcaklık değeri okuma
olculendeger = analogRead(sicaklikSensor); //A0'den değeri alacak
olculendeger = (olculendeger/1024)*3300;//değeri mV'a dönüştürecek 
sicaklikdegeri = olculendeger /10,0; // mV'u sicakliğa dönüştürecek

if (client.connect (thingSpeakHost, 80)){
 // String body = writeAPIKey;
//  body += "&field1="+ String (sicaklikdegeri)+"\r\n\r\n";
  String postStr = "field1=";
         postStr+= String (sicaklikdegeri);
// birden fazla field verisi göndermek için
// postStr+="field2=";
//postStr+= String (sicaklikdegeri);

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + writeAPIKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
    client.print("\n\n");
  
  Serial.println(sicaklikdegeri);
  Serial.println ("Thingspeak veri gönderildi");  
}
client.stop();
delay (20000);

}
