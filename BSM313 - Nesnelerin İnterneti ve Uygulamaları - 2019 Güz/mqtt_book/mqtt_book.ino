/************************************************
 BSM 451 Nesnelerin İnterneti ve Uygulaması Dersi
              Doç. Dr. Cüneyt BAYILMIŞ
       Adafruit MQTT Uygulaması (Wemos D1 Mini)
 *************************************************/
/*** ESP8266 WiFi Kütüphane Dosyası ***/
#include <ESP8266WiFi.h>
/*** Adafruit Kütüphane Dosyaları ***/ 
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>


/*** Kablosuz Ağ Bilgileri ***/
#define   WLAN_SSID     "Orion23"   // "Kablosuz Ağ Adı"
#define   WLAN_PASSWORD "11223344"  // "Kablosuz Ağ Şifresi"

/************************* Adafruit.io Kurulumu *********************************/
#define   AIO_SERVER      "io.adafruit.com"
#define   AIO_SERVERPORT  1883                     // MQTT Portu
#define   AIO_USERNAME    "x1saint"              // Kullanıcı Adı
#define   AIO_KEY         "0b1b1265dd3740bfa6b3e3bef7b4fa68"   // adafruit türetilen KEY

/************************* MQTT Sunucuya Bağlantı Ayarları *********************************/
WiFiClient client;     // ESP8266WiFiClient sınıfından bağlantı nesnesi
// adafruit MQTT bağlantı kurulumu 
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

// Publish (yayım yapılacak) Feed Ayarları
Adafruit_MQTT_Publish sicaklik = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Grafik");

// Subscribe (abone) olunan Feed Ayarları
Adafruit_MQTT_Subscribe anahtar = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/anahtar");
Adafruit_MQTT_Subscribe slider = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/myslider");

/*** Değişken ve Pin Tanımlamaları ***/
int sicaklikSensor= A0;
float sicaklikdegeri;   //Analog değeri dönüştüreceğimiz sıcaklık değeri 
float olculendeger;   //Ölçeceğimiz analog değer

/*** MQTT Bağlantı Fonksiyonu ***/
void MQTT_connect() {
  int8_t ret;
  // Bağlantı kurulmuş ise dur
  if (mqtt.connected()) {
    return;
  }
  Serial.print("MQTT Baglantisi Kuruluyor ");
  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // 0 dönerse bağlanmıştır
       Serial.println(mqtt.connectErrorString(ret));   
       Serial.println("Baglanti Kurulamadi, 5 sn sonra tekrar denenecektir");
       mqtt.disconnect();
       delay(5000);  // 5sn bekle
       // 3 Başarısız bağlantıdan sonra yazılımsal reset işlemi
       retries--;
       if (retries == 0) {
         while (1);
       }
  }
  Serial.println("MQTT Baglanti Kuruldu");
}


void setup() {
  Serial.begin(115200);  // Seri port baud rate ayarı
  WiFi_Setup();          //Kablosuz ağ bağlantı fonksiyonu
  mqtt.subscribe(&anahtar);  // ToggleAnahtar Feed abone işlemi
  mqtt.subscribe(&slider);  // Slider Feed abone işlemi
  pinMode(D1,OUTPUT);        // LED bağlı uç çıkış yapıldı
}

void loop() {

MQTT_connect();   // MQTT bağlanma fonksiyonu
anahtarAbone ();
//sicaklikPublish();
//sliderAbone ();

}
void sicaklikPublish(){
// LM35 sıcaklık değeri okuma
olculendeger = analogRead(sicaklikSensor); //A0'den değeri alacak
olculendeger = (olculendeger/1024)*5000;//değeri mV'a dönüştürecek 
sicaklikdegeri = olculendeger /12,0; // mV'u sicakliğa dönüştürecek
sicaklikdegeri=sicaklikdegeri-10;


Serial.print(F("\n Sicaklik Degeri : "));
Serial.println(sicaklikdegeri);

// MQTT server sicaklık değeri gönderiliyor (Publish)
sicaklik.publish(sicaklikdegeri);

}
void sliderAbone (){
// Adafruit okunan Slider değerini görmek için seri port ekranını açın 
Adafruit_MQTT_Subscribe *abone2;
while ( ( abone2 = mqtt.readSubscription(1000))) {
    if (abone2 == &slider) 
      Serial.println((char*)slider.lastread); 
 }
} 
void anahtarAbone (){
// Abone olunan anahtar 
Adafruit_MQTT_Subscribe *abone;
while ( ( abone = mqtt.readSubscription(1000))) {
    if (abone == &anahtar) {
     Serial.print(F("Durum: "));  // anahtar verisi
     char *oku;
     oku=(char*)anahtar.lastread;
    // Serial.println((char*)anahtar.lastread); 
    Serial.println(oku);
     if (strcmp(oku,"AC")==0)
          {digitalWrite(D1,HIGH);
          Serial.println((char*)anahtar.lastread); }
     else
          digitalWrite(D1,LOW);
          
    } 
 }
} 
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
