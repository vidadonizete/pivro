# ILI9341

| Display  | ESP32   | Function                    |
|----------|---------|-----------------------------|
| SCL (RS) | SCK     | Serial clock                |
| SDI      | MOSI    | Serial data Master -> Slave |
| SDO      | MISO    | Serial data Slave -> Master |
| D/CX (WR)| DC      | Data / Command register sel |
| CSX      | CS      | Chip Select (Active Low)    |
| RST      | RST     | Reset                       |

# References:
Code is almost as a copy of:
https://github.com/JeremySayers/pi-pico-ili9341-display