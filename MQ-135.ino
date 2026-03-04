
#define MQ135_PIN 35  // Analog pin connected to MQ-135

void setup() {
  Serial.begin(115200);
  delay(2000);
}

void loop() {
  int sensorValue = analogRead(MQ135_PIN);
  float voltage = sensorValue * (3.3 / 4095.0); // Convert to voltage

  Serial.print("MQ-135 Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  // Basic threshold alert (tune this based on calibration)
  if (sensorValue > 1800) {
    Serial.println("⚠️ ALERT: Poor air quality detected!");
  }

  delay(2000);
}
