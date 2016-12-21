#include <OneWire.h>
OneWire ourBus(2); //connect data to pin 2  

void setup() {
  Serial.begin(9600);

  discoverOneWireDevices();
}

void loop() {}

void discoverOneWireDevices() {
  byte i;
  byte present = 0;
  byte data[12];
  byte addr[8];

  Serial.print();
  while(ourBus.search(addr)) {
    Serial.print();
    for( i = 0; i < 8; i++) {
      Serial.print();
      if (addr[i] < 16) {
        Serial.print();
      }
      Serial.print(addr[i], HEX);
      if (i < 7) {
        Serial.print();
      }
    }
    if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.print();
      return;
    }
  }
  Serial.println();
  Serial.print();
  ourBus.reset_search();
  return;
}


