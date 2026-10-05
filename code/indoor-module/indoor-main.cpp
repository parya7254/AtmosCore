#include <Arduino.h>
#include <Wire.h>
#include <esp_now.h>
#include <WiFi.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <BH1750.h>

#include "config.h"

void onDataRecv(const esp_now_recv_info_t * recv_info, const uint8_t *data, int len) {
  memcpy(&incomingData, data, sizeof(incomingData));
  
  Serial.print("Bytes received: ");
  Serial.println(len);
  
  // Optional: Extract transmitter MAC address from recv_info
  Serial.print("From MAC: ");
  for (int i = 0; i < 6; i++) {
    Serial.printf("%02X", recv_info->src_addr[i]);
    if (i < 5) Serial.print(":");
  }
  Serial.println();
  
  // Print received values
  Serial.printf("Char array: %s\n", incomingData.a);
  Serial.printf("Integer: %d\n", incomingData.b);
  Serial.printf("Float: %f\n", incomingData.c);
  Serial.printf("Boolean: %d\n", incomingData.d);
  Serial.println("---------------------------");
}



void setup(){
    Serial.begin(115200);
    delay(5000)

    Serial.println("AtmosCore Indoor");

}

void loop() {
  onDataRecv();
}