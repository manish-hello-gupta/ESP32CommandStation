# NeoPixelBus

NOTE: This library has been modified for ESP32CommandStation as follows:
1. Remove Arduino references
2. Remove HTML color support (removes large chunk of static allocations)
3. Only ESP32 RMT output support
4. Remove NeoPixelAnimator (unused and has hard dependency on millis() for timing)

[![Donate](https://img.shields.io/badge/paypal-donate-yellow.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=6AA97KE54UJR4)

Arduino NeoPixel library

A library to control one wire protocol RGB and RGBW leds like SK6812, WS2811, WS2812 and WS2813 that are commonly refered to as NeoPixels and two wire protocol RGB like APA102 commonly refered to as DotStars.
Supports most Arduino platforms.  
This is the most functional library for the Esp8266 as it provides solutions for all Esp8266 module types even when WiFi is used.  


Please read this best practices link before connecting your NeoPixels, it will save you a lot of time and effort.  
[Adafruit NeoPixel Best Practices](https://learn.adafruit.com/adafruit-neopixel-uberguide/best-practices)

For quick questions jump on Gitter and ask away.  
[![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/Makuna/NeoPixelBus?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)

For bugs, make sure there isn't an active issue and then create one.

## Why this library and not FastLED or some other library?
See [Why this Library in the Wiki](https://github.com/Makuna/NeoPixelBus/wiki/Library-Comparisons). 

## Documentation
[See Wiki](https://github.com/Makuna/NeoPixelBus/wiki)

## Installing This Library (prefered, you just want to use it)
Open the Library Manager and search for "NeoPixelBus by Makuna" and install

## Installing This Library From GitHub (advanced, you want to contribute)
Create a directory in your Arduino\Library folder named "NeoPixelBus"
Clone (Git) this project into that folder.  
It should now show up in the import list when you restart Arduino IDE.





