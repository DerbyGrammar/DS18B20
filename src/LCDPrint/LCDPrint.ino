#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

OneWire oneWire(2); //connect data to pin 2
DallasTemperature sensors(&oneWire);

DeviceAddress black = { 0x28, 0xFF, 0x1A, 0xAA, 0x62, 0x15, 0x03, 0x20 };
DeviceAddress red   = { 0x28, 0xFF, 0xA9, 0xB4, 0x62, 0x15, 0x03, 0x0C }; 
DeviceAddress green = { 0x28, 0xFF, 0xF5, 0xB3, 0x62, 0x15, 0x03, 0x3E };

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int delayTime = 1000;
const String topLine = "Derby Grammar";

void setup() {
  sensors.begin();
  sensors.setResolution(black, 10);
  sensors.setResolution(red, 10);
  sensors.setResolution(green, 10);
}

void loop() {
  sensors.requestTemperatures();

  printToLCD(black, "Black");
  delay(delayTime);
  printToLCD(red, "Red");
  delay(delayTime);
  printToLCD(green, "Green");
  delay(delayTime);
}

String getTemp(DeviceAddress address) {
  float tempC = sensors.getTempC(address);

  return (tempC != -127.00) ? String(tempC) : "Error";
}

void printToLCD(DeviceAddress address, String sensorName) {
  String tempC = getTemp(address);
  
  lcd.clear();
  lcd.print(topLine);
  lcd.setCursor(0, 1);
 
  if(sensorName.length() == 3) { //ie name is red  
    lcd.print(sensorName + ":   " + tempC);
  } else {
    lcd.print(sensorName + ": " + tempC);
  }
  
}

