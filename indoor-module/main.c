#include <stdio.h>

#include "battery.h"
#include "bme280.h"
#include "power.h"

void main(void){
    printf("Start System\n");
    
    battery_init();
    bme280_init();
    power_init();

    float voltage = battery_get_voltage(); //we need voltage for battery
    float percent = battery_get_percent();

    //sensors!
    float humidity = bme280_get_humidity();
    float temperature = bme280_get_temp();
    float pressure = bm280_get_pressure();

    printf("Battery Voltage: %.2f\n", voltage)
    printf("Battery Percent: %.2f\n", percent)
    printf("Temperature: %.2f\n", temperature)
    printf("Pressure: %.2f\n", pressure);
}