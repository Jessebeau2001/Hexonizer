int randNum;
int ranLet;
char *myString[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};

void setup() {
    Serial.begin(9600);
}

void loop() {
    randNum = random(1, 10);
    ranLet = random(10);
    Serial.print(randNum);
    Serial.println(myString[ranLet]);
    delay(5000);
}