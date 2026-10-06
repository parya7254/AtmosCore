#include <Arduino.h>
#include <Wire.h>

#include <Adafruit_BME280.h>
#include <BH1750.h>

#include "config.h"
#include "data_n_func.h"


bool rainSensor(uint8_t pin)
{
    int rainValue = analogRead(pin);
    const int RAIN_THRESHOLD = 2000;
    return rainValue < RAIN_THRESHOLD;
}

//we'll do all the other sensors in the main.cpp files