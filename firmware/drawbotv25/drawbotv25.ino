#include <TMCStepper.h>

#define R_SENSE                 0.075f

#define PIN_GRBL_STEPPER_EN     A0
#define PIN_STEPPER_EN          7
#define PIN_X_CS                4
#define PIN_Y_CS                3
#define PIN_Z_CS                2
#define PIN_X_LIMIT             A7
#define PIN_Y_LIMIT             A6
#define PIN_Z_LIMIT             A5

#define STALL_VALUE             15 // [-64..63]
// #define STALL_VALUE             100 // [0..255

#define ENDSTOP_DWELL_TIME      1000

#define STEPPER_CURRENT_XY      700
#define STEPPER_CURRENT_Z       600

TMC5160Stepper driverX(PIN_X_CS, R_SENSE);
TMC5160Stepper driverY(PIN_Y_CS, R_SENSE);
TMC5160Stepper driverZ(PIN_Z_CS, R_SENSE);

long endstop_hit_X  = -1;
long endstop_hit_Y  = -1;
long endstop_hit_Z  = -1;
long now            = -1;

void initDriver(TMC5160Stepper driver, int current) {

    driver.begin();                 // SPI: Init CS pins
    // driver.toff(5);              // Enables driver in software
    driver.rms_current(current);    // Set motor RMS current
    driver.microsteps(16);          // Set microsteps to 1/16th

    driver.en_pwm_mode(true);       // Toggle stealthChop on TMC2130/2160/5130/5160
    driver.pwm_autoscale(true);     // Needed for stealthChop

    // driver.SGTHRS(STALL_VALUE);

} 

void setup() {

    SPI.begin();

    Serial.begin(9600);

    pinMode(PIN_X_CS,               OUTPUT);
    pinMode(PIN_Y_CS,               OUTPUT);
    pinMode(PIN_Z_CS,               OUTPUT);

    pinMode(PIN_GRBL_STEPPER_EN,    INPUT);
    pinMode(PIN_STEPPER_EN,         OUTPUT);
    pinMode(MISO,                   INPUT_PULLUP);

    pinMode(PIN_X_LIMIT,            OUTPUT);
    pinMode(PIN_Y_LIMIT,            OUTPUT);
    pinMode(PIN_Z_LIMIT,            OUTPUT);

    digitalWrite(PIN_X_LIMIT,       LOW);
    digitalWrite(PIN_Y_LIMIT,       LOW);
    digitalWrite(PIN_Z_LIMIT,       LOW);

    digitalWrite(PIN_STEPPER_EN,    LOW);

    initDriver(driverX, STEPPER_CURRENT_XY);
    initDriver(driverY, STEPPER_CURRENT_XY);
    initDriver(driverZ, STEPPER_CURRENT_Z);
}

void loop() {    
    
    if (digitalRead(PIN_GRBL_STEPPER_EN)) {
        digitalWrite(PIN_STEPPER_EN, HIGH);
    } else {
        digitalWrite(PIN_STEPPER_EN, LOW);
    }

    //Serial.print("0 ");
    //Serial.print(driverZ.ENC_STATUS(), DEC);
    //Serial.print(" "); Serial.print(driver.SG_RESULT(), DEC);
    //Serial.print(" ");
    //Serial.println(driverZ.cs2rms(driverZ.cs_actual()), DEC);

    // if (driverX.SG_RESULT()) {
    //     endstop_hit_X = millis();
    //     digitalWrite(PIN_X_LIMIT, HIGH);
    // }   
    // if (driverY.SG_RESULT()) {
    //     endstop_hit_Y = millis();
    //     digitalWrite(PIN_Y_LIMIT, HIGH);
    // }   
    // if (driverZ.SG_RESULT()) {
    //     endstop_hit_Z = millis();
    //     digitalWrite(PIN_Z_LIMIT, HIGH);
    // }

    // now = millis();
    // if (endstop_hit_X + ENDSTOP_DWELL_TIME > now) {
    //     digitalWrite(PIN_X_LIMIT, LOW);
    //     endstop_hit_X = -1;
    // }
    // if (endstop_hit_Y + ENDSTOP_DWELL_TIME > now) {
    //     digitalWrite(PIN_Y_LIMIT, LOW);
    //     endstop_hit_Y = -1;
    // }
    // if (endstop_hit_Z + ENDSTOP_DWELL_TIME > now) {
    //     digitalWrite(PIN_Z_LIMIT, LOW);
    //     endstop_hit_Z = -1;
    // }

    delay(1);

}
