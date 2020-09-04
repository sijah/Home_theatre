## Smart Remote For Audio Amplifier 
Esp8266 based WiFi enabled remote kit to control Audio amplifier.This project can be used to control tone of An Amplifier from a smartphone ,PC or even with Voice Assistance devices such as Amazon Alexa or Google Home 

## wrap-up

 1. Currently Support **TDA 74xx**  series 
 2. Currently project is designed for 2 channel 
 3. Web App  can be used to control following Features
    - Volume 
    - Bass 
    - Treble
    - Balance 
    - Power 
    - Mute 
    - Input Selection 3 channel + USB , FM , SD ,Bluetooth (Additional Mp3 Module Required)
 4. Support for **multiple ESP8266-based boards**
 5. -   Wifi  **AP Mode**  or  **STA mode**
    -   Supports static IP
    -   Up to 5 different networks can be defined
    -   Network visibility supports mDNS (service reporting and metadata)  (.local name resolution)
    
 6.  Supports Voice Assistance devices such as Amazon Alexa or Google Home (Not implemented)
 
## # How it works...

 - Main Hardware of this system is Esp8266 based Soc .
 - Esp8266 Act as web server  
 - Esp8266 and Audio processor IC ( **TDA7439**) connected via i2c commutation upon changing different parameters on web app Audio processor IC will receive corresponding data via i2c.
