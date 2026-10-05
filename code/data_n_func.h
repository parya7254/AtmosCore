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

bool bme280_init(uint8_t address);
float bme280_get_humidity();
float bme280_get_temperature();
float bme280_pressure();

bool lightSensorInit();
float readLight();

bool rainSensorInit(uint8_t pin);
bool rainSensor(uint8_t pin);