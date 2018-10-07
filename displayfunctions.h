#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

byte   type[MAX_LINES];
String text[MAX_LINES];
String unit[MAX_LINES];
String val0[MAX_LINES];
String val1[MAX_LINES];
char timeValue[9];
char dateValue[9];
bool timeline = false;

void displayInit(){
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
    // init done, show KONNEKTING LOGO
    display.clearDisplay();
    display.drawBitmap(32, 0, klogo64_glcd_bmp, KLOGO64_GLCD_WIDTH, KLOGO64_GLCD_HEIGHT, WHITE);
    display.display();
    delay(1000);
    
    // Clear the buffer.
    display.clearDisplay();
}


void updateInfo(byte line, byte column, char *text){
    Debug.println(F("UPDATE: Line %d, column %d, text: %s"), line, column, text);
    display.setTextSize(1);
    display.setTextColor(WHITE,BLACK);
    switch(column){
        case 0:
            display.setCursor(0, 8 * line);
            break;
        case 1:
            display.setCursor(69, 8 * line);
            break;
        case 2:
            display.setCursor(108, 8 * line);
            break;
        default:
            break;
    }
    display.print(text);
    display.display();
}


void updateTime(byte *time){
    char out[] = {0,0,0,0,0,0,0,0,0};
    sprintf(out, "%2d:%02d", time[0] & B00011111, time[1]);
    Debug.println(F("Time: %2d:%02d"),time[0] & B00011111, time[1]);
    display.setTextSize(1);
    display.setTextColor(WHITE,BLACK);
    display.setCursor(75, 0);
    display.print(out);
    display.display();
}

void updateDate(byte *date){
  	char out[] = {0,0,0,0,0,0,0,0,0,0};
  	sprintf(out, "%02d.%02d.20%d", date[0], date[1], date[2]);
    Debug.println(F("Date: %d.%02d.20%d"),date[0], date[1], date[2]);
  	display.setTextSize(1);
    display.setTextColor(WHITE,BLACK);
  	display.setCursor(0, 0);
  	display.print(out);
    display.display();
}

void intToChar(int val, char *out){
    sprintf(out, "%6d", val);
    Debug.println(F("intToChar: %d -> %s"), val, out);
}

void doubleToChar(float val, char *out){
/* max 6 digits:
-12345	x < -999.99
-123.4	x < -99.99, x >= -999.99
-12.34	x < 0, x >= -99.99
  0.00
123.45	x <= 999.99, x >= 0
1234.5	x <= 9999.99, x > 999.99
123456	x > 9999.99
*/
	if (val < -999.99){
  	  	sprintf(out, "%6d", (int)val); //-12345
  	}else if (val < -99.99 && val >= -999.99){
  	  	sprintf(out, "%6.1f", val);    //-123.4
  	}else if (val < 0 && val >= -99.99){
  	  	sprintf(out, "%6.2f", val);    //-12.34
  	}else if(val <= 999.99 && val >= 0.0){
  		  sprintf(out, "%6.2f", val);    //123.45
  	}else if(val <= 9999.99 && val > 999.99){
  		  sprintf(out, "%6.1f", val);    //1234.5
  	}else{
  		  sprintf(out, "%6d", (int)val); //123456
  	}
    Debug.println(F("doubleToChar: %9.2f -> %s"), val, out);
}
