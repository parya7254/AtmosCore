#pragma once

struct OutdoorData{
    float temperature;
    float humidity;
    float pressure;

    float light_lux;
    bool isRaining;

    float bat_volt;
};

struct IndoorData{
    float temperature;
    float humidity;
    float pressure;

    float bat_volt;
};

void rainSensorInit(uint8_t pin);
bool rainSensor(uint8_t pin);