#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <esp_now.h>

#include <Adafruit_BME280.h>
#include <BH1750.h>

#include "config.h"
#include "../data_n_func.h"


Adafruit_BME280 bme;
BH1750 lightMeter;
OutdoorData outdoorValues;

uint8_t indoorAddress[]={
    //outdoor module's esp32 ADDRESS
}


void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast packet's print status:\t");
  if (status == ESP_NOW_SEND_SUCCESS) {
    Serial.println("Delivery Success");
  }
  else {
    Serial.println("Delivery Failed");
  }




void setup() {
    Serial.begin(115200);
    delay(1000);

    Serial.println("ATMOS CORE!!");
    analogReadResolution(12);

    //bme
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);

    bool bme_success = bme.begin(0x76);
    if(bme_success)
        Serial.println("Successful!");
    else
        Serial.println("Can't find the BME280!");
        return;


    //lightMeter
    bool lightMeter_success = lightMeter.begin();
    if (lightMeter_success)
        Serial.println("Successful!");
    else
        Serial.println("Can't find the lightMeter!");
        return


    pinMode(ANALOG_OUT, INPUT);

    WiFi.mode(WIFI_STA);

    if(esp_now_init() ==  ESP_OK){
        Serial.println("Successful!");
    }
    else{
        Serial.println("Failed to initialize ESP-NOW!");
        return
    }

    esp_now_register_send_cb(OnDataSent);

    esp_now_peer_info_t indoorInfo = {};
    memcpy(indoorInfo.peer_addr, indoorAddress, 6);

    indoorInfo.channel = 0;
    indoorInfo.encrypt = false;

    //Used to be: esp_now_peer(&indoorInfo)
    if(esp_now_add_peer(&indoorInfo) != ESP_OK){
        Serial.println("failed to add indoor peer!");
    }

    Serial.println("ESP-NOW ready");
    
}



void loop() {

    outdoorValues.temperature = bme280.readTemperature();
    outdoorValues.humidity = bme280.readHumidity();
    outdoorValues.pressure = bme280.readPressure()/100.0F;
    //it measures in Pa, so we convert to hPa


    outdoorValues.light_lux = lightMeter.readLight();
    outdoorValues.isRaining = rainSensor(ANALOG_OUT);

    outdoorValues.bat_volt = analogReadMilliVolts(BATTERY_ADC) * 2.00f / 1000.00f; //because we divided our voltage by 2, 470K resistors each!

    esp_now_send(indoorAddress, (uint8_t *)&outdoorValues, sizeof(outdoorValues));

    delay(5000);
}