#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

const int buttonPin = 2;

int buttonState = 0;
int lastButtonState = 0;
int clicks = 0;
int circle= 0;
int drawNum[] = {10, 8, 4, 4, 1};
int randNum;

void setup() {
    lcd.begin(16,2);
    lcd.backlight();

    Serial.begin(9600);
    Serial.println("Hello and again, welcome to this Arduino program");
    pinMode(buttonPin, INPUT);
    randomSeed(analogRead(0));
}

void loop() {
    randNum = random(1, drawNum[circle]);
    buttonState = digitalRead(buttonPin);
    if (buttonState != lastButtonState) {
        if (buttonState == HIGH) {
            clicks++;
            lcd.setCursor(0,0);
            lcd.print("You clicked: ");
            lcd.print("  ");
            lcd.setCursor(13, 0);
            lcd.print(clicks);
            lcd.print("  ");
            lcd.setCursor(0, 1);
            lcd.print(randNum);
            Serial.print("Cricle: ");
            Serial.println(circle);
            Serial.print("Number pulled from the array: ");
            Serial.println(drawNum[circle]);
            Serial.print("Randomly generated number: ");
            Serial.println(randNum);
            Serial.print("Click: ");
            Serial.println(clicks);

        }
        delay (50);
    }
    lastButtonState = buttonState;

    if (clicks == drawNum[circle]) {
        clicks = 0;
        circle++;
    } 
}