**17th and 18th September** 
So, we have our project decided on. We're gonna be working on a smart ESP32-powered weather station that contains two modules that communicate wirelessly, one that collects weather data using sensors (will typically be placed outside where weather data is sourced), and another that is connected to a screen and displays this data. It runs on battery and charged by a solar panel. More details will be added soon.

I searched, added, and wired components for our weather tracker and display system including the processor chip (espressif esp32 wroom), ldo, battery points for the solar panel and battery, and a battery charger for the battery. I also added some of the sensors for the weather. Our device will track temperature, humidity, pressure, wind speed, wind direction, rain, and light/UV.

![mcu](images/mcu.png)

![power](images/power_and_bat.png)

We found suitable modules for temp, pressure, humidity and UV light, but we're still gonna finalize for wind speed, wind direction, and rain (amount of rain fall).

![sensors](images/sensors.png)

Timelapse: https://lapse.hackclub.com/timelapse/0soD5C5SFuWm

---

**18th September midnight**

I started wiring the ldo. I wired input voltage, switching nodes, and power with necessary caps using the datasheet. I also wired the gpio pins on the processor.

![ldo](images/ldo-power.png)

![gpio](images/processor-gpio.png)

Timelapse: https://lapse.hackclub.com/timelapse/47Nh-5HsW0Z_


---


**19th September**

I finished wiring up the ldo. I wired up enable, power saving, and some other pins. We're gonna use the Adafruit 6V 2W solar panel that has a barrel jack connector, so I added the jack socket (or whatever its calld) that will connect to the jack of the solar panel. I also started wiring the TP4056 to the battery and the solar.

![usb-serial-connector](images/usb-ser-con.png)

![sensors](images/sensors.png)

![image](images/wiring.png)

![ldo](images/ldo-more.png)

Timelapse: https://lapse.hackclub.com/timelapse/MDIkPO2Eiles
Timelapse 2: https://lapse.hackclub.com/timelapse/ODEb5UjX_YcE
