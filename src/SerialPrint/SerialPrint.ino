#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(2); //connect data to pin 2
DallasTemperature sensors(&oneWire);

DeviceAddress black = { 0x28, 0xFF, 0x1A, 0xAA, 0x62, 0x15, 0x03, 0x20 };
DeviceAddress red   = { 0x28, 0xFF, 0xA9, 0xB4, 0x62, 0x15, 0x03, 0x0C }; 
DeviceAddress green = { 0x28, 0xFF, 0xF5, 0xB3, 0x62, 0x15, 0x03, 0x3E };

const int delayTime = 1000;

void setup() {
  Serial.begin(9600);

  sensors.begin();
  sensors.setResolution(black, 10);
  sensors.setResolution(red, 10);
  sensors.setResolution(green, 10);
}

void loop() {
  sensors.requestTemperatures();
  Serial.print(getTemp(black) + " ");
  Serial.print(getTemp(red) + " ");
  Serial.print(getTemp(green) + " \n");

  delay(delayTime);
}

String getTemp(DeviceAddress address) {
  float tempC = sensors.getTempC(address);

  if(tempC != -127.00) {
    return String(tempC);
  } else {
    return "Error";
  }
}

