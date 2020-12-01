#include <TMCStepper.h>

// Errata:
//
// Y_CS uses PD5 which is not available on standard Arduino Leonardo

#define R_SENSE 0.075f  // Match to your driver
                        // SilentStepStick series use 0.11
                        // UltiMachine Einsy and Archim2 boards use 0.2
                        // Panucatt BSD2660 uses 0.1
                        // Watterott TMC5160 uses 0.075


#define CS_PIN       A5 // Chip select

TMC5160Stepper driver(CS_PIN, R_SENSE);

void setup() {

    SPI.begin();

    Serial.begin(9600);

    pinMode(CS_PIN, OUTPUT);
    pinMode(MISO, INPUT_PULLUP);

    driver.begin();
    driver.toff(4);
    driver.blank_time(24);
    driver.rms_current(400); // mA
    driver.microsteps(16);
    driver.TCOOLTHRS(0xFFFFF); // 20bit max
    driver.THIGH(0);
    driver.semin(5);
    driver.semax(2);
    driver.sedn(0b01);
    driver.sgt(STALL_VALUE);

}

void loop() {    

}
