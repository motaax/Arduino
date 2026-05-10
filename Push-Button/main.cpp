#include <Arduino.h>

#define led 4
#define button 3
int buttonclick = 0;
int buttonlibera = 0;

void trocaLed() {
  if(digitalRead(led) == HIGH) {
    digitalWrite(led, LOW);
    buttonlibera = 0;
  } else {
    digitalWrite(led, HIGH);
  }
}

void keyup() {
  if(buttonclick == 1 && buttonlibera == 1) {
    buttonclick = 0;
    buttonlibera = 0;
    trocaLed();
  }
}

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  if(digitalRead(button) == HIGH) {
    buttonclick = 1;
    buttonlibera = 0;
  } else {
    buttonlibera = 1;
  }

  keyup();
}