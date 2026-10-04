#pragma once

typedef struct{
    float temperature;
    float humidity;
    float pressure;
} BmeData;


typedef struct{
     BmeData bme;
    float light_lux;
    bool isRaining;
    float outdoor_bat_volt;
} OutdoorData;

typedef struct{
    OutdoorData outdoor;
    BmeData indoor;
    float indoor_bat_volt;
} WeatherStationData;
