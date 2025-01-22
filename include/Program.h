#pragma once
#include <Arduino.h>
#include "Modules/ADXL345Sensor.h"

class Program {
private:
    ADXL345Sensor* m_ADXL345;
    String m_axeX;
    String m_axeY;
    String m_axeZ;
    uint64_t m_lastReadTime;
    uint16_t m_interval;
    void getADXL345Values();
public:
    Program();
    void printValues();
    void loop();
};
