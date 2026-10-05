#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <esp_now.h>

#include <Adafruit_BME280.h>
#include <BH1750.h>

#include "config.h"
#include "../data_n_func.h"


uint8_t indoorAddress[]={
    //outdoor module's esp32 ADDRESS
}

Adafruit_BME280 bme;
BH1750 lightMeter;
OutdoorData outdoorValues;


void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast packet's print status:\t");
  if (status == ESP_NOW_SEND_SUCCESS) {
    Serial.println("Delivery Success");
  } else {
    Serial.println("Delivery Failed");
  }
}

void setup(){
    Serial.begin(115200);
    delay(1000);
    analogReadResolution(12);

    Serial.println("ATMOS CORE Outdoor (iBrick):)");

    //bme
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);

    bool bme_success = bme.begin(0x76);
    if(bme_success)
        Serial.println("Successful!");
    else
        Serial.println("Can't find the BME280!");

    //lightMeter
    bool lightMeter_success = lightMeter.begin();
    if (lightMeter_success)
        Serial.println("Successful!");
    else
        Serial.println("Can't find the lightMeter!");


    pinMode(ANALOG_OUT, INPUT);

    WiFi.mode(WIFI_STA);

    if(esp_now_init() ==  ESP_OK){
        Serial.println("Successful!");
    }else{
        Serial.println("Failed to initialize ESP-NOW!");
    }

    esp_now_register_send_cb(OnDataSent);

    esp_now_peer_info_t indoorInfo = {};
    memcpy(indoorInfo.peer_addr, indoorAddress, 6);

    indoorInfo.channel = 0;
    indoorInfo.encrypt = false;

    //Used to be esp_now_peer(&indoorInfo)
    if(esp_now_add_peer(&indoorInfo) != ESP_OK){
        Serial.println("failed to add indoor peer!");
    }

    Serial.println("ESP-NOW ready");

    
}

void loop() {

    outdoorValues.temperature = outdoorValues.readTemperature();
    outdoorValues.humidity = outdoorValues.readHumidity();
    outdoorValues.pressure = outdoorValues.readPressure()/100.0F;

    outdoorValues.light_lux = outdoorValues.readLight();
    outdoorValues.isRaining = outdoorValues.readRain();

    outdoorValues.bat_volt = analogReadMilliVolts(BATTERY_ADC) * 2.00f / 1000.00f;

    esp_now_send(indoorAddress, (uint8_t *)&outdoorValues, sizeof(outdoorValues));

    delay(5000);
}