/*Multi Interface header file
Author: E.Burkowski / e.burkowski@konnekting.de, GPL Licensed
*/

//don't change this lines!
#include <Wire.h>
#include <Arduino.h>

#define PROG_LED_PIN A5
#define PROG_BUTTON_PIN 38
#define KNX_SERIAL Serial
#define FLASH_CS 9 

#ifdef KDEBUG
#include <DebugUtil.h>
#define DEBUGSERIAL SerialUSB
#endif



#ifdef EEPROM_24AA256
// use 24AA256 I2C EEPROM
byte readMemory(int index) {
    byte data = 0xFF;
    if(index >= 0 && index < 32768){
        Wire.beginTransmission(0x50);
        Wire.write((int) (index >> 8));
        Wire.write((int) (index & 0xFF));
        Wire.endTransmission();
        Wire.requestFrom(0x50, 1);
        if (Wire.available()) {
            data = Wire.read();
        }
    }
    return data;
}

void writeMemory(int index, byte val) {
    if(index >= 0 && index < 32768 && val >= 0 && val < 256){
        Wire.beginTransmission(0x50);
        Wire.write((int) (index >> 8));
        Wire.write((int) (index & 0xFF));
        Wire.write(val);
        Wire.endTransmission();
        delay(5); //is it needed?!
    }
}

void updateMemory(int index, byte val) {
    if (readMemory(index) != val) {
        writeMemory(index, val);
    }
}

void commitMemory() {
    // EEPROM needs no commit, so this function is intentionally left blank 
}
#else 
//FlashStorage
byte readMemory(int index) {
    Debug.println(F("FLASH read on index %d"),index);
    return EEPROM.read(index);
}

void writeMemory(int index, byte val) {
    Debug.println(F("FLASH write value %d on index %d"),val, index);
    EEPROM.write(index, val);
}

void updateMemory(int index, byte val) {
    Debug.println(F("FLASH update"));
    if (EEPROM.read(index) != val) {
        EEPROM.write(index, val);
    }
}

void commitMemory() {
    Debug.println(F("FLASH commit"));
    EEPROM.commit();
}
#endif

void kinit(){
#ifdef KDEBUG

    // Start debug serial with 115200 bauds
    DEBUGSERIAL.begin(115200);
    // wait for serial port to connect. Needed for Leonardo/Micro/ProMicro/Zero only
    delay(5000);//wait for serial
    //while (!DEBUGSERIAL)
    // make debug serial port known to debug class
    // Means: KONNEKTING will use the same serial port for console debugging
    Debug.setPrintStream(&DEBUGSERIAL);
#endif
    Wire.begin();
    Wire.setClock(400000L);
    Konnekting.setMemoryReadFunc(&readMemory);
    Konnekting.setMemoryWriteFunc(&writeMemory);
    Konnekting.setMemoryUpdateFunc(&updateMemory);
    Konnekting.setMemoryCommitFunc(&commitMemory);


    // Initialize KNX enabled Arduino Board
    Konnekting.init(KNX_SERIAL,
            PROG_BUTTON_PIN,
            PROG_LED_PIN,
            MANUFACTURER_ID,
            DEVICE_ID,
            REVISION); 
}

