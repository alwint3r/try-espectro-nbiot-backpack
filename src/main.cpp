#include <Arduino.h>
#include <HardwareSerial.h>
#include <Sodaq_nbIOT.h>
#include <Sodaq_nbIOT_UDP.h>

HardwareSerial nbSerial(1);

#define PIN_ENABLE 17
#define RXPIN 25
#define TXPIN 26
#define DTRPIN 14
#define RTSPIN 2

Sodaq_nbIOT nbiot;
Sodaq_nbIOT_UDP udp(nbiot);

void setup() {
    Serial.begin(115200);

    pinMode(DTRPIN, OUTPUT);
    pinMode(RTSPIN, OUTPUT);
    digitalWrite(DTRPIN, LOW);
    digitalWrite(RTSPIN, LOW);

    pinMode(PIN_ENABLE, OUTPUT);
    digitalWrite(PIN_ENABLE, HIGH);
    delay(500);
    digitalWrite(PIN_ENABLE, LOW);
    delay(500);
    digitalWrite(PIN_ENABLE, HIGH);

    nbSerial.begin(115200, SERIAL_8N1, RXPIN, TXPIN);

    nbiot.init(nbSerial, -1, -1, -1, 1);
    nbiot.setDiag(Serial);
    nbiot.on();
    nbiot.connect("iotxl", "");
}

void loop() {
    while (Serial.available()) {
        nbSerial.write(Serial.read());
    }

    while (nbSerial.available()) {
        Serial.write(nbSerial.read());
    }
}
