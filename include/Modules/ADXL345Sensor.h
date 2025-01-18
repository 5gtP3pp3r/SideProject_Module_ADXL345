#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

#include "const.h"

#define MS2 "m/s²"              // Accélération en mètre par seconde au carré. La gravité est une accélération constante de 9.81m/s² soit 1G.
#define ADXL_ADD 0x53           // SD0 sur GND. SI sur VCC: 0x1D
#define G_CONST 9.81f           // Constante De la gravité.

class ADXL345Sensor {
private:
    float m_axeX;               // Hummmm. Les 3 axes pouraient être représenté par un vecteur...
    float m_axeY;
    float m_axeZ;               // L'axe Z sera l'axe important puisqu'il représente l'axe vertical.
    Adafruit_ADXL345_Unified m_ADXL345 = Adafruit_ADXL345_Unified();

    uint64_t m_lastReadTime;
    uint16_t m_interval;
    void setMembresValues();
public:
    ADXL345Sensor();
    void tick();
    String getAxeXString();     // Que de possibilités!!!
    String getAxeYString();
    String getAxeZString();
    float getAxeXms2();
    float getAxeYms2();
    float getAxeZms2();
    float getAxeXg();
    float getAxeYg();
    float getAxeZg();
};
