//Interface the DHT11 Temp & Humidity sensor and display humidity and temperature
//in Celsius on a 16x2 character LCD

#include <dht.h>
#include <LiquidCrystal.h>

dht DHT;
const int RS = 2, EN = 3, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);   //set Uno pins that are connected to LCD, 4-bit mode

void setup() {
  lcd.begin(16,2);    //set 16 columns and 2 rows of 16x2 LCD

}

void loop() {
  int readDHT = DHT.read11(8);    //grab 40-bit data packet from DHT sensor
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  //lcd.print((char)223);         //used to display degree symbol on display
  //lcd.write(0xdf);              //another way to display degree symbol
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(2000);

}