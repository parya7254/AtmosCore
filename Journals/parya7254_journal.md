# 9/17/2026 Made new project and started working on the schematic!! (1hr)

Today, I started working on this project which is going to be a ESP31-powered weather station with Funmi! Starting off, we brainstormed how our weather station will be and what parts/sensors it will have. Then, I made a new EasyEDA team and invited Funmi to it so that we could collaborate on the PCB and schematic. Moving on to the schematic, I first did the ESP32 where I did have some trouble on finding the perfect module. I was looking for an ESP32 module, not the bare chip as the module had the flash chip and all of the other essentials along with the WiFi+BT antenna which is very crucial as designing that by ourselves would be quite troublesome and maybe problematic. While searching for a good ESP32 module, I could not find one and I got many bare chips. I tried many different keywords but did not get results that satisfied my request. But, after some while of searching, I finally stumbled upon a module that satisfied my requirements. I then went on searching for a BME280 temperature, humidity, and pressure sensor which was not hard, and the same could be said for the BH1750 light sensor. But, when it came to the VEML6075, the IC was not in stock, and I could not find and alternatives to it as of now. I will continue working on finding the rest of the parts needed and hopefully I get done with finding all of the parts needed and put them in the schematic by the end of the next time that I work on this.

Lapse: https://lapse.hackclub.com/timelapse/F5m8yYxM26DT

<img width="461" height="423" alt="image" src="https://github.com/user-attachments/assets/44625419-b8d5-4ee2-80f6-22a13c6a4612" />

# 9/18/2026 Read datasheets + wired a little power!! (2hrs)

Today, I started off with wiring some of the things that were also on the schematic. Me and Funmi also did some searching for an LDO/some sort of power regulator for 3.3V. I also added a CH340 to the schematic as well because we will need a way to communicate with our ESP32 and program it over a USB port. The CH340 will convert USB signals to serial signals so that the ESP32 can properly communicate with our computer for debugging and coding. I also started wiring the power pins for the sensors as well. I managed to wire all of the needed power pins for the BME280 and then moved on to the ambient light sensor. This was a bit more troublesome as it had some sort of special rule for one of its pins. I unfortunately did not have enough time to finish wiring the power pins for everything, but I did still make some progress in the end! And also, all of this research will be important for the proper functionality of our project as well. I also thought of an idea that was about using the schematic for the modules by Adafruit that use the same sensor as Adafruit makes everything open source. I thought about this at the end of today's work session so I will try to not forget about this the next time that I work on this.

Lapse: https://lapse.hackclub.com/timelapse/n_8TG-TNRAbT

<img width="1114" height="807" alt="image" src="https://github.com/user-attachments/assets/cf642897-8ede-419a-9027-aa33e1f800ab" />

# 9/19/2026 Finished wiring sensors! (2hrs)

Today, I managed to lock in enough and finish wiring all of the sensors. The reason that this took so long was because I had to go through the datasheet and confirm the correct way to do things. I have also never worked with a bare chip and I2C before so that was a bit problematic since I did not know about pull up resistors on I2C lines. I used 4.7k resistors on each I2C line since that was the recommended amount from looking it up and then pulled the resistor up. But I managed to learn about them today! I did use some example schematics from Adafruit's modules that use the same chip for reference to properly wiring the chip! I also had to set some pins to high or low to make sure that they have the proper address for I2C. Me and Funmi also discussed some plans for our project and its indoor and outdoor module as well.

Lapse: https://lapse.hackclub.com/timelapse/fbDPuQSLvLiT

<img width="1540" height="561" alt="image" src="https://github.com/user-attachments/assets/764eada7-da10-4633-a036-104f98aec467" />

# 9/20/2026 Finished wiring CH340C to ESP32 and also added a USB-C port!! (3hrs)

Today, I managed to finish wiring the CH340C, which is a USB to serial converter, to the ESP32! I also added and almost finished the USB-C port, all that I have left to do is wire the CC pins along with the VBUS. I did take a lot of time today as I got stuck on wiring the CH340C to the ESP32, the RX and TX was not too hard, but the part that automatically reset and put the ESP32 into the code upload mode every time code needs to be uploaded to the board. I got stuck on this because the wiring was pretty weird and there was a weird symbol on the reference schematic that I looked up. All of the reference schematic for the CH340C to the ESP32 had the same weird thing and then I later learned that they were a thing called MOSFETS, which work similarly to a transistor, or that's my understanding on this. And the signal and gate pins were also wired very weirdly, and I really got confused during this part. After stressfully wiring that together, I worked on the USB C port and finding a good port that had less pins but still supported data transfer. I got the data pins with the GND pins wired, but I still have to work on the VBUS and CC1 and CC2 pins. I also did some research on the TP4056 and its pins.

Lapse: https://lapse.hackclub.com/timelapse/sECMAntu1_vI

<img width="1236" height="433" alt="image" src="https://github.com/user-attachments/assets/06cb090c-789a-4ae6-bb1f-e92a2dea4144" />


# 9/21/2026 Finished USB-C port + started working on indoor module!! (1hr)

Today, I did some research on the USB-C CC pins and learnt that they are pins that can detect the orientation of the cable plugged into it and that they are also crucial to getting power from USB-C and also very important in USB PD, which can negotiate higher amps and voltages. I did some research on these pins, although I did not find the results that I needed initially, after some more searching and rewording my question, I found an answer, I also hunted for another source to confirm the correct values. It turned out that I needed to out a 5.1K pulldown resistor on both of the CC pins so that they can even receive power in the first place, I do not need USB PD in this as this is very low power and I just need USB power in general. After I finished that, I moved on to the indoor module, as we thought the outdoor module's schematic was finished! We decided to use the same ESP32 chip on the indoor module, and I went to find a display. We decided to go for a touchscreen TFT, and I did spend some time searching for ones that were decently priced. We were going to do a bigger screen, but it was not worth the very large price difference, even though they were the same resolution, and we decided to stick with 2.8 inches. I managed to also find a good header pin footprint, and we will not get this assembled by PCBA and solder this by hand. I had to stop after I added the footprint for today, and I will continue to work on the TFT the next time that I work on this project.

Lapse: https://lapse.hackclub.com/timelapse/WTt2GvQR11WG

<img width="581" height="386" alt="image" src="https://github.com/user-attachments/assets/3b56870d-7b74-4a09-a299-863a9401e6a0" />
<img width="948" height="470" alt="image" src="https://github.com/user-attachments/assets/aa497d05-d8a7-4f97-9fcb-026f09cf4d23" />
