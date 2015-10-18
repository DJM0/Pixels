/* Pixels - Library for controlling APA102 LED's on mbed compatible ARM Cortex devices
 * DavidMaitland.me 2015
 * Released under the MIT License
 */

#ifndef MBED_PIXELS_H
#define MBED_PIXELS_H

#include "mbed.h"

class Pixels {

    public:
        Pixels(int totalPixels, PinName MOSI, PinName MISO, PinName SCK);
        int pixels;

        void push(void);
        void set(int pixel, int red, int green, int blue);
        void setAll(int red, int green, int blue);
        void clear(void);

    private:
        int _totalPixels;
        mbed::SPI _device;

        int* _red;
        int* _green;
        int* _blue;

};

#endif
