/*
PIR sensor tester
*/
int relay = 13; // choose the pin for the relay
int inputPin = 2; // choose the input pin (for PIR sensor)
int pirState = LOW; // we start, assuming no motion detected
int val = 0; // variable for reading the pin status
void setup() {
pinMode(relay, OUTPUT); // declare relay as output
pinMode(inputPin, INPUT); // declare sensor as input
Serial.begin(9600);
}
void loop() {
val = digitalRead(inputPin); // read input value
if (val == HIGH) { // check if the input is HIGH
digitalWrite(relay, HIGH); // turn relay ON
if (pirState == LOW) {
// we have just turned on
Serial.println("Motion detected!");
// We only want to print on the output change, not state
pirState = HIGH;
}
} else {
digitalWrite(relay, LOW); // turn relay OFF
if (pirState == HIGH) {
// we have just turned of
Serial.println("Motion ended!");
// We only want to print on the output change, not state
pirState = LOW;
}
}
}
