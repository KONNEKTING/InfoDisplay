/* ---------------------------------------------------------------------------------------------
Info Display 1.0
Hardware/Firmware/Sketch/kdevice.xml by E.Burkowski / e.burkowski@konnekting.de, GPL Licensed
Compatible with: KONNEKTING Device Library 1.0.0 beta 4b
*/

/* this libraries are required (click on link and download with library manager):
KONNEKTING Device Library: http://librarymanager/All#Konnekting
FlashStorage:              http://librarymanager/All#FlashStorage
Adafruit_GFX_Library       http://librarymanager/All#Adafruit_GFX
Adafruit_SSD1306:          http://librarymanager/All#Adafruit_SSD1306
*/



// ################################################
// ### DEBUG CONFIGURATION
// ################################################
//#define KDEBUG

#define MAX_LINES 8
#define FIRST_PARAM 1
#define PARAM_AMOUNT 5
#define FIRST_COMBJ 2
#define COMBJ_AMOUNT 6
#define EEPROM_EMULATION_SIZE 2048 //for FlashStorage
//#define EEPROM_24AA256

#ifndef EEPROM_24AA256
#include <FlashAsEEPROM.h>
#endif
#include <KonnektingDevice.h>
#include "kdevice_Debug_Display.h"
#include "mi.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Konnekting_logo_64x64_bw.h"
#include "displayfunctions.h"



/*
Types
06=unused
00=byte (DPT 5.0xx)
01=integer value (DPT 8.0xx)
02=unsigned interger value (DPT 7.0xx)
03=float value (DPT 9.0xx)
04=text for bool value (DPT 1.0xx)
05=text (DPT 16.001)
07=date/time (DPT 10.001 + DPT 11.001)

2 Text  00|01|02|03|04 le 04
3 Unit  00|01|02|03	   le 03
4 Text0 04             eq 04
5 Text1 04             eq 04

05|06 alle ausblenden

CO DPT    Values

2  5.0xx  0..255             00
3  8.0xx  -32768..32767      01
4  7.0xx  0..65535           02
5  9.0xx  -9999.99..99999.99 03
6  1.0xx  0/1                04
7  16.001 text               05

*/

/*
ComObjects per group
*/
byte TYPE_DPT1_0XX = 4;
byte TYPE_DPT5_0XX = 0;
byte TYPE_DPT7_0XX = 2;
byte TYPE_DPT8_0XX = 1;
byte TYPE_DPT9_0XX = 3;
byte TYPE_DPT16_001 = 5;

