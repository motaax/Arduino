#include <Arduino.h>

#define ledR 2
#define ledG 4
#define ledB 3
#define botao 7
#define maximo 3

int buttonclick = 0;
int buttonliberado = 0;
int ciclo = 0;

void vermelho() {
	digitalWrite(ledR, HIGH);
  	digitalWrite(ledG, LOW);
  	digitalWrite(ledB, LOW);
}

void verde() {
	digitalWrite(ledR, LOW);
  	digitalWrite(ledG, HIGH);
  	digitalWrite(ledB, LOW);
}

void azul() {
	digitalWrite(ledR, LOW);
  	digitalWrite(ledG, LOW);
  	digitalWrite(ledB, HIGH);
}

void trocaLed() {
  if(ciclo == 0) {
    vermelho();
  } else if(ciclo == 1){
  	verde();
  } else if(ciclo == 2){
  	azul();
  }
  
  ciclo++;
  
  if(ciclo > maximo - 1) {
   	ciclo = 0; 
  } 
}

void verificaButton() {
  if(digitalRead(botao) == HIGH) {
  	buttonclick = 1;  
    buttonliberado = 0;
  } else {
  	buttonliberado = 1;
  }
     
     if((buttonclick == 1) && (buttonliberado == 1)) {
  		buttonclick = 0;  
    	buttonliberado = 0;
    	trocaLed();
  } 
}

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  verificaButton();
}