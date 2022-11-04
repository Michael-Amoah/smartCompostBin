/*
 * DHT11 - test
 * Temperature and Humidity Sensor  
 * Artificial Intelligence Application to the Compost Process
 * 
 */

#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("DHT11 Test"));
  
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // Wait a few seconds between measurements
  delay(2000);

    float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);

  // Check if any readings failed
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print("%\t");
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F("C"));
  Serial.print("\t");
  Serial.print(f);
  Serial.println(F("F"));

  if (t <= 40) {
    Serial.println("Temp too cold! \nTurn up heat");
  }

  if (40 < t && t < 65) {
    Serial.println("Perfect temperature!");
  }
  
  if (t >= 65) {
    Serial.println("Temp too hot! \nTurn down heat");
  }
}
