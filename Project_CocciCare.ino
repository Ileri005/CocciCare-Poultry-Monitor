

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL2oSO24Hv5"
#define BLYNK_TEMPLATE_NAME "GAS SENSOR"
#define BLYNK_AUTH_TOKEN "dAjp3gOOm0pnyuSpNcLhV60nPp36IgnW"

#define RED_PIN 18
#define GREEN_PIN 23

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

#define DHTPIN 19
#define DHTTYPE DHT22
#define MQ135_PIN 35

char ssid[] = "JJ (2)";  // Simplified SSID
char pass[] = "Oyinkansola";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected!");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();
}

void loop() {
  Blynk.run();

  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
  int adcValue = analogRead(MQ135_PIN);

  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V2, adcValue);

  Serial.printf("🌡️ Temp: %.2f°C | 💧 Humidity: %.2f%% | ☠️ NH3: %d\n", temp, humidity, adcValue);

  bool alert = false;

  String statusMessage = "Normal Conditions";

  if (adcValue > 1800) {
    statusMessage = "Ammonia Alert: Poor Air Quality!";
    Blynk.logEvent("☠️ Ammonia Alert: Air quality is poor!");
    alert = true;
  }

  if (humidity >= 80) {
    if (!alert){
      statusMessage = "Litter Alert";
      Blynk.logEvent("Humidity Alert");
    }
    alert = true;

  if (temp >= 32) {
    if (!alert){
      statusMessage = "High Stress Temperature";
      Blynk.logEvent("🔥 Temp Alert: Temperature is dangerously high!");
    }
    alert = true;
  }
  

  if (alert) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    Blynk.virtualWrite(V3, 1);
  } else {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    Blynk.virtualWrite(V3, 0);
  }

  Blynk.virtualWrite(V4, statusMessage);
  delay(2000);
}
}
