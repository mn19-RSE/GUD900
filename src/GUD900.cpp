#include "GUD900.h"

GUD900::GUD900(SPIClass &spi, uint8_t csPin)
: _spi(spi), _cs(csPin) {}

bool GUD900::begin(uint32_t spiClock) {
    _spiClock = spiClock;

    pinMode(_cs, OUTPUT);
    digitalWrite(_cs, HIGH);

    _spi.begin();
    return true;
}

void GUD900::select() {
    _spi.beginTransaction(SPISettings(_spiClock, MSBFIRST, SPI_MODE0));
    digitalWrite(_cs, LOW);
}

void GUD900::deselect() {
    digitalWrite(_cs, HIGH);
    _spi.endTransaction();
}

void GUD900::drawBitmap(
    uint16_t xDot,
    uint16_t yByte,
    uint16_t width,
    uint16_t heightPixels,
    const uint8_t *data
) {
    uint16_t yBytes = (heightPixels + 7) / 8;

    uint8_t header[] = {
        0x1F, 0x28, 0x66, 0x11,
        (uint8_t)(width & 0xFF),
        (uint8_t)(width >> 8),
        (uint8_t)(yBytes & 0xFF),
        (uint8_t)(yBytes >> 8),
        0x01
    };

    select();

    for (uint8_t b : header) {
        _spi.transfer(b);
    }

    uint32_t count = (uint32_t)width * yBytes;
    while (count--) {
        _spi.transfer(*data++);
    }

    deselect();
}
