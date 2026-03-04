#include <DHT.h>
#define DHTPin 19
#define DHTTYPE DHT22

DHT dht(DHTPin, DHTTYPE);
const float TEMP_WARNING = 29.0;
const float TEMP_CRITICAL = 32.0;
const float HUMIDITY_WARNING = 72.0;
const float HUMIDITY_CRITICAL = 80.0;


void setup() {
  dht.begin();
  delay(2000);

  Serial.begin(115200);
}

void loop() {
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" C ");
  
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" % ");

  //Temperature alerts
  if(temp >= TEMP_CRITICAL){
    Serial.println("Critical!!! Temperature is very high");
  } else if(temp >= TEMP_WARNING){
    Serial.println("Warning! Temperature is above comfort level");
  }

  //Humidity alerts
  if (humidity >= HUMIDITY_CRITICAL) {
    Serial.println("Critical!!! Humidity is too high. Try changing the litter!");
  } else if (humidity >= HUMIDITY_WARNING) {
    Serial.println("Warning! Humidity is rising check litter.");
  }

  delay(2000);

}
