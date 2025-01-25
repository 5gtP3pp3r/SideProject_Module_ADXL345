#pragma once
#include <Arduino.h>
#include "Modules/ADXL345Sensor.h"

class Program {
private:
    ADXL345Sensor* m_ADXL345;
    uint64_t m_lastReadTime;
    uint16_t m_interval;
public:
    Program();
    void printValues();
    void loop();
};
