#include "Program.h"

Program::Program()
  : m_ADXL345(nullptr),  
    m_lastReadTime(DEFAULT_ZERO),
    m_interval(INTERVAL_1) {                    // 1 sec               
        this->m_ADXL345 = new ADXL345Sensor();
    
}

void Program::printValues() {
    Serial.print("Accel axe X: " + String(m_ADXL345->getAxeXString()));
    Serial.println("    Max accel axe X: " + String(this->m_ADXL345->getMaxAccelX()) + "G");
    Serial.print("Accel axe Y: " + String(m_ADXL345->getAxeYString()));
    Serial.println("    Max accel axe Y: " + String(this->m_ADXL345->getMaxAccelY()) + "G");
    Serial.print("Accel axe Z: " + String(m_ADXL345->getAxeZString()));
    Serial.println("    Max accel axe Z: " + String(this->m_ADXL345->getMaxAccelZ()) + "G");
    Serial.println(EMPTY);  
}

void Program::loop() {
    m_ADXL345->tick();
    if (m_lastReadTime + m_interval < millis()) {   // Pour l'instant, lecture au 1 seconde
        m_lastReadTime = millis();
        printValues();
    }
}