//Store new Strings
char tempByteValue[] = {0,0,0,0,0,0,0};
char tempUIntValue[] = {0,0,0,0,0,0,0};
char tempIntValue[]  = {0,0,0,0,0,0,0};
char tempFloatValue[] = {0,0,0,0,0,0,0};
char tempBoolValue[] = {0,0,0,0,0,0,0,0,0,0};
byte tempText[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//char or byte? 

bool updateByte = false;
bool updateUInt = false;
bool updateInt = false;
bool updateFloat = false;
bool updateBool = false;
bool updateText = false;

byte lineByte = 255;
byte lineUInt = 255;
byte lineInt = 255;
byte lineFloat = 255;
byte lineBool = 255;
byte lineText = 255;

//Dirty hack, getSTRING11Param can't handle "°" and umlauts
String getSTRING11Param(byte index) {
    String ret;

    byte paramValue[PARAM_STRING11];
    Konnekting.getParamValue(index, paramValue);

    // check if string is 0x00 terminated (means <11 chars)
    for (int i = 0; i < PARAM_STRING11; i++) {
        if (paramValue[i] == 0x00) {
             // stop at null-termination
        } else {
            switch(paramValue[i]){//E4 F6 FC DF C4 D6 DC B0 äöüßÄÖÜ°
                case 0xE4:
                    ret += (char)0x84;//"ä"
                    break;
                case 0xF6:
                    ret += (char)0x94;//"ö"
                    break;
                case 0xFC:
                    ret += (char)0x81;//"ü"
                    break;
                case 0xDF:
                    ret += (char)0xE0;//"ß"
                    break;
                case 0xC4:
                    ret += (char)0x8E;//"Ä"
                    break;
                case 0xD6:
                    ret += (char)0x99;//"Ö"
                    break;
                case 0xDC:
                    ret += (char)0x9A;//"Ü"
                    break;
                case 0xB0:
                    ret += (char)0xF7;//deegre symbol for Adafruit SSD1306
                    break;
                default:
                    ret += (char) paramValue[i]; // copy char by char into string      
                    break;
            }
        }
    }

    return ret;
}



void setup() {
    kinit();
    displayInit();
    if (!Konnekting.isFactorySetting()) {
        for (byte l = 0; l < MAX_LINES;l++){
            type[l] = Konnekting.getUINT8Param(l*PARAM_AMOUNT+FIRST_PARAM);
            text[l] = getSTRING11Param(l*PARAM_AMOUNT+FIRST_PARAM + 1);
            unit[l] = getSTRING11Param(l*PARAM_AMOUNT+FIRST_PARAM + 2);
            val0[l] = getSTRING11Param(l*PARAM_AMOUNT+FIRST_PARAM + 3);
            val1[l] = getSTRING11Param(l*PARAM_AMOUNT+FIRST_PARAM + 4);
        }
    }else{
        Konnekting.toggleProgState();
    }
/*    for (byte l = 0; l < MAX_LINES;l++){
        Debug.println(F("Line %d, Type: %d, Text: %s, Unit: %s, Value 0: %s, Value 1: %s"),type[l],text[l],unit[l],val0[l],val1[l]);
    }*/
  	if (!Konnekting.isFactorySetting()) {
      	for (byte l = 0; l < MAX_LINES;l++){
      	
        		if(type[l] <= 4){
          			char tempText[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
          			text[l].toCharArray(tempText, 12);
          			updateInfo(l,0,tempText);
        		}
        		if(type[l] <= 3){
          			char tempUnit[4] = {0,0,0,0};
          			unit[l].toCharArray(tempUnit, 4);
          			updateInfo(l,2,tempUnit);
        		}
      	}
  	}
    Debug.println("Setup is ready");
}

void loop() {
    Knx.task();
    if(updateByte && lineByte != 255){
        updateInfo(lineByte, 1, tempByteValue);
        updateByte = false;
        lineByte = 255;
    }
}

// ################################################
// ### KNX EVENT CALLBACK
// ################################################

void knxEvents(byte comObj) {
    Debug.println(F("knxEvents: %d"),comObj);
    
  	if(comObj == COMOBJ_line1time){
    		byte temp[] = {0,0,0};
    		Knx.read(comObj,temp);
    		updateTime(temp);
  	}else if(comObj == COMOBJ_line1date){
    		byte temp[] = {0,0,0};
    		Knx.read(comObj,temp);
    		updateDate(temp);
  	}else{
    		byte line = (byte)floor((comObj-FIRST_COMBJ) / COMBJ_AMOUNT); 
    		byte type = (byte)((comObj-FIRST_COMBJ) % COMBJ_AMOUNT);
    		Debug.println(F("ComObj: %d, line: %d, type: %d"),comObj,line,type);
        if (type == TYPE_DPT5_0XX){//byte
            Debug.println(F("type: byte (DPT 5.0xx)"));
				    byte tempByte = 0;
				    Debug.println(F("tempByte: %d"), tempByte);
				    tempByte = (byte)Knx.read(comObj); //workaround for beta4
      			intToChar(tempByte, tempByteValue);
            lineByte = line;
            updateByte = true;
        }
	      if (type == TYPE_DPT7_0XX){ //uint
            Debug.println(F("type: unit (DPT 7.0xx)"));

				    unsigned int tempUInt = 0;
            Knx.read(comObj, tempUInt);
            Debug.println(F("tempUInt: %d"), tempUInt);
      			intToChar(tempUInt, tempUIntValue);
            updateInfo(line, 1, tempUIntValue);
      			
	      }
	      if (type == TYPE_DPT8_0XX){ //int
            Debug.println(F("type: int (DPT 8.0xx)"));
            //SAMD21's int is 4 byte long. KNX's is 2 byte, so we use short on SAMD21 for KNX int
				    short tempInt = 0;
            Knx.read(comObj,tempInt);
				    Debug.println(F("tempInt: %d"), tempInt);
      			intToChar(tempInt, tempIntValue);
      	    updateInfo(line, 1, tempIntValue);
	      }
    		if (type == TYPE_DPT9_0XX){ //float
            Debug.println(F("type: float (DPT 9.0xx)"));

            float tempFloat = 0;
            Knx.read(comObj,tempFloat);
            Debug.println(F("tempFloat: %6.2f"), tempFloat);
            unsigned long startTime = millis();
      			doubleToChar(tempFloat, tempFloatValue);
      			updateInfo(line, 1, tempFloatValue);
            Debug.println(F("Time to display: %d"), millis()-startTime);
    		}
    		if (type == TYPE_DPT1_0XX){ //text for bool value
            Debug.println(F("type: text for bool (DPT 1.0xx)"));
            display.setTextSize(1);
            display.setTextColor(WHITE,BLACK);
            display.setCursor(69, 8 * line);
            display.print("         ");
            display.setCursor(69, 8 * line);
      			if(Knx.read(comObj)){
//      				  val1[line].toCharArray(tempBoolValue, 10);
                  display.print(val1[line]);
      			}else{
//      				  val0[line].toCharArray(tempBoolValue, 10);
                  display.print(val0[line]);
      			}
            display.display();
//      			updateInfo(line, 1, tempBoolValue);
    		}
    		if (type == TYPE_DPT16_001){ //text
            Debug.println(F("type: text (DPT 16.001)"));

      			Knx.read(comObj,tempText);
            display.setTextSize(1);
            display.setTextColor(WHITE,BLACK);
            display.setCursor(0, 8 * line);
            //workaround to cast byte to char
            //char out[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            String ret;
            for(byte i = 0; i < sizeof(tempText);i++){
                switch(tempText[i]){//E4 F6 FC DF C4 D6 DC B0 äöüßÄÖÜ°
                    case 0xE4:
                        ret += (char)0x84;//"ä"
                        break;
                    case 0xF6:
                        ret += (char)0x94;//"ö"
                        break;
                    case 0xFC:
                        ret += (char)0x81;//"ü"
                        break;
                    case 0xDF:
                        ret += (char)0xE0;//"ß"
                        break;
                    case 0xC4:
                        ret += (char)0x8E;//"Ä"
                        break;
                    case 0xD6:
                        ret += (char)0x99;//"Ö"
                        break;
                    case 0xDC:
                        ret += (char)0x9A;//"Ü"
                        break;
                    case 0xB0:
                        ret += (char)0xF7;  //deegre symbol for Adafruit SSD1306
                        break;
                    default:
                        ret += (char) tempText[i]; // copy char by char into string      
                        break;
                }
            //    Debug.println(F("Byte %02d, data %03d"),i,tempText[i]);
            }
           //  = {tempText[0],tempText[1],tempText[2],tempText[3],tempText[4],tempText[5],tempText[6],tempText[7],tempText[8],tempText[9],tempText[10],tempText[11],tempText[12],tempText[13],tempText[14],tempText[15],tempText[16],tempText[17]};
            //sprintf(out, "%c", tempText);
            //Debug.println(F(ret));
            display.print(ret);
            display.display();
    		}
  	}
}

