#pragma once
#include "data.h"

void bme280_init(void);

float bme280_get_temp(void);
float bme280_get_humidity(void);
float bme280_get_pressure(void);