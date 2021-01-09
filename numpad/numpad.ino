#include <Keypad.h>
const char first = '1';
const int second = '5';
const int third = '2';
const int fourth = '1';

const int led1 = 10;
const int led2 = 12;
const int led3 = 11;
const int led4 = 13;

int correct = 0;
int wrong = 0;

boolean complete = false;


char hexaKeys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[4] = {9, 8, 7, 6}; 
byte colPins[4] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, 4, 4); 

void solid () {
  for (int i = 0; i < 3; i++) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      delay(200);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      delay(200);
  }

  digitalWrite(led1, HIGH);   
}

void blinkN (int n) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  if (n == 0) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    delay(200);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    delay(200);
  }
  else if (n == 1) {
    digitalWrite(led1, HIGH);
  } else if (n == 2) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    
  } else if (n == 3) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  } else if (n == 4) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
}

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  if (!complete) {
      if (customKey){
        Serial.println(customKey);
        
        if (correct + wrong == 4) {
          if (!complete) {
            correct = 0;
            wrong = 0;
          }
          
        } else {
          if (correct + wrong == 0) {
            if (customKey == first) {
              correct++;
            } else {
              wrong++;
            }
          } else if (correct + wrong == 1) {
            if (customKey == second) {
              correct++;
            } else {
              wrong++;
            }
          } else if (correct + wrong == 2) {
            if (customKey == third) {
              correct++;
            } else {
              wrong++;
            }
          } else if (correct + wrong == 3) {
            if (customKey == fourth) {
              correct++;
            } else {
              wrong++;
            }
    
            if (correct == 4) {
              complete = true;
              Serial.println("Completed");
            } else {
              Serial.print("Correct : ");
              Serial.println(correct);
              Serial.print("Wrong : ");
              Serial.println(wrong);
              blinkN(correct);
              correct = 0;
              wrong = 0;
              
            }
        

        
        }
      }
      delay(100);
    }
  } else {
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    
    digitalWrite(led1, HIGH);
    delay(200);
    digitalWrite(led1, LOW);
    delay(200);

//    if (customKey) {
//      correct = 0;
//      wrong = 0;
//      complete = false;
//    }
  }
  

  
}
