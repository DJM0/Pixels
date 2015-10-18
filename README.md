# Pixels
Library for controlling APA102 LED's on mbed compatible ARM Cortex devices

## Example

```
#include "mbed.h"
#include "Pixels.h"

Pixels pixels(36, SPI_MOSI, SPI_MISO, SPI_SCK);

int main(void) {

  while(true) {

    for (int i = 0; i < pixels.pixels; i++) {
        pixels.clear();
        pixels.set(i, 255, 255, 255);
        pixels.push();
        wait(0.05);
    }

  }

}
```
