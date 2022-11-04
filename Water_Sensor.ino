/*
 * Water Sensor - test
 * Artificial Intelligence Application to the Compost Process
 */

int waterLevel = 0; 
int pin = A5; // connect sensor pin A5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  waterLevel = analogRead(pin);
  
  if (waterLevel <= 100) {
    Serial.println("Water Level: Empty");
  }
  else if (waterLevel > 100 && waterLevel <= 300) {
    Serial.println("Water Level: Low");    
  }
  else if (waterLevel > 300 && waterLevel <= 330) {
    Serial.println("Water Level: Medium");    
  }
  else if (waterLevel > 330) {
    Serial.println("Water Level: High");    
  }
  delay(1000); 
}
