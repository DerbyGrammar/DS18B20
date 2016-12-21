#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(2); //connect data to pin 2
DallasTemperature sensors(&oneWire);
