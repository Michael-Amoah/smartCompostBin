/*
 * DHT11 - test
 * Temperature and Humidity Sensor  
 * Artificial Intelligence Application to the Compost Process
 * 
 */

#include <DHT.h>         

#define DHTPIN 2          // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11     

DHT dht(DHTPIN, DHTTYPE);   

void setup () {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);         
}

void loop (){
    // put your main code here, to run repeatedly:
    float H = dht.readHumidity();    
    // Read temperature as Celsius
    float T = dht.readTemperature();    
    // Read temperature as Fahrenheit
    // float f = dht.readTemperature(true);

    // Check if any reads failed and if exit
    if (isnan(H) || isnan(T)){
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
 
    // Combine Humidity and Temperature into single string
    String dhtData = String(H) + "," + String(T);
    Serial.println(dhtData);
    delay(2000);   // Wait two seconds between measurements
}
