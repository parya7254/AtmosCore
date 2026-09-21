<img width="2362" height="1672" alt="SCH_outdoor-module_1-P1_2026-09-20" src="https://github.com/user-attachments/assets/e33a192e-91ff-4ccc-85b7-314d9525eb20" />
# AtmosCore

AtmosCore is a smart ESP32-powered weather monitor! It consists of two modules that communicate wirelessly, one that collects weather data using sensors (which will typically be placed outside where weather data is sourced), and another that is connected to a screen and displays the data. It runs on battery that is charged by a solar panel.

# Key Features:
|Features|Model/Description|
|-|-|
|Processor|ESPRESSIF ESP32-WROOM-32D-N8|
|Power Supply|Li-ion Battery (may change in future), chargeable by Solar Panel and by USB-C|
|Communication/Data Transfer|ESP-now|
|LDO|TPS63020DSJR buck boost|
|Battery Charger|TP4056|
|Temperature + Humidity + Pressure sensor|BME280|
|Light Sensor|BH1750FVI-TR|
|Temperature Sensors|KNTC0603/10KF3950|
