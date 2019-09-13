#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

const int buttonPin = 2;
const int switchPin = 3;

int buttonState = 0;
int lastButtonState = 0;
int clicks = 0;
int circle= 0;
int drawNum[] = {10, 4, 4, 1};
int totalHexAmount[] = {18, 12, 6, 6, 6};
int randNum;

bool stop = false;

void setup() {
    lcd.begin(16,2);
    lcd.backlight();
    lcd.print("Press button!");

    Serial.begin(9600);
    pinMode(buttonPin, INPUT);
    pinMode(switchPin, INPUT);
    randomSeed(analogRead(0));
}

void loop() {
    if (digitalRead(switchPin) == HIGH) {
        stop = true;
    } else {
        stop = false;
    }
    buttonState = digitalRead(buttonPin);
    if (buttonState != lastButtonState) {
        if (buttonState == HIGH) {
          if (stop == false) {
                  clicks++;
              }
            randNum = random(1, totalHexAmount[circle]);
            lcd.setCursor(0,0);
            lcd.print("You clicked: ");
            lcd.print("  ");
            lcd.setCursor(13, 0);
            lcd.print(clicks);
            lcd.setCursor(0, 1);
            lcd.print("  ");
            lcd.setCursor(0, 1);
            lcd.print(randNum);

        }
        delay (50);
    }
    lastButtonState = buttonState;

    if (circle >= 4 && clicks >= 1 ) {
        stop = true;
    } else if (clicks == drawNum[circle] && stop == false) {
        clicks = 0;
        circle++;
    }
}