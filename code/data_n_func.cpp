#include <Arduino.h>
#include <Wire.h>

#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#include <BH1750.h>

#include "config.h"
#include "data_n_func.h"

Adafruit_BME280 bme;
BH1750 lightMeter;

bool bme280_init(unit8_t address)
{
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);

    if (bme.begin(0x76)) {
        Serial.println("BME280 initialized successfully!");
        return true;
    }
    
    Serial.println("Can't find the BME280!");
    return false;
}


float bme280_get_temp()
{
    return bme.readTemperature();
}


float bme280_get_humidity()
{
    return bme.readHumidity();
}


float bme280_get_pressure()
{
    return bme.readPressure() / 100.0F;//converting from Pa to hPa
}

bool light_sensor_init()
{
    if (lightMeter.begin()) {
        Serial.println("BH1750 initialized successfully!");
        return true;
    }

    Serial.println("Can't find the BH1750!");
    return false;
}


float light_sensor_get_lux()
{
    return lightMeter.readLightLevel();
}

bool rain_sensor_init()
{
    pinMode(ANALOG_OUT, INPUT);

    Serial.println("Rain sensor initialized!");

    return true;
}


bool rain_sensor_is_raining()
{
    int rainValue = analogRead(ANALOG_OUT);
    const int RAIN_THRESHOLD = 2000;

    return rainValue < RAIN_THRESHOLD;
}












#include "bme280.h"

static i2c_bus_handle_t i2c_bus = NULL;
static bme280_handle_t bme280 = NULL;

i2c_config_t conf = {
    .mode = I2C_MODE_MASTER,
    .sda_io_num = I2C_MODE_MASTER,
    .sda_pullup_en = GPIO_PULLUP_ENABLE,
    .scl_io_num = I2C_MASTER_SCL_IO,
    .scl_pullup_en = GPIO_PULLUP_ENABLE,
    .master.clk_speed = I2C_MASTER_
}
bme280 = bme280_create(
    i2c_bus, BME280_I2C_ADDRESS_DEFAULT;
)

bme280_default_init(bme280);


void bme280_init(void){

}

IndoorDara bme280_read(void){

}

float bme280_get_temp(void){
    return 0.0f;
}

float bme280_get_humidity(void){
    return 0.0f;
}

float bme280_get_pressure(void){
    return 0.0f;
}




//BME
#include "espnow.h"
#include <string.h>

#include "esp_now.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_netif.h"

OutdoorData g_outdoorData;

static void receiveCallback(const esp_now_recv_info_t *info, const uint8_t *data, int len){
    if(len != sizeof(OutdoorData)){
        return;
    }

    memcpy(&g_outdoorData, data, sizeof(OutdoorData));

}

void espnow_init(void){
    esp_netif_init();
    esp_event_loop_create_default();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    
    esp_wifi_init(&cfg);
    esp_wifi_set_mode(WIFI_MODE_STA);

    esp_wifi_start();
    esp_now_init();

    esp_now_register_recv_cb(receiveCallback);


}

bool espnow_has_new_data(void){
    return true;
}

OutdoorData espnow_get_data(void){
    return latestData;
}