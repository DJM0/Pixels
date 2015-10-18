/* Pixels - Library for controlling APA102 LED's on mbed compatible ARM Cortex devices
 * DavidMaitland.me 2015
 * Released under the MIT License
 */

#include "Pixels.h"
#include "mbed.h"

Pixels::Pixels(int totalPixels, PinName MOSI, PinName MISO, PinName SCK): _device(MOSI, MISO, SCK) {

    _totalPixels = totalPixels;
    pixels = totalPixels;

    _red = new int[totalPixels];
    _green = new int[totalPixels];
    _blue = new int[totalPixels];

}

void Pixels::push(void) {

    // Start frame
    this->_device.write(0x00);
    this->_device.write(0x00);
    this->_device.write(0x00);
    this->_device.write(0x00);

    // Pixel data frame
    for (int i = 0; i < _totalPixels; i++) {

        this->_device.write(0xff); // Brightness 100% 0xff
        this->_device.write(_blue[i]); // B
        this->_device.write(_green[i]); // G
        this->_device.write(_red[i]); // R

    }

    // End frame
    for (int i = 0; i < _totalPixels; i+=16) {

        this->_device.write(0xff); // 8 more clock cycles

    }

}

void Pixels::set(int pixel, int red, int green, int blue) {

    this->_red[pixel] = red;
    this->_green[pixel] = green;
    this->_blue[pixel] = blue;

}

void Pixels::setAll(int red, int green, int blue) {

    for (int i = 0; i < this->_totalPixels; i++) {

        this->set(i, red, green, blue);

    }

}

void Pixels::clear(void) {

    this->setAll(0, 0, 0);

}
