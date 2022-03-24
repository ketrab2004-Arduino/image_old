#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
//#include <Adafruit_FT6206.h>

#include <Draw_BMP.h>

#define TFT_CS 10
#define TFT_DC 9
#define TFT_BL 5
#define SD_CS  4

#define BRIGHTNESS  127

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup()
{
    SD.begin(SD_CS);

    pinMode(TFT_BL, OUTPUT);
    analogWrite(TFT_BL, BRIGHTNESS);

    tft.begin();
    tft.setRotation(1);

    String toLoad = "/TRAINS/LOC-E.BMP";

    for (uint16_t j = 0; j <= 240-48; j+=48) {
        for (uint16_t i = 0; i <= 320-48; i+=48) {
            bmpDraw(tft, toLoad, i,j);
        }
    }
}

void loop()
{
}
