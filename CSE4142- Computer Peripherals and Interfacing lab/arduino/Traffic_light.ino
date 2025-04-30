int red = 10;
int yellow = 12;
int green = 11;
//###########################
void setup(){
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
}
//###########################
void loop(){
    changeLights();
   // delay(1000);
}

void changeLights(){
    // Red on for 10 Sec
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    delay(10000);

    // Yellow on for 5 sec
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(5000);

    // Green on for 15 sec
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    delay(15000);
   
}
