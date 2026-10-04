#pragma once

typedef struct{
    float temperature;
    float humidity;
    float pressure;

    float bat_folt;
} IndoorData;


typedef struct{
    float temperature;
    float humidity;
    float pressure;

    float light_lux;
    bool isRaining;

    float bat_volt;
} OutdoorData;

typedef struct{
    IndoorData indoor;
    OutdoorData outdoor;
} WeatherStationData;
