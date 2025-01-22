#include "Program.h"

Program::Program()
  : m_ADXL345(nullptr),
    m_axeX(EMPTY),
    m_axeY(EMPTY),
    m_axeZ(EMPTY),    
    m_lastReadTime(DEFAULT_ZERO),
    m_interval(INTERVAL_1) {                    // 1 sec               
        this->m_ADXL345 = new ADXL345Sensor();
    
}

void Program::getADXL345Values() {
    m_axeX = m_ADXL345->getAxeXString();
    m_axeY = m_ADXL345->getAxeYString();
    m_axeZ = m_ADXL345->getAxeZString();
}

void Program::printValues() {
    Serial.println(m_axeX);
    Serial.println(m_axeY);
    Serial.println(m_axeZ);
    Serial.println(EMPTY);  
}

void Program::loop() {
    m_ADXL345->tick();
    getADXL345Values();
    if (m_lastReadTime + m_interval < millis()) {   // Pour l'instant, lecture au 1 seconde
        m_lastReadTime = millis();
        printValues();
    }
}
