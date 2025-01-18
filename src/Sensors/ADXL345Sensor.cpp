#include "Sensors/ADXL345Sensor.h"

ADXL345Sensor::ADXL345Sensor() 
  : m_axeX(DEFAULT_ZERO_F),
    m_axeY(DEFAULT_ZERO_F),
    m_axeZ(DEFAULT_ZERO_F),
    m_lastReadTime(DEFAULT_ZERO),
    m_interval(INTERVAL_500) { 
        if(!m_ADXL345.begin()) {
            Serial.println("Incapable de démarrer le capteur ADXL345. Vérifiez l'adresse et le câblage.");
            while(true);
        } else {
             Serial.println("Capteur ADXL345 initialisé avec succès.");
        }
    }

void ADXL345Sensor::setMembresValues() {
    sensors_event_t event;
    this->m_ADXL345.getEvent(&event);

    this->m_axeX = event.acceleration.x;
    this->m_axeY = event.acceleration.y;
    this->m_axeZ = event.acceleration.z;
}

// Retour en String, exemple: 21,15m/s² Soit 2,2G
String ADXL345Sensor::getAxeXString() {
    return String(this->m_axeX) + MS2 + " Soit " + String(this->m_axeX / G_CONST, 1) + "G";
}
String ADXL345Sensor::getAxeYString() {
    return String(this->m_axeY) + MS2 + " Soit " + String(this->m_axeY / G_CONST, 1) + "G";
}
String ADXL345Sensor::getAxeZString() {
    return String(this->m_axeZ) + MS2 + " Soit " + String(this->m_axeZ / G_CONST, 1) + "G";
}

// Retour en float, exemple: 21,15
float ADXL345Sensor::getAxeXms2() {
    return this->m_axeX;
}
float ADXL345Sensor::getAxeYms2() {
    return this->m_axeY;
}
float ADXL345Sensor::getAxeZms2() {
    return this->m_axeZ;
}

// Retour en float exemple: 2,2
float ADXL345Sensor::getAxeXg() {
    return String(this->m_axeX / G_CONST, 1).toFloat();             // Formate facilement le float avec 1 chiffre après la virgule
}
float ADXL345Sensor::getAxeYg() {
    return String(this->m_axeY / G_CONST, 1).toFloat();
}
float ADXL345Sensor::getAxeZg() {
    return String(this->m_axeZ / G_CONST, 1).toFloat();
}

void ADXL345Sensor::tick() {
    if (this->m_lastReadTime + this->m_interval < millis()) {       // Pour l'instant, lecture au 1/2 seconde
        this->m_lastReadTime = millis();
        setMembresValues();
    }
}
