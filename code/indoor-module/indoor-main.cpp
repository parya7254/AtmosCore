#include <Arduino.h>
#include <Wire.h>
#include <esp_now.h>
#include <WiFi.h>

#include <Adafruit_BME280.h>
#include <BH1750.h>

#include "config.h"
#include "data_n_func.h"


Adafruit_BME280 bme280;
IndoorData indoorValues;
OutdoorData outdoorValues;

uint8_t outdoorAddress[] = { /* ESP32 ADDRESS */ };


//the void on data recv function was copied from docs.. same as the datasend in the other file

void onDataRecv(const esp_now_recv_info_t * recv_info, const uint8_t *data, int len) {
  if (len == sizeof(OutdoorData)){
    memcpy(&incomingData, data, sizeof(incomingData));
    Serial.print("Outdoor data received: ");
  }
  else
    Serial.println("wrong data size received");


void setup(){
    Serial.begin(115200);
    delay(1000)

    Serial.println("AtmosCore Indoor!!");


    analogReadResolution(12);
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);

    if (!bme280.begin(0x76))
      Serial.println("BME280 initialization failed!");
    else
      Serial.println("BME280 initialized successfully!");

    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK){
        Serial.println("ESP-NOW initialization failed!");
        return;
    }

    esp_now_register_recv_cb(OnDataRecv);

    Serial.println("ESP-NOW ready!");
}




void loop() {
  indoorValues.temperature = bme280.readTemperature();
  indoorValues.humidity = bme280.readHumidity();
  indoorValues.pressure = bme280.readPressure() / 100.0F;

  indoorValues.bat_volt = analogReadMilliVolts(BATTERY_ADC) * 2.0F / 1000.0F;

  Serial.println("----- INDOOR -----");
  Serial.println();
  Serial.print("Temperature: ");
  Serial.print(indoorValues.temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(indoorValues.humidity);
  Serial.println(" %");

  Serial.print("Pressure: ");
  Serial.print(indoorValues.pressure);
  Serial.println(" hPa");

  Serial.print("Battery: ");
  Serial.print(indoorValues.bat_volt);
  Serial.println(" V");


  Serial.println();
  Serial.println("----- OUTDOOR -----");

  Serial.print("Temperature: ");
  Serial.print(outdoorValues.temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(outdoorValues.humidity);
  Serial.println(" %");

  Serial.print("Pressure: ");
  Serial.print(outdoorValues.pressure);
  Serial.println(" hPa");

  Serial.print("Light: ");
  Serial.print(outdoorValues.light_lux);
  Serial.println(" lux");

  Serial.print("Rain: ");

  if (outdoorValues.isRaining)
  {
      Serial.println("YES");
  }
  else
  {
      Serial.println("NO");
  }

  Serial.print("Outdoor Battery: ");
  Serial.print(outdoorValues.bat_volt);
  Serial.println(" V");


  delay(5000);
}