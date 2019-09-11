int randNum;
int ranLet;
const int buttonPin = 2;
char *myString[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
int buttonState = 0;
int lastButtonState = 0;

void setup() {
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
    randomSeed(analogRead(0));
}

void loop() {
    buttonState = digitalRead(buttonPin);
    if (buttonState != lastButtonState) {
        if (buttonState == HIGH) {
            randNum = random(1, 10);
            ranLet = random(10);
            Serial.print(randNum);
            Serial.println(myString[ranLet]);
        }
        delay (50);
    }
    lastButtonState = buttonState;
}