#pragma once
#include <Arduino.h>
#include <SPI.h>

class GUD900 {
public:
    GUD900(SPIClass &spi, uint8_t csPin);

    bool begin(uint32_t spiClock = 1000000);

    void drawBitmap(
        uint16_t xDot,
        uint16_t yByte,
        uint16_t width,
        uint16_t heightPixels,
        const uint8_t *data
    );

private:
    SPIClass &_spi;
    uint8_t _cs;
    uint32_t _spiClock;

    void select();
    void deselect();
};