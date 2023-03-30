#include <Arduino.h>
#include <String>

#include <WiFi.h>
#include <WiFiMulti.h>

#include "ptzController.cpp"
#define USE_SERIAL Serial

WiFiMulti wifiMulti;

PtzController ptzController;

void setup() {

    USE_SERIAL.begin(115200);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();

    for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
        USE_SERIAL.flush();
        delay(1000);
    }

    wifiMulti.addAP("Riki_Tiki_tak", "1706199517061995");

}

void loop() {
    if((wifiMulti.run() == WL_CONNECTED)) {


    ptzController.gotoPreset("0");
    delay(2000);
    ptzController.gotoPreset("1");
    delay(2000);
    ptzController.gotoPreset("2--");
    delay(2000);
    USE_SERIAL.println("Stop()");

    delay(3000);
    }
}
