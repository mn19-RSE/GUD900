# NOTE:
This library is a learning experiment and does not currently work

# GU140X32F-D903S_VFD_Library
Modern Arduino library for the Noritake GU140X32F-D903S graphical VFD.
Controller is: 7292ZA00 R5F21368 SDFP

## Scope:
The goal of this project is to create a custom library for the Noritake VFD. This will be a learning experience for learning how to write custom libraries for SPI devices. The end product should be compatible with Adafruit GFX and be able to detect the touch inputs built into the display.

## Pinout of VFD:

|Pin # | Signal name | Function       | Direction      |   
|------|-------------|----------------|----------------|
|1     |  VCC        | Power supply   | Input          |
|2     |  MOSI       | Data receive   | Input          |
|3     |  GND        | Ground         | Input          |
|4     |  MBUSY      | Module busy    | Output         |
|5     |  SCK        | Serial clock   | Input          |
|6     |  /RESET     | Reset          | Input          |
|7     |  /CS        | Chip select    | Input          |
|8     |  MISO       | Data send      | Output         |
|9     |  /TRDY      | Transmit ready | Output         |
|10    |  GND        | Ground         | Input          |
|11    |  P00        | I/O port0_bit0 | Input / Output |
|12    |  P01        | I/O port0_bit1 | Input / Output |
|13    |  P02        | I/O port0_bit2 | Input / Output |
|14    |  P03        | I/O port0_bit3 | Input / Output |


## Steps:
