// Digital Dice Project
// Press the button to roll the dice
// Arduino Uno + 7-Segment Display + Buzzer

#include <Arduino.h>

const int buttonPin = 2;
const int buzzerPin = 8;
const int segmentPins[7] = {3,4,5,6,7,9,10}; // a,b,c,d,e,f,g
int buttonState = 0;

const byte numbers[6][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}  // 5
};

void setup() {
  for(int i=0; i<7; i++) pinMode(segmentPins[i], OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  randomSeed(analogRead(0)); // random seed
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH){
    int dice = random(1,7); // generate 1-6
    for(int i=0; i<7; i++){
      digitalWrite(segmentPins[i], numbers[dice-1][i]);
    }
    tone(buzzerPin, 1000, 100); // beep
    delay(500); // debounce
  }
}
