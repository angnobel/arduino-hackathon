#include <Keypad.h>
const char first = 'C';
const int second = '3';
const int third = '8';
const int fourth = '0';

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

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
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
          correct = 0;
          wrong = 0;
        }
        

        
      }
    }
    
  }

  delay(100);
}
