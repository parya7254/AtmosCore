# AtmosCore
<img width="2362" height="1672" alt="SCH_outdoor-module_1-P1_2026-09-20" src="https://github.com/user-attachments/assets/e33a192e-91ff-4ccc-85b7-314d9525eb20" />

![3d-pcb](./Journals/images/3d-indoor-pcb.png)

AtmosCore is a smart ESP32-powered weather monitor! It consists of two modules that communicate wirelessly, one that collects weather data using sensors (which will typically be placed outside where weather data is sourced), and another that is connected to a screen and displays the data. It runs on battery that is charged by a solar panel.

# Key Features:
|Features|Model|
|-|-|
|Processor|ESPRESSIF ESP32-WROOM-32D-N8|
|Power Supply|Li-ion Battery (may change in future), chargeable by Solar Panel and by USB-C|
|Communication/Data Transfer|ESP-now|
|LDO|TPS63020DSJR buck boost|
|Battery Charger|TP4056|
|Temperature + Humidity + Pressure sensor|BME280|
|Light Sensor|BH1750FVI-TR|
|Temperature Sensors|KNTC0603/10KF3950|
|Radar Sensor|LD2140C|

# Development setup

This repository is configured as a native ESP-IDF project. Open the `AtmosCore`
folder in VS Code (rather than the parent repository folder), then use the
Espressif IDF extension to:

1. Run **ESP-IDF: Configure ESP-IDF extension** and install the ESP-IDF tools if
   they are not already installed.
2. Set the target to **esp32**.
3. Run **ESP-IDF: Build your project**.
4. Select the board's serial port and use **ESP-IDF: Flash your project** or
   **ESP-IDF: Flash your project and monitor**.

The current source is a hardware-initialization scaffold; sensor drivers and
wireless communication still need to be implemented.

## ESP-IDF or PlatformIO?

ESP-IDF is the recommended choice for this project. It is Espressif's native
framework, has first-class ESP-NOW support, and gives direct access to the
power-management and deep-sleep APIs needed by this battery-powered design.
PlatformIO is a reasonable alternative if you want one common workflow across
multiple microcontroller families, but it adds another build/configuration
layer and is not needed for this ESP32-only project.

# Pictures of Outdoor Module!!
<img width="2362" height="1672" alt="SCH_AtmosCore-Outdoor-Schematic_1-P1_2026-10-05" src="https://github.com/user-attachments/assets/89930ba5-e499-4782-b8ca-a346117adc3b" />
<img width="2160" height="1331" alt="PCB_AtmosCore-Outdoor-PCB_2026-10-05" src="https://github.com/user-attachments/assets/3e7d0401-8a12-455a-b47f-b41a5109b7fb" />
<img width="2160" height="1618" alt="3D_AtmosCore-Outdoor-PCB_2026-10-05" src="https://github.com/user-attachments/assets/14903b1d-7e95-4ca8-bfb5-9dc2999f15d7" />
<img width="1243" height="744" alt="image" src="https://github.com/user-attachments/assets/70813fc4-25f9-4c5b-9a29-ce944a5b098a" />

# Pictures of Indoor Module!!
<img width="2362" height="1672" alt="SCH_indoor-module_1-AtmosCore-Indoor-Schematic_2026-10-05" src="https://github.com/user-attachments/assets/b5fbae4d-ffa2-4447-8b2a-357dd840c696" />
<img width="2160" height="1904" alt="PCB_AtmosCore-Indoor-PCB_2026-10-05" src="https://github.com/user-attachments/assets/a665c19a-a97e-4849-909e-d05490623385" />
<img width="2160" height="1646" alt="3D_AtmosCore-Indoor-PCB_2026-10-05" src="https://github.com/user-attachments/assets/c8fb4547-3d68-454d-ba96-20ed0a6332b1" />
<img width="1246" height="840" alt="image" src="https://github.com/user-attachments/assets/f52a9381-8416-429b-84fb-7d9b82c2fd2a" />


## NOTE: THIS PROJECT WAS MADE WITH ASSISTANCE OF AI TOOLS FOR RESEARCH AND GUIDANCE
