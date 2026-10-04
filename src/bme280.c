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